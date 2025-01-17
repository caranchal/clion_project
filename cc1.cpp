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
/*int* Summass(int* array, int* array2, int size, int size2) {
    bool flag = false;
    int size_max = 0;
    //int size_min = 0;
    size_max = (size > size2) ? size : size2;
    //size_min = (size < size2) ? size : size2;

    if (flag) {
        int* SumArray = new int[size_max];
        for (int i = 0; i < size_max; i++) {
            SumArray[i] = array2[i];
        }
        for (int j = 0; j < size_max; j++) {
            SumArray[j] += array[j];
        }
    }
    else {
        int* SumArray = new int[size];
        for (int i = 0; i < size; i++) {
            SumArray[i] = array[i];
        }
        for (int j = 0; j < size; j++) {
            SumArray[j] += array2[j];
        }
    }
    return SumArray;

    
    
}*/

int* Summass(int* arr, int* arr2, int size1, int size2) {
   bool flagA = false;
    int size_max = 0;
    if (size1 > size2) {
        size_max = size1;
        flagA = true;
    }
    else {
        size_max = size2;
    }
    int* SumArray = new int[size_max];

    if (flagA == true) {
        for (int i = 0; i < size_max; i++) {
            SumArray[i] = arr[i];
        }
        for (int j = 0; j < size_max; j++) {
            SumArray[j] += arr2[j];
        }
    }
    else {
        
        for (int i = 0; i < size_max; i++) {
            SumArray[i] = arr2[i];
        }
        for (int j = 0; j < size_max; j++) {
            SumArray[j] += arr[j];
        }
    }
    return SumArray;
}
int main()
{
    int* arr = initArray(7);
    int* arr2 = initArray(10);
   //int* SumArray = summass(arr, arr2, 5);
   //int* sum = Sum(arr, 5, 20);
    //printArray(SumArray,7);
    int* SumArray = Summass(arr, arr2, 7, 10);
    printArray(SumArray, 10);
    cout << endl;
    //printArray(sum, 7);

}
