#pragma once
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include  "Course.h"
#include "HOPS.h"
#include "Student.h"


#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/vector.hpp>

//#include <boost/serialization/split_member.hpp>
//#include <boost/serialization/base_object.hpp>
//#include <boost/archive/tmpdir.hpp>
//#include <boost/serialization/assume_abstract.hpp>


class SaveLoad
{
public:
	SaveLoad();
	virtual ~SaveLoad();

	void saveGeneric(const Course &s, const char * filename);
	void restoreGeneric(Course &s, const char * filename);

	void saveGeneric(const HOPS &s, const char * filename);
	void restoreGeneric(HOPS &s, const char * filename);

	void saveGeneric(const Student &s, const char * filename);
	void restoreGeneric(Student &s, const char * filename);
};

