/*
        Name: Danylo Vityk
        Email: dvityk@myseneca.ca
        Sudent ID: 176326213
        Date: Feb 6, 2023


 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


*/

#include <cstring>
#include <iostream>
#include <iomanip>
#include "Toys.h"

using namespace std;

namespace sdds{

int Toys::getSKU(){
    
    return m_sku;
}


void Toys::addToys(const char* tname, int sku, double price, int age)
{
    if(tname != nullptr && sku >= 10000000){
        strcpy(m_tname, tname);
        m_sku = sku;
        m_price = price;
        m_age = age;
        m_onSale = false;
        
    }else
    {
        clearToy();
    }
}

void Toys::isSale(bool sale){
    m_onSale = sale;
}

void Toys::calSale()
{
    m_price *= 0.8;
}

void Toys::clearToy()
{
    m_sku = 0;
    m_price = 0;
    strcpy(m_tname, "");
    m_age = 0;
    m_onSale = false;
    
}

void Toys::display()const
{
    
    if(m_sku > 0 && m_age > 0 && m_price > 0){
        
        cout.width(15);
        cout << left << m_tname;
        
        cout.setf(ios::right);
        
        cout.width(10);
        cout << m_sku;
        
        cout.width(6);
        cout << m_age;
        
        cout.width(12);
        cout << fixed << setprecision(2) << m_price;
        
        if(m_onSale){
            cout.width(11);
            cout << "On Sale ";
        }else {
            cout << "        ";
        }
    }else{
        cout << "Invalid Toy";
    }

    
}



}
