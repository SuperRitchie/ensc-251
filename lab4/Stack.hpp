#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstddef>

template <typename T>
struct StackFrame {
  T data;
  StackFrame<T>* link;
};

template <typename T>
using StackFramePtr = StackFrame<T>*;

template <typename T>
class Stack {
  private:
    StackFrame<T>* top;

  public:
    //Constructors
    Stack<T>();

    //Copy Constructor
    Stack<T>(const Stack &s);

    //Destructor
    ~Stack<T>();

    //Overloaded Operator
    void operator=(const Stack &s) noexcept;

    //Functions
    void push(T popNew);
    T pop();
    bool empty() const;
    T reverse();
    void bottomfeeder(T input);


    //Getters
    StackFrame<T>* getTop(); //returns pointer to the top of Stack
};
#include "Stack.cpp"
#endif