#include <iostream>
using namespace std;

int* arr(int size) {
    int* newArray = new int[size];
    for (int i = 1; i < size; i++)
        newArray[i] = i;
    return newArray;

}
bool contains(int* array, int size, int key) {
    for (int i = 1; i < size; i++)
        if (array[i] == key) return true;
    return false;
}
int* GetRandomTicket(int size) {
    int* mass = new int[size];
    for (int i = 1; i < size; i++) {
        int randt = rand() % 20 + 1;
        if(!contains(mass,size, randt))
            mass[i] = randt;
        else {
            i--;
            continue;
        }
    }
    return mass;
}
void Print(int* arr, int* arr1, int size) {
    for (int i = 1; i < size; i++)
        cout << arr[i] << "." << arr1[i] << endl;
}
int main()
{
    int size = 17;
    int* student = arr(size);
    int* ticket = GetRandomTicket(17);
    Print(student, ticket, size);
    
}

