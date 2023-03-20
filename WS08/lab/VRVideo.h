#ifndef VRVIDEO_H
#define VRVIDEO_H

#include "Video.h"

namespace sdds{

class VRVideo : public Video{
    
    char* m_equipment;
    
public:
    VRVideo();
    VRVideo(int length, const char* name);
    ~VRVideo();
    void load(std::istream& istr);
    std::ostream& play(std::ostream& ostr) const;
    
    
    
};


}


#endif
