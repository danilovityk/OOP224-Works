/*
|||   Final Project Milestone 5/1
|||   Module: Date
|||   Filename: Date.h
|||   Version 1.0
|||   Author    Danylo Vityk
|||   Revision History
|||   -----------------------------------------------------------
|||   Date      Reason
|||   2020/?/?  Preliminary release
|||   2020/?/?  Debugged DMA
|||   -----------------------------------------------------------
|||   I have done all the coding by myself and only copied the code
|||   that my professor provided to complete my project milestones.
|||   -----------------------------------------------------------
*/

#ifndef DATE_H
#define DATE_H
#include <ctime>
#include "Error.h"
#include "POS.h"

namespace sdds {

class Date{
  
private:
    
    int m_year, m_month, m_day, m_hour, m_minute;
    bool m_dateOnly;
    Error m_error;
    
public:

    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
    int uniqueDateValue(int year, int mon, int day, int hour, int min) const;
    int daysOfMonth(int year, int month);
    void validateDate();
    
    bool operator== (const Date& date) const;
    bool operator!= (const Date& date) const;
    bool operator< (const Date& date) const;
    bool operator> (const Date& date) const;
    bool operator<= (const Date& date) const;
    bool operator>= (const Date& date) const;
    Date& operator =(const Date& date);
    
    Date();
    Date(const int& year, const int& month, const int& day);
    Date(const int& year, const int& month, const int& day, const int& hour, const int& minute = 0);
    
    Date& dateOnly(bool dateOnly);
    operator bool() const;
    const Error& error() const;

    std::ostream& display(std::ostream& ostr) const;
    std::istream& read(std::istream& istr);
    
    void clearDate();
    
};

std::ostream& operator<<(std::ostream& ostr,const Date& date);
std::istream& operator>>(std::istream& istr, Date& date);


}

#endif

