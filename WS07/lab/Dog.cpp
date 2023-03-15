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

#include <iostream>
#include "Dog.h"

using namespace std;
namespace sdds{

Dog::Dog(const char *name, int age, int numWalks) : Pet::Pet(name, age, COST_BASE), m_numWalks(numWalks){}

void Dog::feed(){
    
    Pet::feed();
    if(isAlive()){
        addCharge(COST_FEED);
        
    }
}

void Dog::reSpawn() {
    Pet::reSpawn();
    m_numWalks = 0;
    addCharge(COST_REVIVE);
}

void Dog::operator++(int num) {
    if(isAlive()){
        //borrowed from WS07 pdf file
        double healthDelta = 0;
              healthDelta += 0.15 * (getHugs()   - 1);
              healthDelta += 0.10 * (getFeeds()  - 2);
              healthDelta += 0.10 * (getGrooms() - 1);
              healthDelta += 0.20 * (m_numWalks  - 2);
        
        //end of borrowed code
        applyHealthDelta(healthDelta);
    }
    
    Pet::operator++(num);
    m_numWalks = 0;
}

sdds::Dog &Dog::operator=(const sdds::Dog &rhs) {
    if(this != &rhs){
        Pet::operator=(rhs);
        addCharge(COST_DOG * 2);
        m_numWalks = rhs.m_numWalks;
    }
    return *this;
    
}

void Dog::walk(){
    if(isAlive()){
        m_numWalks++;
    }
}

std::ostream& Dog::outputData(std::ostream& os){
    cout << "   Walks: " << m_numWalks << endl;
    Pet::outputData(os);
    
    return os;
}

std::ostream& operator<<(std::ostream& os, Dog& dog){
    os << "** Generic Dog **" << endl;
    dog.outputData(os);
    
    return os;
}


}







