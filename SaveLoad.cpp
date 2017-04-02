#include "stdafx.h"
#include "SaveLoad.h"


SaveLoad::SaveLoad()
{
}


SaveLoad::~SaveLoad()
{
}


void SaveLoad::saveGeneric(const Course &s, const char * filename) {
	// make an archive
	std::ofstream ofs(filename);
	boost::archive::text_oarchive oa(ofs);
	oa << s;
}

void SaveLoad::restoreGeneric(Course &s, const char * filename)
{
	// open the archive
	std::ifstream ifs(filename);
	boost::archive::text_iarchive ia(ifs);
	// restore the schedule from the archive
	ia >> s;
}

void SaveLoad::saveGeneric(const HOPS &s, const char * filename) {
	// make an archive
	std::ofstream ofs(filename);
	boost::archive::text_oarchive oa(ofs);
	oa << s;
}

void SaveLoad::restoreGeneric(HOPS &s, const char * filename)
{
	// open the archive
	std::ifstream ifs(filename);
	boost::archive::text_iarchive ia(ifs);

	// restore the schedule from the archive
	ia >> s;
}

void SaveLoad::saveGeneric(const Student &s, const char * filename) {
	// make an archive
	std::ofstream ofs(filename);
	boost::archive::text_oarchive oa(ofs);
	oa << s;
}

void SaveLoad::restoreGeneric(Student &s, const char * filename)
{
	// open the archive
	std::ifstream ifs(filename);
	boost::archive::text_iarchive ia(ifs);

	// restore the schedule from the archive
	ia >> s;
}
