#include "stdafx.h"
#include "Course.h"


Course::Course(std::string courseId, std::string courseName, int courseEcts, int courseGrade, std::string courseDescription) {
	this->courseId = courseId;
	this->courseName = courseName;
	this->courseEcts = courseEcts;
	this->courseGrade = courseGrade;
	this->courseDescription = courseDescription;
}

Course::Course(const Course &c) {
	courseId = c.courseId;
	courseName = c.courseName;
	courseEcts = c.courseEcts;
	courseGrade = c.courseGrade;
	courseDescription = c.courseDescription;
}

Course::~Course() {
}

//std::istream Course::&operator >> (std::istream &in, Course &c) {return in}

std::ostream &operator<<(std::ostream &out, const Course &c) {
	out << "Course ID:\t\t" << c.courseId << std::endl;
	out	<< "Course name:\t\t" << c.courseName << std::endl;
	out << "Course ECTS:\t\t" << c.courseEcts << std::endl;
	if (!(c.courseGrade < GRADE_MIN)) {
		out << "Course grade:\t\t" << c.courseGrade << std::endl;
	} else {
		out << "Course grade:\t\tNot yet taken." << std::endl;
	}
	if (!(c.courseDescription.length() < 1)) {
		out << "Course Description:\t" << c.courseDescription;
	}
	return out;
}

std::string Course::getCourseId() {
	return this->courseId;
}

bool Course::setCourseId(std::string courseId) {
	if (courseId.length() <= COURSE_MAX_THEO) {
		this->courseId = courseId;
		return true;
	}
	return false;
}

std::string Course::getCourseName() {
	return this->courseName;
}

bool Course::setCourseName(std::string courseName) {
	if (courseName.length() <= 50) {
		this->courseName = courseName;
		return true;
	}
	return false;
}

int Course::getCourseEcts() {
	return this->courseEcts;
}

bool Course::setCourseEcts(int courseEcts) {
	if (courseEcts >= ECTS_MIN) {
		this->courseEcts = courseEcts;
		return true;
	}
	return false;
}


int Course::getCourseGrade() {
	return this->courseGrade;
}

bool Course::setCourseGrade(int courseGrade) {
	if (courseGrade >= GRADE_EMPTY && courseGrade <= GRADE_MAX) {
		this->courseGrade = courseGrade;
		return true;
	}
	return false;
}

std::string Course::getCourseDescrpition() {
	return this->courseDescription;
}

bool Course::setCourseDescrpition(std::string courseDescription) {
	if (courseDescription.length() <= DESCRIPTION_MAX) {
		this->courseDescription = courseDescription;
		return true;
	}
	return false;
}


