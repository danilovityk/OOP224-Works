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
