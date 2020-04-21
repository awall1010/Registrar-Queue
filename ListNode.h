#ifndef LISTNODE_H
#define LISTNODE_H


#include <cstddef>
#include <iostream>
using namespace std;

template<class T>
class ListNode{
public:
  T data;
  ListNode *next;
  ListNode *prev;

  ListNode();//my deffault constructor
  ListNode(T d);//overload constructor

  ~ListNode();
};

template<class T>
ListNode<T>::ListNode(){
  T data;
  ListNode *next;
  ListNode *prev;
}

template<class T>
ListNode<T>::ListNode(T d){
  // data;
  data = d;
  ListNode *next;
  ListNode *prev;
}


template<class T>
ListNode<T>::~ListNode(){

}
#endif
