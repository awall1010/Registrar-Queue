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
  void closeWindow();
  void addStudent(int timeTime);


};

Registrar::Registrar(){
  windowCount=0;
}


Registrar::~Registrar(){

}

void Registrar::createWindow(){
  Window *window = new Window();
  registrar->insertBack(window);
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

#endif
