#include <iostream>
#include <cstring>
#include "NameTag.h"

using namespace std;

namespace sdds
{
    
    void NameTag::malloc(const char* name)
    {
        if(name != nullptr)
        {
            
            if (strlen(name) > 40)
            {
                m_name = new char[41];
                strcpy(m_name, name);
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
    
    NameTag::NameTag(const char* name)
    {
        
        clear();
        
        if (name != nullptr)
        {
            malloc(name);
        }
        
    }

    NameTag::NameTag(const char* name, int number)
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
        bool flag = true;
        
        cout << "Please enter the name: ";
        
        
        cin.getline(buffer, 999);
      
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
                    flag = true;
                    cin >> number;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        flag = false;
                        cout << "Bad integer value, try again: ";
                        
                    }else if (!(10000 <= number && number <= 99999))
                    {
                        flag = false;
                        cout << "Invalid value [10000<=value<=99999]: ";
                    }
                    
                }while (!flag);
                
                cin.ignore(10000, '\n');
                
                m_number = number;
                
            }else if (choice == 'N' || choice == 'n')
            {
                m_number = 0;
                
                
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
                if (m_number == 0)
                {
                    cout << "Extension: N/A";
                }else
                {
                    cout.width(0);
                    cout << "Extension: ";
                    cout.width(9);
                    cout << m_number;
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
                if (m_number == 0)
                {
                    cout << "Extension: N/A";
                }else
                {
                    cout.width(0);
                    cout << "Extension: ";
                    cout.width(29);
                    cout << m_number;
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


