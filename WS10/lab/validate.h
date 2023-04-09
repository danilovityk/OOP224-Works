/*
 *         Name: Danylo Vityk
 *         Email: dvityk@myseneca.ca
 *         Sudent ID: 176326213
 *         Date: April 8, 2023
 *
 *
 *         I have done all the coding by myself and only copied the code that my professor provided to complete my workshops
 *         and assignments.
 *
 *
 */

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


