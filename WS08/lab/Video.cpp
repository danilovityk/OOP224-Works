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




