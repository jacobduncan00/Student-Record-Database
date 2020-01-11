#include <iostream>
#include "Course.h"
#include "Student.h"
#include "StudentDB.h"

// Project Created by Jacob Duncan @ Salisbury University
// Class: COSC 220
// Professor: Joseph Anderson
// Date Completed: Oct 13, 2019

/*
* This is a student database software that allows the user to
* enter Student Records, Student Courses, manage Records, delete
* records and courses, and print the roster of the students.
* This is a complex program that is to be ran with extreme care
* and attention to details. Please do not deviate too much from
* the instructions within the terminal. Enjoy!
*/


/*

* Fixed memory leaks and the weird functionality of the delete course function
* Leaked in Student and Course creation fixed
* 10/21/2019

*/


void Welcome() // function that prompts a screen of options for user to choose from
{
	std::cout << "-------------------------------\n";
	std::cout << "       Student Database       \n";
	std::cout << "                              \n";
	std::cout << "   What operation would you   \n";
	std::cout << "      like to perform?        \n";
	std::cout << "                              \n";
	std::cout << "                              \n";
	std::cout << "  1) Add a Student Record    \n";
	std::cout << "  2) Edit a Student Record   \n";
	std::cout << "  3) Remove a Student Record \n";
	std::cout << "  4) Print Roster             \n";
	std::cout << "  5) Add Course to Student    \n";
	std::cout << "  6) Remove Course from Student \n";
	std::cout << "  7) Exit Application        \n";
	std::cout << "-------------------------------\n";
}

int main(){
	StudentDB linkedlist; // Linked list of Students and Courses combined
	int option;
	Welcome();
	while(true){
		std::cout << "Please Input a Valid Choice: ";
		std::cin >> option;
		if (!std::cin){ // input validation for integer
			std::cin.clear();
			std::cin.ignore();
			std::cout << "ERROR: a number must be input" << std::endl;
		}
		if (option < 1 || option > 7){ // input validation for correct choice
			std::cout << "Invalid choice." << std::endl;
			Welcome();
			continue;
		}
		if (option == 1){ //  if option is 1, add a student node
			char choice;
			bool flag;
			Student newStudent = newStudent.addStudent();
			linkedlist.addRecord(newStudent);
			Welcome();
			continue;
		}
		if (option == 2){ // if option is 2, allow user to edit student node
			std::string targetName;
			linkedlist.printRecords();
			if (linkedlist.getCount() != 0){
			std::cout << "Enter the Name (First_Last) of the Student you would like to edit: ";
			std::cin >> targetName;
			linkedlist.editRecord(targetName);
			}
			Welcome();
			continue;
		}
		if (option == 3){  //  if option is 3, allow user to remove student node
			std::string targetName;
			linkedlist.printRecords();
			if (linkedlist.getCount() != 0){
				std::cout << "------------------------------\n";
				std::cout << "Enter the Name (First_Last) of the Student you would like to remove: ";
				std::cin >> targetName;
				linkedlist.removeRecord(targetName);
			}
			Welcome();
			continue;
		}
		if (option == 4){ //  if option is 4, print out all students and their courses
			std::cout << "------------------------------\n";
			std::cout << "        Student Roster        \n";
			std::cout << "Number of Students in List: " << linkedlist.getCount() << std::endl;
			linkedlist.printRecords();
			std::cout << "------------------------------\n";
			Welcome();
			continue;
		}
		if (option == 5){ //  if option is 5, allow user to add course to student
			std::string targetName;
			char choice;
			bool flag;
			linkedlist.printRecords();
			if (linkedlist.getCount() != 0){
				std::cout << "------------------------------\n";
				std::cout << "Enter the Name (First_Last) of the Student you would like to add a course to: ";
				std::cin >> targetName;
				Course newCourse = newCourse.addCourseRecord(); // if the name is not in the list, you will still be prompted to enter the students information however, will get the message that student is not in course, after completeting the information
				linkedlist.addCourseRecord(newCourse, targetName); // assigns newCourse to the targeted student
				do{
					std::cout << "Would you like to insert another course [y/n]: ";
					std::cin >> choice;
					if (choice == 'Y' || choice == 'y'){ // if user wants to input another student
						linkedlist.printRecords();
						std::cout << "------------------------------\n";
						std::cout << "Enter the Name (First_Last) of the Student you would like to add a course to: ";
						std::cin >> targetName;
						newCourse = newCourse.addCourseRecord();
						linkedlist.addCourseRecord(newCourse, targetName);
					}
					else if (choice == 'N' || choice == 'n'){
						flag = true;
						std::cout << "Returning to Menu" << std::endl;
					}
					else {
						std::cout << "Invalid choice." << std::endl;
					}
				}while(!flag);
			}
			Welcome();
			continue;
		}
		if (option == 6){ // if option is 6, allow user to remove a specific course from a specific student
			std::string targetName;
			std::string course;
			linkedlist.printRecords();
			if(linkedlist.getCount() != 0){
				std::cout << "------------------------------\n";
				std::cout << "Enter the Name (First_Last) of the Student you would like to remove a course from: ";
				std::cin >> targetName;
				if (linkedlist.getCourseCount(targetName) == -1){
					std::cout << "No Student with that name in Database" << std::endl;
				}
				else if (linkedlist.getCourseCount(targetName) == 0){
					std::cout << "Student has no courses. Cannot delete anything, returning to Menu" << std::endl;
				}
				else{
					std::cout << "Enter the Name of the course (same as how you entered it) you would like to remove: ";
					std::cin >> course;
					linkedlist.deleteCourseNode(course, targetName);
				}
			}
			Welcome();
			continue;
		}
		if (option == 7){ // if option is 7, terminate program
			std::cout << "------------------------------\n";
			std::cout << "Thank you for using Jacob's ";
			std::cout << "Student Database Software!" << std::endl;
			std::cout << "------------------------------\n";
			exit(0);
		}
	}
	return 0;
}
