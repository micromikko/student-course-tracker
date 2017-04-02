#pragma once
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include  "Course.h"
#include "HOPS.h"



#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/serialization/vector.hpp>

#define STUDENT_NAME_MAX 50
#define STUDENT_ID_MAX 50

//#include <boost/serialization/split_member.hpp>
//#include <boost/serialization/base_object.hpp>
//#include <boost/archive/tmpdir.hpp>
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/serialization/base_object.hpp>




class Student {
//friend std::istream &operator >> (std::istream &in, Student &p);
friend std::ostream &operator<<(std::ostream &out, const Student &s);
friend class boost::serialization::access;

template<class Archive>
void serialize(Archive &ar, const unsigned int version)
{
	ar & studentId;
	ar & studentName;
	ar & studentHops;
	ar & studentTotalEcts;
}
public:
	Student(std::string studentId, std::string studentName, HOPS *newhops);
	virtual ~Student();

	std::string getStudentId();
	bool setStudentId(std::string studentId);

	std::string getStudentName();
	bool setStudentName(std::string studentName);

	HOPS* getStudentHops() const;
	bool setStudentHops(HOPS *studentHOPS);

	int calculateStudentTotalEcts() const;
	int getTotalEcts();


private:
	std::string studentId;
	std::string studentName;
	HOPS *studentHops;
	int studentTotalEcts;
};

