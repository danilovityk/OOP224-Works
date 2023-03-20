#ifndef ANIMATION_H
#define ANIMATION_H

#include "Video.h"

namespace sdds{

class Animation : public Video{
    
    int m_dimension;
    
public:
   
    Animation();
    
    Animation(int length, int dimension);
    
    
    void load(std::istream& istr);
    std::ostream& play(std::ostream& ostr) const;
    
    
    
};


}


#endif
