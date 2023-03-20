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
#include "Media.h"

using namespace std;

namespace sdds{

ostream& operator<<(ostream& ostr, const Media& media){
    media.play(ostr);
    
    return ostr;
}
istream& operator>>(istream& istr, Media& media){
    media.load(istr);
    
    return istr;
}

}
