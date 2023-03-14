#ifndef SDDS_DOG_H
#define SDDS_DOG_H

#include "Pet.h"


namespace sdds
{

class Dog : Pet {
  
private:
    const double COST_DOG        = 4.00;        // Fee: Initial purchase
    const double COST_FEED        = 0.25;        // Fee: For each feeding
    const double COST_REVIVE      = 1.0;        // Fee: Respawn if
    const double CLONE_PRICE = COST_DOG + COST_BASE;
    
public:
    Dog(const char* name, int age = 0);
    void feed();
    void reSpawn();
    void operator++(int num);
    Dog& operator=(const Dog& rhs);
    
};

}

#endif
