#ifndef WINDOW_H
#define WINDOW_H


class Window{
private:
  bool isStudent;
public:

  int exitTime;
  Window();
  // Window(Student *s);
  Student *student;

  bool inUse();
  void windowInUse();
  void windowNotInUse();
  void addStudent(Student *s);
  ~Window();

};

Window::Window(){
  isStudent=false;
}
// Window::Window(Student *s){
//   Student *newStudent = s;
//   isStudent = true;
// }
bool Window::inUse(){
  return isStudent;
}
void Window::windowInUse(){
  isStudent=true;
}
void Window::windowNotInUse(){
  isStudent=false;
}

void Window::addStudent(Student *s){

    student = s;
    exitTime = student->timeNeeded;
    isStudent = true;
}

Window::~Window(){

}

#endif
