/////////////////////////////////////////////////////////////////////////////////////
//    Big-O Analysis of reverse() + helpers:
// 
// 1. All operations of reverse() and its inside functions (bottomfeeder(), pop()):
//
///       Big-O Notation = O(n^2)
//
//    Originally, to calculate the big-O notation, we broke up the reverse()
//    function into its individual operations and calculated each big-O
//    for each. Afterwards, you add up the big-O of each operation together. In
//    the end, the highest order term is what we consider the big-O of the
//    function. In this case, O(n^2).  
/////////////////////////////////////////////////////////////////////////////////////
#include "Stack.hpp"
#include "Stack.cpp"
#include <iostream>
#include <cstdlib>
#include <new>
using namespace std;


//printStack() ordinary function: passes generalized data type into print function and utilizes pop()
template <typename T>
void printStack(Stack<T> s) {
  if(!s.empty()) {
    s.reverse();
  }
  else {
    cout << "Could not print an empty stack" << endl;
  }
  while(!s.empty()) {
    cout << s.pop();
  }
}

//main() program!!
int main() {
  cout << "\nWelcome to the Stack program! Brought to you by Linked Lists.\n";

  //Initialization
  bool prompt = true;

  Stack<int> sint1;
  for(int i = 1; i <= 6; i++) {
    sint1.push(i);
  }

  cout << "\nTest 1:\nStack<int> test case" << endl;
  Stack<int> sint2 = sint1;
  sint1.reverse();
  printStack(sint1);
  printStack(sint2);
  cout << " -> Entire stack of sint1 and sint2" << endl;

  cout << "\nTest 2:\nStack<double> test case" << endl;
  Stack<double> sdouble1;
  for(double i = 1.5; i <= 6.5; i = i + 1.0) {
    sdouble1.push(i);
  }
  printStack(sdouble1); 
  cout << " -> sdouble1" << endl;
  Stack<double> sdouble2(sdouble1);
  sdouble2.reverse();
  cout << sdouble2.getTop() -> data << " -> sdouble2 top" << endl; 

 
  while(prompt) {
    Stack<char> palindromeInput;
    string x;
    
    cout << "\nEnter a string (type 'exit' to end program): ";
    cin >> x; cout << endl;
    
    if(x == "exit") {
      cout << "Buh-bye" << endl;
      prompt = false;
      break;
    }
    for(int i = 0; i < x.length(); i++) {
      palindromeInput.push(x[i]);
    }

    // Print original stack, then its reverse!
    printStack(palindromeInput);
    palindromeInput.reverse();
    printStack(palindromeInput);
    cout << endl;
  }
  return 0;
}