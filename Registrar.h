#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "Window.h"
#include "LinkedList.h"


class Registrar{
private:
  // Window *window = new Window();
  // DoublyLinkedList<Window> *registrar = new DoublyLinkedList<Window>();
  // Window *window = new Window();
  int windowCount;
public:
  DoublyLinkedList<Window> *registrar = new DoublyLinkedList<Window>();
  genQueue<Student> *studentQ= new genQueue<Student>();
  Registrar();
  ~Registrar();
  void createWindow();
  void createWindow(Student *s);
  void closeWindow();
  void addStudent(int time);
  void removeStudent();
  // Student printStudents();
  // void populateWindow();


};

Registrar::Registrar(){
  windowCount=0;
}


Registrar::~Registrar(){

}

void Registrar::createWindow(){
  Window *window = new Window();
  registrar->insertBack(*window);
  windowCount++;

}

void Registrar::createWindow(Student *s){
  Window *window = new Window(s);
  registrar->insertBack(*window);
  windowCount++;

}


void Registrar::closeWindow(){
  if(!registrar->isEmpty()){
    registrar->removeFront();
  }
  else{
    cout<<"No Windows Open "<<endl;
  }
}

void Registrar::addStudent(int timeNeeded){
  Student *s1 = new Student(timeNeeded);
  studentQ ->insert(*s1);
}

void Registrar::removeStudent(){
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

#endif
