//
// Created by abrikosik on 28.10.2024.
//
#include <iostream>
#include "math.h"
using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    if(a + b <= c){
        cout<<"UNDEFINED"<<endl;
        return 0;
    }
    if(pow(c,2) == pow(a,2) + pow(b,2)){
        cout<<"YES"<<endl;
        return 0;
    }
    else{
        cout<<"NO"<<endl;
        return 0;
    }
}