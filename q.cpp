#include <iostream>
#include <vector>
using namespace std;
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
int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}


int linearSearch(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            return i;
        }
    }
    return -1;
}
int binarySearchIterative(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    
    return -1; 
}

int main() {
   
}
void mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) return;

    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    mergeSort(left);
    mergeSort(right);

   
    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }

    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

int main() {

    vector<int> sortedArray = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

    int target = 7;
    int result = binarySearchIterative(sortedArray, target);

    if (result != -1) {
        std::cout << "Элемент " << target << " найден по индексу: " << result << std::endl;
    }
    else {
        std::cout << "Элемент " << target << " не найден" << std::endl;
    }

    target = 10;
    result = binarySearchIterative(sortedArray, target);

    if (result != -1) {
        std::cout << "Элемент " << target << " найден по индексу: " << result << std::endl;
    }
    else {
        std::cout << "Элемент " << target << " не найден" << std::endl;
    }

    return 0;

    vector<int> numbers = { 7, 3, 5, 2, 6, 1, 4 };

    cout << "До: ";
    for (int n : numbers) cout << n << " ";

    mergeSort(numbers);

    cout << "\nПосле: ";
    for (int n : numbers) cout << n << " ";

    return 0;
}
