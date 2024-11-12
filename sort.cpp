
#include <iostream>
using namespace std;
int main()
{
    const int n = 6;
    int array[n] = {1,2,6,4,2,7};
   int left = 1;
   int right = n - 1;
   bool swaped = true;
   while(swaped == true){
   for(int i = left; i <= right;++i){
       if(array[i] > array[i + 1]){
           swap (array[i + 1 ], array[i]);
           swaped = false;
       }
       right--;
   }
   for(int i = right; i >= left;--i){
       if(array[i] < array[i + 1]){
           swap (array[i], array[i + 1])
           swaped = false;
       }
       left++;
   }
   
   }
}
