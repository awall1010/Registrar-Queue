// Input will be in the form of a command line argument
// (./myprog test.in) that specifies the location of a text
//  file.  The text file will define at what times students
//  arrive andwill have the following format.  The first line
//  will be the number of windows open.  The next line will be
//  the time (or clock tick) at which the next students arrive.
//  The next line will be the number of students that arrive at
//  that time.  The following lines will be the amount of time
//  each student needs at a window.  This is followed by the
//  next clock tick, number of students, etc.For example, and
//  input of:
//  5
//  1
//  2
//  5
//  10
//  3
//  1
//  4
//
//
// Means that 5 windows will be open.  At time 1, 2 students
// arrive.  One will need 5 minutes at a window, and the other 10.
// Then, at time 3, 1 student arrives and needs 4 minutes at a
// window, etc, etc.When students arrive at the same time, assume
// that the student listed first in the text file is also the first
// to get into line.  In the above, at time 1 there will be 2
// students that arrive.  The student requiring 5 minutes will
// get into line before the student requiring 10 minutes.



#ifndef SIMULATION_H
#define SIMULATION_H
#include "Student.h"
#include <fstream>
// #include <ofstream>

class Simulation{
private:

public:
  int windowsOpen;
  int numStudents;
  int totalStudents= 0;
  int timeAtWindow;
  int clockTick;
  int timeNeeded;
  // int lineCount = 0;
  int time = 0;
  Registrar *reg = new Registrar();
  Simulation();
  ~Simulation();
  void readFile(string fName);
  void runSim();
  double avgStuWait;
  double medWaitTime;
  double longStuWait;
  int numOver10;
  double meanIdle;
  double longestIdle;
  int numOver5;



};

Simulation::Simulation(){

}
Simulation::~Simulation(){

}

void Simulation::readFile(string fName){
  ifstream inFS;

  inFS.open(fName);
  if(!inFS.is_open()){
    cout<<"couldn't open file. "<<endl;
  }

  inFS>> windowsOpen;
  cout<<"Windows Open: "<< windowsOpen<<endl;
  reg->newWindow(windowsOpen);
  for(int i = 0;i<windowsOpen;++i){
    reg->createWindow();

  }

while(true){

  inFS>>clockTick;
  inFS >> numStudents;
if(inFS.eof()){
  break;
}

if(!inFS.fail()){
    cout<<"At clock tick "<<clockTick<<", "<<numStudents<<" students arrive "<<endl;
    totalStudents+=numStudents;
    for(int j = 0;j<numStudents;++j){
      inFS >> timeNeeded;
      cout<<"Sudent "<<j<<" needs "<<timeNeeded<<" minutes "<<endl;
      // cout<<endl;
      // Student *s1 = new Student(timeNeeded);
      reg->addStudent(clockTick,timeNeeded);
      // cout<<"added"<<endl;
      // Student *s1 = new Student(clockTick,timeNeeded);
    }
    cout<<endl;
    }
}
}

void Simulation::runSim(){
  int exitTime = 0;

  //need a clock in a loop
  while(!reg->noStudents()){
    if(reg->peekArrival()==time){
      // int exitTime = time+reg->timeNeededAtWindow;
      // cout<<"exit time: "<<exitTime<<endl;
      reg->studentToWindow();
      exitTime = time+reg->timeNeededAtWindow;
      // cout<<"exit time: "<<exitTime<<endl;
      // int exitTime = time+window->exitTime;
      //exit time = time(time student gets to window) and time needed.
    }

    if(exitTime == time){
      //remove student from window

      reg->leaveWindow();
      // cout<<"removed "<<endl;
    }
    // if()
    // time++;
    // if(reg->noStudents()){
    //   break;
    // }
    time++;
  }
  meanIdle = (reg->totalIdleTime)/totalStudents;
  avgStuWait = (reg->totalWaitTime)/totalStudents;
  cout<<"Mean Student Wait Time: "<< avgStuWait<<endl;
  cout<<"Median Wait Time: "<< medWaitTime<<endl;
  cout<<"Longest Student Wait Time: "<< longStuWait<<endl;
  cout<<"Over 10 Min "<< reg->STUover10<<endl;
  cout<<"Mean Idle Time: "<<meanIdle<<endl;
  cout<<"Windows Idle Over 5 Min: "<< reg->over5<<endl;


}


#endif
