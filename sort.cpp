//
// Created by abrikosik on 17.11.2024.
//
#include "sort.h"
#include <iostream>

int temp;

void buble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
}

void insert_sort(int arr[], int size) {
    int temp;
    int i, j;
    for (i = 1; i < size; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
            arr[j + 1] = arr[j];

        arr[j + 1] = temp;
    }
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
}

void select_sort(int arr[], int size) {
    int min, temp;
    for (int i = 0; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min == i) continue;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
}