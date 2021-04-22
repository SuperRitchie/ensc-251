//header file date.hpp to declare your class
class Date
{
  private:
  //Initialize and declare variables
  int month;
  int day;
  bool appointed[48] = {0};
    
  public:
  //Constructors
  Date();
  
  //Function declaration
  bool isValid(int aMonth, int aDay);
  bool isHoliday(int aMonth, int aDay);
  bool isWeekend(int aMonth, int aDay);
  void output();
  //void appointmentPrompt();
  void printFreeTimeSlots();
  void printAppointedTimeSlots();
  void setAppointment(int beginHour, int beginMinute, int endHour, int endMinute);
  void dateCheck(int aMonth, int aDay);

  //friend function that will check if user inputted date is the same as what's already in date:private (2 dates)
  friend bool equal(Date &date1, Date &date2);

  //Get and set for taking private variables into public
  void setMonth(int month);
  void setDay(int day);
  void changeDate();
  bool getAppointed(int i);
  
  int getMonth();
  int getDay();
  void setAppointed(int i);
  void delAppointed(int i);
};