#ifndef WINDOW_H
#define WINDOW_H


class Window{
private:
  bool isStudent;
public:


  Window();
  Window(Student *s);
  bool inUse();
  void windowInUse();
  void windowNotInUse();
  ~Window();

};

Window::Window(){
  isStudent=false;
}
Window::Window(Student *s){
  Student *newStudent = s;
  isStudent = true;
}
bool Window::inUse(){
  return isStudent;
}
void Window::windowInUse(){
  isStudent=true;
}
void Window::windowNotInUse(){
  isStudent=false;
}

Window::~Window(){

}

#endif
