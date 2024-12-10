#include <iostream>
#include<string>
using namespace std;

void palindrom(string* str) {
    string& pal = *str;
    int counter = 0;
    for (int i = 0; i < pal.size(); i++) {
        if (pal[i] == pal[pal.size() - 1 - i]) {
            counter++;
        }
    }


    if (counter == pal.size()) {
        cout << "yes";
    }
    else {
        cout << "no";
    }

}
int* dynamicArray(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10;
    }

    return array;
}

int sredArr(int* array, int size) {
    int sum = 0;

    for (int i = 0; i < size;i++) {
        sum += array[i];

    }
    int result = sum / size;

    return result;
}
int* sortArray(int* array, int size) {
    int* sort = new int;
    int temp = 0;
    for (int i = 0; i < size;i++) {
        temp = array[i];
        if (temp > array[i + 1]) {
            array[i + 1] = temp;
        }
        else {
            array[i] = temp;
        }
    }
    return array;
}\
void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

}

int main() {
    string pal = "ababa";
    string* pal1 = &pal;
    palindrom(pal1);
    cout << endl;
    int* arr = dynamicArray(10);
    printArray(arr, 10);
    cout << endl;
    sortArray(arr, 10);
    printArray(arr, 10);
    //cout << sredArr(arr,10);




}

