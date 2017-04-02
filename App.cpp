#include "stdafx.h"
#include "App.h"
#define SAVE_POLKU "/savetettu.txt"


// 
App::App(bool running)
{
	this->appRunning = running;
}


App::~App()
{
}

bool App::run() {
	UI ui;
	SaveLoad sl;
	Student backup("000000", "backup_student", new HOPS("NONE"));
	Student st("123456", "Untamo Kuutamo", new HOPS("ICT"));

	ui.displayMenuIntro();

	while (appRunning) {

		ui.displayMenuMain();
		switch (mainSelector(ui)) {
		case 1:
			st.getStudentHops()->initialize();
			ui.displayInitializeOK();
			break;
		case 2:
			setWhereToSaveLoad();
			sl.saveGeneric(st, getWhereToSaveLoad().c_str());
			ui.displaySaveOK();
			break;
		case 3:
			setWhereToSaveLoad();
			sl.restoreGeneric(st, getWhereToSaveLoad().c_str());

			ui.displayLoadOK();
			break;
		case 4:
			addCo(st, ui);			
			break;
		case 5:
			delCo(st, ui);
			break;
		case 6:
			editCo(st, ui);			
			break;
		case 7:
			ui.displayStudent(st);
			ui.displayStudentOK();
			break;
		case 8:
			appRunning = false;
			break;

		default:
			continue;
		}
		system("cls");
	}
	ui.displayGoodbye();
	return false;
}

bool App::addCo(Student st, UI ui) {
	std::cout << "\n\nA star ( * ) indicates a required field." << std::endl;
	std::cout << "ID (Must be 6 characters) *: ";
	std::string id = "";
	std::getline(std::cin, id);
	if (id.length() != COURSE_ID_MAX) {
		std::cout << std::endl;
		std::cout << "Invalid input. ID must be exactly 6 characters in length.";
		ui.divider();
		return false;
	}
	std::cout << "Name (1 - 50 characters) *: ";
	std::string name = "";
	std::getline(std::cin, name);
	if (name.length() < COURSE_NAME_MIN || name.length() > COURSE_NAME_MAX) {
		std::cout << std::endl;
		std::cout << "Invalid input. ";
		ui.divider();
		return false;
	}
	std::cout << "ECTS (ranging from 0 to 60) *: ";
	std::string sects = "";
	std::getline(std::cin, sects);
	if (sects == "") {
		std::cout << std::endl;
		std::cout << "Invalid input. ";
		ui.divider();
		return true;
	}
	int ects = std::stoi(sects);
	if (ects < ECTS_MIN || ects > ECTS_MAX) {
		std::cout << std::endl;
		std::cout << "Invalid input. ";
		ui.divider();
		return false;
	}
	std::cout << "Grade (ranging from 0 to 5. May also be left empty for \"Not Attended\"): ";
	std::string sgrade = "";
	std::getline(std::cin, sgrade);
	if (sgrade == "") {
		st.getStudentHops()->addCourse(id, name, ects);
		std::cout << std::endl;
		ui.displayAddCourseOK();
		return true;
	}
	int grade = std::stoi(sgrade);
	if (grade < GRADE_MIN || grade > GRADE_MAX) {
		std::cout << std::endl;
		std::cout << "Invalid input. ";
		ui.divider();
		return false;
	}
	std::cout << "Description (0 - 500 characters): ";
	std::string desc = "";
	std::getline(std::cin, desc);
	if (desc == "") {
		st.getStudentHops()->addCourse(id, name, ects, grade);
		ui.displayAddCourseOK();
		return true;
	}
	if (desc.length() < DESCRIPTION_MIN || desc.length() > DESCRIPTION_MAX) {
		std::cout << std::endl;
		std::cout << "Invalid input. ";
		ui.divider();
		return false;
	}
	st.getStudentHops()->addCourse(id, name, ects, grade, desc);
	std::cout << std::endl;
	ui.displayAddCourseOK();

	return true;
}

bool App::delCo(Student st, UI ui) {
	std::cout << "\n\nEnter the ID of the course you wish to delete." << std::endl;
	std::cout << "Leaving the field empty will cancel the action." << std::endl;
	std::cout << "ID (Must be 6 characters) *: ";
	std::string id = "";
	std::getline(std::cin, id);
	if (id.length() != COURSE_ID_MAX) {
		std::cout << std::endl;
		std::cout << "\nInvalid input. ID must be exactly 6 characters in length.";
		ui.divider();
		return false;
	}
	bool courseTaken = st.getStudentHops()->deleteCourse(id);
	if (courseTaken) {
		std::cout << std::endl;

		ui.displayDeleteCourseOK();
		return true;
	}
	else {
		std::cout << "\nYou cannot delete a course which has been graded." << std::endl;
		ui.divider();
		return false;
	}
}

bool App::editCo(Student st, UI ui) {
	std::cout << "\n\nEnter the ID of the course you wish to grade." << std::endl;
	std::cout << "Leaving the field empty will cancel the action." << std::endl;
	std::cout << "ID (Must be 6 characters) *: ";
	std::string id = "";
	std::getline(std::cin, id);
	if (id.length() != COURSE_ID_MAX) {
		std::cout << std::endl;
		std::cout << "\nInvalid input. ID must be exactly 6 characters in length.";
		ui.divider();
		return false;
	}
	std::cout << "Grade (ranging from 0 to 5. If left empty, old grade will stay in place.): ";
	std::string sgrade = "";
	std::getline(std::cin, sgrade);
	if (sgrade == "") {
		std::cout << std::endl;
		std::cout << "No new grade assigned.";
		ui.divider();
		return true;
	}
	int grade = std::stoi(sgrade);
	if (grade < GRADE_MIN || grade > GRADE_MAX) {
		std::cout << std::endl;
		std::cout << "Invalid input. ";
		ui.divider();
		return false;
	}
	std::cout << std::endl;
	st.getStudentHops()->editEditGrade(id, grade);
	ui.displayEditGradeOK();
	return true;
}

int App::mainSelector(UI ui) {
	std::cout << "\nInput: ";
	std::string choice;
	std::getline(std::cin, choice);
	if (choice == "") {
		std::cout << "\nPlease select one of the options to continue." << std::endl;
		ui.divider();
		return 0;
	}
	if (atoi(choice.c_str() - CHAR_TO_I_SUB) < SELECTION_MAINMENU_MIN || atoi(choice.c_str() - CHAR_TO_I_SUB) > SELECTION_MAINMENU_MAX) {
		return atoi(choice.c_str());
	}
	else {
		std::cout << "\nPlease select one of the options to continue." << std::endl;
		ui.divider();
		return 0;
	}
}

bool App::setWhereToSaveLoad() {
	std::cout << "\n\nGive a filename for the save (no extensions): ";
	std::string loc;
	std::getline(std::cin, loc);
	loc = loc + ".txt";
	this->whereToSaveLoad = loc;
	return true;
}

bool App::setWhereToLoad() {
	std::cout << "\n\nGive a filename for the save (no extensions): ";
	std::string loc;
	std::getline(std::cin, loc);
	loc = "/" +  loc + ".txt";
	this->whereToSaveLoad = loc;
	return true;
}

std::string App::getWhereToSaveLoad() {
	return this->whereToSaveLoad;
}