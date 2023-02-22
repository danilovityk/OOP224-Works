#include <iostream>
#include <iomanip>
#include "Bus.h"

using namespace std;
namespace sdds
{

Bus::Bus(int numberSeats, int numPassangers)
{
    
    m_numOfSeats = numberSeats;
    m_numOfPassangers = numPassangers;
    
    validateInput();
   
}

void Bus::validateInput()
{
    if (m_numOfSeats % 2 != 0 || m_numOfSeats > 40 || m_numOfSeats < 10 || m_numOfPassangers > m_numOfSeats || m_numOfPassangers < 0)
    {
        m_numOfSeats = -1;
        m_numOfPassangers = -1;
    }
}
 
void Bus::drawBus(int seats, int noOfPassengers, ostream& ostr) const
{
  int i, p;
  ostr.fill('_');
  ostr.width((seats / 2) * 3 + 4);
  ostr << "_";
  ostr << endl << "| ";
  for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
  ostr << "|_\\_" << endl;
  ostr << "| ";
  ostr.fill(' ');
  ostr.width(((seats / 2) * 3 - 14) / 2);
  ostr << " " << "Seneca College";
  ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
  ostr << " " << "    )" << endl;
  ostr << "`---OO";
  ostr.fill('-');
  ostr.width((seats / 2) * 3 - 5);
  ostr << "-" << "O---'" << endl;
}

std::ostream& operator<<(std::ostream& ostr, const Bus& bus)
{
    
    if(bus)
    {
        bus.drawBus(bus.m_numOfSeats, bus.m_numOfPassangers, ostr);
        ostr << "Total Fare Price: " << (double)bus;
        if ((double)bus == 0) ostr << ".00";
        ostr << endl;
    }else
    {
        ostr << "Out of service!" << endl;
    }
    return ostr;
}

istream& operator>>(istream& istr, Bus& right)
{
    istr >> right.m_numOfSeats;
    istr.ignore();
    
    istr >> right.m_numOfPassangers;
    right.validateInput();
    
    
    return istr;
}

Bus::operator bool () const
{
    bool result = false;
    if(m_numOfSeats != -1 || m_numOfPassangers != -1)
        result = true;
    
    return result;
}

Bus::operator int () const
{
    return m_numOfPassangers;
}

Bus::operator double() const
{

    return m_numOfPassangers != -1 ? ticketPrice * m_numOfPassangers : -1;
}

bool Bus::operator++()
{
    bool result = false;
    if(*this && m_numOfPassangers < m_numOfSeats)
    {
        result = true;
        m_numOfPassangers++;
    }
    
    return result;
}
bool Bus::operator--()
{
    bool result = false;
    if(*this && m_numOfPassangers > 0)
    {
        result = true;
        m_numOfPassangers--;
    }
    
    return result;
}

bool Bus::operator++(int)
{
    bool result = false;
    if(*this && m_numOfPassangers < m_numOfSeats)
    {
        result = true;
        m_numOfPassangers++;
    }
    
    return result;
}

bool Bus::operator--(int)
{
    bool result = false;
    if(*this && m_numOfPassangers > 0)
    {
        result = true;
        m_numOfPassangers--;
    }
    
    return result;
}


Bus& Bus::operator=(int value)
{
    m_numOfPassangers = -1;
    
    if (value < m_numOfSeats)
        m_numOfPassangers = value;
    
    validateInput();
    
    return *this;
}

Bus& Bus::operator+=(int value)
{
    
    if (*this){
        if((m_numOfPassangers + value) < m_numOfSeats)
        {
            m_numOfPassangers += value;
        }else
        {
            m_numOfSeats = -1;
            m_numOfPassangers = -1;
        }
            
    }
    
    return *this;
}

Bus& Bus::operator+=(Bus& right)
{
    if(right)
    {
        int spaceLeft = this->m_numOfSeats - this->m_numOfPassangers;
        
        if (spaceLeft <= right.m_numOfSeats)
        {
            this->m_numOfPassangers += spaceLeft;
            right.m_numOfPassangers -= spaceLeft;
        }else
        {
            this->m_numOfPassangers += right.m_numOfPassangers;
            right.m_numOfPassangers = 0;
        }
    }
    
    return *this;
}

bool Bus::operator==(Bus& right) const
{
    bool result = false;
    
    if(*this && right && this->m_numOfPassangers == right.m_numOfPassangers)
        result = true;
    
    return result;
}


int operator+(int left, const Bus& right)
{
    int value = 0;
    
    if(right)
    {
        value = left + (int)right;
    }
    else
    {
        value = left;
    }
    
    return value;
}


}
