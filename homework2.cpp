//
// Created by abrikosik on 04.11.2024.
//
#include <iostream>
#include "windows.h"
#include <vector>
#include <cmath>

using namespace std;


void value_n_sum(int n) {// сумма чисел
    int sum_value;
    while (n != 0) {

        sum_value += n % 10;
        n /= 10;
    }
    cout << sum_value << endl;
}

void way(int s) {//путь черепахи
    int start = 15;
    while (s != 2) {
        start += 2;
        start += start;
        s -= 1;

    }
    cout << start << endl;

}

void password() {
    std::vector<int> numbers;
    for (int i = 0; i <= 9; ++i) {
        numbers.push_back(i);
    }
    int counter;
    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = 0; j < numbers.size(); ++j) {
            for (int k = 0; k < numbers.size(); ++k) {
                if (i != j && i != k && j != k) {
                    cout << numbers[i] << numbers[j] << numbers[k] << endl;
                    counter++;
                }
            }

        }
    }
    int time = 3;
    int bad_time = time * counter;
    SetConsoleOutputCP(CP_UTF8);
    cout << "количество возможных комбинаций = " << counter << endl;
    cout << "время на худший исход = " << bad_time << " секунд" << endl;
}

void picture(int colvo, string symbol, string vertikal) {//вывод символов
    if (vertikal == "-") {
        for (int i = 0; i < colvo; ++i) {
            cout << symbol;

        }
        if (vertikal == "|") {
            for (int j = 0; j < colvo; ++j) {
                cout << symbol << endl;
            }

        }
    }


}

bool easy_number(int n) {//простое число
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}


int main() {
    /*value_n_sum(55);
    way(4);
    password();
    SetConsoleOutputCP(CP_UTF8);

    int colvo;
    string symbol;
    string vertikal;
    cout << "ВВедите количество символов которые хотите ввести" << endl;
    cin >> colvo;
    cout << "ВВедите символ который хотите видеть и" << endl;
    cin >> symbol;
    cout << "введите напрвление - или |" << endl;
    cin >> vertikal;
    if (vertikal == "|") {
        for (int i = 0; i < colvo; ++i) {
            cout << symbol;

        }

    }
    if (vertikal == "|") {
        for (int j = 0; j < colvo; ++j) {
            cout << symbol << endl;
        }

    }*/

    /* for(int i = 2; i < 1000;++i){
         if(i * i % 24 == 1){
             cout<<i<<endl;
         }
 */
    int counter;
    SetConsoleOutputCP(CP_UTF8);
    cout << "" << endl;
    for (int i = 2; i < 1000; ++i) {
        if (easy_number(i) == true) {
            cout << i << "\t";
            counter++;
        }
    }
    cout << "всеого простых чисел = " << counter << endl;
}






