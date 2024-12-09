#include <iostream>
#include <string>
using namespace std;

/*int* codic(string str) {
    string res = str;
    const int n = size(str);
    int* array = new int[n];
    for (int i = 0; i < n; i++) {
        array[i] = str[i];
    }
    return array;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size;i++) {
        cout << array[i] << " ";
    }
}
*/


/*char* atbash(string str) {
    string newstr;
    char* p = new char[size(str)];
    for (int i = 0; i < size(str); i++) {
        *p = str[i];
    }
    return p;
}
*/
//атбаш
string at(string str) {
    string result = str;
    for (int i = 0; i < size(str);i++) {
        if (result[i] > 64 && result[i] < 91) {
            result[i] = 155 - result[i];
        }
        if (result[i] > 96 && result[i] < 123) {
            result[i] = 219 - result[i];
        }
        else result[i] = result[i];
    }
    return result;
}
//палиндром

void task4(string str) {
    string pal = str;
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
//убрать дубликат числа
string duplicate(string str) {
    string res = str;

    /*for (int n = 0; n < res.size();n++) {
        if (res[n] == res[n + 1]) {
            res.erase(n, 1);
        }
    }*/
    for (int i = 0; i < res.size();i++) {
        for (int j = res.size() - 1; j > i;j--) {
            if (res[i] == res[j]) {
                res.erase(j, 1);
            }

        }

    }
    return res;

}

int main()
{
    //string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string test = "hello world";
    //cout << size(alpha);
    //cout << endl;
    //int* tost = codic(alpha);
    //printArray(tost,26);
    //char* top = atbash(test);
    cout << at(test);

}
