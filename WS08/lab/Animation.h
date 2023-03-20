/*
 *         Name: Danylo Vityk
 *         Email: dvityk@myseneca.ca
 *         Sudent ID: 176326213
 *         Date: Mar 20, 2023
 *
 *
 *         I have done all the coding by myself and only copied the code that my professor provided to complete my workshops
 *         and assignments.
 *
 *
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include "Video.h"

namespace sdds{

class Animation : public Video{
    
    int m_dimension;
    
public:
   
    Animation();
    
    Animation(int length, int dimension);
    
    
    void load(std::istream& istr);
    std::ostream& play(std::ostream& ostr) const;
    
    
    
};


}


#endif
