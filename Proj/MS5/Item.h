#ifndef ITEM_H
#define ITEM_H

#include "POS.h"
#include "PosIO.h"
#include "Error.h"

namespace sdds{

class Item : public PosIO{
private:
    char m_SKU[MAX_SKU_LEN];
    char* m_name;
    double m_price;
    bool m_taxable;
    int m_quantity;
protected:
    int m_flag;
    Error m_error;
public:
    Item();
    Item(const Item& source);
    ~Item();
    Item& operator=(const Item& source);
    
    bool operator==(Item& rop) const;
    bool operator==(const char* rop) const;
    bool operator>(const Item& rop) const;
    int operator+=(int quantity);
    int operator-=(int rop);
    operator bool() const;

    virtual char ItemType()const = 0;
    Item& displayType(int flag);
    double cost()const;
    int quantity() const;
    Item& clear();

    
    std::ostream& write(std::ostream& ostr) const;
    std::istream& read(std::istream& istr);
    std::ofstream& save(std::ofstream& ofstr) const;
    std::ifstream& load(std::ifstream& ifstr);

    std::ostream& bprint(std::ostream& ostr) const;
    
};
double operator+=(double& number,const Item& item);

}
#endif
