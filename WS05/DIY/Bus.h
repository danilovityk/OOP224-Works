/*
 *         Name: Danylo Vityk
 *         Email: dvityk@myseneca.ca
 *         Sudent ID: 176326213
 *         Date: Feb 21, 2023
 *
 *
 *         I have done all the coding by myself and only copied the code that my professor provided to complete my workshops
 *         and assignments.
 *
 *
 */

#ifndef BUS_H
#define BUS_H

const double ticketPrice = 125.34;

namespace sdds{


class Bus{
    
    int m_numOfSeats;
    int m_numOfPassangers;
    
    void drawBus(int seats, int noOfPassengers, std::ostream& ostr) const;
    friend std::ostream& operator<<(std::ostream& ostr, const Bus& bus);
    friend std::istream& operator>>(std::istream& istr, Bus& right);
    void validateInput();
public:
    Bus(int numberSeats = 20, int numPassangers = 0);
    operator bool() const;
    operator int() const;
    operator double() const;
    
    bool operator++();
    bool operator--();
    bool operator++(int);
    bool operator--(int);
    
    Bus& operator=(int value);
    Bus& operator+=(int value);
    Bus& operator+=(Bus& right);
    bool operator==(Bus& right) const;
    
};


std::ostream& operator<<(std::ostream& ostr, const Bus& bus);
std::istream& operator>>(std::istream& istr, Bus& right);
int operator+(int left, const Bus& right);
}

#endif
