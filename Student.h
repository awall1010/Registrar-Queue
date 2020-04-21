#ifndef STUDENT_H
#define STUDENT_H


#include <cstddef>
#include <iostream>
using namespace std;

class Student{
private:
  int timeNeeded;
public:
  Student();
  Student(int timeNeeded);
  ~Student();
  // int timeNeeded;

};

Student::Student(){
  timeNeeded = 0;
}


Student::Student(int time){
  timeNeeded = time;
}


Student::~Student(){

}

#endif
