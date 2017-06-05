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
