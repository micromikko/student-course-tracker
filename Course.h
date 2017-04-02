#pragma once
#include "stdafx.h"
#include <cstddef> // NULL
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#define DESCRIPTION_MAX 500
#define GRADE_MIN 0
#define GRADE_MAX 5
#define GRADE_EMPTY -1
#define ECTS_MIN 0
#define COURSE_MAX_THEO 13



//#include <boost/serialization/split_member.hpp>
//#include <boost/serialization/base_object.hpp>
//#include <boost/archive/tmpdir.hpp>
//#include <boost/serialization/base_object.hpp>
//#include <boost/serialization/utility.hpp>
//#include <boost/serialization/assume_abstract.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>


class Course {
//friend std::istream &operator >> (std::istream &in, Course &c);
friend std::ostream &operator<<(std::ostream &out, const Course &c);
friend class boost::serialization::access;
template<class Archive>
void serialize(Archive & ar, const unsigned int version)
{
	ar & courseId;
	ar & courseName;
	ar & courseEcts;
	ar & courseGrade;
	ar & courseDescription;
}

public:
	Course(std::string courseId="NO_ID", std::string courseName="NO_NAME", int courseEcts = 0, int courseGrade = -1, std::string courseDescription = "");
	Course(const Course &c);
	virtual ~Course();

	std::string getCourseId();
	bool setCourseId(std::string courseId);

	std::string getCourseName();
	bool setCourseName(std::string courseName);

	int getCourseEcts();
	bool setCourseEcts(int courseEcts);

	int getCourseGrade();
	bool setCourseGrade(int courseGrade);

	std::string getCourseDescrpition();
	bool setCourseDescrpition(std::string courseDescription);

private:
	std::string courseId;
	std::string courseName;
	int courseEcts;
	int courseGrade;
	std::string courseDescription;
};

