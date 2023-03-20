#include <iostream>
#include <string>
#include "VRVideo.h"
using namespace std;

namespace sdds{

VRVideo::VRVideo() : Video(), m_equipment(nullptr){}


VRVideo::VRVideo(int length, const char *name) : Video(length){
    
    if (get() != -1 && name != nullptr)
    {
        m_equipment = new char [length + 1];
        strcpy(m_equipment, name);
    }else{
        m_equipment = nullptr;
        
    }
}

VRVideo::~VRVideo()  {
    delete[] m_equipment;
}

void VRVideo::load(std::istream &istr) {
    Video::load(istr);
    
    
    char* temp = new char[200];
    istr.getline(temp, 200);
    delete[] m_equipment;
    
    m_equipment = new char[strlen(temp) + 1];
    strcpy(m_equipment, temp);
    
    delete[] temp;
    
    
}

std::ostream &VRVideo::play(std::ostream &ostr) const {
    if (m_equipment != nullptr && get() != -1 ){
        ostr << "VRVideo requires " << m_equipment << endl;
        ostr << "Video Length = " << get();
    }
    
    return ostr;
}




}



