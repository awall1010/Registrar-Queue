#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "Window.h"
#include "LinkedList.h"
#include <fstream>


class Registrar{
private:
  // Window *window = new Window();
  // DoublyLinkedList<Window> *registrar = new DoublyLinkedList<Window>();
  // Window *window = new Window();
  int windowCount;
public:
  DoublyLinkedList<Window> *registrar = new DoublyLinkedList<Window>();
  Window* winArr;
  genQueue<Student> *studentQ= new genQueue<Student>();
  Registrar();
  ~Registrar();
  void createWindow();
  void createWindow(Student *s);
  void closeWindow();
  void addStudent(int timeArrived, int time);
  void removeStudent();
  void newWindow(int numWindows);
  int it = 0;
  int totalIdleTime;
  int totalWaitTime;
  int STUover10;
  int over5;
  int longestIdle;


  int peekArrival();
  int peekTimeNeeded();
  // Student printStudents();
  // void populateWindow();
  bool noStudents();

  void studentToWindow();
  void leaveWindow();

  // void readFile(string fName);
  int timeNeededAtWindow;
  // int iterator = 0;




};

Registrar::Registrar(){
  windowCount=0;
}


Registrar::~Registrar(){

}

void Registrar::createWindow(){
  Window* window = new Window();
  registrar->insertBack(*window);
  windowCount++;

}

void Registrar::newWindow(int numWindows){
  // Window *winArr[numWindows] = new Window[numWindows];

  winArr = new Window[numWindows];
  for(int i = 0; i<numWindows;++i){
    Window *window = new Window();
    winArr[i] = *window;
  }
}


// void Registrar::createWindow(Student *s){
//   Window *window = new Window(s);
//   registrar->insertBack(*window);
//   windowCount++;
//
// }


void Registrar::closeWindow(){
  if(!registrar->isEmpty()){
    registrar->removeFront();
  }
  else{
    cout<<"No Windows Open "<<endl;
  }
}

void Registrar::addStudent(int timeArrived,int timeNeeded){
  Student *s1 = new Student(timeArrived,timeNeeded);
  studentQ ->insert(*s1);
}

void Registrar::removeStudent(){
  studentQ->remove();
}

bool Registrar::noStudents(){
  return studentQ->isEmpty();
}


int Registrar::peekArrival(){
  return studentQ->peek().viewArrivalTime();
}

int Registrar::peekTimeNeeded(){
  return studentQ->peek().viewTimeNeeded();
}



void Registrar::studentToWindow(){
  // Student tempStudent = studentQ->remove();
  // int it = 0;
  while(true){
    int iterator = 0;
    if(!winArr[iterator].inUse()){

      Student tempStudent = studentQ->peek();
      timeNeededAtWindow = studentQ->peek().timeNeeded;
      studentQ->remove();
      winArr[iterator].addStudent(&tempStudent);
      totalIdleTime++;
      if(totalIdleTime>5){
        over5++;
      }

    }
    else if(iterator=4){
      totalWaitTime++;
      if(totalWaitTime>10){
        STUover10++;
        int waitTime[10];
        for(int i = 0;i<10;++i){
          if(totalWaitTime<=waitTime[i]){
            waitTime[i]=totalWaitTime;
          }
          else{
            waitTime[i+1]=totalWaitTime;
          }

        }

      }


      // if(iterator>)

    }
    iterator++;
    it = iterator;
    break;
    // it = iterator;
  }
  // it = iterator;
}


void Registrar::leaveWindow(){

  winArr[it].windowNotInUse();
  studentQ->remove();  
}


// Student Registrar::printStudents(){
//   return studentQ->peek();
//   studentQ->remove();
//
// }
// void Registrar::populateWindow(){
//   ListNode<Window> *curr = registrar->front;
//   registrar->viewFront().windowInUse();
//   curr = curr->next;
// }


//
// void Registrar::readFile(string fName){
//   ifstream inFS;
//
//   inFS.open(fName);
//   if(!inFS.is_open()){
//     cout<<"couldn't open file. "<<endl;
//   }
//
//   inFS>> windowsOpen;
//   cout<<"Windows Open: "<< windowsOpen<<endl;
//
//   // reg->newWindow(windowsOpen);
//
//   newWindow(windowsOpen);
//
//   for(int i = 0;i<windowsOpen;++i){
//     // reg->createWindow();
//
//
//
//   }
//
// while(true){
//
//   inFS>>clockTick;
//   inFS >> numStudents;
//
//
//
//
//
// if(inFS.eof()){
//   break;
// }
//
// if(!inFS.fail()){
//
//
//     cout<<"At clock tick "<<clockTick<<", "<<numStudents<<" students arrive "<<endl;
//     for(int j = 0;j<numStudents;++j){
//       inFS >> timeNeeded;
//       cout<<"Sudent "<<j<<" needs "<<timeNeeded<<" minutes "<<endl;
//       // Student *s1 = new Student(timeNeeded);
//       reg->addStudent(clockTick,timeNeeded);
//       Student *s1 = new Student(clockTick,timeNeeded);
//
//
//     }
//
//
//
//     }
//
// }
//
//
// }





#endif
