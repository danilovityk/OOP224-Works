#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_


namespace sdds {
   class Numbers {
       
       double* m_collection;
       char m_filename[255];
       unsigned int m_collectionSize;
       bool m_original;
       bool m_addedFlag;
       
       void setEmpty();
       bool load();
       void save();
       double max() const;
       double min() const;
       double average() const;
       
       unsigned int countLines(const char* filename);
       void sort(double* collectionPtr, unsigned int size);
       
   public:
       
       Numbers (const char filename[]);
       Numbers();
       ~Numbers();
       Numbers(const Numbers &numbers);
       Numbers& operator=(const Numbers& rOp);
       operator bool() const;
       void sort();
       Numbers operator+=(const double rOp);
       std::ostream& display(std::ostream& ostr = std::cout) const;
       
       
      
    
   };

std::istream& operator>>(std::istream& istr, Numbers& right);
std::ostream& operator<<(std::ostream& ostr, const Numbers& right);

}
#endif // !SDDS_NUMBERS_H_

