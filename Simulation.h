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
  int timeAtWindow;
  int clockTick;
  int timeNeeded;
  int lineCount = 0;
  Registrar *reg = new Registrar();
  Simulation();
  ~Simulation();
  void readFile(string fName);



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

  for(int i = 0;i<windowsOpen;++i){
    reg->createWindow();

  }


while(!inFS.eof()){

if(!inFS.fail()){

    lineCount++;

    inFS>>clockTick;
    inFS >> numStudents;
    cout<<"At clock tick "<<clockTick<<", "<<numStudents<<" students arrive "<<endl;
    for(int j = 0;j<numStudents;++j){
      inFS >> timeNeeded;
      cout<<"Sudent "<<j<<" needs "<<timeNeeded<<" minutes "<<endl;
      // Student *s1 = new Student(timeNeeded);
      reg->addStudent(timeNeeded);
      Student *s1 = new Student(timeNeeded);

      // reg->printStudents();

    }

    // for(int i = 0; i < numStudents;++j)
    //this is where student goes to window
    // registrar


    // cout<<"printing to see "<<endl;


    }
  }
  // cout<<"Line count: "<<lineCount<<endl;

}




#endif
