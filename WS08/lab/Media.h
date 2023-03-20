#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>

namespace sdds{

class Media{
  
public:
//    play
//    Returns reference to ostream and receives a reference to ostream as an argument. This pure virtual function can not modify the current object.
    virtual std::ostream& play(std::ostream& ostr) const = 0;
    
//    load
//    Returns void and receives a reference to istream as an argument.
    virtual void load(std::istream& istr) = 0;

    virtual ~Media() = 0;
};

std::ostream& operator<<(std::ostream& ostr, const Media& media);
std::istream& operator>>(std::istream& istr, Media& media);

}




#endif
