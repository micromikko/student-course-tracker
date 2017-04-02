#include "stdafx.h"
#include "Student.h"


Student::Student(std::string studentId, std::string studentName, HOPS *newhops) {
	this->studentId = studentId;
	this->studentName = studentName;
	this->studentHops = newhops;
}

Student::~Student() {}

std::ostream &operator<<(std::ostream &out, const Student &s) {
	int jaska = 0;
	out << "Student ID: " << s.studentId << std::endl;
	out << "Student name: " << s.studentName << std::endl;
	out << "Student ECTS: " << s.calculateStudentTotalEcts() << std::endl;
	out << "=====| Student courses |=====" << std::endl;
	out << *s.getStudentHops();
	return out;
}

std::string Student::getStudentId() {
	return this->studentId;
}

bool Student::setStudentId(std::string studentId) {
	if (studentId.length() <= STUDENT_ID_MAX) {
		this->studentId = studentId;
		return true;
	}
	return false;
}
std::string Student::getStudentName() {
	return this->studentName;
}

bool Student::setStudentName(std::string studentName) {
	if (studentName.length() <= STUDENT_NAME_MAX) {
		this->studentName = studentName;
		return true;
	}
	return false;
}
HOPS* Student::getStudentHops() const{
	return studentHops;
}

bool Student::setStudentHops(HOPS *studentHOPS) {
	this->studentHops = studentHOPS;
	return true;
}

//TODO: ATM does same as HOPS::getCurrentEcts(), but modify in the future if more hops added to student.
int Student::calculateStudentTotalEcts() const{
	return this->studentHops->getCurrentEcts();
}

int Student::getTotalEcts() {
	return this->studentTotalEcts;
}
