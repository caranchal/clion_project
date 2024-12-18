#include <iostream>
#include <string>

using namespace std;

string* returnTest(string& str) {
    string* stringPtr = new string; // Создаем память под string
    *stringPtr = str; // Устанавливаем значение из str в только что выделенную память
    return stringPtr; // Возвращаем указатель на строку
}

int main() {
    string str = "test"; // Определяем строку и инициализируем ее
    string* newStr = returnTest(str); // Вызываем функцию и получаем указатель на новый string

    cout << newStr << endl; // Выводим адрес newStr
    cout << *newStr << endl; // Выводим значение, на которое указывает newStr
    cout << &*newStr << endl; // Выводим адрес значения, на которое указывает newStr
    cout << *&*newStr << endl; // Выводим то же значение, что и *newStr
    cout << &*&*newStr << endl; // Выводим адрес того же значения
    cout << *&*&*newStr << endl; // Выводим то же значение, что и *newStr
}
