#include <iostream>
using namespace std;

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " "; 
    }
    cout << endl; 
}

void printTriangle(int size) {
    int* arrayLast = new int[size]; 
    arrayLast[0] = 1; 
    printArray(arrayLast, 1); 

    for (int i = 1; i < size; i++) {
        int* newArray = new int[i + 1]; 
        newArray[0] = 1; 
        newArray[i] = 1; 

       
        for (int j = 1; j < i; j++) {
            newArray[j] = arrayLast[j - 1] + arrayLast[j];
        }

        printArray(newArray, i + 1);

        delete[] arrayLast;

        arrayLast = newArray;
    }

    delete[] arrayLast;
}

int main() {
    printTriangle(5);
}


