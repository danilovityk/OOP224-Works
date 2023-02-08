#include <iostream>
#include <iomanip>
#include <cstring>
#include "Soccer.h"

using namespace std;

namespace sdds {

void SoccerTeam::setTeam(const SoccerTeam& team)
{
    setName(team.m_teamName);
    setFine(team.m_fines, team.m_noFouls);
}


void SoccerTeam::setName(const char* tname)
{
    if (tname != nullptr & tname[0] != '\0')
    {
        strcpy(m_teamName, tname);
    }else{
        setEmpty();
    }
}

void SoccerTeam::setFine(double fines, int foul)
{
    
    if(fines >= 0 && foul >= 0)
    {
        m_fines = fines;
        m_noFouls = foul;
        
    }else
    {
        setEmpty();
    }
    
}

void SoccerTeam::setEmpty()
{
    strcpy(m_teamName, "");
    m_fines = -1;
    m_noFouls = -1;
    m_golas = 0;
};

bool SoccerTeam::isEmpty() const
{
    bool result = false;
    
    if(m_teamName[0] != '\0' && m_fines >= 0 && m_noFouls >= 0)
        result = true;
    
    
    
    return result;
    
}

void SoccerTeam::calFines(){
    
    m_fines *= 1.2;
    m_noFouls *= 2;
}


int SoccerTeam::fouls() const
{
    return m_noFouls;
}

void SoccerTeam::increaseGoal(){
    m_golas++;
}

SoccerTeam::SoccerTeam()
{
    setEmpty();
}

SoccerTeam::SoccerTeam(const char* tname, double fines, int foul)
{
    setName(tname);
    setFine(fines, foul);
    m_golas = 0;
}


std::ostream& SoccerTeam::display()const{
    
 
    
    if(isEmpty())
    {
        cout.unsetf(ios::right);
        cout.setf(ios::left);
        cout.width(30);
        cout << m_teamName;
        
        
        cout.width(6);
        cout << right << fixed << setprecision(2);
        cout << m_fines;
        
        cout.width(6);
        cout << m_noFouls;
        
        
        cout.width(10);
        if (m_golas > 0){
            cout << m_golas << "w";
        } else{cout << m_golas << " ";}
        
        return cout;
        
    }else
    {
        return cout << "Invalid Team";
    }
    
}
}


