#include <iostream>
#include <cstring>
#include "Error.h"

using namespace std;

namespace sdds{


Error::Error() {
    m_errorType = nullptr;
}

Error::Error(const char *errorType) {
    *this = errorType;
}

Error& Error::operator=(const Error& errorObj) {
    
    if (errorObj && this != &errorObj){
        delete[] m_errorType;
        int size = (int)strlen(errorObj.m_errorType);
        m_errorType = new char [size + 1];
        m_errorType[size] = '\0';
        strcpy(m_errorType, errorObj.m_errorType);
    
        
    };
    return *this;
    }

Error& Error::operator=(const char *errorType) {
    if(errorType != nullptr){
        int size = (int)strlen(errorType);
        m_errorType = new char [size + 1];
        m_errorType[size] = '\0';
        strcpy(m_errorType, errorType);
    }
    return *this;
}

Error::operator bool() const{
    return m_errorType != nullptr;
}

Error& Error::clear() {
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
