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

#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include "Media.h"

namespace sdds{

class Video : public Media{
    
private:
    int m_length;
    
protected:
    int get() const;
    
public:
    Video();
    Video(int length);
    Video(const Video& vid) = delete;
    Video& operator=(const Video& vid) = delete;
    
    void load(std::istream& istr);
    
};



}
#endif
