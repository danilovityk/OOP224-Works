/*
 *  *         Name: Danylo Vityk
 *   *         Email: dvityk@myseneca.ca
 *    *         Sudent ID: 176326213
 *     *         Date: Feb 21, 2023
 *      *
 *       *
 *        *         I have done all the coding by myself and only copied the code that my professor provided to complete my workshops
 *         *         and assignments.
 *          *
 *           *
 *           
 *
 *           */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Numbers.h"
using namespace std;
namespace sdds {


   void Numbers::sort(double* nums, unsigned int size) {
      unsigned int i, j;
      double temp;
      for(i = size - 1; size && i > 0; i--) {
         for(j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]) {
               temp = nums[j];
               nums[j] = nums[j + 1];
               nums[j + 1] = temp;
            }
         }
      }
   }

   unsigned int Numbers::countLines(const char* filename) { /**/
      unsigned int lines = 0u;
      ifstream nums(filename);
      while(nums) {
         lines += (nums.get() == '\n');
      }
      return lines;
   }

    Numbers::Numbers (const char filename[])
    {
        setEmpty();
        if(filename){
            strcpy(m_filename, filename);
            load();
        }
    }

Numbers::Numbers() { 
    setEmpty();
}
Numbers::~Numbers() {
    if(m_collection){
	if(m_collection[0] == -5) save();
}
    delete[] m_collection;
}

Numbers::Numbers(const sdds::Numbers &numbers) { 
    this->setEmpty();
    *this = numbers;
 
    
}

sdds::Numbers& Numbers::operator=(const sdds::Numbers &rOp) { 
    if(this != &rOp)
    {
        save();
        delete[] m_collection;
        this->setEmpty();
        if (rOp)
        {
            strcpy(m_filename, rOp.m_filename);
            m_original = false;
            m_collection = new double[rOp.m_collectionSize];
            for(unsigned int i = 0; i < rOp.m_collectionSize; i++)
            {
                m_collection[i] = rOp.m_collection[i];
            }
            m_collectionSize = rOp.m_collectionSize;

        }
    }
    return *this;
}

Numbers::operator bool() const { 
    return m_collection != nullptr;
}

void Numbers::sort() { 
    sort(m_collection, m_collectionSize);
}

sdds::Numbers& Numbers::operator+=(const double rOp) {
    if(*this)
    {
        double *temp = new double[m_collectionSize + 1];
        for (unsigned int i = 0; i < m_collectionSize; i++){
            temp[i] = m_collection[i];
        }
        temp[m_collectionSize] = rOp;
        delete[] m_collection;
        m_collection = temp;
        m_collectionSize++;
        
    }
    return *this;
}

std::ostream &Numbers::display(std::ostream &ostr) const { 
    if(*this)
    {
        ostr<<fixed<<setprecision(2);
        if (!m_original) ostr<<"Copy of ";

        ostr<< m_filename <<endl;
        for(unsigned int i = 0; i < m_collectionSize; i++)
        {
            ostr<<m_collection[i];
            if(i+1 != m_collectionSize) ostr<<", ";
        }
        ostr<<endl << string(76, '-') << endl;
        
        ostr<<"Total of "<< m_collectionSize << " number(s), Largest: " << max() <<", Smallest: " << min() << ", Average: " << average()<<endl;
        ostr << string(76, '=');
        
    }else
    {
        ostr<<"Empty list";
    }
    return ostr;
}

void Numbers::setEmpty() {
    
    m_collection = 0;
    m_filename[0] = '\0';
    m_collectionSize = 0;
    m_original = false;
    m_addedFlag = false;
}

bool Numbers::load() {
    unsigned int readLinesCount = countLines(m_filename);
    
    if(m_collection != nullptr)
        delete[] m_collection;
    if(readLinesCount > 0)
    {
        unsigned int size = 0;
        m_collection = new double[readLinesCount];
        ifstream file(m_filename);
        
        
        double temp;
        while(file >> temp)
        {
            m_collection[size++] = temp;
        }
        
        file.close();
        
        m_collectionSize = readLinesCount;
        m_original = true;
        
        if (size != readLinesCount)
        {
           // cout<<"\n\nWRONG SIZE OF LOAD\n\n";
            delete[] m_collection;
            setEmpty();
        }
        
        
    }
    
    return readLinesCount > 0;
}

void Numbers::save() {
    if (m_original && m_collectionSize > 0)
    {
        ofstream file(m_filename);
        
        file << fixed << setprecision(2);
        
        for(unsigned int i = 0; i < m_collectionSize; i++){
            file << m_collection[i] << endl;
        }
        
        file.close();
    }
}

double Numbers::max() const {
    
    double max = m_collection[0];
    for (unsigned int i = 1; i < m_collectionSize; i ++)
    {
        if(max < m_collection[i]){
            max = m_collection[i];
        }
    }
    return max;
}

double Numbers::min() const {
    double min = m_collection[0];
    for (unsigned int i = 1; i < m_collectionSize; i ++)
    {
        if(min > m_collection[i]){
            min = m_collection[i];
        }
    }
    return min;
}

double Numbers::average() const {
    double total = 0;
    for (unsigned int i = 0; i < m_collectionSize; i ++)
    {
        total += m_collection[i];
    }
    return total/m_collectionSize;
}


istream& operator>>(istream& istr, Numbers& right)
{
    double temp = 0;
    if(istr){
        istr >> temp;
    }
    right += temp;
    
    return istr;
}
ostream& operator<<(ostream& ostr, const Numbers& right)
{
   return  right.display(ostr);;
}

}
