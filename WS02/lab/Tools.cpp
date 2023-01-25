#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Tools.h"
#include "Package.h"

FILE* fp;

namespace sdds {
    int openFile_r(const char filename[]) { // Fully provided
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }
    int noOfTraces() {  // Fully provided
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');
        }
        rewind(fp);
        return noOfTraces;
    }
    

    // To Do: read functions (4 overloaded read functions)
    
      

        int read(char packageName[]) {
        
            int returnValue{};
            char buffer[60];
            returnValue = fscanf(fp, "%60[^\n]\n", buffer);
        
            strCpy(packageName, buffer);
            return returnValue;
        }


    int read(int* result) {
        
        int returnValue{};
        int buffer{};
        returnValue = fscanf(fp, "%d,", &buffer);
        result = &buffer;
               
               
        return returnValue;
    }

    int read(double* result) {
        
        int statusValue{};
        double buffer{};
        statusValue = fscanf(fp, "%lf,", &buffer);
        result = &buffer;
        
        return statusValue;
    }

    int read(char result) {
        
        int statusValue{};
        char buffer{};
        fscanf(fp, "%[^ \t\n\r\v\f,]%*c", &buffer);
        
//        result = &buffer;
        
        return statusValue;
    }

    

    void closefile() { // Fully provided
        if (fp) fclose(fp);
    }
    
    void strCpy(char* str1, const char* str2) { // Fully provided 
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) {  // Fully provided
        int i = -1;
        while (str[++i]);
        return i;
    }
}
