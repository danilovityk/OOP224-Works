#ifndef soccerTeam_hpp
#define soccerTeam_hpp

const int MAX_FOUL = 4;

#include <stdio.h>

namespace sdds{

class SoccerTeam{
    
private:
    char m_teamName[41];// a statically allocated Cstring with size 41. Remember, name could be
    //maximum 40 characters long and 1 byte is for the null byte.
    int m_noFouls;//number of fouls, it can be zero or more but cannot be a negative number
    double m_fines;//it can be equal to and more than zero.
    int m_golas;//can be zero or more
   
    
public:
    int fouls() const ;
    bool isEmpty() const;
    void setEmpty();
    void setFine(double fines, int foul);
    void setTeam(const SoccerTeam& team);
    void setName(const char* tname);
    void calFines();
    std::ostream& display()const;

    SoccerTeam();
    SoccerTeam(const char* tname, double fines, int foul);
    
};


}

#endif /* soccerTeam_hpp */
