#include "Stack.hpp"
#ifndef STACK_CPP
#define STACK_CPP


using namespace std;

//Constructor definition
template <typename T>
Stack<T>::Stack() {
  top = NULL; //initialize empty stack at top
}

// Copy Constructor definition
template <typename T>
Stack<T>::Stack(const Stack &s) {
  if (s.top == NULL) {
    top = NULL;
  }
  else {
    StackFrame<T>* temp;
    temp = s.top; //temp pointer set to top, keeps moving down

    StackFrame<T>* bot; //bottom of a stack pointer
    bot = new StackFrame<T>; //creation of node at bot pointer
    bot->data = temp->data; //assign the pointer data to the bot
    top = bot; //top receives bot data

    temp = temp->link; //set link of current node to temp pointer

    //while the temp isnt empty...
    while(temp != NULL) {
      bot->link = new StackFrame<T>; //new node at the bottom of stack
      bot = bot->link; //link node assigned to bot
      bot->data = temp->data; //temp data is also assigned 
      temp = temp->link; //new temp pointer from temp link
    }
    bot->link = NULL; //at the end, bottom of stack must initialize to null
  }
}

//Destructor definition
template <typename T>
Stack<T>::~Stack() {
  T tart;
  while(!empty()) {
    tart = pop(); //keep popping stack until empty (remove dynamic variables)
  }
}

//Overloaded operator definition
template <typename T>
void Stack<T>::operator=(const Stack &s) noexcept { //noexcept for bad throw (operator)
  //Copy from the copy constructor (same logic for assignment operator)
  if (s.top == NULL) {
    top = NULL;
  }
  else {
     StackFrame<T>* temp;
    temp = s.top;

     StackFrame<T>* bot;
    bot = new StackFrame<T>;
    bot->data = temp->data;
    top = bot;

    temp = temp->link;
    while(temp != NULL) {
      bot->link = new StackFrame<T>;
      bot = bot->link;
      bot->data = temp->data;
      temp = temp->link;
    }
    bot->link = NULL;
  }
  
}

//Top getter - returns pointer that points to the top of the list
template <typename T>

StackFrame<T>* Stack<T>::getTop() {
  return top;
}


/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


//push() function: pushes a new data type onto the top of the stack
template <typename T>
void Stack<T>::push(T popNew) {
  //create temp pointer and assign to new node allocation
  StackFrame<T>* temp;
  temp = new StackFrame<T>; //memory allocation for new node StackFrame

  //bad_alloc: catching the bad allocation exception when new memory is allocated
  try {
    StackFrame<T>* bad = new StackFrame<T>;
  }
  catch(std::bad_alloc) {
    cout << "\nError: Bad memory allocation.\n";
  }

  //assign current data to temp pointer
  temp->data = popNew;
  temp->link = top;
  top = temp; //setting the new temp node to the top of stack
}

//pop() function: pops off data type at the top of current stack
template <typename T>
T Stack<T>::pop() {
  //outputs error if user tries to pop empty stack
  if(empty()) { 
    cout << "\nError: Popping an empty stack.\n";
    return ' ';
  }

  //create and set output return to be top node data (so we can pop it)
  T output = top -> data;

  //create and set current top to temp pointer
  StackFrame<T>* temp_ptr;
  temp_ptr = top;
  top = top->link; //sets current top to new link pointer (next node)
  
  //delete temp pointer (holding old top) and return output
  delete temp_ptr;
  return output;
}

//empty() function: checks if top is NULL
template <typename T>
bool Stack<T>::empty() const {
  return (top == NULL); //returns true if top == NULL
}

//reverse() function: reverses the current stack (top->bottom = bottom->top)
template <typename T>
T Stack<T>::reverse() {
  if(empty()) { 
    return '\0';
  }
  // If the Stack is not empty, the starting point is top of the stack
  T input = top->data;
  pop();
  // While the function is not empty, empty it. After the function is empty, 
  reverse();
  bottomfeeder(input);
  return top->data;
}


//bottomfeeder() helper function: pushes popped out nodes into reverse stack
template <typename T>
void Stack<T>::bottomfeeder(T input) {
  if(empty()) {
    push(input);
  }
  else {
    T nextInput = top->data;
    pop();
    bottomfeeder(input);
    push(nextInput);
  }
}
#endif