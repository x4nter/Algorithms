#include <iostream>

int main(){
  const int length = 10;
  int array[length] = {10,20,30,40,50,60,70,80,90,100};
  int target;
  std::cin >> target;
  
  int min = 0;
  int max = length-1;
  
  while(1){
    int mid = min + (max-min)/2;
    
    if(array[mid] == target){
      std::cout << "Target found at element " << mid << std::endl;
      break;
    }
    if(max == min){
      std::cout << "Target not found" << std::endl;
      break;
    }
    if(target < array[mid])
      max = mid-1;
    if(target > array[mid])
      min = mid+1;
  }
  
  return 0;
}
