#ifndef COURSE_H
#define COURSE_H

class Course { // class Course that holds all information for each course
private:
  // private data members that each Course holds
  std::string nameOfCourse;
  std::string departmentName;
  std::string semesterTaken;
  char gradeRecieved;
public:
  // all function prototypes to be used in Course.cpp
  void displayCourses();
  void displayDepartments();
  void displaySemesters();
  Course addCourseRecord();
  void addCourseRecord(std::string, std::string, std::string, char);
  void setNameOfCourse(std::string);
  void setSemesterTaken(std::string);
  void setDepartmentName(std::string);
  void setGradeRecieved(char);
  std::string getSemesterTaken();
  std::string getDepartmentName();
  std::string getNameOfCourse();
  char getGradeRecieved();
  void printCourses();
};

#endif
