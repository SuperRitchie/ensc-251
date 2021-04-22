//date.cpp to implement your class
#include "date.hpp"
#include "time.hpp"
#include <iostream>
using namespace std;


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Date constructor definition. 'appointed[48]' array is also initialized here.
Date::Date()
{
  bool appointed[48] = {0}; //array initialization
}
/////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////
// After user inputs run through all of the checks, the following set functions will run and set the 
// private variables 'month' and 'day' to whatever the user inputted for 'aMonth' and 'aDay'.
void Date::setMonth(int aMonth) {
  month = aMonth;
}
void Date::setDay(int aDay) {
  day = aDay;
}

// The following get functions will get and return the private 'month' and 'date' to the user
// when requested.
int Date::getMonth() {
  return month;
}
int Date::getDay() {
  return day;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////// isValid //////////////////////////////////////////////
// bool type function checks if the user inputted date is a valid date (within the valid date range).
bool Date::isValid(int aMonth, int aDay)
{
  //September 8-30:
  if(aMonth == 9 && aDay >= 8 && aDay <= 30) {
    month = aMonth;
    day = aDay;
    return true;
  }
  //October 1-31:
  else if(aMonth == 10 && aDay >= 1 && aDay <= 31) {
    month = aMonth;
    day = aDay;
    return true;
  }
  //November 1-30:
  else if(aMonth == 11 && aDay >= 1 && aDay <= 30) {
    month = aMonth;
    day = aDay;
    return true;
  }
  //December 1-20:
  else if(aMonth == 12 && aDay >= 1 && aDay <= 20) {
    month = aMonth;
    day = aDay;
    return true;
  }
  //If date is does not fall within the valid date range:
  else {
    cout << "\nThe date does not fall within the valid range.\n";
    return false;
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////// isHoliday //////////////////////////////////////////////
// bool type function checks if the user inputted date falls on holiday. Constant parameters are
// set for Thanksgiving and Remembrance Day.
bool Date::isHoliday(int aMonth, int aDay)
{
  //Constant parameters for Thanksgiving Day (Oct 12) and Remembrance Day (Nov 11).
  const int thanksgivingMonth = 10;
  const int thanksgivingDay = 12;
  const int rememberanceDay = 11;
  const int rememberanceMonth = 11;

  //Checks if date selected is on a holiday. If it is, returns true.
  if((aMonth == thanksgivingMonth && aDay == thanksgivingDay) || (aMonth == rememberanceMonth && aDay == rememberanceDay)) {
    cout << "\nThe date falls on a holiday.\n";
    return true;
  }
  //If date is not a holiday, returns false.
  else {
    return false;
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////// isWeekend //////////////////////////////////////////////
// bool type function checks if user inputted date falls on weekend. First, it will check what the
// user inputted month is. Then within that month, it will add on the user inputted days to a 
// counter called dayCount. This is to find the total days starting from Sept.8 to the user inputted
// day. 
//
// After finding the total days from the start of the period, we can match that value to the
// weekend values. The weekend values are just the total number of days, for each weekend, starting
// from the first Saturday of the valid date range.
bool Date::isWeekend(int aMonth, int aDay) 
{
  //Local variable initialization:
  //dayCount = day counter, starting on the first day of the valid date range.
  //Saturdays = starting Saturday of the valid date range.
  int dayCount;
  int Saturdays = 12;
  
  //September: dayCount is set to a certain day of the week.
  if(aMonth == 9)
  {
    dayCount = aDay;
  }
  //October: dayCount is set to a certain day of the week, added on from previous month.
  else if(aMonth == 10)
  {
    dayCount = 30 + aDay;
  }
  //November: dayCount is set to a certain day of the week, added on from previous months.
  else if(aMonth == 11)
  {
    dayCount = 30 + 31 + aDay;
  }
  //December: dayCount is set to a certain day of the week, added on from previous months.
  else if(aMonth == 12)
  {
    dayCount = 30 + 31 + 30 + aDay;
  }

  //From the start of the valid date range, every seven days is a weekend (starting on the 12th of September)
  //This while loop will check if dayCount is on a weekend (checks if dayCount equals Saturdays and Sundays)
  while(Saturdays < 103) 
  {
    if(dayCount == Saturdays || dayCount == Saturdays + 1) //If it lies on a weekend, outputs error message
    {
      cout << "\nThe date falls on a weekend, please enter another date.\n";
      return true;
    }
    Saturdays += 7; //adds one week each time to check all weekends of valid date range.
  }
  return false; 
}
///////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////// output /////////////////////////////////////////////////
// Output the currently selected month and day to the user. 
void Date::output()
{
  cout << "\nYour chosen appointment date is: " << month << "/" << day << "/" << "2020 (Month/Day/Year)\n\n" << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////appointmentPrompt///////////////////////////////////////////
void Date::appointmentPrompt()
{
  //Asks user if they would like to view booked and free appointment slots (for that day)
  int appointmentloop = 0;
  do {
    //Initialize local variable to use within loop
    int x;

    //Prompts user to input a selection
    cout << "Enter '1' to view all available appointment times.\n" << "Enter '2' to view already booked appointment times.\n" << "Enter '3' to proceed to selecting your desired time.\n";
    cin >> x;

    if(x == 1) { //prints out all time slots that are free
      Date::printFreeTimeSlots(appointed);
    }
    else if(x == 2) { //prints out all time slots that are booked
      Date::printAppointedTimeSlots(appointed);
    }
    else if(x == 3) { //Breaks while loop and continues onto next section to select time
      break;
    }
  } while(appointmentloop == 0); //keeps loop infinitely running until user 'breaks' out (3rd option)
}
///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////printFreeTimeSlots/////////////////////////////////////////
void Date::printFreeTimeSlots(bool appointed[48])
{
  int start = 0, c = 0;
  for(int i = 0; i < 48; i++) {
    if(appointed[i] == 0 && c % 2 == 0) {
      cout << start << ":00 - " << start << ":30" << endl; 
    }
    else if(appointed[i] == 0 && c % 2 == 1) {
      cout << start << ":30 - " << start + 1 << ":00" << endl;
    }
    if(c % 2 == 1) {
      start++;
    }
    c++;
  } 
}
///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////printAppointedTimeSlots/////////////////////////////////////
void Date::printAppointedTimeSlots(bool appointed[48])
{
  int start = 0, c = 0;
  for(int i = 0; i < 48; i++) {
    if(appointed[i] == 1 && c % 2 == 0) {
      cout << start << ":00 - " << start << ":30" << endl; 
    }
    else if(appointed[i] == 1 && c % 2 == 1) {
      cout << start << ":30 - " << start + 1 << ":00" << endl;
    }
    if(c % 2 == 1) {
      start++;
    }
    c++;
  } 
}
///////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////// friend function ///////////////////////////////////////////
bool equal(Date &date1, Date &date2) {
  bool equality;
  if((date1.month == date2.month) && (date1.day == date2.day)) {
    equality = true;
  }
  else {
    equality = false;
  }
  return equality;
}
///////////////////////////////////////////////////////////////////////////////////////////////////