#include <iostream>
#include <fstream>
#include "PosIO.h"

using namespace std;

namespace sdds{

std::ostream& operator<<(std::ostream& ostr, const PosIO& pos){
    pos.write(ostr);
    return ostr;
}
std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& pos){
    pos.save(ofstr);
    return ofstr;
}

std::istream& operator>>(std::istream& istr, PosIO& pos){
    pos.read(istr);
    return istr;
}
std::ifstream& operator>>(std::ifstream& ifstr, PosIO& pos){
    pos.load(ifstr);
    return ifstr;
}

}
