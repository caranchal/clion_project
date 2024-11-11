//
// Created by abrikosik on 30.10.2024.
//
#include <iostream>

using namespace std;

int main() {
    /*int y, x;
    const int n = 5, m = 6;
    int a[n][m];
    for (int i = 0; i < n; ++i) {
        int j_min = 0;
        for (int j = 1; j < m; ++j) {
            if (a[i][j] < a[i][j_min]) { j_min = j; }
        }
        if (i == 0 || a[i][j_min] > a[y][x]) {
            y = i;
            x = j_min;
        }
    }
    cout << y << ' ' << x;*/

    const int n = 5;
    int array[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            array[i][j] = i + j;
        }
    }
    int counter;//1 задание
    for (int i = 0; i < n; ++i) {

        for (int k = 0; k < n; ++k) {
            if (array[i][k] == 0) {
                counter++;
            }

        }
    }
    cout << counter << endl;
    int counter2;//2 задание
    for (int i = 0; i < n; ++i) {
        counter2 = 0;
        for (int j = 0; j < n; ++j) {
            if (array[i][0] == array[i][j]) counter2++;
        }
    }
    cout << counter2 << endl;

    int counter1;//3 задание
    for (int i = 0; i < n; i++) {
        counter1 = 0;
        for (int j = 0; j < n; j++)
            if (array[i][j] % 2 == 1 && array[i][j] != 0)counter1++;

    }
    cout << counter1 << endl;


}
