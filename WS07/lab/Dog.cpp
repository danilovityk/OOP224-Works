#include <iostream>
#include "Dog.h"

using namespace std;
namespace sdds{

Dog::Dog(const char *name, int age, int numWalks) : Pet::Pet(name, age, COST_CREATION), m_numWalks(numWalks){}

void Dog::feed(){
    
    Pet::feed();
    if(isAlive()){
        addCharge(COST_DOG);
        
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
}

sdds::Dog &Dog::operator=(const sdds::Dog &rhs) {
    if(this != &rhs){
        Pet::operator=(rhs);
        addCharge(COST_CREATION * 2);
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
    Pet::outputData(os);
    
    return os;
}

std::ostream& operator<<(std::ostream& os, Dog& dog){
    os << "** Generic Dog **" << endl;
    dog.outputData(os);
    
    return os;
}






    
}







