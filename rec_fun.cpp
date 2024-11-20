//
// Created by abrikosik on 20.11.2024.
//
#include <iostream>


using namespace std;

int fib(int n) {
    if (n > 0 && n > 2) {
        return fib(n - 2) + fib(n - 1);
    } else {
        return 1;
    }
}

int stepen(int number, int i) {
    if (i > 1) {
        return number * stepen(number, i - 1);
    }
    if (i == 1) {
        return number;
    }
    if (i == 0) {
        return 1;
    }


}

int main() {
    //cout << fib(10);
    cout<<stepen(2,10);
}