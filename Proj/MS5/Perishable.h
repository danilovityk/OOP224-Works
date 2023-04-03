/*
|||   Final Project Milestone 5/1
|||   Module: Whatever
|||   Filename: Perishable.h
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

#ifndef Perishable_hpp
#define Perishable_hpp
#include "Item.h"
#include "Date.h"

namespace sdds{

class Perishable : public Item{
private:
    Date m_date;
public:
    char ItemType() const override;
    std::istream & read(std::istream &istr) override;
    std::ostream & write(std::ostream &ostr) const override;
    std::ifstream & load(std::ifstream &ifstr) override;
    std::ofstream & save(std::ofstream &ofstr) const override;
    
    
};

}
#endif /* Perishable_hpp */
