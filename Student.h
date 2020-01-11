#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <fstream>

class Student{ // class Student that holds information about each student

private:
	// private data mambers that each Student holds
	std::string name;
	std::string birth;
	std::string major;

public:
	// all function prototypes to be used in Student.cpp
	Student addStudent();
	void addStudent(std::string, std::string, std::string);
	void setName(std::string);
	void setBirth(std::string);
	void setMajor(std::string);
	void displayMajors();
	std::string getName();
	std::string getBirth();
	std::string getMajor();
	void printStudent();

};

#endif
