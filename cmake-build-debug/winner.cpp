//
// Created by abrikosik on 02.11.2024.
//
#include <iostream>
#include "windows.h"

using namespace std;

void bubbleSort(int list[], int listLength) {
    while (listLength--) {
        bool swapped = false;

        for (int i = 0; i < listLength; i++) {
            if (list[i] > list[i + 1]) {
                swap(list[i], list[i + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int list[7];
    int i{};
    cout << "Введите результаты 7 игроков" << endl;
    while (i < 7) {
        cin >> list[i];
        i++;
    }
    bubbleSort(list, 7);
    cout << "Первое место с результатом = " << list[6] << endl;
    cout << "Второе место с рузультатом = " << list[5] << endl;
    cout << "Третье место с результатом = " << list[4] << endl;


}