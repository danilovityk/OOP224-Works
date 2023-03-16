#ifndef ERROR_H
#define ERROR_H

namespace sdds {

class Error {
  
private:
    char* m_errorType;
    
public:
    Error ();
    Error (const char* errorType);
    
   
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

