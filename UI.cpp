#include "stdafx.h"
#include "UI.h"


UI::UI() {
}


UI::~UI() {
}

bool UI::displayMenuIntro() {
	std::cout << "Welcome to HOPSMASTER2000!" << std::endl;
	return true;
}

bool UI::displayMenuMain() {
	std::cout << "Please type the number of the query and hit Enter." << std::endl;
	std::cout << "Which function would you like to perform?." << std::endl;
	std::cout << std::endl;
	std::cout << "1. Initialize student HOPS.\n\t- you will lose all data." << std::endl;
	std::cout << "2. Save HOPS to disk.\n\t- the file may then be retrieved at a later time." << std::endl;
	std::cout << "3. Load HOPS from disk.\n\t- read a previously saved HOPS" << std::endl;
	std::cout << "4. Add a course to the HOPS.\n\t- for adding new courses to the HOPS." << std::endl;
	std::cout << "5. Delete a course from the HOPS.\n\t- removes a course from the HOPS. Graded courses may not be removed." << std::endl;
	std::cout << "6. Grade a course.\n\t- assign a new grade or revise an already given one." << std::endl;
	std::cout << "7. Print a full transcript of the student.\n\t- for viewing detailed information about the student and their course progression." << std::endl;
	std::cout << "8. Exit\n\t- quit the program. Your HOPS will be saved automatically in its current form." << std::endl;
	return true;
}

bool UI::displayInstructions() {
	std::cout << "Please type the number of the query and hit Enter." << std::endl;
	return true;
}

bool UI::displayAddCourse()
{
	std::cout << "You are now adding a course to the HOPS." << std::endl;
	std::cout << "Please enter the following information:" << std::endl;
	std::cout << "Course ID: 6 characters (ex. TX0012)" << std::endl;
	std::cout << "Course name: 1 - 50 characters (ex. Object-Oriented Programming in C++)" << std::endl;
	std::cout << "Course ECTS: 0 - 60 (ex. 15)" << std::endl;
	std::cout << "Course grade: 0 - 5 (ex. 5)" << std::endl;
	std::cout << "Course Description: 1 - 500 characters (ex. This is a description of the course.)" << std::endl;
	return true;
}

bool UI::displayDeleteCourse()
{
	std::cout << "You are now deleting a course from the HOPS." << std::endl;
	std::cout << "Please enter the following information:" << std::endl;
	std::cout << "Course ID: 6 characters (ex. TX0012)" << std::endl;
	return true;
}

bool UI::displayGrade()
{
	std::cout << "You are now entering a grade for a course in the HOPS." << std::endl;
	std::cout << "Please enter the following information:" << std::endl;
	std::cout << "Course ID: 6 characters (ex. TX0012)" << std::endl;
	std::cout << "New grade: 0 - 5 (ex. 5)" << std::endl;
	return true;
}

bool UI::displayStudent(Student stu)
{
	std::cout << stu << std::endl;
	return true;
}

bool UI::displayInitializeOK()
{
	std::cout << "Student HOPS initialized. You have a clean slate to work with." << std::endl;
	std::cout << "\n\n========================\nPress Enter to continue.\n========================" << std::endl;	std::cin.get();
	return true;
}

bool UI::displaySaveOK()
{
	std::cout << "Student HOPS saved successfully!" << std::endl;
	std::cout << "\n\n========================\nPress Enter to continue.\n========================" << std::endl;	std::cin.get();
	return true;
}

bool UI::displayLoadOK()
{
	std::cout << "Student HOPS loaded successfully. You may view it in section 7." << std::endl;
	std::cout << "\n\n========================\nPress Enter to continue.\n========================" << std::endl;	std::cin.get();
	return true;
}

bool UI::displayAddCourseOK()
{
	std::cout << "Course successfully added to the HOPS." << std::endl;
	std::cout << "\n\n========================\nPress Enter to continue.\n========================" << std::endl;	std::cin.get();
	return true;
}

bool UI::displayDeleteCourseOK()
{
	std::cout << "Course successfully deleted from the HOPS." << std::endl;
	std::cout << "\n\n========================\nPress Enter to continue.\n========================" << std::endl;	std::cin.get();
	return true;
}

bool UI::displayEditGradeOK()
{
	std::cout << "Course graded successfully." << std::endl;
	std::cout << "\n\n========================\nPress Enter to continue.\n========================" << std::endl;	std::cin.get();
	return true;
}

bool UI::displayStudentOK()
{
	std::cout << "\n\n========================\nPress Enter to continue.\n========================" << std::endl;	std::cin.get();
	std::cin.get();
	return true;
}

bool UI::displayGoodbye() {
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\nThanks for using HOPSMASTER 2000! See you next time!" << std::endl;
	std::cout << "\n\n========================\nPress Enter to continue.\n========================" << std::endl;	std::cin.get();
	std::cin.get();
	return true;
}

int UI::getUserInputNumMain(int min, int max) {
	//std::cout << "\nInput: ";
	//std::string choice;
	//while (true) {
	//	std::getline(std::cin, choice);
	//	if () {

	//	}
	//	if (choice == "") {
	//		return -5;
	//	}
	//	if (!(std::stoi(choice) < min || std::stoi(choice) > max)) {
	//		break;
	//	}
	//	std::cout << "The input needs to be between " + std::to_string(min) + " and " + std::to_string(max) + "." << std::endl;
	//}
	//std::cout << std::endl;
	//return std::stoi(choice);


	//std::cout << "\nInput: ";
	//std::string choice;
	//if (choice == "") {
	//	std::cout << "\nInvalid input." << std::endl;
	//}
	return 0;
}

int UI::getUserInputNum(int min, int max) {
	std::cout << "\nInput: ";
	std::string choice;
	while (true) {
		std::getline(std::cin, choice);

		if (!(std::stoi(choice) < min || std::stoi(choice) > max)) {
			break;
		}
		std::cout << "The input needs to be between " + std::to_string(min) + " and " + std::to_string(max) + "." << std::endl;
	}
	std::cout << std::endl;
	return std::stoi(choice);
}

std::string UI::getUserInputAlpha(int min, int max) {
	std::cout << "\nInput: ";
	std::string input;
	while (true) {
		std::getline(std::cin, input);
		if (!(input.length() < min || input.length() > max)) {
			break;
		}
		if (min == max) {
			std::cout << "The input needs to be between " + std::to_string(min) + " characters long." << std::endl;
		}
		else {
			std::cout << "The input needs to be between " + std::to_string(min) + " and " + std::to_string(max) + " characters long." << std::endl;
		}
	}
	std::cout << std::endl;
	return input;
}

bool UI::divider() {
	std::cout << "\n\n========================\nPress Enter to continue.\n========================" << std::endl;	std::cin.get();
	return true;
}