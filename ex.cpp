#include <iostream>
#include <string>
using namespace std;

int* Arr(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10;
    }
    return array;
}

void PrintArray(int* array, int size) {
    for (int i = 0; i < size;i++) {
        cout << array[i] << " ";
    }
}

float sred(int* array, int size) {
    float temp = 0;
    for (int i = 0; i < size; i++) {
        temp += array[i];
    }
    float sred = temp / size;
    return sred;
}
string Lower(string& str) {
    string result = str;
    for (int i = 0; i < size(str);i++) {
        if (isupper(str[i])) {

            result[i] = result[i] + 32;
            
        }
    }
    return result;
}
/*string task3(string str) {
    string result = str;
    int res = 0;
    for (int i = 0; i < result.size(); i++) {
        //res = 97 - i + 1;
        res = 122 - str[i] - 97;
        result[i] = res;
        res = 0;
    }
    return result;
}
*/
int main()
{
    string test = "HELLO WORLD";
    int* arr = Arr(10);
    PrintArray(arr, 10);
    cout << endl;
    cout << sred(arr,10);
    cout << endl;
   cout << Lower(test);
    //string test1 = task3(test);
    //cout << test1;
    
    
}

