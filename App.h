#pragma once
#include "stdafx.h"
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#define SELECTION_MIN 1
#define SELECTION_MAINMENU_MIN 1
#define SELECTION_MAINMENU_MAX 8
#define GRADE_MIN 0
#define GRADE_MAX 5
#define COURSE_ID_MIN 6
#define COURSE_ID_MAX 6
#define COURSE_NAME_MIN 1
#define COURSE_NAME_MAX 50
#define ECTS_MIN 0
#define ECTS_MAX 60
#define DESCRIPTION_MIN 1
#define DESCRIPTION_MAX 500
#define HOPS_DEGREE_MIN 0
#define HOPS_DEGREE_MAX 50
#define STUDENT_ID_MIN 6
#define STUDENT_ID_MAX 6
#define STUDENT_NAME_MIN 0
#define STUDENT_NAME_MAX 50
#define CHAR_TO_I_SUB 48
//
#include <stdlib.h>

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
#include "UI.h"


#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/vector.hpp>

//#include <boost/serialization/split_member.hpp>
//#include <boost/serialization/base_object.hpp>
//#include <boost/archive/tmpdir.hpp>
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/serialization/base_object.hpp>
//#include <boost/serialization/assume_abstract.hpp>

class App {
public:
	App(bool running=true);
	virtual ~App();

	bool run();


	bool addCo(Student st, UI ui);
	bool delCo(Student st, UI ui);
	bool editCo(Student st, UI ui);
	int mainSelector(UI ui);

	bool setWhereToSaveLoad();
	std::string getWhereToSaveLoad();
	bool setWhereToLoad();

private:
	bool appRunning;
	std::string whereToSaveLoad;
};

