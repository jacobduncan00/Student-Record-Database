#ifndef STUDENTDB_H
#define STUDENTDB_H
#include "Student.h"
#include "Course.h"
#include <string>

class StudentDB{ // class StudentDB which holds two linked list, one horizontal and multiple vertical
private:
	struct CourseNode // linked list coming from each Student that holds courses they took
	{
		Course c;
		CourseNode* next;
	};
	struct Node{ // linked list of Students which holds the header of the linked list of courses 
		Student s;
		Node* next;
		CourseNode *header;
	};
	Node* head;

	StudentDB::Node* findStudent(std::string targetName){ // name-based search allowing certain nodes to be edited or altered
		if (head == NULL){
			std::cout << "No Students in List" << std::endl;
			return NULL;
		}
		if (head -> s.getName() == (targetName)){
			return head;
		}
		Node* current = head;
		while (current){
			if (current -> s.getName() == (targetName)){
				return current;
			}
		current = current -> next;
		}
		std::cout << "Student Not Found" << std::endl;
		return NULL;
	}

public: 
	// prototypes of functions to be used in StudentDB.cpp
	StudentDB();
	void deleteCourseNode(std::string, std::string);
	void addRecord(Student);
	void addCourseRecord(Course, std::string);
	int getCount();
	int getCourseCount(std::string);
	void removeRecord(std::string);
	void editRecord(std::string);
	void printRecords();
};

#endif
