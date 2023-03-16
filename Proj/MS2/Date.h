#ifndef DATE_H
#define DATE_H
#include <ctime>
#include "Error.h"

namespace sdds {

class Date{
  
private:
    
    int m_year, m_month, m_day, m_hour, m_minute;
    bool m_dateOnly;
    Error m_error;
    
public:

    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
    int uniqueDateValue(int year, int mon, int day, int hour, int min);
    int daysOfMonth(int year, int month);
    void validateDate();
    
    bool operator== (const Date& date) const;
    bool operator!= (const Date& date) const;
    bool operator< (const Date& date) const;
    bool operator> (const Date& date) const;
    bool operator<= (const Date& date) const;
    bool operator>= (const Date& date) const;
    
    Date();
    Date(const int& year, const int& month, const int& day);
    Date(const int& year, const int& month, const int& day, const int& hour, const int& minute);
    
    
    
};

}

#endif

