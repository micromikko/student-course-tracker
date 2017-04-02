#include "stdafx.h"
#include "HOPS.h"


HOPS::HOPS(std::string degreeName) {
	//(degreeName.length() <= 50) ? this->degreeName = degreeName : this->degreeName = "";
	this->degreeName = degreeName;
	this->initialize();
}

HOPS::HOPS(const HOPS &HOPStoCopy) {
	degreeName = HOPStoCopy.degreeName;
	courseList = HOPStoCopy.courseList;
	requiredEcts = HOPStoCopy.requiredEcts;
	currentEcts = HOPStoCopy.currentEcts;
}

HOPS::~HOPS() {}

//std::istream HOPS::&operator >> (std::istream &in, HOPS &c) {return in}

std::ostream &operator<<(std::ostream &out, const HOPS &h) {
	for (auto &i : h.getCourseList()) {
		out << *i << "\n" << std::endl;
	}
	return out;
}

bool HOPS::initialize() {
	for (auto &i : this->courseList) {
		delete i;
	}
	this->courseList.clear();
	return true;
}


bool HOPS::addCourse(Course* newCourse) {
	Course *p;
	p = newCourse;
	this->courseList.push_back(p);
	return true;
}

bool HOPS::addCourse(std::string courseId, std::string courseName, int courseEcts, int courseGrade, std::string courseDescription) {
	for (auto &i : this->courseList) {
		if (i->getCourseId() == courseId) {
			return false;
		}
	}
	this->courseList.push_back(new Course(courseId, courseName, courseEcts, courseGrade,  courseDescription));
	return true;
}

bool HOPS::deleteCourse(std::string courseId) {
	for (auto &i : this->courseList) {
		if (!(i->getCourseGrade() >= GRADE_MIN_GIVABLE)) {
			if (i->getCourseId() == courseId) {
				delete i;
				this->courseList.erase(std::remove(this->courseList.begin(), this->courseList.end(), i), this->courseList.end());
				return true;
			}
		}
	}
	return false;
}

std::vector<Course*> HOPS::getCourseList() const {
	return this->courseList;
}

bool HOPS::editEditGrade(std::string courseId, int grade) {
	for (auto &i : this->courseList) {
		if (i->getCourseId() == courseId) {
			i->setCourseGrade(grade);
			return true;
		}
	}
	return false;
}


std::string HOPS::getDegreeName() {
	return this->degreeName;
}

bool HOPS::setDegreeName(std::string degreeName) {
	if (degreeName.length() <= DEGREE_LENGTH) {
		this->degreeName = degreeName;
		return true;
	}
	return false;
}

int HOPS::getRequiredEcts() {
	return this->requiredEcts;
}

bool HOPS::setRequiredEcts(int requiredEcts) {
	this->requiredEcts = requiredEcts;
	return true;
}

int HOPS::getCurrentEcts() {
	int tempEcts = 0;
	for (auto &i : this->courseList) {
		tempEcts += i->getCourseEcts();
	}
	return tempEcts;
}

//bool HOPS::sortHopsList() {
//
//}