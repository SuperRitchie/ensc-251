#include "calendar.hpp"
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////
// NOTES:
// -overload operators
// -print all free day/time slots as an option in the menu
// then we are DONE!!!!!







/////////////////////////////////// constructor definition ////////////////////////////////////////
Calendar::Calendar()
{
  //array initialization for time
  for(int i = 0; i < 72; i++) {
    for(int j = 0; j < 48; j++) {
      startingHours[i][j] = -1;
      startingMinutes[i][j] = -1;
      endingHours[i][j] = -1;
      endingMinutes[i][j] = -1;
    }
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
// set statements
void Calendar::setcalMonth(int aMonth)
{
  calMonth = aMonth;
}

void Calendar::setcalDay(int aDay)
{
  calDay = aDay;
}

// get statements
int Calendar::getcalMonth()
{
  return calMonth;
}

int Calendar::getcalDay()
{
  return calDay;
}
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////// book /////////////////////////////////////////////////
void Calendar::book(Date &date, TimeRange &time)
{
  int start = time.getbeginHour() * 2;
  int end = time.getendHour() * 2;
  if(time.getbeginMinute() == 30) {
    start++;
  }
  if(time.getendMinute() == 30) {
    end++;
  }
  for(int i = start; i < end; i++) {
    date.setAppointed(i);
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////// query //////////////////////////////////////////////////
// Searches all dates for specified month. Functions returns if it is booked or not.
void Calendar::query(Date &date, TimeRange &time) 
{
  bool part = false, full = true;
  int start = time.getbeginHour() * 2;
  int end = time.getendHour() * 2;
  if(time.getbeginMinute() == 30) {
    start++;
  }
  if(time.getendMinute() == 30) {
    end++;
  }
  
  for(int i = start; i < end; i++) {
    if(!date.getAppointed(i)) {
      full = false;
    }
    else if(date.getAppointed(i))
    {
      part = true;
    } 
  }
  
  if(full) {
    cout << "\nAll time slots are booked for this time range.\n";
  }
  else if(part && !full) {
    cout << "\nTime slots are partially booked for this time range.\n";
  }
  else {
    cout << "\nAll of the selected time slots are free.\n";
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////// delete /////////////////////////////////////////////////////
void Calendar::del(Date &date, TimeRange &time) {
  bool run = false;
  bool startingTime = false, endingTime = false;
  int start = time.getbeginHour() * 2;
  int end = time.getendHour() * 2;
  int delI;
  if(time.getbeginMinute() == 30) {
    start++;
  }
  if(time.getendMinute() == 30) {
    end++;
  }
  
  for(int i = 0; i < 48; i++) {
    if(startingHours[dateNumber][i] == time.getbeginHour() && startingMinutes[dateNumber][i] == time.getbeginMinute() && endingHours[dateNumber][i] == time.getendHour() && endingMinutes[dateNumber][i] == time.getendMinute()) {
      startingTime = true;
      endingTime = true;
      delI = i;
    }
  }
  if(startingTime && endingTime) {
    run = true;
  }
  cout << endl;
  if(run) {
    startingHours[dateNumber][delI] = -1;
    endingHours[dateNumber][delI] = -1;
    for(int i = start; i < end; i++) {
      date.delAppointed(i);
    }
    cout << "The appointment has been deleted.\n";
  }
  else {
    cout << "You did not select a valid appointment to delete.\n";
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////// printFreeTimeSlots /////////////////////////////////////////
// Function that prints the valid days of the month
void Calendar::printFreeTimeSlots(Date date[72])
{
  bool first;
  const int thanksgiving = 24, remembrance = 45;
  int displayDay = 8;
  int start, end, fiveCount = 1;
  for(int i = 0; i < 72; i++) {
    first = false;
    if(fiveCount % 5 == 0) { //Resets 5 count to start of week, skips displayDay by 2 at end of week.
      displayDay += 2;
      fiveCount = 0;
    }
    
    //const HOLIDAYS
    if(i == thanksgiving) { //Skips Thanksgiving holiday
      displayDay += 1;
      fiveCount += 1;
    }
    if(i == remembrance) { //Skips Remembrance holiday
      displayDay += 1;
      fiveCount += 1;
    }

    if(i == 17) { //Resets to start of October
      displayDay = 1;
      fiveCount = 3;
    }
    else if(i == 38) { //Resets to start of November
      displayDay = 2;
      fiveCount = 0;
    }
    else if(i == 58) { //Resets to start of December
      displayDay = 1;
      fiveCount = 1;
    }

    //date outputs
    if(i < 17) { //September
      cout << "September " << displayDay;
    }
    else if(i >= 17 && i < 38) { //October
      cout << "October " << displayDay;
    }
    else if(i >= 38 && i < 58) { //November
      cout << "November " << displayDay;
    }
    else if(i >= 58 && i < 72) { //December
      cout << "December " << displayDay;
    }
    displayDay++;
    fiveCount++;
    cout << "\n";
    
    for(int j = 0; j < 48; j++) {
      if(!date[i].getAppointed(j) && !first) {
        start = j;
        end = j;
        first = true;
      }
      if(!date[i].getAppointed(j) && first) {
        end++;
      }
      if((date[i].getAppointed(j) && first) || j == 47) {
        first = false;
        if(start % 2 == 1) {
          cout << start/2 << ":30";
        }
        else {
          cout << start/2 << ":00";
        }
        cout << " - ";
        if(end % 2 == 1) {
          cout << end/2 << ":30";
        }
        else {
          cout << end/2 << ":00";
        }
        cout << ", ";
      }
    }
    cout << "\n---------------------------\n";
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////// calCheck ////////////////////////////////////////////////
// Runs user inputted month and day through all the error checks.      
void Calendar::calCheck(Date &date, int aMonth, int aDay)
{ 
  bool flag = true; //used for while loop

  //Calls and runs isValid, isHoliday, and isWeekend member functions and checks if the are true/false
  while(flag) 
  {
    if(date.isValid(aMonth, aDay) && !date.isHoliday(aMonth, aDay) && !date.isWeekend(aMonth, aDay)) 
    {
      setcalMonth(aMonth); //set user inputted month in date1
      setcalDay(aDay); //set user inputted day in date1
      break;
    }
    else //Prompts user to re-input new values
    { 
      cout << "\nPlease re-enter a valid date below:";
      cout << "\nMonth: ";
      cin >> aMonth;
      cout << "Day: ";
      cin >> aDay;
    }
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////// displayAppointed ///////////////////////////////////////////
// Displays user set appointment times, in a list.
void Calendar::displayAppointed(int dateNumber) {
  int temp;

  cout << "\n---------------------------\n";

  // for loop that sorts the times in ascending order
  for(int i = 0; i < 48; i++)
	{		
		for(int j= i+1; j < 48; j++)
		{
			if(startingHours[dateNumber][i] > startingHours[dateNumber][j])
			{
				temp = startingHours[dateNumber][i];
				startingHours[dateNumber][i] = startingHours[dateNumber][j];
				startingHours[dateNumber][j] = temp;

        temp = startingMinutes[dateNumber][i];
				startingMinutes[dateNumber][i] = startingMinutes[dateNumber][j];
				startingMinutes[dateNumber][j] = temp;

        temp = endingHours[dateNumber][i];
				endingHours[dateNumber][i] = endingHours[dateNumber][j];
				endingHours[dateNumber][j] = temp;

        temp = endingMinutes[dateNumber][i];
				endingMinutes[dateNumber][i] = endingMinutes[dateNumber][j];
				endingMinutes[dateNumber][j] = temp;
			}
		}
	}
  for(int i = 0; i < 48; i++)
	{		
		for(int j= i+1; j < 48; j++)
		{
			if(startingMinutes[dateNumber][i] > startingMinutes[dateNumber][j])
			{
				temp = startingHours[dateNumber][i];
				startingHours[dateNumber][i] = startingHours[dateNumber][j];
				startingHours[dateNumber][j] = temp;

        temp = startingMinutes[dateNumber][i];
				startingMinutes[dateNumber][i] = startingMinutes[dateNumber][j];
				startingMinutes[dateNumber][j] = temp;

        temp = endingHours[dateNumber][i];
				endingHours[dateNumber][i] = endingHours[dateNumber][j];
				endingHours[dateNumber][j] = temp;

        temp = endingMinutes[dateNumber][i];
				endingMinutes[dateNumber][i] = endingMinutes[dateNumber][j];
				endingMinutes[dateNumber][j] = temp;
			}
		}
	}

  for(int i = 0; i < 48; i++) {
    if(startingHours[dateNumber][i] == -1) {
      continue;
    }

    if(startingHours[dateNumber][i] < 10) {
      cout << "0" << startingHours[dateNumber][i];
    }
    else {
      cout << startingHours[dateNumber][i];
    }

    cout << ":";

    if(startingMinutes[dateNumber][i] == 0) {
      cout << "00";
    }
    else {
      cout << "30";
    }

    cout << " - ";

    if(endingHours[dateNumber][i] < 10) {
      cout << "0" << endingHours[dateNumber][i];
    }
    else {
      cout << endingHours[dateNumber][i];
    }

    cout << ":";

    if(endingMinutes[dateNumber][i] == 0) {
      cout << "00";
    }
    else {
      cout << "30";
    }
    cout << endl;
  }
  cout << "---------------------------\n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////// appointmentPrompt //////////////////////////////////////////////
void Calendar::appointmentPrompt(Date &date)
{
  //Asks user if they would like to view booked and free appointment slots (for that day)
  int appointmentloop = 0;
  do {
    //Initialize local variable to use within loop
    int x;

    //Prompts user to input a selection
    cout << "\nEnter '1' to view all available appointment times.\n" << "Enter '2' to view already booked appointment times.\n" << "Enter '3' to proceed to selecting your desired time.\n";
    cin >> x;
    if(x == 1) { //prints out all time slots that are free
      date.printFreeTimeSlots();
    }
    else if(x == 2) { //prints out all time slots that are booked
      displayAppointed(dateNumber);
    }
    else if(x == 3) { //Breaks while loop and continues onto next section to select time
      break;
    };
  } while(appointmentloop == 0); //keeps loop infinitely running until user 'breaks' out (3rd option)
}
/////////////////////////////////////////////////////////////////////////////////////////////////// 


//////////////////////////////////////// alreadyBooked //////////////////////////////////////////////// 
bool Calendar::alreadyBooked(Date &date, TimeRange &time) {
  bool duplicate = false;
  int start = time.getbeginHour() * 2;
  int end = time.getendHour() * 2;
  if(time.getbeginMinute() == 30) {
    start++;
  }
  if(time.getendMinute() == 30) {
    end++;
  }
  for(int i = start; i < end; i++) {
    if(date.getAppointed(i)) {
      duplicate = true;
    }
  }
  if(duplicate) {
    cout << "\nAn appointment already exists within the selected time slot.\n";
    return true;
  }
  else {
    return false;
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////// 