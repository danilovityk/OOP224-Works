/*
|||   Final Project Milestone 5/1
|||   Module: Error
|||   Filename: Error.h
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

