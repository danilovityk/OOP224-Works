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




