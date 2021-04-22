//time.cpp to implement your class
#include "time.hpp"
#include "date.hpp"
#include <iostream>

using namespace std;

// Constructor that calls the respective functions to check validty of the inputted time
TimeRange::TimeRange() {
}

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
}
///////////////////////////////////////////////////////////////////////////////////////////////////

// sets the respective variables
void TimeRange::setbeginMinute(int abeginMinute)
{
  beginMinute = abeginMinute; 
}

void TimeRange::setbeginHour(int aabeginHour)
{
  beginHour = aabeginHour;
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