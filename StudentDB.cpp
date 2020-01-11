#include<iostream>
#include "StudentDB.h"
#include "Student.h"
#include "Course.h"

StudentDB::StudentDB() // default constructor
{
	head = NULL; // sets head of linked list to NULL
}

void StudentDB::deleteCourseNode(std::string course, std::string targetName){ // function deleting course node takes in a course name and a student name
	if (findStudent(targetName) == NULL){ // if student is not in the list, return 
		return;
	}
	Node* found = findStudent(targetName); // if student is in the list, set equal to Node* found
	CourseNode* previous = found -> header;
	CourseNode* curr = found -> header;
	if (found -> header -> c.getNameOfCourse() == (course)){ // if name of head of course list is equal to the target course
		CourseNode* temp = found -> header;
		CourseNode* prev = found -> header;
		temp = temp -> next; // move along list
		delete prev; // delete previous
		found -> header = temp;
		std::cout << "------------------------------\n";
		std::cout << "Course removed successfully!" << std::endl;
		return;
	}
	while(curr){ // if not the header, traverse list 
		if ((curr -> c.getNameOfCourse()) == (course)){ // if the name of the current node is equal to the target course
			previous -> next = curr -> next; // assign previous to currents next
			delete curr; // delete current
			std::cout << "------------------------------\n";
			std::cout << "Course removed successfully!" << std::endl;
			return;
		}
		previous = curr; // traverses through list
		curr = curr -> next;
	}
	std::cout << "------------------------------\n";
	std::cout << "ERROR: Could not remove course. Input was invalid" << std::endl;
}

void StudentDB::addRecord(Student newStudent) // Adds a student record to the linked list
{
	Node* temp = new Node; 
	temp -> s = newStudent; // assign new node student to the passed in student object
	temp -> next = NULL;
	temp -> header = NULL;
	Node* curr = head;
	if (head == NULL) // if head of linked list is NULL
	{
		head = temp; // assign head to the new node
	}
	else
	{
		while (curr -> next != NULL){ // if the current nodes next is not empty
			curr = curr -> next; // traverse list
		}
		curr -> next = temp; // assign current nodes next to new node
	}
}

void StudentDB::addCourseRecord(Course newCourse, std::string targetName){
	if (findStudent(targetName) == NULL){ // if student is not in the list, return 
		return;
	}
	Node* found = findStudent(targetName); // if student is in list, set equal to Node* found
	CourseNode* temp = new CourseNode;
	temp -> c = newCourse;
	temp -> next = NULL;
	if (found -> header == NULL){ // if the header of the linked list going down is NULL
		found -> header= temp; // set header to new CourseNode
	}
	else {
		CourseNode* nodeptr = found -> header;
		while (nodeptr -> next != NULL){ // if current CourseNode's next is not empty
			nodeptr = nodeptr -> next; // traverse course list
		}
		nodeptr -> next = temp; // set currents next to new CourseNode
	}
}

int StudentDB::getCount() // function to return the amount of Student Nodes in list
{
	Node* curr = head;
	int counter = 0;
	while (curr)
	{
		counter++; // counter for how many nodes are counted while traversing list
		curr = curr -> next;
	}
	return counter; // returns number of nodes
}

int StudentDB::getCourseCount(std::string targetName)
{
	if (findStudent(targetName) == NULL){ // if student is not in the list, return 
		return -1;
	}
	Node* found = findStudent(targetName); 
	CourseNode* temp = found -> header;
	int counter = 0;
	while (temp)
	{
		counter++;
		temp = temp -> next;
	}
	return counter;
}

void StudentDB::removeRecord(std::string targetName) // function that removes Student Record and all their classes, passes in target name of student being deleted
{
	if (findStudent(targetName) == NULL){ // if student is not in list, return 
		return;
	}
	Node* found = findStudent(targetName); // if student is in list, set equal to Node* found
	Node* curr = head;
	Node* previous = head;
	if (head -> next == NULL){ // if head's next is NULL, remove head
		CourseNode* curr1 = found -> header;
		CourseNode* prev = found -> header;
		while (curr1){
			prev = curr1;
			curr1 = curr1 -> next;
			delete prev; // deletes CourseNodes
		}
		delete head; // deletes Node
		std::cout << "------------------------------\n";
		std::cout << "Student Removed from Database!" << std::endl;
		head = NULL;
		return;
	}
	if (head -> s.getName() == (targetName)){ // if heads name matches target name, remove head
		Node* temp = head;
		CourseNode* current = found -> header;
		CourseNode* previous1 = found -> header;
		while (current){
			previous1 = current;
			current = current -> next;
			delete previous1; // deletes CourseNodes
		}
		temp = temp -> next;
		delete head; // deletes Node
		head = temp;
		std::cout << "------------------------------\n";
		std::cout << "Student Removed from Database!" << std::endl;
		return;
	}
	while(curr){ // if not head, traverse through list and find node with matching student name as the one passed in by function
		if((curr -> s.getName()) == (targetName)){
			previous -> next = curr -> next;
			CourseNode* temp3 = found -> header;
			CourseNode* temp4 = found -> header;
			while (temp3){
				temp4 = temp3;
				temp3 = temp3 -> next;
				delete temp4; // deletes CourseNodes
			}
			delete curr; // deletes Node
			std::cout << "------------------------------\n";
			std::cout << "Student Removed from Database!" << std::endl;
			break;
		}
		previous = curr;
		curr = curr -> next;
	}
}

void StudentDB::editRecord(std::string targetName) // function that allows user to edit information of a student
{
	if (findStudent(targetName) == NULL){ // if student is not in the list, return
		return;
	}
	Node* curr = head;
	while (curr){ // while curr != NULL 
		if (curr -> s.getName() == targetName){ // if the current nodes name is equal to that of whats being passed in 
			int input;
			int input1;
			int input2;
			bool check = false;
			bool check2 = false;
			bool check3 = false;
			std::string newName;
			std::string newBirth;
			std::string newMajor;
			while(!check){                          // ask if they would like to change name
				std::cout << "If you would like to change the name press [1] if you would like to change something else insert a # besides 1: ";
				std::cin >> input;
				if (input == 1){
					std::cout << "Enter the name you would like to update this student to (First_Last): ";
					check = true;
					std::cin >> newName;
					curr -> s.setName(newName);
				}
				if (input != 1){                                         
					break;
				}
				if (!check){
					std::cout << "Not a valid entry. Try again" << std::endl;
				}
			}
			while (!check2){                          // ask if they would like to change birthday
				std::cout << "If you would like to change the birthday press [1] if you would like to change something else insert a # besides 1: ";
				std::cin >> input1;
				if (input1 == 1){
					std::cout << "Enter the birthday you would like to update this student to (dd/mm/yyyy) for example (06/13/2000): ";
					check2 = true;
					std::cin >> newBirth;
					curr -> s.setBirth(newBirth);
				}
				if (input1 != 1){
					break;
				}
				if (!check2){
					std::cout << "Not a valid entry. Try again" << std::endl;
				}
			}
			while (!check3){                            // ask if they would like to change major
				std::cout << "If you would like to change the major press [1] if you would like to change something else insert a # besides 1: ";
				std::cin >> input2;
				if (input2 == 1){
					std::cout << "Enter the major you would like to update this student to: ";
					check3 = true;
					std::cin >> newMajor;
					curr -> s.setMajor(newMajor);
				}
				if(input2 != 1){
					break;
				}
				if (!check3){
					std::cout << "Not a valid entry. Try again" << std::endl;
				}
			}
		}
		curr = curr -> next; // traverse through list if current nodes name is not equal to that of whats being passed in
	}
}

void StudentDB::printRecords() // function to print the Student information and their courses
{
	if (head == NULL) // if head == NULL, list is empty
	{
		std::cout << "        List is Empty" << std::endl;
		return;
	}
	Node* curr = head;
	while (curr) // while curr != 
	{
		CourseNode* temp1 = curr -> header;
		curr -> s.printStudent(); // prints student info
		std::cout << "------------------------------" << std::endl;
		if (temp1 == NULL){ //  if header of course list == NULL, student has no courses
			std::cout << "No Courses" << std::endl;
			curr = curr -> next;
			continue;
		}
		while (temp1){ // while head != NULL, traverse list of courses student has and print
			temp1 -> c.printCourses();
			std::cout << "------------------------------" << std::endl;
			temp1 = temp1 -> next;
		}
		curr = curr -> next; // moves along student list and continues to reprint courses for each student
	}
}
