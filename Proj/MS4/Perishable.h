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
