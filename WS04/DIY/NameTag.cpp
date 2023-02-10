#include <iostream>
#include <cstring>
#include "NameTag.h"

using namespace std;

namespace sdds
{
    
    void NameTag::malloc(char* name)
    {
        if(name != nullptr)
        {
            
            if (strlen(name) > 40)
            {
                m_name = new char[41];
                strncpy(m_name, name, 40);
                m_name[40] = '\0';
            }else
            {
                m_name = new char[strlen(name + 1)];
                strcpy(m_name, name);
                
                m_name[40] = '\0';
            }
        
        }
    }

    void NameTag::clear()
    {
        m_name = nullptr;
        m_number = 0;
    }
    
    NameTag::NameTag()
    {
        clear();
    }
    
    NameTag::NameTag(char* name)
    {
        
        clear();
        
        if (name != nullptr)
        {
            malloc(name);
        }
        
    }

    NameTag::NameTag(char* name, int number)
    {
        clear();
        
        if (name != nullptr)
        {
            malloc(name);
        }
        
        
        if (10000 <= number && number <= 99999)
        {
            m_number = number;
        }else
        {
            m_number = 1;
        }
        
        
    }

    NameTag::~NameTag()
    {
        delete[] m_name;
    }
    
    NameTag& NameTag::read()
    {
        int number = 0;
        char choice, buffer[41];
        bool flag = false;
        
        cout << "Please enter the name: ";
        
        
        cin.getline(buffer, 40);
      
        
      
        
        
        
        buffer[40] = '\0';
        
        malloc(buffer);
        
        cout << "Would you like to enter an extension? (Y)es/(N)o: ";
        
       
        
        do {
            
      
            cin.get(choice);
            
            cin.ignore(10000, '\n');
            
            if (choice == 'Y' || choice == 'y')
            {
                cout << "Please enter a 5 digit phone extension: ";
                do{
                    flag = false;
                    cin >> number;
                    if (cin.fail())
                    {
                        
                        flag = true;
                        cout << "Bad integer value, try again: ";
                        
                    }else if (!(10000 <= number && number <= 99999))
                    {
                        flag = true;
                        cout << "Invalid value [10000<=value<=99999]: ";
                    }
                    
                }while (flag);
                
                m_number = number;
                
            }else if (choice == 'N' || choice == 'n')
            {
                
                
                
            }else
            {
                cout << "Only (Y) or (N) are acceptable, try agin: ";
            }
            
        }while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
        
        
        return *this;
    }


    void NameTag::print()
    {
        cout.setf(ios::left);
        
        if (m_name != nullptr && m_number != 1)
        {
            if (strlen(m_name) < 20)
            {
                
                cout << "+----------------------+" << endl;
                cout << "|                      |" << endl;
                
                
                cout << "| ";
                cout.width(20);
                cout << m_name;
                cout << " |" << endl;
                
                
                cout << "|                      |" << endl;
                
                
                cout << "| ";
                cout.width(20);
                if (m_name != 0)
                {
                    cout << "Extension: N/A";
                }else
                {
                    cout << "Extension: " << m_number;
                }
                cout << " |" << endl;
                
                
                cout << "|                      |" << endl;
                cout << "+----------------------+" << endl;
                    
            }else
            {
                
                cout << "+------------------------------------------+" << endl;
                cout << "|                                          |" << endl;
                
                
                cout << "| ";
                cout.width(40);
                cout << m_name;
                cout << " |" << endl;
                
                
                cout << "|                                          |" << endl;
                
                
                cout << "| ";
                cout.width(40);
                if (m_name != 0)
                {
                    cout << "Extension: N/A";
                }else
                {
                    cout << "Extension: " << m_number;
                }
                cout << " |" << endl;
                
                
                cout << "|                                          |" << endl;
                cout << "+------------------------------------------+" << endl;
                
            }
        }else
        {
            cout << "EMPTY NAMETAG!" << endl;
        }
        
        cout.unsetf(ios::left);
    }



    
    
    
}


