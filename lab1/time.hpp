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

  //Get and set for taking private variables into public
  bool isValid(int beginHour, int beginMinute, int endHour, int endMinute);
  void output();

  //Get and set for taking private variables into public
    void setbeginHour(int beginHour);
    void setbeginMinute(int beginMinute);
    void setendHour(int endHour);
    void setendMinute(int endMinute);
    
    int getbeginHour();
    int getbeginMinute();
    int getendHour();
    int getendMinute();
};