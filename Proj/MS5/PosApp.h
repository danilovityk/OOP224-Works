/*
|||   Final Project Milestone 5/1
|||   Module: Whatever
|||   Filename: PosApp.h
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


#ifndef POSAPP_H
#define POSAPP_H

#include "Item.h"
#include "POS.h"

namespace sdds
{

class PosApp{
    
private:
    int m_numberOfItems;
    char m_fileName[128];
    Item* m_items[MAX_NO_ITEMS];
    
    
    void addItem();
    void removeItem();
    void stockItem();
    void listItems();
    void POS();
    void saveRecs() const;
    void loadRecs();
    
    void printActionTitle (const char* title) const;
public:
    int menu();
    void run();
    PosApp(const char* filename);
    PosApp(const PosApp& other) = delete;
    PosApp& operator=(const PosApp& other) = delete;
};



}



#endif

