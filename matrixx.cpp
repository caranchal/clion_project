//
// Created by abrikosik on 05.11.2024.
//

#include <iostream>
#include <algorithm>
#include "windows.h"

using namespace std;

int sort(int array[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {

    int mat[7];
    int matrix[5][7];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7; ++j) {

            matrix[i][j] = rand() % 60 - 30;
            mat[j] = matrix[0][j];
        }
    }
    /*for(int i = 0; i < 5;++i){
        for(int j = 0; j < 7;++j){
            cout<<matrix[i][j]<<" ";
        }       
        cout<<endl;
    }*/


    for (int j = 0; j < 7; ++j) {
        cout << mat[j] << "  ";
    }
    sort(mat, 7);
    for (int j = 0; j < 7; ++j) {
        cout << "  " << mat[j];
    }
}

