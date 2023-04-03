/*
|||   Final Project Milestone 5/1
|||   Module: Date
|||   Filename: Date.cpp
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
#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;
namespace sdds{

void Date::getSystemDate(int &year, int &mon, int &day, int &hour, int &min, bool dateOnly) {
    
    time_t t = time(NULL);
          tm lt = *localtime(&t);
          day = lt.tm_mday;
          mon = lt.tm_mon + 1;
          year = lt.tm_year + 1900;
          if(dateOnly) {
             hour = min = 0;
          } else {
             hour = lt.tm_hour;
             min = lt.tm_min;
          }
}

int Date::uniqueDateValue(int year, int mon, int day, int hour, int min) const{
    
    return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
    
}

int Date::daysOfMonth(int year, int month) {
    
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
          int mon = month >= 1 && month <= 12 ? month : 13;
          mon--;
          return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    
}

void Date::validateDate() {
    if (m_year >= MIN_YEAR && m_year <= MAX_YEAR)
    {
        if(m_month >= 1 && m_month <= 12)
        {
            if(m_day >= 1 && m_day <= daysOfMonth(m_year, m_month))
            {
                if(m_hour >= 0 && m_hour <= 23)
                {
                    if(m_minute >= 0 && m_minute <= 59)
                    {
                        
                    }else
                    {
                        m_error = "Invlid Minute";
                    }
                }else
                {
                    m_error = "Invalid Hour";
                }
            }else
            {
                m_error = "Invalid Day";
            }
        }else
        {
            m_error = "Invalid Month";
        }
    }else
    {
        m_error = "Invalid Year";
    }
}


Date::Date() {
    m_dateOnly = false;
    getSystemDate(m_year, m_month, m_day, m_hour, m_minute, false);
}

Date::Date(const int &year, const int &month, const int &day) {
    m_year = year;
    m_month = month;
    m_day = day;
    m_dateOnly = true;
    m_hour = 0;
    m_minute = 0;
    validateDate();
}

Date::Date(const int &year, const int &month, const int &day, const int &hour, const int &minute) {
    m_year = year;
    m_month = month;
    m_day = day;
    m_dateOnly = false;
    m_hour = hour;
    m_minute = minute;
    validateDate();
}

Date& Date::operator=(const Date& date){
    m_year = date.m_year;
    m_month = date.m_month;
    m_day = date.m_day;
    m_dateOnly = date.m_dateOnly;
    m_hour = date.m_hour;
    m_minute = date.m_minute;
    
    return *this;
}

bool Date::operator==(const sdds::Date &date) const {
    return (uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute)) == (uniqueDateValue(date.m_year, date.m_month, date.m_day, date.m_hour, date.m_minute));
}

bool Date::operator!=(const sdds::Date &date) const {
    return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) != uniqueDateValue(date.m_year, date.m_month, date.m_day, date.m_hour, date.m_minute);
}

bool Date::operator<(const sdds::Date &date) const {
    return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) < uniqueDateValue(date.m_year, date.m_month, date.m_day, date.m_hour, date.m_minute);
}

bool Date::operator>(const sdds::Date &date) const {
    return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) > uniqueDateValue(date.m_year, date.m_month, date.m_day, date.m_hour, date.m_minute);
}

bool Date::operator<=(const sdds::Date &date) const {
    return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) <= uniqueDateValue(date.m_year, date.m_month, date.m_day, date.m_hour, date.m_minute);
}

bool Date::operator>=(const sdds::Date &date) const {
    return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) >= uniqueDateValue(date.m_year, date.m_month, date.m_day, date.m_hour, date.m_minute);
}


Date& Date::dateOnly(bool dateOnly) {
    m_dateOnly = dateOnly;
    
    if(dateOnly == true)
    {
        m_hour = 0;
        m_minute = 0;
    }
    
    return *this;
}

Date::operator bool() const {
    return !m_error;
}

const Error &Date::error() const {
    return m_error;
}



std::ostream& Date::display(std::ostream& ostr) const
{
    ostr.unsetf(ios::left);
    ostr.setf(ios::right);
    if(*this){
        
        if (m_dateOnly)
        {
            ostr << m_year << "/";
            if (m_month < 10) ostr << "0";
            ostr << m_month << "/" << setfill('0') << setw(2) << m_day;
        }else
        {
            ostr << m_year << "/";
            if (m_month < 10) ostr << "0";
            ostr << m_month << "/" << setfill('0') << setw(2) << m_day << ", " << setw(2) <<  m_hour << ":" << setw(2) << m_minute;
        }
        
    }else
    {
        if (m_dateOnly){
            ostr << m_error << "(" << m_year << "/";
            if (m_month < 10) ostr << "0";
            ostr << m_month << "/" << setfill('0') << setw(2) << m_day << ")";
        }else{
            ostr << m_error << "(" << m_year << "/";
            if (m_month < 10) ostr << "0";
            ostr << m_month << "/" << setfill('0') << setw(2) << m_day << ", " << setw(2) << m_hour << ":" << setw(2)  << m_minute << ")";
        }
        
        
    }
    
    ostr.unsetf(ios::right);
    ostr.setf(ios::left);
    return ostr;
}

void Date::clearDate()
{
    m_year = 0;
    m_month = 0;
    m_day = 0;
    m_hour = 0;
    m_minute = 0;
}

std::istream& Date::read(std::istream& istr){
    
    m_error.clear();
    clearDate();
    //m_dateOnly = false;
    istr >> m_year;
    if(!istr.fail()){
        istr.ignore();
        istr >> m_month;
        if(!istr.fail()){
            istr.ignore();
            istr >> m_day;
            if(!istr.fail()){
                if(!m_dateOnly){
                    istr.ignore();
                    istr >> m_hour;
                    if(!istr.fail()){
                        istr.ignore();
                        istr >> m_minute;
                        if (istr.fail()){m_error = "Cannot read minute entry";}else {validateDate();}
                    }else{m_error = "Cannot read hour entry"; }
                }else{validateDate();}
            }else{m_error = "Cannot read day entry";}
        }else{m_error = "Cannot read month entry";}
    }else{m_error = "Cannot read year entry";}
   
    return istr;
}


std::ostream& operator<<(std::ostream& ostr,const Date& date)
{
    return date.display(ostr);
}

std::istream& operator>>(std::istream& istr, Date& date){
    date.read(istr);
    return istr;
}


}


