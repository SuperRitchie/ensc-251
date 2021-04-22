//time.cpp to implement your class
#include "time.hpp"
#include "date.hpp"
#include <iostream>
using namespace std;

// Constructor that calls the respective functions to check validty of the inputted time
TimeRange::TimeRange() {}

// Inputs the beginning and start times
bool TimeRange::isValid(int abeginHour, int abeginMinute, int aendHour, int aendMinute) {
  bool valid = false;
  // Checks if the hours are in 24h format
  if(abeginHour >= 0 && abeginHour <= aendHour && abeginMinute % 30 == 0 && aendMinute % 30 == 0 && aendHour <= 24) {
    if(abeginHour == aendHour) {
      if(aendMinute > abeginMinute && aendMinute <= 30) {
        valid = true;
      }
    }
    else if(aendMinute <= 30 && abeginMinute <= 30) {
      valid = true;
    }
  }
  // Boolean that determines the final output, based on the nested if statement
  if(valid) {
    return true;
  }
  else {
    cout << "The selected time range is invalid. Please enter a valid date.\n";
    return false;
  }
}

////////////////////////////////////////// output /////////////////////////////////////////////////
//Output the currently selected month and day to the user
void TimeRange::output()
{
  cout << "\nYour chosen appointment time is: ";
  if(beginHour < 10) {
    cout << "0" << beginHour;
  }
  else {
    cout << beginHour;
  }
  cout << ":";
  if(beginMinute == 0) {
    cout << "00";
  }
  else {
    cout << beginMinute;
  }
  cout << " - ";
  if(endHour < 10) {
    cout << "0" << endHour;
  }
  else {
    cout << endHour;
  }
  cout << ":";
  if(endMinute == 0) {
    cout << "00";
  }
  else {
    cout << endMinute;
  }
  cout << "\n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////

// sets the respective variables
void TimeRange::setbeginMinute(int abeginMinute)
{
  beginMinute = abeginMinute; 
}

void TimeRange::setbeginHour(int abeginHour)
{
  beginHour = abeginHour;
}

void TimeRange::setendHour(int aendHour)
{
  endHour = aendHour;
}

void TimeRange::setendMinute(int aendMinute)
{
  endMinute = aendMinute;
}

int TimeRange::getbeginHour() {
  return beginHour;
}
int TimeRange::getbeginMinute() {
  return beginMinute;
}
int TimeRange::getendHour() {
  return endHour;
}
int TimeRange::getendMinute() {
  return endMinute;
}

/*
void TimeRange::changeTime() {
  int abeginHour, abeginMinute;
  int aendHour, aendMinute;
  bool flag = true;
  while(flag) {
    if(isValid(abeginHour, abeginMinute, aendHour, aendMinute)) {
      setbeginHour(abeginHour); //set user inputted start-hour in time1
      setbeginMinute(abeginMinute); //set user inputted start-minutein time1
      setendHour(aendHour); //set user inputted end-hour in time1
      setendMinute(aendMinute); //set user inputted end-minute in time1
      break;
    }
    else { //Prompts user to re-input new values
      cout << "\nPlease re-enter a valid time below:\n";
      cout << "\nBeginning time: ";
      cin >> abeginHour >> abeginMinute;
      cout << "\nEnding time: ";
      cin >> aendHour >> aendMinute;
    }
  }
}
*/

////////////////////////////////////////// timeCheck ////////////////////////////////////////////////
// Runs user inputted times through all the error checks.
void TimeRange::timeCheck(int abeginHour, int abeginMinute, int aendHour, int aendMinute)
{
  bool flag = true;

  while(flag) 
  {
    if(isValid(abeginHour, abeginMinute, aendHour, aendMinute)) 
    {
      setbeginHour(abeginHour); //set user inputted start-hour in time1
      setbeginMinute(abeginMinute); //set user inputted start-minutein time1
      setendHour(aendHour); //set user inputted end-hour in time1
      setendMinute(aendMinute); //set user inputted end-minute in time1
      break;
    }
    else //Prompts user to re-input new values
    { 
      cout << "\nPlease re-enter a valid time below:\n";
      cout << "\nBeginning time: ";
      cin >> abeginHour >> abeginMinute;
      cout << "\nEnding time: ";
      cin >> aendHour >> aendMinute;
    }
  }
}

void TimeRange::displayAppointed() {
}

/////////////////////////////////////////////////////////////////////////////////////////////////////