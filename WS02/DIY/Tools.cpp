/*
        Name: Danylo Vityk
        Email: dvityk@myseneca.ca
        Sudent ID: 176326213
        Date: Jan 31, 2023


 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


*/



#define _CRT_SECURE_NO_WARNINGS
#include "Tools.h"

namespace sdds {
   void strCpy(char* str1, const char* str2) {
      while(*str2) {
         *str1++ = *str2++;
      }
      *str1 = 0;
   }
}
