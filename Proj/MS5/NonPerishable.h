/*
|||   Final Project Milestone 5/1
|||   Module: Whatever
|||   Filename: NonPerishable.h
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

#ifndef NonPerishable_hpp
#define NonPerishable_hpp

#include "Item.h"

namespace sdds {

class NonPerishable : public Item{
    
public:
    char ItemType() const override;
    std::ostream& write(std::ostream &ostr) const override;
    
};


}



#endif /* Utils_cpp_NonPerishable_hpp */
