/*
|||   Final Project Milestone 5/1
|||   Module: PosIO
|||   Filename: PosIO.h
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


#ifndef POSIO_H
#define POSIO_H

#include <iostream>
namespace sdds{

class PosIO{
    
public:
    virtual std::ostream& write(std::ostream& ostr) const = 0;
    virtual std::istream& read(std::istream& istr) = 0;
    virtual std::ofstream& save(std::ofstream& ofstr) const = 0;
    virtual std::ifstream& load(std::ifstream& ifstr) = 0;
};

std::ostream& operator<<(std::ostream& ostr, const PosIO& pos);
std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& pos);

std::istream& operator>>(std::istream& istr, PosIO& pos);
std::ifstream& operator>>(std::ifstream& ifstr, PosIO& pos);
}




#endif
