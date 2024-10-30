//
// Created by abrikosik on 29.10.2024.
//
#include <windows.h>
#include<iostream>
#include "math.h"
using namespace std;
int resistance(double R1, double R2, double R3){ //округляет результат -
    double answer = ((1/(1 / R1) + 1 / R2 + (1 / R3)));
    return answer;
}
int cordinate(float x1, float y1, float x2, float y2){ //округляет результат -
    float distance = sqrt(pow(x1,2) + pow(x2,2) + (pow(y1,2) + pow(y2,2)));
    return distance;

}
void ravennstvo(int a, int b, int c){ //ok
    if((a < b && a < c) && (b > a && b < c) && (c > b && c > a)){
        cout<<"верно равенство"<<endl;
    }
    else{
        cout<<"неверно равенство"<<endl;
    }

}
void ravenstvo_3(int a, int b, int c){ //ok
    while(true){
        if(a >= 1 && a <= 3){
            cout<<"входит a\t"<<endl;

        }
        if(b >= 1 && b <= 3){
            cout<<"входит b\t"<<endl;

        }
        if(c >= 1 && c <= 3){
            cout<<"входит c\t"<<endl;
           break;
        }


    }
}
void value_n_lenght(int n){
    int count_value;

    int i = 0;
    for(;n > 0;i++){
        n /= 10;

    }
    cout<<"в данном числе "<<i<<" символов"<<endl;
}
void value_n_sum(int n){
    int sum_value;
    while(n != 0){

        sum_value += n % 10;
        n = n / 10;
        break;
    }
    cout<<sum_value;
}
void sum_value(int n){
    int sum_value = 0;
    while (n != 0) {
        sum_value += n%10;
        n /= 10;
        sum_value = sum_value;
    }
    cout << sum_value<<endl;
}
void last_value(int value){
    int last = value % 10;
    cout<<last<<endl;
}
void first_value(int value){
    if(value < 10){
       cout<<value<<endl;
    }
    if(value > 10 && value << 100){
        cout<<value / 10<<endl;
    }
    else{
        cout<< value / 100<<endl;
    }
}
int main() {
    SetConsoleOutputCP(CP_UTF8);

    cout << resistance(1, 2, 3) << endl;
    cout << cordinate(1.0, 2.0, -3.0, 4.0) << endl;
    ravennstvo(3, 2, 3);
    ravenstvo_3(1, 4, 1);
    value_n_lenght(56);
    sum_value(56);
    last_value(2);
    first_value(45);
    return 0;
}