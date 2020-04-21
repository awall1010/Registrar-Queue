#ifndef REGQUEUE_H
#define REGQUEUE_H


#include <iostream>
// #include "LinkedList.h"

using namespace std;

template<class T>
class genQueue{
  public:
    genQueue();//deffault constructor
    // genQueue(int maxSize);//overloaded constructor
    ~genQueue();

    //core functions
    void insert(T d);//enqueue
    T remove();//dequeue
    //aux functions
    T peek();
    bool isFull();
    bool isEmpty();
    int getSize();

    // vars
    ListNode<T> *front; //aka head
    ListNode<T> *rear; //read
    // int m_size;
    int numElements;

    // DoublyLinkedList<T> *myQueue;
    T data;

};




template<class T>
genQueue<T>::genQueue(){
  // myQueue = new DoublyLinkedList<T>();
  // m_size=maxSize;
  // front = 0;
  // rear = -1;
  front = new ListNode<T>();
  rear = new ListNode<T>();
  numElements = 0;
}

template<class T>
genQueue<T>::~genQueue(){
  // delete myQueue;
}

template<class T>
void genQueue<T>::insert(T d){
  //add error checking
  // myQueue[++rear]=d;
  //to create circular, add
  //myQueue[++rear%maxSize]=d;
  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty()){
    front = node;
  }
  else{
    //not empty
    rear->next = node; //next pointer back = node
    node->prev = rear; //node previous = back
  }
  rear = node;
  // size++;

  ++numElements;
}

template<class T>
T genQueue<T>::remove(){
  //add error checking
  numElements--;
  T temp = front->data;
  ListNode<T> *ft = front; //have to create because after you update front, have to delete the old front and if no reference to it its lost
  front = front->next;
  ft->next = NULL;//set first value = null before you can delete
  delete ft;
  return temp;

  // return data;



  // if(!isFull()){
  //   char c = '\0';
  //   c = myQueue[front];
  //   ++front;
  //   --numElements;
  //   return c;
  // }
  // char c = '\0';
  // c = myQueue[front];
  // ++front;
  // --numElements;
  // return c;
}


template<class T>
T genQueue<T>::peek(){
  return front->data;
}


// template<class T>
// bool genQueue<T>::isFull(){
//   return(numElements==m_size);
// }

template<class T>
bool genQueue<T>::isEmpty(){
  return (numElements==0);
}

template<class T>
int genQueue<T>::getSize(){
  return numElements;
}


#endif
