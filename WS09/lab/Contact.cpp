#include <iostream>
#include "Contact.h"
#include "Tools.h"

using namespace std;
namespace sdds{

    Contact::Contact() : Person(){}

    Contact::Contact(const sdds::Contact &obj)  : Person(obj){
        operator=(obj);
    }
    
    Contact& Contact::operator=(const Contact &rOp) {
        
        Person::operator=(rOp);
        
        if(this != &rOp){
            delAlloCopy(m_address, rOp.m_address);
            delAlloCopy(m_city, rOp.m_city);
            strCpy(m_province, rOp.m_province);
            strCpy(m_postalCode, rOp.m_postalCode);
        }
        
        return *this;
    }
    
    std::istream &Contact::read(std::istream &istr) {
        
        
        Person::read(istr);
        m_address = dynRead(istr, ',');
        m_city = dynRead(istr, ',');
        
        istr.getline(m_province, 3, ',');
      //  istr.ignore();
        istr.getline(m_postalCode, 7, '\n');
       // istr.ignore();
        if (istr.fail()) ~*this;
        
        return istr;
    }
    
    std::ostream &Contact::write(std::ostream &ostr) const {
        if (*this){
            Person::write(ostr);
            ostr << endl << m_address << endl << m_city << " " << m_province << endl << m_postalCode << endl;
        }
        
        return ostr;
    }
    

    Contact::~Contact() {
        operator~();
    }
    
    Contact::operator bool() const {
        return Person::operator bool() && m_city && m_city[0] && m_address && m_address[0];
    }
    
    void Contact::operator~() {
        Person::operator~();
        delete[] m_address;
        delete[] m_city;
        m_city = nullptr;
        m_address = nullptr;
    }

}


