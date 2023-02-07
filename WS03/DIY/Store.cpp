/*
        Name: Danylo Vityk
        Email: dvityk@myseneca.ca
        Sudent ID: 176326213
        Date: Feb 6, 2023


 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


*/

#include <cstring>
#include <iostream>
#include "Store.h"

using namespace std;

namespace sdds{


void Store::setStore(const char* sName, int no){
    
    setEmpty();
    
    if(sName != nullptr){
        strcpy(m_sName, sName);
        m_noOfToys = no;
    }else{
        strcpy(m_sName, "");
        m_noOfToys = 0;
    }
    
    
}


void Store::setToys(const char* tname, int sku, double price, int age)
{
//    if(m_addToys != 0 && m_toy[m_addToys - 1].getSKU() == 0 && m_addToys == 2){
//        setCountToZero();
//    }
    
    if(m_addToys < m_noOfToys)
    {
        m_toy[m_addToys].addToys(tname, sku, price, age);
        m_addToys++;
    }
}

void Store::display()const{
    
    cout.width(60);
    cout << "************************************************************" << endl;
    cout << m_sName << endl;
    cout << "************************************************************" << endl;
    
    cout << "list of the toys" << endl;
    cout.setf(ios::right);
    
    cout.width(30);
    
    cout << "SKU";
    cout.width(10);
    cout << "Age";
    cout.width(11);
    cout << "Price";
    cout.width(10);
    cout << "Sale" << endl;
    cout.unsetf(ios::right);
    
    cout.setf(ios::left);
    
    for(int i = 0; i < m_addToys; i++){
        cout << "Toy[" << i+1 << "] :";
        m_toy[i].display();
        cout << endl;
    }
    
 
}

void Store::find(int sku){

    for (int i = 0; i < m_addToys; i++)
    {
        if (sku == m_toy[i].getSKU())
        {
            m_toy[i].isSale(true);
            m_toy[i].calSale();
            i = m_addToys;
        }
    }
    
}

void Store::setEmpty(){
    
    for(int i = 0; i < m_addToys; i++){
        m_toy[i].clearToy();
    }
    
    strcpy(m_sName, "");
    m_addToys = 0;
    m_noOfToys = 0;
}

    
    void Store::setCountToZero(){
        
        m_addToys = 0;
    }


}
