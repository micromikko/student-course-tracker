#pragma once
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include  "Course.h"

#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/list.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

//#include <boost/serialization/list.hpp>
//#include <boost/serialization/split_member.hpp>
//#include <boost/serialization/base_object.hpp>
//#include <boost/archive/tmpdir.hpp>
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/serialization/base_object.hpp>
//#include <boost/serialization/utility.hpp>
//#include <boost/serialization/assume_abstract.hpp>


#define DEGREE_LENGTH 50
#define GRADE_MIN_GIVABLE 0

class HOPS {
//friend std::istream &operator >> (std::istream &in, HOPS &p);
friend std::ostream &operator<<(std::ostream &out, const HOPS &h);
friend class boost::serialization::access;

template<class Archive>
void serialize(Archive &ar, const unsigned int version)
{
	ar & degreeName;
	ar & courseList;
	ar & requiredEcts;
	ar & currentEcts;
}
public:
	HOPS(std::string degreeName="General Studies");
	//TODO: TEST COPY CONSTRUCTOR
	HOPS(const HOPS &HOPStoCopy);
	virtual ~HOPS();
	
	std::string getDegreeName();
	bool setDegreeName(std::string degreeName);

	bool initialize();
	bool addCourse(Course* newCourse);
	bool addCourse(std::string courseId, std::string courseName, int courseEcts = 0, int courseGrade = -1, std::string courseDescription = "");
	bool deleteCourse(std::string courseId);

	std::vector<Course*> getCourseList() const;
	bool editEditGrade(std::string courseId, int grade);
	//TODO: bool sortCourseList(std::string order);

	int getRequiredEcts();
	bool setRequiredEcts(int requiredEcts);

	int getCurrentEcts();
	void HOPS::sortHopsList();


private:
	std::string degreeName;
	std::vector<Course*> courseList;
	int requiredEcts;
	int currentEcts;
};

