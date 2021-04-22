#include "date.hpp"
#include "time.hpp"
#include <iostream>
using namespace std;

int main()
{ 
  //Initialize variables for user inputs
  int aMonth, aDay;
  int abeginHour, abeginMinute;
  int aendHour, aendMinute;

  //Initialize bool type variables for new date prompt and error prompts
  bool confirmPrompt = true;
  bool flag = true;
  string confirm;

  cout << "Lab assignment 1: You will now be prompted to specify a date for your appointment.\n\n";

////////////////////////////////////////////////////////////////////////////////////////////////////////
  //DATE 1
  cout << "\nDate 1:";

  //Creating class object for certain date entry
  Date date1; //calls to default constructor in Date class
  
  //Prompt user to input desired date values
  cout << "\nNote: Valid range is from September.8 to December.20";
  cout << "\nPlease input desired month, in number form (eg. January = 1, February = 2, etc.): ";
  cin >> aMonth;
  cout << "Please input desired day of the month. (Note: Holidays and Weekends are not available): ";
  cin >> aDay;

  //Calls and runs isValid, isHoliday, and isWeekend member functions and checks if the are true/false
  while(flag) {
    if(date1.isValid(aMonth, aDay) && !date1.isHoliday(aMonth, aDay) && !date1.isWeekend(aMonth, aDay)) {
      date1.setMonth(aMonth); //set user inputted month in date1
      date1.setDay(aDay); //set user inputted day in date1
      break;
    }
    else { //Prompts user to re-input new values
      cout << "\nPlease re-enter a valid date below:";
      cout << "\nMonth: ";
      cin >> aMonth;
      cout << "Day: ";
      cin >> aDay;
    }
  }
  
  date1.output(); //Calls to output function; prints out selected date to user.
  date1.appointmentPrompt(); //Calls to prompt function; asks user if they would like to view all time slots.

  //TIME 1
  //Prompt user to input desired date values
  cout << "\nPlease enter a starting time range in the 24hr format (hh mm)\n";
  cin >> abeginHour >> abeginMinute;
  cout << "Please enter the end time for the appointment" << endl;
  cin >> aendHour >> aendMinute;

  TimeRange time1; //calls to default constructor in time class, creates time1 object

  while(flag) {
    if(time1.isValid(abeginHour, abeginMinute, aendHour, aendMinute)) {
      time1.setbeginHour(abeginHour); //set user inputted start-hour in time1
      time1.setbeginMinute(abeginMinute); //set user inputted start-minutein time1
      time1.setendHour(aendHour); //set user inputted end-hour in time1
      time1.setendMinute(aendMinute); //set user inputted end-minute in time1
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
  
  time1.output();  // Calls to the TimeRange output function and displays values.
////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Prompt to ask user if they would like to enter another date
  do 
  {
    cout << "\n\nWould you like to enter a second date? (Y/N)\n";
    cin >> confirm;

    if(confirm == "Y" || confirm == "y") {
      break;
    }
    else if(confirm == "N" || confirm == "n") {
      return 0;
    }
  } while(confirmPrompt == true);
////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////
  //DATE 2
  cout << "\nDate 2:";
  
  //Creating class object for certain date entry
  Date date2; //calls to default constructor in Date class

  //Prompt user to input desired date values
  cout << "\nNote: Valid range is from September.8 to December.20";
  cout << "\nPlease input desired month, in number form (eg. January = 1, February = 2, etc.): ";
  cin >> aMonth;
  cout << "Please input desired day of the month. (Note: Holidays and Weekends are not available): ";
  cin >> aDay;

  //Calls and runs isValid, isHoliday, and isWeekend member functions and checks if the are true/false
  while(flag) {
    if(date2.isValid(aMonth, aDay) && !date2.isHoliday(aMonth, aDay) && !date2.isWeekend(aMonth, aDay)) {
      date2.setMonth(aMonth); //set user inputted month in date1
      date2.setDay(aDay); //set user inputted day in date1
      break;
    }
    else { //Prompts user to re-input new values
      cout << "\nPlease re-enter a valid date below:";
      cout << "\nMonth: ";
      cin >> aMonth;
      cout << "Day: ";
      cin >> aDay;
    }
  }

  date2.output(); //Calls to output function; prints out selected date to user.
  date2.appointmentPrompt(); //Calls to prompt function; asks user if they would like to view all time slots.

  //TIME 2
  //Prompt user to input desired date values
  cout << "\nPlease enter a starting time range in the 24hr format (hh mm)\n";
  cin >> abeginHour >> abeginMinute;
  cout << "Please enter the end time for the appointment" << endl;
  cin >> aendHour >> aendMinute;

  TimeRange time2; //calls to default constructor in time class, creates time1 object

  while(flag) {
    if(time2.isValid(abeginHour, abeginMinute, aendHour, aendMinute)) {
      time2.setbeginHour(abeginHour); //set user inputted start-hour in time1
      time2.setbeginMinute(abeginMinute); //set user inputted start-minutein time1
      time2.setendHour(aendHour); //set user inputted end-hour in time1
      time2.setendMinute(aendMinute); //set user inputted end-minute in time1
      break;
    }
    else { //Prompts user to re-input new values
      cout << "\n Please re-enter a valid time below:\n";
      cout << "\nBeginning time: ";
      cin >> abeginHour >> abeginMinute;
      cout << "\nEnding time: ";
      cin >> aendHour >> aendMinute;
    }
  }
  
  time2.output();  // Calls to the TimeRange output function and displays values.
////////////////////////////////////////////////////////////////////////////////////////////////////////
  

////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Calling the friend 'equal' function to check if two dates are equal, the friend function returns a boolean
  if(equal(date1, date2) == 1) //if both dates inputted are the same
  {
    cout << "\n\nDate 2 is equal to Date 1.\n";
  }
  else //if they are different
  {
    cout << "\n\nThe dates differ.\n";
  }
  return 0;
////////////////////////////////////////////////////////////////////////////////////////////////////////
}