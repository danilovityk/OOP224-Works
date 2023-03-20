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

#ifndef ERROR_H
#define ERROR_H

namespace sdds {

class Error {
  
private:
    char* m_errorType;
    
public:
    Error ();
    Error (const char* errorType);
    Error (const Error& source);
   
    Error& operator=(const Error& errorObj);
    Error& operator=(const char* errorType);
    
    char* getErrorMessage() const;
    operator bool() const;
    Error& clear();
    ~Error();
    
    
};

std::ostream& operator<<(std::ostream& ostr, const Error& error);

}

#endif

