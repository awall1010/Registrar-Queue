#include "LinkedList.h"
#include "RegQueue.h"
#include "Student.h"
#include "Window.h"
#include "Registrar.h"
#include "Simulation.h"


int main(int argc, char const *argv[]) {
  if(argc<2){ //make sure valid command line parameters
    cout<<"invalid command line parameters."<<endl;
    return 1;

  }

  string fName = argv[1];
  Simulation *sim = new Simulation();
  sim->readFile(fName);
  sim->runSim();



  cout<<endl;



  return 0;
}




//
//
// #ifndef REGISTRAR_H
// #define REGISTRAR_H
//
// #include "Window.h"
// #include "LinkedList.h"
// #include <fstream>
//
//
// class Registrar{
// private:
//   // Window *window = new Window();
//   // DoublyLinkedList<Window> *registrar = new DoublyLinkedList<Window>();
//   // Window *window = new Window();
//   int windowCount;
// public:
//   DoublyLinkedList<Window> *registrar = new DoublyLinkedList<Window>();
//   Window* winArr;
//   genQueue<Student> *studentQ= new genQueue<Student>();
//   Registrar();
//   ~Registrar();
//   void createWindow();
//   void createWindow(Student *s);
//   void closeWindow();
//   void addStudent(int timeArrived, int time);
//   void removeStudent();
//   void newWindow(int numWindows);
//   int iter = 0;
//   int totalIdleTime;
//   int totalWaitTime;
//   int STUover10;
//   int over5;
//
//
//   int peekArrival();
//   int peekTimeNeeded();
//   // Student printStudents();
//   // void populateWindow();
//   bool noStudents();
//
//   void studentToWindow();
//   void leaveWindow();
//
//   // void readFile(string fName);
//   int timeNeededAtWindow;
//   // int iterator = 0;
//
//
//
//
// };
//
// Registrar::Registrar(){
//   windowCount=0;
// }
//
//
// Registrar::~Registrar(){
//
// }
//
// void Registrar::createWindow(){
//   Window* window = new Window();
//   registrar->insertBack(*window);
//   windowCount++;
//
// }
//
// void Registrar::newWindow(int numWindows){
//   // Window *winArr[numWindows] = new Window[numWindows];
//
//   winArr = new Window[numWindows];
//   for(int i = 0; i<numWindows;++i){
//     Window *window = new Window();
//     winArr[i] = *window;
//   }
// }
//
//
// // void Registrar::createWindow(Student *s){
// //   Window *window = new Window(s);
// //   registrar->insertBack(*window);
// //   windowCount++;
// //
// // }
//
//
// void Registrar::closeWindow(){
//   if(!registrar->isEmpty()){
//     registrar->removeFront();
//   }
//   else{
//     cout<<"No Windows Open "<<endl;
//   }
// }
//
// void Registrar::addStudent(int timeArrived,int timeNeeded){
//   Student *s1 = new Student(timeArrived,timeNeeded);
//   studentQ ->insert(*s1);
// }
//
// void Registrar::removeStudent(){
//   studentQ->remove();
// }
//
// bool Registrar::noStudents(){
//   return studentQ->isEmpty();
// }
//
//
// int Registrar::peekArrival(){
//   return studentQ->peek().viewArrivalTime();
// }
//
// int Registrar::peekTimeNeeded(){
//   return studentQ->peek().viewTimeNeeded();
// }
//
//
//
// void Registrar::studentToWindow(){
//   // Student tempStudent = studentQ->remove();
//   int iter;
//   while(true){
//     int iterator = 0;
//     if(!winArr[iterator].inUse()){
//
//       Student tempStudent = studentQ->peek();
//       timeNeededAtWindow = studentQ->peek().timeNeeded;
//       studentQ->remove();
//       winArr[iterator].addStudent(&tempStudent);
//       totalIdleTime++;
//       if(totalIdleTime>5){
//         over5++;
//       }
//
//     }
//     else if(iterator=4){
//       totalWaitTime++;
//       if(totalWaitTime>10){
//         STUover10++;
//         // int[] longestIdle = new int[10];
//       }
//
//
//       // if(iterator>)
//
//     }
//     iterator++;
//     break;
//
//   }
//   // iter = iterator;
// }
//
//
// void Registrar::leaveWindow(){
//   winArr[iterator].windowNotInUse();
// }
//
//
//
// #endif
