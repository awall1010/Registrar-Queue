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
  // DoublyLinkedList<Window> *DLL = new DoublyLinkedList<Window>();
  // Window *w1 = new Window(true);
  // DLL->insertBack(w1);
  // Registrar *registrar = new Registrar();
  //
  // registrar->createWindow();
  string fName = argv[1];
  Simulation *sim = new Simulation();
  sim->readFile(fName);



  // genQueue<Student> *studentQ= new genQueue<Student>();
  // Student *Aidan = new Student(5);
  // testQ->insert(*Aidan);

  cout<<endl;



  return 0;
}
