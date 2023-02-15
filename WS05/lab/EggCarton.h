#ifndef EGGCARTON_H
#define EGGCARTON_H

namespace sdds
{
    
    const int RegularEggWieght = 50;
    const int JumboEggWieght = 75;
    
    
    class EggCarton
    {
        
        
    private:
        int m_size;
        int m_noOfEggs;
        bool m_jumboSize;
        
        
        void setBroken();
        std::ostream& displayCarton(int size, int noOfEggs, bool jumbo, std::ostream& ostr)const;
        
    public:
        
        EggCarton(int size=6, int noOfEggs=0, bool jumboSize=false);
        std::ostream& display(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr = std::cin);
        
        operator bool() const;
        operator int() const;
        operator double() const;
        
        EggCarton& operator++();
        EggCarton& operator--();
        
        EggCarton operator++(int);
        EggCarton operator--(int);
        
        EggCarton& operator=(int value);
        //Sets the number of eggs to the integer value and If the number of eggs exceeds the size, it will set the Carton to broken. Returns a reference to the current object at the end.
        
        EggCarton& operator+=(int value);
        //Add the value to the number of eggs if the Carton is not broken. If the number of eggs exceeds the size, it will set the Carton to broken. Returns a reference to the current object at the end.

        EggCarton& operator+=(EggCarton& right);
        //If the Carton is not broken it will move the eggs from the right Carton to the empty spots of the current Carton as much as it can. If there is not enough space in the current Carton, the rest of the eggs are left in the right one.

        //For example, if the current Carton has 3 empty spots and there are 7 eggs in the right Carton after this operator runs, the current Carton will be full and the right Carton will have 4 eggs in it.

        //In the end, return a reference to the current object.

        bool operator==(const EggCarton& right) const;
        //Return true if the difference between the weight of the current Carton and the weight of the right Carton is between -0.001 and 0.001 kilos otherwise, return false.

        
        
        
        
        

};

    int operator+(int left, const EggCarton& right);
    //If the right operand is not broken it will return the sum of "left" and the number of eggs in the     "right". Otherwise, it will return the value of the left only.
    
    std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);
    //displays the EggCarton and returns ostr;
    
    std::istream& operator>>(std::istream& istr, EggCarton& right);
    //Reads the specs from the console into the right Carton and returns istr.

}

#endif
