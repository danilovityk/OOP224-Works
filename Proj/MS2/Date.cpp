#include <iostream>
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

int Date::uniqueDateValue(int year, int mon, int day, int hour, int min) {
    
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
                        m_error = "Invalid Minute";
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

bool Date::operator==(const sdds::Date &date) const {
    <#code#>;
}

bool Date::operator!=(const sdds::Date &date) const {
    <#code#>;
}

bool Date::operator<(const sdds::Date &date) const {
    <#code#>;
}

bool Date::operator>(const sdds::Date &date) const {
    <#code#>;
}

bool Date::operator<=(const sdds::Date &date) const {
    <#code#>;
}

bool Date::operator>=(const sdds::Date &date) const {
    <#code#>;
}


sdds::Date &Date::dateOnly(bool dateOnly) {
    <#code#>;
}

Date::operator bool() const {
    <#code#>;
}

sdds::Error &Date::error() const {
    <#code#>;
}


}


