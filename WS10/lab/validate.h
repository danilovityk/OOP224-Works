#include <iostream>



template <typename type>

bool validate(const type& minimum_value, const type* testingArray, const int arraySize, bool* resultsArray){
    bool returnValue = true;
    
    for (int i = 0; i < arraySize; i++){
        
        if (testingArray[i] >= minimum_value){
            resultsArray[i] = true;
        }else {
            resultsArray[i] = false;
        }
    
    }
    
    
    for (int i = 0; i < arraySize; i++){
        
        if (resultsArray[i] == false) returnValue = false;
        
        
        
    }
    
    
    return returnValue;
}


