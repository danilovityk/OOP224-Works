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

