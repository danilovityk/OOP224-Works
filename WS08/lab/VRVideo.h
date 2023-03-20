#ifndef VRVIDEO_H
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

#define VRVIDEO_H

#include "Video.h"

namespace sdds{

class VRVideo : public Video{
    
    char* m_equipment;
    
public:
    VRVideo();
    VRVideo(int length, const char* name);
    ~VRVideo();
    void load(std::istream& istr);
    std::ostream& play(std::ostream& ostr) const;
    
    
    
};


}


#endif
