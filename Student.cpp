#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include "Student.h" // includes header file with prototypes

Student Student::addStudent() // function that will allow user to input information about the student they are adding
{
  std::ifstream theFile;
  theFile.open("majorList.txt"); // opens file of acceptable majors
  bool isValid = false;
  Student *newStudent = new Student;
  std::string userName, userBirth, userMajor;
  bool isCorrect = false;
  std::cout << "Please enter Student's name (First_Last): ";
  std::cin >> userName;
  do{
    int days, month, dd, mm, yy, num;
    do{
      std::cout << "Enter month Student was born (ex. If Born Jan 4, 2019 / Enter 1): ";
      std::cin >> mm;
    }while (mm < 1 || mm > 12);
    if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12){ 
      days = 31;
    } 
    if (mm == 4 || mm == 6 || mm == 9 || mm == 11){                                 // sets specified amount of days depending on which month the user picks
      days = 30;
    }
    if (mm == 2){
        days = 28;
    }
    do{
      std::cout << "Enter day Student was born (ex. If Born Jan 4, 2019 / Enter 4): ";
      std::cin >> dd;
    }while (dd < 1 || dd > days);
    do{
      std::cout << "Enter year Student was born (ex. If Born Jan 4, 2019 / Enter 2019): ";
      std::cin >> yy;
    }while (yy > 2019);
    if (((dd >= 1) && (dd<=days)) && ((mm >= 1) && (mm <= 12)) && (yy <= 2019)){
      std::string d = std::to_string(dd);
      std::string m = std::to_string(mm);
      std::string y = std::to_string(yy);
      std::string dummy = "/";
      std::string dummy2 = "/";                                 // string streaming the day, month, and year into one string called userBirth
      std::stringstream ss;
      ss << m << dummy << d << dummy2 << y;
      userBirth = ss.str(); // set userBirth to the stream of the three strings as well as the '/'
      isCorrect = true;
    }
  }while (isCorrect = false);

  std::string array[13];               // crteates an array that is populated with the majors from the file
  for (int i = 0; i < 13; i++){
    theFile >> array[i];
  }
  while (!isValid){
    displayMajors();
    std::cout << "--------------------" << std::endl;
    std::cout << "Please enter major: ";
    std::cin >> userMajor;
    for (int i = 0; i < 13; i++){
      if (userMajor == array[i]){  // loops through array to check if what was inserted is in the array or "file"
        isValid = true;
        theFile.close();
      }
    }
    if(!isValid){
      std::cout << "Invalid Major. Press enter to try again" << std::endl;
    }
  }
  newStudent -> addStudent(userName, userBirth, userMajor); // sends this information that was acquired by this function into the other
  Student temp = *newStudent;
  delete newStudent;
  return temp; // returns a pointer to newStudent Student object
}

void Student::addStudent(std::string userName, std::string userBirth, std::string userMajor){ // this function takes in information from previous function and sets it to private data members
  name = userName;
  birth = userBirth;
  major = userMajor;
  std::ofstream fout;
  fout.open("Student_DB.txt", std::ios_base::app); // opens Student_DB text file and inserts information into file
  fout << userName << " " << userBirth << " " << userMajor << std::endl;
  fout.close();
  fout.open("studentNames.txt", std::ios_base::app); // opens studentNames text file and inserts information into file
  fout << userName << std::endl;
  fout.close(); // closes file
}

void Student::displayMajors(){ // function to open majorList text file and display whats inside text file
  std::string temp;
  std::ifstream disp;
  disp.open("majorList.txt");
  if (!disp) // makes sure file opened properly
  {
    std::cout << "Error. Unable to open file.";
    exit(1);
  }
  std::cout << "------------------------------\n";
  std::cout << "List of Majors:\n";
  while (disp >> temp)
  {
    std::cout << temp << std::endl;
  }
  disp.close();
}

void Student::setName(std::string userName){
  name = userName;
}

void Student::setBirth(std::string userBirth){
  birth = userBirth;
}

void Student::setMajor(std::string userMajor){                          // setter & getter functions
  major = userMajor;
}

std::string Student::getName(){
  return name;
}

std::string Student::getBirth(){
  return birth;
}

std::string Student::getMajor(){
  return major;
}

void Student::printStudent() // function that will print each students name, birthday, and major
{
  std::cout << "------------------------------" << std::endl;
  std::cout << "Name: " << getName() << std::endl;
  std::cout << "------------------------------" << std::endl;
  std::cout << "Birthday (Month / Day / Year): " << getBirth() << std::endl;
  std::cout << "Major: " << getMajor() << std::endl;
}
