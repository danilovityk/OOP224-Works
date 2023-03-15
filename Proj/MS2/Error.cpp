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

Error& Error::operator=(const sdds::Error& errorObj) {
    //if (!errorObj){
    delete[] m_errorType;
    int size = (int)strlen(errorObj.m_errorType);
    m_errorType = new char [size + 1];
    
    strcpy(m_errorType, errorObj.m_errorType);
    
        
   // };
}

Error& Error::operator=(const char *errorType) {
    <#code#>;
}

Error::operator bool() {
    <#code#>;
}

Error& Error::clear() {
    <#code#>;
}

Error::~Error() {
    <#code#>;


}



}
