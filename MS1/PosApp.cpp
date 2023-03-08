#include <iostream>
#include <string>
#include "PosApp.h"
#include "Utils.h"
using namespace std;
namespace sdds
{

int PosApp::menu() {
    
    int choice;
    bool flag;
    cout << "The Sene-Store" << endl << "1- List items" << endl << "2- Add item" << endl << "3- Remove item" << endl << "4- Stock item" << endl <<  "5- Point of Sale" << endl << "0- exit program" << endl << "> ";
    
    
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
        
    return choice;
}

void PosApp::run() {
    int choice = 0;
    
    cout << ">>>> Loading Items..........................................................."<< endl << "Loading data from datafile.csv" << endl;
    
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
    
    cout << ">>>> Saving Data............................................................." << endl << "Saving data in datafile.csv" << endl << "Goodbye!" << endl;
    
}

PosApp::PosApp(const char *filename) {
    
}

void PosApp::addItem() { 
    cout << "Running addItem()" << endl;
}

void PosApp::removeItem() { 
    cout << "Running removeItem()" << endl;
}

void PosApp::stockItem() { 
    cout << "Running stockItem()" << endl;
}

void PosApp::listItems() { 
    cout << "Running listItems()" << endl;
}

void PosApp::POS() { 
    cout << "Running POS()" << endl;
}

void PosApp::saveRecs() { 
    cout << "Running saveRecs()" << endl;
}

void PosApp::loadRecs() { 
    cout << "Running loadRecs()" << endl;
}



}




