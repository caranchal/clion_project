#include <iostream> 
using namespace std;



int* initArray(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10;
    }
    return array;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void printArray(int* array, int size, int position) {
    for (int i = 0; i < size; i++) {
        if (i == position) {
            cout << "\033[31m" << array[i] << "\033[0m" << " ";
        }
        else
            cout << array[i] << " ";
    }
    cout << endl;
}


int* delPosition(int*& array, int size, int pos) {
    int* newArray = new int[size - 1];

    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i != pos) {
            newArray[j] = array[i];
            j++;
        }
    }

    // [1,2,3] size = 3 
    // [1, ] size = 2 
    delete[] array;
    return newArray;
}

//1. Удаление i-ого элемента массива. 
void task1() {
    const int size = 10;
    int* array = initArray(size);
    printArray(array, size, 4);

    int* deletedArray = delPosition(array, size, 4);
    printArray(deletedArray, size - 1);
}



int* summass(int* array, int* array2, int size) {
    int* SumArray = new int[size];
    int temp = 0;
    for (int i = 0; i < size; i++) {
        SumArray[i] = array[i] + array2[i];
    }
    return SumArray;
}
int* Sum(int* array, int size, int num) {
    int* SumArray = new int[size];
    for (int i = 0; i < size; i++) {
        SumArray[i] = num + array[i];
    }
    return SumArray;
}

int* delmass(int* array, int* array2, int size) {
    int* SumArray = new int[size];
    int temp = 0;
    for (int i = 0; i < size; i++) {
        SumArray[i] = array[i] / array2[i];
    }
    return SumArray;
}
int main()
{
    int* arr = initArray(5);
    int* arr2 = initArray(5);
    int* SumArray = summass(arr, arr2, 5);
    int* sum = Sum(arr, 5, 20);
    printArray(SumArray,5);
    cout << endl;
    printArray(sum, 5);

}
