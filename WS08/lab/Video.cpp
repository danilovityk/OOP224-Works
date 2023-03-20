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

#include <iostream>
#include "Video.h"

using namespace std;
namespace sdds{

int Video::get() const {
    return m_length;
}

Video::Video() {
    m_length = 0;
}

Video::Video(int length) {
    m_length = length >= 0 ? length : -1;
}

void Video::load(std::istream &istr) {
    istr >> m_length;
    istr.ignore();
}



}




