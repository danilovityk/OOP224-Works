//
//  NameTag.hpp
//  W4P2
//
//  Created by Danik on 09.02.2023.
//

#ifndef NameTag_h
#define NameTag_h

#include <stdio.h>

namespace sdds
{

class NameTag{
    
private:
    char* m_name;
    int m_number;
    
    void malloc(char* name);
    void clear();
    
    
public:
    
    NameTag();
    NameTag(char name[]);
    NameTag(char name[], int number);
    
    ~NameTag();
    
    
    void print();
    NameTag& read();
    
    
    
};

}

#endif /* NameTag_h */
