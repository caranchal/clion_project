//
// Created by abrikosik on 12.11.2024.
//
#include <iostream>
using namespace std;
int main() {
    const int n = 10;
    int array[n];
    int number = 0;
    for(int i = 0; i < n;++i){
        cin>>number;
        array[i] = number;

    }
for(int i = 0; i < n;++i){
    if(array[i] == 1 ){
        cout<<array[i]<<"*"<<endl;
    }
    if(array[i] == 2){
        cout<<array[i]<<"**"<<endl;
    }
    if(array[i] == 3 ){
        cout<<array[i]<<"***"<<endl;
    }
    if(array[i] == 4){
        cout<<array[i]<<"****"<<endl;
    }
    if(array[i] == 5 ){
        cout<<array[i]<<"*****"<<endl;
    }
    if(array[i] == 6){
        cout<<array[i]<<"******"<<endl;
    }
    if(array[i] == 7 ){
        cout<<array[i]<<"*******"<<endl;
    }
    if(array[i] == 8){
        cout<<array[i]<<"********"<<endl;
    }
    if(array[i] == 9 ){
        cout<<array[i]<<"*********"<<endl;
    }

}
}