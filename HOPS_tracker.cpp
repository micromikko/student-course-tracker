// HOPS_tracker.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
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
#include "App.h"

//
//
//#include <boost/serialization/list.hpp>
//#include <boost/serialization/string.hpp>
//#include <boost/serialization/version.hpp>
//#include <boost/serialization/split_member.hpp>
//#include <boost/serialization/base_object.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/tmpdir.hpp>
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/serialization/base_object.hpp>
//#include <boost/serialization/utility.hpp>
//#include <boost/serialization/list.hpp>
//#include <boost/serialization/assume_abstract.hpp>
//#include <boost/serialization/vector.hpp>



//TODO: ADD ALL THE CONSTS!
//TODO: Getters don't change the state. So make them const.
int main() {
	App app(true);
	app.run();
    return 0;
}
