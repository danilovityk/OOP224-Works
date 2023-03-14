#ifndef SDDS_FISH_H
#define SDDS_FISH_H

#include "Pet.h"


namespace sdds
{

class Fish : Pet {
  
private:
    const double COST_FISH        = 2.00;        // Fee: Initial purchase
    const double COST_FEED        = 0.10;        // Fee: For each feeding
    const double COST_REVIVE      = 0.5;        // Fee: Respawn if
    const double COST_CREATION = COST_FISH + COST_BASE;
    
public:
    Fish(const char* name, int age = 0);
    void feed();
    void reSpawn();
    void operator++(int num);
    Fish& operator=(const Fish& rhs);
    std::ostream& outputData(std::ostream& os);

};

std::ostream& operator<<(std::ostream& os, Fish& fish);
}

#endif
