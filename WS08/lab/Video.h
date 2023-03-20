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
