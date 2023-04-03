// Final Project
// Point of Sale Application
// Version 1.0
// Date  2023-03-29
// Author   Fardad Soleimanloo
// Description
// This program test the student implementation of the Point of
// Sale Application
//
/////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include "PosApp.h"
void resetDataFile();
void displayfileContent();
int main() {
   resetDataFile();
   displayfileContent();
   sdds::PosApp pos("/Users/danilovityk/Documents/OOP244/OOP224-Works/Proj/MS5/posdata.csv");
   pos.run();
   displayfileContent();
   return 0;
}
void resetDataFile() {
   char ch{};
   std::ofstream outfile("/Users/danilovityk/Documents/OOP244/OOP224-Works/Proj/MS5/posdata.cs");
   std::ifstream infile("/Users/danilovityk/Documents/OOP244/OOP224-Works/Proj/MS5/posdataOrigin.csv");
   while(infile.get(ch)) {
      outfile.put(ch);
   }
}
void displayfileContent() {
   std::cout << "Data file:\n------------------\n";
   char ch{};
   std::ifstream infile("/Users/danilovityk/Documents/OOP244/OOP224-Works/Proj/MS5/posdata.csv");
   while(infile.get(ch)) {
      std::cout.put(ch);
   }
   std::cout << "------------------\n";
}
