//
// Created by abrikosik on 17.11.2024.
//
#include <iostream>
#include "sort.h"
#include <windows.h>
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    const int size = 10;
    int arr[10];
    int a;
    cout<<"Ведите 10 элементов "<<endl;
    for(int i = 0; i < size;i++){
        cin>>a;
        arr[i] = a;
    }
    int b;
cout<<"веберите метод сортировки"<<endl;
    cout<<"1 = пузырьком "<<endl;
    cout<<"2 = вставкой "<<endl;
    cout<<"3 = выборкой "<<endl;
    cin>>b;
    while(true) {
        if (b == 1) {
            buble_sort(arr, size);
            return 0;
        }
        if (b == 2) {
            insert_sort(arr, size);
            return 0;
        }
        if (b == 3){
            select_sort(arr,size);
            return 0;
        }

    }

}