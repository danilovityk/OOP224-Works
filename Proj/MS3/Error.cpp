/*
 *         Name: Danylo Vityk
 *         Email: dvityk@myseneca.ca
 *         Sudent ID: 176326213
 *         Date: Mar 17, 2023
 *
 *
 *         I have done all the coding by myself and only copied the code that my professor provided to complete my workshops
 *         and assignments.
 *
 *
 */

#include <iostream>
#include <cstring>
#include "Error.h"

using namespace std;

namespace sdds{


Error::Error() {
    m_errorType = nullptr;
}

Error::Error(const char *errorType) {
    m_errorType = nullptr;
    *this = errorType;
}

Error::Error(const Error& source){
    ;
}

Error& Error::operator=(const Error& errorObj) {
    
    if (errorObj && this != &errorObj){
        delete[] m_errorType;
        int size = (int)strlen(errorObj.m_errorType);
        m_errorType = new char [size + 1];
        strcpy(m_errorType, errorObj.m_errorType);
        m_errorType[size] = '\0';
    }
    return *this;
    }

Error& Error::operator=(const char *errorType) {
    if(errorType != nullptr){
        delete[] m_errorType;
        int size = (int)strlen(errorType);
        m_errorType = new char [size + 1];
        strcpy(m_errorType, errorType);
        m_errorType[size] = '\0';
    }
    return *this;
}

Error::operator bool() const{
    return m_errorType != nullptr;
}

Error& Error::clear() {
    delete[] m_errorType;
    m_errorType = nullptr;
    return *this;
}

Error::~Error() {
    delete[] m_errorType;


}

char* Error::getErrorMessage() const{
   // if (m_errorType){
        return m_errorType;
   // }
}

std::ostream& operator<<(std::ostream &ostr, const Error& error)
{
    if (error){
        ostr << error.getErrorMessage();
    }
    
    return ostr;
}

}
