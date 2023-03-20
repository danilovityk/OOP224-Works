#include <iostream>
#include "Animation.h"

using namespace std;

namespace sdds{

Animation::Animation() : Video(), m_dimension(0){
   
}

Animation::Animation(int length, int dimension) : Video(length), m_dimension(dimension) {
        
    if (m_dimension != 2 && m_dimension != 3)
    {
        m_dimension = 0;
    }
    
    
}

void Animation::load(std::istream &istr) {
    Video::load(istr);
    istr >> m_dimension;
    istr.ignore();
    
    if (m_dimension != 2 && m_dimension != 3)
    {
        m_dimension = 0;
    }
}

std::ostream &Animation::play(std::ostream &ostr) const {
    
    if (m_dimension != 0 && get() != -1){
        ostr << "Animation is in " << m_dimension << "-D" << endl;
        ostr << "Video Length = " << get();
    }
    
    
    return ostr;
}



}
