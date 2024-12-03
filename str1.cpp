#include <iostream>
#include<string>
using namespace std;

/*string glas(string str) {
    string result = str;
    int temp = size(str);
    int counter = 0;
    for (int i = 0; i < temp; i++) {
        if (result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u' || result[i] == 'y') {
            counter++;
        }
    }
    
}
*/
int task1(string str) {
    string alphavit = "aeiouy";
    int counter = 0;
    int temp = size(str);
    for (int i = 0; i < alphavit.size();i++) {
        for (int j = 0; j < temp; j++) {
            if (alphavit[i] == str[j]) {
                counter++;
            }
        }


    }

    return counter;

}

string sup(string str, int g) {
    string result = str;
    for (int i = 0; i < result.size(); i++) {
        result[i] += g;

        }

    return result;
}

string task3(string str) {
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


string duplicate(string str) {
    string res = str;

    /*for (int n = 0; n < res.size();n++) {
        if (res[n] == res[n + 1]) {
            res.erase(n, 1);
        }
    }*/
    for (int i = 0; i < res.size();i++) {
        for (int j = res.size() - 1 ; j > i;j--) {
            if (res[i] == res[j]) {
                res.erase(j, 1);
            }

        }

    }
    return res;

}

int main()
{
    setlocale(LC_ALL, "Russian");
    string str = "aabbbbrrrdda";
    //str = "abcd";
    //cout << int(char(str[0]));
    //cout << task1(str);
    //cout << sup(str, 3);
    //cout << task3(str);
    //task4(str);
    cout << duplicate(str);
}

