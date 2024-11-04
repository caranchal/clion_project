//
// Created by abrikosik on 04.11.2024.
//
#include <iostream>
#include "windows.h"
#include <vector>

using namespace std;


void value_n_sum(int n) {
    int sum_value;
    while (n != 0) {

        sum_value += n % 10;
        n /= 10;
    }
    cout << sum_value << endl;
}

void way(int s) {
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

int easy_values(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        } else {
            return true;
        }

    }

}

int main() {
    /*value_n_sum(55);
    way(4);
    password();*/
    for (int i = 2; i <= 1000; ++i) {
        cout<<easy_values(i)<<endl;


   }
}