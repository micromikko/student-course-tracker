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
#include "SaveLoad.h"


#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


#include <boost/archive/tmpdir.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>



class UI {
public:
	UI();
	virtual ~UI();

	
	bool displayMenuIntro();
	bool displayMenuMain();

	bool displayInstructions();
	bool displayAddCourse();
	bool displayDeleteCourse();
	bool displayGrade();
	bool displayStudent(Student stu);

	bool displayInitializeOK();
	bool displaySaveOK();
	bool displayLoadOK();
	bool displayAddCourseOK();
	bool displayDeleteCourseOK();
	bool displayEditGradeOK();
	bool displayStudentOK();
	bool displayGoodbye();

	int getUserInputNumMain(int min, int max);
	int getUserInputNum(int min, int max);
	std::string getUserInputAlpha(int min, int max);
	bool divider();


private:
	//jaska
};

