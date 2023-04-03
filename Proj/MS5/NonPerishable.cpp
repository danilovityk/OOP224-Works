/*
|||   Final Project Milestone 5/1
|||   Module: Whatever
|||   Filename: NonPerishable.cpp
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
#include "NonPerishable.h"
#include "POS.h"

namespace sdds {

char NonPerishable::ItemType() const {
    return 'N';
}

std::ostream &NonPerishable::write(std::ostream &ostr) const {
    
    if (*this){
        
        Item::write(ostr);
        if (m_flag == POS_LIST) ostr << "     N / A   |";
        if (m_flag == POS_FORM) ostr << "=============^" << std::endl;
        
    }
    
    return  ostr;
}



}




