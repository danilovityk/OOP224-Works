#ifndef EGGCARTON_CPP
#define EGGCARTON_CPP

#include <iostream>

#include "EggCarton.h"

using namespace std;
namespace sdds
{
    // Two args constructor
    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize)
    {
        
        if (size % 6 == 0 && size <= 36 && size >= 6 && noOfEggs >= 0 && noOfEggs <= size)
        {
            m_size = size;
            m_noOfEggs = noOfEggs;
            m_jumboSize = jumboSize;
        }else
        {
            setBroken();
        }
    }

    // Set to broken
    void EggCarton::setBroken()
    {
        m_size = -1;
        m_noOfEggs = -1;
    }

    //given function
    ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const
    {
        int cartonWidth = size == 6 ? 3 : 6;
        
        for(int i = 0; i < size; i++)
        {
            ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
            ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
        }
        
        return ostr;
    }
    
    //Display carton if not broken
    ostream& EggCarton::display(ostream& ostr) const
    {
        if(*this)
        {
            displayCarton(m_size, m_noOfEggs, m_jumboSize, ostr);
        }else
        {
            ostr << "Broken Egg Carton!" << endl;
        }
        
        return ostr;
    }


    // read from console
    istream& EggCarton::read(istream& istr)
    {
        if(istr.get() == 'j')
        {
            m_jumboSize = true;
        }else
        {
            m_jumboSize = false;
        }
        
        istr.ignore();
        
        istr >> m_size;
        istr.ignore();
        
        istr >> m_noOfEggs;
        istr.ignore();
        
        if (!(m_size % 6 == 0 && m_size <= 36 && m_size >= 6 && m_noOfEggs > 0 && m_noOfEggs <= m_size))
        {
            setBroken();
        }
        
        return istr;
    }


    EggCarton::operator bool() const
    {
        return m_size > 0;
    }


    EggCarton::operator int() const
    {
        return *this ? m_noOfEggs : -1;
    }

    EggCarton::operator double() const
    {
        double weightInKilos = -1.0;
        
        if (*this)
        {
            weightInKilos = m_jumboSize ? m_noOfEggs * JumboEggWieght : m_noOfEggs * RegularEggWieght;
            
            weightInKilos /= 1000;
        }
        
        return weightInKilos;
    }


    EggCarton& EggCarton::operator++()
    {
        if(*this)
        {
            m_noOfEggs++;
        }
        
        return *this;
    }

    EggCarton& EggCarton::operator--()
    {
        if(*this && m_noOfEggs > 0)
        {
            m_noOfEggs--;
        }
        
        return *this;
    }
    
    EggCarton EggCarton::operator++(int)
    {
        EggCarton old;
        old = *this;
        
        ++*this;
        
        return old;
    }

    EggCarton EggCarton::operator--(int)
    {
        EggCarton old;
        old = *this;
        
        --*this;
        
        return old;
    }


    EggCarton& EggCarton::operator=(int value)
    {
        if(value > m_size)
        {
            setBroken();
        }else
        {
            m_noOfEggs = value;
        }
        
        return *this;
    }
    
    
    EggCarton& EggCarton::operator+=(int value)
    {
        if(*this)
        {
            int spaceLeft = m_size - m_noOfEggs;
            
            if(value > spaceLeft)
            {
                setBroken();
            }else
            {
                m_noOfEggs += value;
            }
        }
        
        return *this;
    }
    
    
    EggCarton& EggCarton::operator+=(EggCarton& right)
    {
        if(right)
        {
            int spaceLeft = this->m_size - this->m_noOfEggs;
            
            if (spaceLeft <= right.m_noOfEggs)
            {
                this->m_noOfEggs += spaceLeft;
                right.m_noOfEggs -= spaceLeft;
            }else
            {
                this->m_noOfEggs += right.m_noOfEggs;
                right.m_noOfEggs = 0;
            }
        }
        
        return *this;
    }



    bool EggCarton::operator==(const EggCarton& right) const
    {
        double difference = (double)right - (double)*this;
        
        return (difference < 0.001 && difference > -0.001);
    }

    
int operator+(int left, const EggCarton& right)
{
    
    int returnValue = 0;
    
    if(right)
    {
        returnValue = left + right;
    }else
    {
        returnValue = left;
    }
    
    return returnValue;
}


    ostream& operator<<(ostream& ostr, const EggCarton& right)
    {
        right.display(ostr);
        
        return ostr;
    }

    istream& operator>>(istream& istr, EggCarton& right)
    {
        right.read(istr);
        
        return istr;
    }


}
#endif
