#include <iostream>
using namespace std;
int main()
{
    int a;
    int array[10];
    int mass[10];
    for(int i = 9; i > 0; --i){
        cin>>a;
       array[i] = a;
       
    }
    for(int i = 0; i < 10; ++i){
        cout<<array[i];
    }
}
