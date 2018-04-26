//Algorithm Type: Iterative
//Efficiency: O(n^2)
//How it works:
//-loop through the array, if two consecutive elements are in the wrong position swap them.
//-loop n * (n-1) to sort the whole array

#include <iostream>
#include <utility>

int main(){
    int length = 5;
    int input[length] = {40,20,50,10,30};
    
    for(int i = 0; i < length - 1; i++){
        for(int i = 0; i < length - 1; i++){
            if(input[i] > input[i+1])
                std::swap(input[i], input[i+1]);
        }
    }
    
    for(int i = 0; i < length; i++){
        std::cout << input[i] << " ";
    }
    
    return 0;
}
