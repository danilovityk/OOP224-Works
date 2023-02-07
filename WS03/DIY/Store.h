/*
        Name: Danylo Vityk
        Email: dvityk@myseneca.ca
        Sudent ID: 176326213
        Date: Feb 6, 2023


 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


*/


#ifndef Store_hpp
#define Store_hpp

#include <stdio.h>
#include "Toys.h"

#define MAX_NUM_TOYS 10     //define it to 10. The maximum number of toys that could be added.
#define MAX_SNAME 31        // define it to 31. The maximum length of a store name

namespace sdds{

class Store{
    
private:
    char m_sName[MAX_SNAME];// Store name, up to MAX_SNAME size
    int m_noOfToys;//No of toys;
    int m_addToys;//no of toys added
    Toys m_toy[MAX_NUM_TOYS];// statically array of toys with size MAX_NUM_TOYS
    
public:
    void setStore(const char* sName, int no);
    void setToys(const char* tname, int sku, double price, int age);
    void display()const;
    void find(int sku);
    void setEmpty();
    void setCountToZero();
    
    
    
};



}
#endif /* Store_hpp */


