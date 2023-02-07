#ifndef Tournament_hpp
#define Tournament_hpp

#include <iostream>
#include <stdio.h>
#include "Soccer.h"

namespace sdds{

class Tournament{
    
private:
    char* m_name;//points to a dynamically allocated Cstring
    int m_num;//size of the dynamically allocated array of soccer team. It should be more then zero.
    SoccerTeam* m_soccer = nullptr;//pointer to the dynamically allocated array of soccerTeam
    
public:
    
    
};


}
#endif /* Tournament_hpp */
