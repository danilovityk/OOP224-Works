/*
 *         Name: Danylo Vityk
 *         Email: dvityk@myseneca.ca
 *         Sudent ID: 176326213
 *         Date: Mar 15, 2023
 *
 *
 *         I have done all the coding by myself and only copied the code that my professor provided to complete my workshops
 *         and assignments.
 *
 *
 */

#ifndef SDDS_FISH_H
#define SDDS_FISH_H

#include "Pet.h"


namespace sdds
{

class Fish : public Pet {
  
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
