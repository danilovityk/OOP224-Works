/*
 *         Name: Danylo Vityk
 *         Email: dvityk@myseneca.ca
 *         Sudent ID: 176326213
 *         Date: Mar 29, 2023
 *
 *
 *         I have done all the coding by myself and only copied the code that my professor provided to complete my workshops
 *         and assignments.
 *
 *
 */

#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H

#include "Person.h"


namespace sdds {

class Contact : public Person {
private:
    char* m_address = nullptr;
    char* m_city = nullptr;
    char m_province[3]{};
    char m_postalCode[7]{};

public:
  Contact();
  Contact(const Contact &obj);
  Contact &operator=(const Contact &rOp);
  std::istream &read(std::istream &istr);
  std::ostream &write(std::ostream &ostr) const;
  ~Contact();

  operator bool() const;
  void operator~();
};

std::istream &operator>>(std::istream &leftOperand, Person &rightOperand);
std::ostream &operator<<(std::ostream &leftOperand, const Person &rightOperand);

}

#endif
