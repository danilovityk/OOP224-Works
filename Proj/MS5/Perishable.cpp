/*
|||   Final Project Milestone 5/1
|||   Module: Whatever
|||   Filename: Perishable.cpp
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
#include "Perishable.h"
using namespace std;

namespace sdds{

char Perishable::ItemType() const {
    return 'P';
}

std::istream &Perishable::read(std::istream &istr) {
    
    Item::read(istr);
    
    if (!istr.fail() && *this){
        
        Date local;
        local.dateOnly(true);
        
        cout << "Expiry date (YYYY/MM/DD)\n" << "> ";
        
        istr >> local;
        
        if(local){
            m_date = local;
        }else{
            m_error = local.error();
        }
        
    }
    
    return istr;
}

std::ostream &Perishable::write(std::ostream &ostr) const {
    
    Item::write(ostr);
    
    
    if (*this){
        if (m_flag == POS_LIST) ostr << "  " << m_date << " |";
        if (m_flag == POS_FORM) ostr << "Expiry date: " << m_date << "\n=============^" << endl;

    }
    
    
    return ostr;
}

std::ifstream &Perishable::load(std::ifstream &ifstr) {
    
    Item::load(ifstr);
    
    if (!ifstr.fail() && *this){
        
        Date local;
        local.dateOnly(true);
        
        ifstr.ignore();
        
        ifstr >> local;
        
        if(local)
        {
            m_date = local;
        }else
        {
            m_error = local.error();
        }
    }
    
   
    return ifstr;
}

std::ofstream &Perishable::save(std::ofstream &ofstr) const {
    
    
    
    Item::save(ofstr);
    
    if(*this){
        ofstr << ',' << m_date;
        
    }
    
    return ofstr;
}



}




