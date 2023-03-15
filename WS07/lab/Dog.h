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

#ifndef SDDS_DOG_H
#define SDDS_DOG_H

#include "Pet.h"


namespace sdds
{

class Dog : public Pet {
  
private:
    const double COST_DOG        = 4.00;        // Fee: Initial purchase
    const double COST_FEED        = 0.25;        // Fee: For each feeding
    const double COST_REVIVE      = 1.0;        // Fee: Respawn if
    const double COST_CREATION = COST_DOG + COST_BASE;
    
    int m_numWalks;
    
public:
    Dog(const char* name, int age = 0, int m_numWalks = 0);
    void feed();
    void reSpawn();
    void operator++(int num);
    Dog& operator=(const Dog& rhs);
    void walk();
    std::ostream& outputData(std::ostream& os);
    
};
std::ostream& operator<<(std::ostream& os, Dog& dog);
}

#endif
