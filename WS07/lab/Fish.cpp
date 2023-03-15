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
#include "Fish.h"

using namespace std;
namespace sdds{

Fish::Fish(const char *name, int age) : Pet::Pet(name, age, COST_BASE){}

void Fish::feed(){
    
    Pet::feed();
    if(isAlive()){
        addCharge(COST_FISH);
        
    }
}

void Fish::reSpawn() {
    Pet::reSpawn();
    addCharge(COST_REVIVE);
}

void Fish::operator++(int num) {
    if(isAlive()){
        //borrowed from WS07 pdf file
        double healthDelta = 0;
        healthDelta += 0.20 * (getFeeds() - 1);
        //end of borrowed code
        applyHealthDelta(healthDelta);
    }
    
    Pet::operator++(num);
}

sdds::Fish &Fish::operator=(const sdds::Fish &rhs) {
    if(this != &rhs){
        Pet::operator=(rhs);
        addCharge(COST_CREATION * 2);
    }
    return *this;
    
}

std::ostream& Fish::outputData(std::ostream& os){
    Pet::outputData(os);
    
    return os;
}

std::ostream& operator<<(std::ostream& os, Fish& fish){
    os << "** Generic Fish **" << endl;
    fish.outputData(os);
    
    return os;
}


}





