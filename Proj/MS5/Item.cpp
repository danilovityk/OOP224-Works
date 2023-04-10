/*
|||   Final Project Milestone 5/1
|||   Module: Item
|||   Filename: Item.cpp
|||   Version 1.0
|||   Author    Danylo Vityk
|||   Revision History
|||   -----------------------------------------------------------
|||   Date      Reason
|||   2020/?/?  Preliminary release
|||   2020/?/?  Debugged DMA
|||   -----------------------------------------------------------
|||   I have done all the coding by myself and only copied the code
|||   that my professor provided to complete my project milestones.
|||   -----------------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>
#include "Item.h"
#include "POS.h"
using namespace std;
namespace sdds{

Item::Item() {
    m_quantity = 0;
    m_taxable = false;
    m_price = 0;
    m_SKU[0] = '\0';
    m_flag = false;
    m_name = nullptr;
}

Item::Item(const Item &source) {
    *this = source;
}

Item::~Item() {
    delete[] m_name;
}

Item &Item::operator=(const Item &source) {
    if (this != &source)
    {
        if (m_name != nullptr) delete[] m_name;
        m_name = new char [strlen(source.m_name) + 1];
        strncpy(m_name, source.m_name, strlen(source.m_name) + 1);
        strcpy(m_SKU, source.m_SKU);
        m_flag = source.m_flag;
        m_error = source.m_error;
        m_price = source.m_price;
        m_taxable = source.m_taxable;
        m_quantity = source.m_quantity;
    }
    
    return *this;
}

bool Item::operator==(sdds::Item &rop) const {
    return strcmp(m_SKU, rop.m_SKU);
}

bool Item::operator==(const char* rop) const {
    return !(strcmp(m_SKU, rop));
}

bool Item::operator>(const sdds::Item &rop) const {
    
    return strcmp(m_name, rop.m_name) > 0;
}

int Item::operator+=(int quantity) {
    m_quantity += quantity;
    if (m_quantity > MAX_STOCK_NUMBER){
        m_quantity = MAX_STOCK_NUMBER;
        m_error = ERROR_POS_QTY;
    }
    return m_quantity;
}

int Item::operator-=(int rop) {
    
    m_quantity -= rop;
    if (m_quantity < 0){
        m_quantity = 0;
        m_error = ERROR_POS_STOCK;
    }
    
    return m_quantity;
}

Item::operator bool() const {
    return !m_error;
}

Item& Item::displayType(int flag) {
    if (flag == POS_FORM) m_flag = POS_FORM;
    if (flag == POS_LIST) m_flag = POS_LIST;
    
    return *this;
}

double Item::cost() const {
    return m_taxable ? m_price + m_price * TAX :  m_price;
}

int Item::quantity() const {
    return m_quantity;
}

sdds::Item &Item::clear() {
    m_error.clear();
    return *this;
}

std::ostream &Item::write(std::ostream &ostr) const {
    if(!m_error){
        ostr.fill(' ');
        if(m_flag == POS_LIST){
            //
            char temp[strlen(m_name) + 1];
            strcpy(temp, m_name);
            temp[20] = '\0';
            ostr << m_SKU << "   |" << setw(20) << left << temp << "|" << right << fixed << setprecision(2) << setw(7) << m_price << setprecision(0) << "| ";
            if (m_taxable) {
                ostr << "X";
                
            }else{
                ostr << " ";
                
            }
            ostr << " |" << setw(4) << m_quantity << "|" << setw(9) << setprecision(2) << cost() * m_quantity << "|";
            
        }else {
            
            ostr << left << "=============v" << endl;
            ostr << setw(13) << "Name:" << m_name << endl;
            ostr << setw(13) << "Sku:" <<  m_SKU << endl;
            ostr << setw(13) << "Price:" << fixed << setprecision(2) << m_price << endl;
            ostr << setw(13) << "Price + tax:";
            if (m_taxable){
                ostr << cost() << endl;
            }else{
                ostr << "N/A" << endl;
            }
            ostr << setw(13) << "Stock Qty:" << setprecision(0) << m_quantity << endl;
            
           
        }
    }
    
    if(m_error){
        cerr << m_error;
    }
    
    ostr.unsetf(ios::right);
    ostr.setf(ios::left);
    
    return ostr;
}

std::istream &Item::read(std::istream &istr) {
    char tempTax;
    clear();
    cout << "Sku\n";
    do {
        
        cout << "> ";
        istr.getline(m_SKU, MAX_NAME_LEN + 1);
        
        if(strlen(m_SKU) > MAX_SKU_LEN){
            cout << "SKU too long" << endl;
        }
        
    } while(strlen(m_SKU) > MAX_SKU_LEN);
    if (istr.fail()) cin.clear();
    cout << "Name\n";
    char buffer [250];
    do {
        
        cout << "> ";
        istr.getline(buffer, 250,'\n');
        
        if(strlen(buffer) > MAX_NAME_LEN){
            cout << "Item name too long\n";
        }else{
            if (m_name != nullptr){
                delete[] m_name;
            }
            m_name = new char [MAX_NAME_LEN + 1];
            strcpy(m_name, buffer);
        }
        
    } while(strlen(buffer) > MAX_NAME_LEN || istr.fail());
    cout << "Price" << endl;
    do {
        if (istr.fail()){
            cin.clear();
            cin.ignore(99999, '\n');
        }
        cout << "> ";
        istr >> m_price;
        

        
        if(cin.fail() || m_price < 0){
            cout << "Invalid price value\n";
            
        }
        
    } while(cin.fail() || m_price < 0);
    
    cout << "Taxed?" << endl;
    cout << "(Y)es/(N)o: ";
    istr.ignore();
    do {
        istr.get(tempTax);
        istr.ignore(99999, '\n');
        
        if(tempTax != 'n' && tempTax != 'y' && tempTax != 'N' && tempTax != 'Y'){
            cout << "Only 'y' and 'n' are acceptable: ";
        }
        
    } while(tempTax != 'y' && tempTax != 'n' && tempTax != 'N' && tempTax != 'Y');
    
    if(tempTax == 'y' || tempTax == 'Y'){
        m_taxable = true;
    }
    else{
        m_taxable = false;
    }
    cout << "Quantity" << endl;
    do {
        if (istr.fail()) {
            istr.clear();
            istr.ignore(10000, '\n');
        }
        cout << "> ";
        istr >> m_quantity;
        
        if(istr.fail() || m_quantity > MAX_STOCK_NUMBER || m_quantity < 1){
            cout << "Invalid quantity value" << endl;
        }
        
    } while(istr.fail() || m_quantity > MAX_STOCK_NUMBER || m_quantity < 1);
    
    return istr;
    }

std::ofstream &Item::save(std::ofstream &ofstr) const {
    int taxable = 0;
    if (m_taxable) taxable = 1;
    ofstr << ItemType() << ',' << m_SKU << "," << m_name << "," << fixed << setprecision(2) << m_price << "," << taxable << "," << m_quantity;
    
    if (m_error) cerr << m_error << endl;
    
    return ofstr;
}

std::ifstream& Item::load(std::ifstream &ifstr) {
    m_error.clear();
    //clear();
    char SKU[200] = {'\0'};
    char name[300] = {'\0'};
    double price = 0;
    int quantity = 0;
    int flag = 0;
    
    ifstr.getline(SKU, 199, ',');
    if (ifstr.fail() || strlen(SKU) > MAX_SKU_LEN) m_error = ERROR_POS_SKU;
    
    ifstr.getline(name, 299, ',');
    if (!m_error && (ifstr.fail() || strlen(name) > MAX_NAME_LEN)) m_error = ERROR_POS_NAME;
    ifstr >> price;
    ifstr.ignore();
    ifstr >> flag;
    ifstr.ignore();
    ifstr >> quantity;
    
    if (!m_error){
        
        if (!ifstr.fail()){
            
            if (price < 0) {
                
                m_error = ERROR_POS_PRICE;
                
            } else if (flag != 1 && flag != 0) {
                
                m_error = ERROR_POS_TAX;
                
            }else if(quantity < 0 || quantity > MAX_STOCK_NUMBER){
                
                m_error = ERROR_POS_QTY;
                
            }
            
        }
    }
    
    if (!m_error){
        delete[] m_name;
        m_name = new char [strlen(name) + 1];
        strcpy(m_name, name);
        strcpy(m_SKU, SKU);
        m_price = price;
        m_quantity = quantity;
        m_taxable = false;
        if (flag == 1) m_taxable = true;
        
    }
 
    
    return ifstr;
}

std::ostream& Item::bprint(std::ostream& ostr) const{
    char temp[100]{};
    strcpy(temp, m_name);
    temp[20] = '\0';
    ostr << "| " << setw(20) << left << temp << "|" << fixed << setprecision(2) << right << setw(10) << cost() << " |  ";
    if (m_taxable) {ostr << "T";}else{ostr << " ";};
    ostr << "  |" << endl;
    
    return ostr;
}

double operator+=(double& number,const Item& item){
    number += item.cost() * item.quantity();
    return number;
}

}


