#include "calendar.hpp"
#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////// MAIN FUNCTION /////////////////////////////////////////////
int main()
{
  cout << "\nLab assignment 2: For this lab, you will be prompted to specify and book a date for your appointment.\n";

  Calendar calendar; // Obj creation: calendar for use of book, query, and delete functions.
  Date date[72]; // Obj creation: 72 valid days.
  TimeRange time[72]; //Obj creation: 72 time objects for 72 valid days
  
  
  //Variable initialization
  int aMonth, aDay; //date variables for user inputs
  int abeginHour, abeginMinute; //start time variables for user inputs
  int aendHour, aendMinute; //end time variables for user inputs
  int menu, i = 0, createdDates = 0, timeStart = 0; //counters
  
  do 
  {
    cout << "\n---------------------------------------------------------\n"
        << "Book an Appointment!"
        << "\nEnter '1' to book a new date.\nEnter '2' to query a certain date.\n"
        << "Enter '3' to delete an appointment.\nEnter '4' to view ALL free time slots.\n"
        << "Enter '5' to end the program.\n";
    cin >> menu;
    if(menu == 1) 
    {

    // DATE:
      //Prompts for user to input desired date values
      cout << "\n(Note: Valid range is from September.8 to December.20)";
      cout << "\nPlease input desired month, in number form (eg. January = 1, February = 2, etc.): ";
      cin >> aMonth;
      cout << "Please input desired day of the month. (Note: Holidays and Weekends are not available): ";
      cin >> aDay;

      date[calendar.dateNumber].dateCheck(aMonth, aDay); //Calls to dateCheck function; checks if date is valid.
      date[calendar.dateNumber].output(); //Calls to output function; prints out selected date to user.
      
      for(int i = 0; i < createdDates; i++) //Searches through the date array if it is the same date
      {
        if(aMonth == date[i].getMonth() && aDay == date[i].getDay()) 
        {
          calendar.dateNumber = i;
          calendar.appointmentPrompt(date[calendar.dateNumber]); //Calls to prompt function; asks user if they would like to view all time slots.
          break;
        }
      }


    // TIME:
      //Prompt user to input desired date values
      cout << "\nPlease enter a starting time range in the 24hr format (hh mm)\n";
      cin >> abeginHour >> abeginMinute;
      cout << "Please enter the end time for the appointment" << endl;
      cin >> aendHour >> aendMinute;

      time[calendar.dateNumber].timeCheck(abeginHour, abeginMinute, aendHour, aendMinute); //checks if time is valid.
      time[calendar.dateNumber].output();  //Calls to the TimeRange output function and displays values.

      for(int  i = 0; i < 48; i++) {
        if(calendar.startingHours[calendar.dateNumber][timeStart] != -1) {
          timeStart++;
        }
      }

      //2d array: sets and saves user inputted time starts/ends to calendar
      if(!calendar.alreadyBooked(date[calendar.dateNumber], time[calendar.dateNumber]))
      {
        calendar.startingHours[calendar.dateNumber][timeStart] = time[calendar.dateNumber].getbeginHour();
        calendar.startingMinutes[calendar.dateNumber][timeStart] = time[calendar.dateNumber].getbeginMinute();
        calendar.endingHours[calendar.dateNumber][timeStart] = time[calendar.dateNumber].getendHour();
        calendar.endingMinutes[calendar.dateNumber][timeStart] = time[calendar.dateNumber].getendMinute();
        calendar.book(date[calendar.dateNumber], time[calendar.dateNumber]);
      }
      menu = 0;
    }
    else if(menu == 2) 
    {
      // DATE:
      //Prompts for user to input desired date values
      cout << "\n(Note: Valid range is from September.8 to December.20)";
      cout << "\nPlease input desired month, in number form (eg. January = 1, February = 2, etc.): ";
      cin >> aMonth;
      cout << "Please input desired day of the month. (Note: Holidays and Weekends are not available): ";
      cin >> aDay;

      date[calendar.dateNumber].dateCheck(aMonth, aDay); //Calls to dateCheck function; checks if date is valid.
      date[calendar.dateNumber].output(); //Calls to output function; prints out selected date to user.
      
      
      for(int i = 0; i < createdDates; i++) //Searches through the date array if it is the same date
      {
        if(aMonth == date[i].getMonth() && aDay == date[i].getDay()) 
        {
          calendar.dateNumber = i;
          //calendar.appointmentPrompt(date[calendar.dateNumber]); //Calls to prompt function; asks user if they would like to view all time slots.
          break;
        }
      } 
      // TIME:
      //Prompt user to input desired date values
      TimeRange queryInput;
      cout << "\nPlease enter a starting time range in the 24hr format (hh mm)\n";
      cin >> abeginHour >> abeginMinute;
      cout << "Please enter the end time for the appointment" << endl;
      cin >> aendHour >> aendMinute;

      queryInput.timeCheck(abeginHour, abeginMinute, aendHour, aendMinute); //checks if time is valid.
      queryInput.output();  //Calls to the TimeRange output function and displays values.
      calendar.query(date[calendar.dateNumber], queryInput);
      menu = 0;
    }
    else if(menu == 3) 
    {
      // DATE:
      //Prompts for user to input desired date values
      cout << "\n(Note: Valid range is from September.8 to December.20)";
      cout << "\nPlease input desired month, in number form (eg. January = 1, February = 2, etc.): ";
      cin >> aMonth;
      cout << "Please input desired day of the month. (Note: Holidays and Weekends are not available): ";
      cin >> aDay;

      date[calendar.dateNumber].dateCheck(aMonth, aDay); //Calls to dateCheck function; checks if date is valid.
      date[calendar.dateNumber].output(); //Calls to output function; prints out selected date to user.
      bool appointedCheck = false;
      for(int i = 0; i < createdDates; i++) //Searches through the date array if it is the same date
      {
        if(aMonth == date[i].getMonth() && aDay == date[i].getDay()) 
        {
          calendar.dateNumber = i;
          calendar.appointmentPrompt(date[calendar.dateNumber]); //Calls to prompt function; asks user if they would like to view all time slots.
          break;
        }
      }


    // TIME:
      //Prompt user to input desired date values
      TimeRange delInput;
      cout << "Please enter the starting time of the appointment to delete (hh mm)\n";
      cin >> abeginHour >> abeginMinute;
      cout << "Please enter the end time of the appointment" << endl;
      cin >> aendHour >> aendMinute;

      delInput.timeCheck(abeginHour, abeginMinute, aendHour, aendMinute); //checks if time is valid.
      delInput.output();  //Calls to the TimeRange output function and displays values.

      /*for(int  i = 0; i < 48; i++) {
        if(calendar.startingHours[calendar.dateNumber][timeStart] != -1) {
          timeStart++;
        }
      }
      */
      calendar.del(date[calendar.dateNumber], delInput);
      menu = 0;
    }
    else if(menu == 4)
    {
      calendar.printFreeTimeSlots(date);
      menu = 0;
    }
    else if(menu == 5) 
    {
      cout << "\nOK!\n";
      break;
    }
    createdDates++;
    calendar.dateNumber = createdDates;
    timeStart = 0;
  } while(menu == 0);
  return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
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
*/