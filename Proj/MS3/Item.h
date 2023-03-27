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
    bool operator>(Item& rop) const;
    int operator+=(int quantity);
    int operator-=(int rop);
    operator bool() const;
//    opertor+=
//    Adds an integer value (right-hand operand) to the quantity and returns the quantity. If the sum of the value and the quantity exceeds the MAX_STOCK_NUMBER then the quantity will be set to MAX_STOCK_NUMBER and the Item error will be set to ERROR_POS_QTY.
//
//    operator-=
//    Reduces the quantity by the right-hand value and returns the quantity. If the value is more than the quantity then the quantity will be set to zero and the Item error will be set to ERROR_POS_STOCK.
//
//    bool type conversion
//    Returns the opposite of the status of the error attribute. This method does not modify the object.

    Item& displayType(int flag);
    double cost()const;
    int quantity() const;
    Item& clear();
//    cost query
//    Returns the cost of the Item; that is the price of the item (plus tax if the item is taxable). This method does not modify the object.
//
//    quantity query
//    Returns the quantity of the Item. This method does not modify the object.
//
//    clear
//    Clears the error status of the object and then returns the reference of the current object.
//
    
    
    std::ostream& write(std::ostream& ostr) const;
    std::istream& read(std::istream& istr);
    std::ofstream& save(std::ofstream& ofstr) const;
    std::ifstream& load(std::ifstream& ifstr);

    std::ostream& bprint(std::ostream& ostr) const;
    
};
double operator+=(double& number,const Item& item);

}
#endif
