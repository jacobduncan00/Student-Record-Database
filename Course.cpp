#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Course.h" // includes header file for Course

void Course::displayCourses(){ // function to open a text file and display courses to choose from
  std::string temp;
  std::ifstream disp;
  disp.open("courseList.txt");
  if(!disp){ // check to make sure the file is open
    std::cout << "Error. Unable to open file." << std::endl;
    exit(1);
  }
  std::cout << "------------------------------\n";
  std::cout << "List of Courses:\n";
  while (disp >> temp){
    std::cout << temp << std::endl;
  }
  disp.close();
}

void Course::displayDepartments(){ // function to open a text file and display departments to choose from
  std::string temp;
  std::ifstream disp;
  disp.open("departmentsList.txt");
  if(!disp){ // check to make sure the file is open
    std::cout << "Error. Unable to open file." << std::endl;
    exit(1);
  }
  std::cout << "------------------------------\n";
  std::cout << "List of Departments:\n";
  while (disp >> temp){
    std::cout << temp << std::endl;
  }
  disp.close();
}

void Course::displaySemesters(){ // function to open a text file and display semesters to choose from
  std::string temp;
  std::ifstream disp;
  disp.open("semesterList.txt");
  if(!disp){ // check to make sure the file is open
    std::cout << "Error. Unable to open file." << std::endl;
    exit(1);
  }
  std::cout << "------------------------------\n";
  std::cout << "List of Semesters:\n";
  while (disp >> temp){
    std::cout << temp << std::endl;
  }
  disp.close();
}

Course Course::addCourseRecord(){ // function that will allow the user to input information about the course they are adding
  std::ifstream fin;
  fin.open("courseList.txt");
  std::ifstream f1in;
  f1in.open("departmentsList.txt");
  std::ifstream f2in;                          // opening all files
  f2in.open("semesterList.txt");
  std::ifstream f3in;
  f3in.open("gradeList.txt");
  bool check = false;
  bool check1 = false;
  bool check2 = false;
  bool check3 = false;
  bool check4 = false;
  Course *newCourse = new Course;
  std::string course, department, semester;
  char grade;
  char choice;
  std::string courseArray[35];
  for (int i = 0; i < 35; i++){
    fin >> courseArray[i];
  }
  std::string departmentArray[20];
  for (int i = 0; i < 20; i++){
    f1in >> departmentArray[i];
  }                                         // populating arrays with information from file
  std::string semesterArray[20];
  for (int i = 0; i < 20; i++){
    f2in >> semesterArray[i];
  }
  char gradeArray[10];
  for (int i = 0; i < 10; i++){
    f3in >> gradeArray[i];
  }
  while (!check){
    displayCourses(); // prints courses
    std::cout << "----------------" << std::endl;
    std::cout << "Enter the name of the course: ";
    std::cin >> course;
    for (int i = 0; i < 35; i++){
      if (course == courseArray[i]){ // checks to make sure course is in the array or "file"
        check = true;
      }
    }
    if (!check){
      std::cout << "Invalid Course. Press enter to try again" << std::endl;
    }
  }

  while (!check1){
    displayDepartments(); // prints departments
    std::cout << "----------------" << std::endl;
    std::cout << "Enter the name of the department: ";
    std::cin >> department;
    for (int i = 0; i < 20; i++){
      if (department == departmentArray[i]){ // checks to make sure department is in the array or "file"
        check1 = true;
      }
    }
    if (!check1){
      std::cout << "Invalid Department. Press enter to try again" << std::endl;
    }
  }

  while (!check2){
    displaySemesters(); // prints semesters
    std::cout << "----------------" << std::endl;
    std::cout << "Enter the semester the course was taken: ";
    std::cin >> semester;
    std::cout << "----------------" << std::endl;
    for (int i = 0; i < 20; i++){
      if (semester == semesterArray[i]){ // checks to make sure semester is in the array or "file"
        check2 = true;
      }
    }
    if (!check2){
      std::cout << "Invalid Semester. Press enter to try again" << std::endl;
    }
  }

  while (!check3){
    std::cout << "A" << std::endl;
    std::cout << "B" << std::endl;
    std::cout << "C" << std::endl;
    std::cout << "D" << std::endl;
    std::cout << "F" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "Enter the grade recieved in the course: ";
    std::cin >> grade;
    for (int i = 0; i < 10; i++){ // checks to make sure grade is in array or "file"
      if (((grade == 'A' || grade == 'a') && grade == gradeArray[i]) || ((grade == 'B' || grade == 'b') && grade == gradeArray[i]) || ((grade == 'C' || grade == 'c') && grade == gradeArray[i]) || ((grade == 'D' || grade == 'd') && grade == gradeArray[i]) || ((grade == 'F' || grade == 'f') && grade == gradeArray[i]) ){
        check3 = true;
      }
    }
    if (!check3){
      std::cout << "Invalid Grade. Press enter to try again" << std::endl;
    }
  }
  fin.close();
  f1in.close();
  f2in.close();                // closes all respected files
  f3in.close();
  newCourse -> addCourseRecord(course, department, semester, grade); // sends information from this function to the same named function with these parameters
  Course temp = *newCourse;
  delete newCourse;
  return temp; // returns pointer to newCourse
}

void Course::addCourseRecord(std::string course, std::string department, std::string semester, char grade){  // information from previous function sent here to be set within Course class private members
  nameOfCourse = course;
  departmentName = department;
  semesterTaken = semester;
  gradeRecieved = grade;
}

void Course::setNameOfCourse(std::string course){
  nameOfCourse = course;
}

void Course::setSemesterTaken(std::string semester){
  semesterTaken = semester;
}

void Course::setDepartmentName(std::string department){
  departmentName = department;
}

void Course::setGradeRecieved(char grade){
  gradeRecieved = grade;
}
                                                                              // setters & getters
std::string Course::getNameOfCourse(){
  return nameOfCourse;
}

std::string Course::getSemesterTaken(){
  return semesterTaken;
}

std::string Course::getDepartmentName(){
  return departmentName;
}

char Course::getGradeRecieved(){
  return gradeRecieved;
}

void Course::printCourses(){ // function to print information for each course information that student creates
  std::cout << "Course: " << getNameOfCourse() << std::endl;
  std::cout << "Department: " << getDepartmentName() << std::endl;
  std::cout << "Semester: " << getSemesterTaken() << std::endl;
  std::cout << "Grade: " << getGradeRecieved() << std::endl;
}
