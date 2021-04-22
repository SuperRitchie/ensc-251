//header file time.hpp to declare your class
class TimeRange 
{
  private:
  //Initialize and declare variables
  int beginHour;
  int beginMinute;
  int endHour;
  int endMinute;

  public:
  //Constructors
  TimeRange();

  //Function declaration
  bool isValid(int beginHour, int beginMinute, int endHour, int endMinute);
  void output();
  void timeCheck(int abeginHour, int abeginMinute, int aendHour, int aendMinute);

  //Get and set for taking private variables into public
  void setbeginHour(int beginHour);
  void setbeginMinute(int beginMinute);
  void setendHour(int endHour);
  void setendMinute(int endMinute);
    
  int getbeginHour();
  int getbeginMinute();
  int getendHour();
  int getendMinute();

  void displayAppointed();
};