// Ethan Massey 2019
// Stack data structure class template

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
class Stack {

   public:
     Stack();              // constructor
     ~Stack();             // destructor
     T pop();              // return AND remove top element
     T peek();             // return top element
     int size();           // return num elements
     void push(T item);    // add element to stack
     void del();           // remove top element
     string toString();    // return string representation
     void print();         // std::cout string representation (void)

   private:
     void resize(int newSize);
     T* values = new T[1024];
     int capacity;
     int currentIndex;

};

template <typename T>
Stack<T>::Stack() {
  currentIndex = 0;
  capacity = 1024;
}

template <typename T>
Stack<T>::~Stack() {

}

template <typename T>
T Stack<T>::pop() {
  T temp = values[currentIndex];
  values[currentIndex] = 0;
  currentIndex--;
  return temp;
}

template <typename T>
T Stack<T>::peek() {
  return values[currentIndex-1];
}

template <typename T>
int Stack<T>::size() {
  return currentIndex;
}

template <typename T>
void Stack<T>::push(T item) {
  if(currentIndex == capacity){
    resize(capacity + 1024);
  }
    values[currentIndex] = item;
    currentIndex++;
}

template <typename T>
void Stack<T>::del() {
  values[currentIndex] = 0;
  currentIndex--;
}

template <typename T>
string Stack<T>::toString() {
  string ret = "";
  int count = 0;
  for(int i = 0; i < currentIndex; i++){
    ret += count << ": " + values[i] + endl;
    count++;
  }
  return ret;
}

template <typename T>
void Stack<T>::print() {
  int count = 0;
  for(int i = 0; i < currentIndex; i++){
    cout << count << ": " << values[i] << endl;
    count++;
  }
}

template <typename T>
void Stack<T>::resize(int newSize) {
  capacity = newSize;
  T newArr[newSize];
  for(int i = 0; i < currentIndex; i++){
    newArr[i] = values[i];
  }
  values = newArr;
}

#endif
