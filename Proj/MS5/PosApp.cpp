/*
|||   Final Project Milestone 5/1
|||   Module: PosApp
|||   Filename: PosApp.cpp
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
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Perishable.h"
#include "NonPerishable.h"
#include "PosApp.h"
#include "Utils.h"
#include "Item.h"
using namespace std;
namespace sdds
{

int PosApp::menu() {
    
    int choice;
    bool flag;
    cout << "The Sene-Store" << endl << "1- List items" << endl << "2- Add item" << endl << "3- Remove item" << endl << "4- Stock item" << endl <<  "5- POS" << endl << "0- exit program" << endl << "> ";
    
    
    do{
        cin >> choice;
        flag = true;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout  << "Invalid Integer, try again: ";
            flag = false;
        }else
        {
            if(choice < 0 || choice > 5){
                cout << "[0<=value<=5], retry: > ";
                flag = false;
            }
            
        }
        
    }while (!flag);
    cin.ignore();
    return choice;
}

void PosApp::run() {
    int choice = 0;
    
    cout << ">>>> Loading Items..........................................................." << endl;
    
    do{
        choice = menu();
        
        switch(choice)
        {
            case 1:
                cout << ">>>> Listing Items..........................................................." << endl;
                listItems();
                break;
                
            case 2:
                cout << ">>>> Adding Item to the store................................................" << endl;
                addItem();
                cout << ">>>> DONE!..................................................................." << endl;
                break;
                
            case 3:
                cout << ">>>> Remove Item............................................................." << endl;
                removeItem();
                break;
                
            case 4:
                cout << ">>>> Select an item to stock................................................." << endl;
                stockItem();
                break;
                
            case 5:
                cout << ">>>> Starting Point of Sale.................................................." << endl;
                POS();
                break;
        }
    }while(choice != 0);
    
    cout << ">>>> Saving Data............................................................." << endl << "Goodbye!" << endl;
    saveRecs();
}

PosApp::PosApp(const char *filename) {
    
    if(filename){
        strcpy(m_fileName, filename);
    }
    
    loadRecs();
    
}

void PosApp::addItem() { 
    
    
    if(m_numberOfItems >= MAX_NO_ITEMS)
    {
        cout << "Inventory Full" << endl;
        
    }else{
        
        char tempPerishable = '\0';
        Item* tempItem = nullptr;
        cout << "Is the Item perishable? (Y)es/(N)o: ";
        cin >> tempPerishable;
        cin.ignore(9999, '\n');
        
        
        if (tempPerishable == 'y')
        {
            tempItem = new Perishable();
            
        }else if(tempPerishable == 'n')
        {
            
            tempItem = new NonPerishable();
            
        }
        
        bool done = false;
        while (!done) {
            cin >> *tempItem;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(9999, '\n');
                cout << *tempItem << ", try again..." << endl;
            } else {
                done = true;
            }
        }
        
        
        m_items[m_numberOfItems++] = tempItem;
        saveRecs();
        
    }
    
}

int PosApp::select() {
    int result = 0;
    bool flag = false;
    
    do {
        
        flag = false;
        
        for (int i = 1; i < m_numberOfItems; i++)
        {
            
            if (m_items[i-1]->operator>(*m_items[i]))
            {
                flag = true;
                Item *temp = m_items[i];
                m_items[i] = m_items[i-1];
                m_items[i-1] = temp;
            }
        }
        
    
        
    }while (flag);
    
    cout << ">>>> Item Selection by row number............................................" << endl;
    cout << "Press <ENTER> to start....";
    cin.ignore(9999, '\n');
    
    cout << ">>>> Listing Items..........................................................." << endl;
    
    cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
    cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;
    
   
    
    for (int i = 0; i < m_numberOfItems; i++)
    {
        cout << setw(4);
        cout << setfill(' ');
        cout.setf(ios::right);
        cout << i+1;
        cout.unsetf(ios::right);
        cout.setf(ios::left);
        cout << " | ";
        m_items[i] -> displayType(POS_LIST);
        m_items[i] -> write(cout);
        cout << endl;
    }
    
    cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
    
    
    cout << "Enter the row number: ";
    
    
    
    
    do {
        cin >> result;
        
        if (cin.fail()){
            result = 0;
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Invalid Integer, try again: ";
            
        }else if (result > m_numberOfItems || result < 1){
            result = 0;
            cout << "[1<=value<=" << m_numberOfItems << "], retry: Enter the row number: ";
            
        }
        
        
    } while (result == 0);
    
    
    
    
    return result;
}

void PosApp::removeItem() { 
    int index = select();
    index--;
    
    cout << "Removing...." << endl;
    m_items[index]->displayType(POS_FORM);
    m_items[index]->write(cout);
    
    
    delete m_items[index];
    
    for (int i = index; i < m_numberOfItems - 1; i++)
    {
        m_items[i] = m_items[i+1];
    }
    
    
    m_numberOfItems--;
    
    cout << ">>>> DONE!..................................................................." << endl;
    
    
}

void PosApp::stockItem() {
    
    int index = select();
    index--;
    
    cout << "Selected Item:" << endl;
    m_items[index]->displayType(POS_FORM);
    m_items[index]->write(cout);
    
    cout << "Enter quantity to add: ";
    
    int result = 0;
    do {
        cin >> result;
        
        if (cin.fail()){
            result = 0;
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Invalid Integer, try again: ";
            
        }else if (result > MAX_STOCK_NUMBER - m_items[index]->quantity() || result < 1){
            result = 0;
            cout << "[1<=value<=" << MAX_STOCK_NUMBER - m_items[index]->quantity() << "], retry: Enter quantity to add: ";
            
        }
        
    } while (result == 0);
    
    *m_items[index] += result;
    cout << ">>>> DONE!..................................................................." << endl;
    
}

void PosApp::listItems() {
    double total = 0;
    bool flag = false;
    
    do {
        
        flag = false;
        
        for (int i = 1; i < m_numberOfItems; i++)
        {
            
            if (m_items[i-1]->operator>(*m_items[i]))
            {
                flag = true;
                Item *temp = m_items[i];
                m_items[i] = m_items[i-1];
                m_items[i-1] = temp;
            }
        }
        
    
        
    }while (flag);
    
    
    cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
    cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;
    
   
    
    for (int i = 0; i < m_numberOfItems; i++)
    {
        cout << setw(4);
        cout << setfill(' ');
        cout.setf(ios::right);
        cout << i+1;
        cout.unsetf(ios::right);
        cout.setf(ios::left);
        cout << " | ";
        m_items[i] -> displayType(POS_LIST);
        m_items[i] -> write(cout);
        cout << endl; 
        total += m_items[i]->cost() * m_items[i] -> quantity();
    }
    
    cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
    cout << fixed << setprecision(2);
    cout << "                               Total Asset: $  |       " << total << "|" << endl;
    cout << "-----------------------------------------------^--------------^" << endl << endl;
  
}

void PosApp::POS() { 
    cout << "Running POS()" << endl;
}

void PosApp::saveRecs() const {
    
    ofstream outputFile(m_fileName);
    for (int i = 0; i < m_numberOfItems; i++){
        m_items[i] -> save(outputFile);
        outputFile << endl;
        
    }
    
    outputFile.close();
}

void PosApp::loadRecs() {
    char productType;
    m_numberOfItems = 0;
    
    for (int i = 0; i < MAX_NO_ITEMS; i++) {
        m_items[i] = nullptr;
    }
 
    ifstream sourceFile(m_fileName);
       if (!sourceFile)
       {
           ofstream output(m_fileName);
           output.close();
       }
          
       while (sourceFile >> productType && m_numberOfItems < MAX_NO_ITEMS) {
           sourceFile.ignore();
           Item* temp = nullptr;
           
           if (productType == 'N')
           {
               temp = new NonPerishable();
               
           } else if (productType == 'P')
           {
               temp = new Perishable();
           }
           
           sourceFile >> *temp;
           
           m_items[m_numberOfItems] = temp;
           m_numberOfItems++;
       }
    
    
}

PosApp::~PosApp (){
    
    for (int i = 0; i < m_numberOfItems; i++){
        delete m_items[i];
        
    }
    
    
}

}




