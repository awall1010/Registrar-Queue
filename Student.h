#ifndef STUDENT_H
#define STUDENT_H


#include <cstddef>
#include <iostream>
using namespace std;

class Student{
private:
  // int timeNeeded;
  // int timeArrived;

public:
  int timeNeeded;
  int timeArrived;
  
  Student();
  Student(int timeArrived,int timeNeeded);
  ~Student();
  int viewArrivalTime();
  int viewTimeNeeded();
  // int timeNeeded;

};

Student::Student(){
  timeNeeded = 0;
  timeArrived = 0;
}


Student::Student(int arrival,int time){
  timeArrived = arrival;
  timeNeeded = time;

}


Student::~Student(){

}

int Student::viewTimeNeeded(){
  return timeNeeded;
}

int Student::viewArrivalTime(){
  return timeArrived;
}

#endif
