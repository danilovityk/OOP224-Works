/*
|||   Final Project Milestone 5/1
|||   Module: Whatever
|||   Filename: PosIO.cpp
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
#include <fstream>
#include "PosIO.h"

using namespace std;

namespace sdds{

std::ostream& operator<<(std::ostream& ostr, const PosIO& pos){
    pos.write(ostr);
    return ostr;
}
std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& pos){
    pos.save(ofstr);
    return ofstr;
}

std::istream& operator>>(std::istream& istr, PosIO& pos){
    pos.read(istr);
    return istr;
}
std::ifstream& operator>>(std::ifstream& ifstr, PosIO& pos){
    pos.load(ifstr);
    return ifstr;
}

}
