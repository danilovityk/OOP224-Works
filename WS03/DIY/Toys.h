/*
        Name: Danylo Vityk
        Email: dvityk@myseneca.ca
        Sudent ID: 176326213
        Date: Feb 6, 2023


 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


*/

#ifndef Toys_hpp
#define Toys_hpp

#include <stdio.h>

#define MAX_TNAME 31 // define it to 31. The maximum length of a Toy name
namespace sdds{



class Toys{
    
private:
    char m_tname[MAX_TNAME];    // toy name, up to MAX_TNAME size
    int m_sku;                  //SKU number, maximum 8 digits long
    double m_price;             //toy price
    int m_age;                  //toy according to age group
    bool m_onSale;              // keep track, if toys are on sale or not
    
    
public:
    int getSKU ();
    void addToys(const char* tname, int sku, double price,int age);
    void isSale(bool sale);
    void calSale();
    void display()const;
    void clearToy();
    
};




}

#endif /* Toys_hpp */
