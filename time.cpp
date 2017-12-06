#include "time.h"

using namespace std;

//Pre: None
//Post: Creates a time with default values for data members.
Time::Time() {
  hour = 0;
  minutes = 0;
  curr_time_min = (hour * 60) + minutes;
}

//Pre: 0 <= hour <= 23 and 0 <= min <= 59.
//Post: Creates a time with the given hour and minute.
Time::Time(int hour, int min) throw (logic_error) {                   // the throw logic error isnt working, This might be a compiler problem
  if(hour<=0 || hour>=23){
    throw logic_error("Hour has to be between 0 and 23");
  }
  if(min<=0 || min>=59){
    throw logic_error("Minute has to be between 0 and 59");
  }
  this -> hour = hour;
  this -> minutes = min;
  curr_time_min = (hour * 60) + minutes;
}

//Assignment operator
//Pre: None
//Assigns other to a Time object
void Time::operator = ( const Time &other){
    hour = other.hour;
    minutes = other.minutes;
}

//Pre: None
//Post: Returns the difference in minutes between t1 and t2. Assumes t2 is between 00:00 and 23:59 hours after t1.
int Time::elapsedMin(Time t1, Time t2){
  int min_elasped;
  min_elasped = (t2.hour * 60 + t2.minutes)-(t1.hour * 60 + t1.minutes);
  if(min_elasped < 0) {
    min_elasped = -1 * min_elasped;
  }
  return min_elasped;
}

//Pre: Non
//Post: Returns a string containing the hour and minute (e.g., “13:01”).
string Time::toString(){
  string the_time;
  string str_hr = to_string(hour);
  string str_min = to_string(minutes);
  the_time = str_hr + ":" + str_min;
  return the_time;
}
