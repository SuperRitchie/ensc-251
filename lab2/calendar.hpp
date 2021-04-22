#include "date.hpp"
#include "time.hpp"
 
class Calendar
{
  private:
  //private variables
  int calMonth;
  int calDay;

  public:
  //public calendar variables
  int dateNumber = 0;
  int startingHours[72][48], startingMinutes[72][48], endingHours[72][48], endingMinutes[72][48];

  //Constructors
  Calendar();

  //Main functions
  void book(Date &date, TimeRange &time);
  void query(Date &date, TimeRange &time);
  void del(Date &date, TimeRange &time);
  bool alreadyBooked(Date &date, TimeRange &time);
  
  void calCheck(Date &date, int aMonth, int aDay);
  void displayAppointed(int dateNumber);
  void appointmentPrompt(Date &date);
  void printFreeTimeSlots(Date date[]);

  //setters
  void setcalMonth(int calMonth);
  void setcalDay(int calDay);


  //getters
  int getcalMonth();
  int getcalDay();
};