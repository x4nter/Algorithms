//Algorithm Type: Iterative
//Efficiency: O(n^2)
//How it works:
//-loop through the array and find the next minimum value
//-swap the element starting with the first index
//-repeat the steps for next indices

#include <iostream>
#include <utility>

int main(){
    const int length = 5;
    int input[length] = {40,30,10,50,20};

    for(int i = 0; i < length; i++){
        int smallest = i;
        for(int j = i+1; j < length; j++){
            if(input[j] < input[smallest])
                smallest = j;
        }
        std::swap(input[smallest], input[i]);
    }

    for(int i = 0; i < length; i++){
        std::cout << input[i] << " ";
    }
    
    return 0;
}
