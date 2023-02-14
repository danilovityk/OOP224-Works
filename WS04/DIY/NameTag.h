/*
 *         Name: Danylo Vityk
 *         Email: dvityk@myseneca.ca
 *         Sudent ID: 176326213
 *         Date: Feb 14, 2023
 *
 *
 *         I have done all the coding by myself and only copied the code that my professor provided to complete my workshops 
 *         and assignments.
 *
 *
 */

#ifndef NameTag_h
#define NameTag_h

#include <stdio.h>

namespace sdds
{

class NameTag{
    
private:
    char* m_name;
    int m_number;
    
    void malloc(const char* name);
    void clear();
    
    
public:
    
    NameTag();
    NameTag(const char* name);
    NameTag(const char* name, int number);
    
    ~NameTag();
    
    
    void print();
    NameTag& read();
    
    
    
};

}

#endif /* NameTag_h */
