#include <iostream>
#include <utility>

int main(){
    const int length = 5;
    int input[length] = {30,50,20,10,40};
    
    for(int i = 0; i < length; i++){
        int j = i;
        while(j > 0 && input[j-1] > input[j]){
            std::swap(input[j-1], input[j]);
            j--;
        }
    }
    
    for(int i = 0; i < length; i++){
        std::cout << input[i] << " ";
    }
    
    return 0;
}
