#ifndef WINDOW_H
#define WINDOW_H


class Window{
private:
  bool isStudent;
public:


  Window();
  Window(bool isStudent);
  bool inUse();
  ~Window();

};

Window::Window(){
  isStudent=false;
}
Window::Window(bool inUse){
  isStudent = inUse;
}
bool Window::inUse(){
  return isStudent;
}

Window::~Window(){

}

#endif
