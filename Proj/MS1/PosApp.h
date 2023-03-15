#ifndef POSAPP_H
#define POSAPP_H

namespace sdds
{

class PosApp{
    
private:
    void addItem();
    void removeItem();
    void stockItem();
    void listItems();
    void POS();
    void saveRecs();
    void loadRecs();
    
public:
    int menu();
    void run();
    PosApp(const char* filename);
    PosApp(const PosApp& other) = delete;
    PosApp& operator=(const PosApp& other) = delete;
};



}



#endif

