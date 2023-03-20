#include <iostream>
#include "Media.h"

using namespace std;

namespace sdds{

ostream& operator<<(ostream& ostr, const Media& media){
    media.play(ostr);
    
    return ostr;
}
istream& operator>>(istream& istr, Media& media){
    media.load(istr);
    
    return istr;
}

}
