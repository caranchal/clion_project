#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectionSort(vector<int>& arr, int& comp, int& swaps) {
    comp = swaps = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            comp++;
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            swaps++;
        }
    }
}

void insertionSort(vector<int>& arr, int& comp, int& swaps) {
    comp = swaps = 0;
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0) {
            comp++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            }
            else break;
        }
        arr[j + 1] = key;
    }
}
int improvedBinarySearch(const vector<int>& arr, int target, int& comparisons) {
    comparisons = 0;
    int left = 0;
    int right = arr.size() - 1;

    // Быстрая проверка границ
    comparisons++;
    if (arr[left] == target) return left;
    comparisons++;
    if (arr[right] == target) return right;

    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
            // Дополнительная проверка после сдвига
            if (left <= right) {
                comparisons++;
                if (arr[left] == target) return left;
            }
        }
        else {
            right = mid - 1;
            // Дополнительная проверка после сдвига
            if (left <= right) {
                comparisons++;
                if (arr[right] == target) return right;
            }
        }
    }
    return -1;
}

template<typename Func>
long long measureTime(Func searchFunc, const vector<int>& arr, int target, int& comparisons) {
    auto start = high_resolution_clock::now();
    int result = searchFunc(arr, target, comparisons);
    auto end = high_resolution_clock::now();
    return duration_cast<nanoseconds>(end - start).count();
}

vector<int> createUniformArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    return arr;
}
vector<int> createNonUniformArray() {
    return { 1, 2, 3, 1000, 50000, 1000000 };
}



int main() {
    vector<int> arr = { 5, 2, 8, 1, 9, 3, 7, 4, 6 };
    vector<int> arr2 = arr;

    int comp1, swaps1, comp2, swaps2;

    selectionSort(arr, comp1, swaps1);
    insertionSort(arr2, comp2, swaps2);

    cout << "Выбором: сравнений=" << comp1 << ", обменов=" << swaps1 << endl;
    cout << "Вставкой: сравнений=" << comp2 << ", обменов=" << swaps2 << endl;

    
    vector<int> targets = { 1, 500000, 1000000, 999999, 250000 };

    cout << "СЛОЖНОСТЬ АЛГОРИТМОВ:" << endl;
    cout << "Линейный поиск: O(n)" << endl;
    cout << "Бинарный поиск: O(log n)" << endl;
    cout << "Улучшенный бинарный: O(log n)" << endl;
    cout << "Интерполяционный: O(log log n) в среднем, O(n) в худшем" << endl;
    cout << "==========================================" << endl;

    // Тест на равномерном массиве
    vector<int> uniformArr = createUniformArray(1000000);
    testSearch("РАВНОМЕРНЫЙ МАССИВ [1..1000000]", uniformArr, targets);

    // Тест на неравномерном массиве
    vector<int> nonUniformArr = createNonUniformArray();
    testSearch("НЕРАВНОМЕРНЫЙ МАССИВ [1,2,3,1000,50000,1000000]", nonUniformArr, { 1, 3, 1000, 50000, 1000000 });

    return 0;
}
