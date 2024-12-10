#include <iostream>
#include<string>
using namespace std;

string reverse(string& str) {
    string rev = "";
    for (int i = size(str); i >= 0;i) {
        rev[i] += str[i];
    }
    return rev;
}

void sub(string str, string strSub) {
    int counter = 0;
    bool flag = false;
    for (int i = 0; i < size(str);i++) {
        if (str[i] == strSub[counter]) {
            flag = true;
        }
        if (flag) {
            counter++;
        }
        else {
            counter = 0;
        }
        if (counter == strSub.size()) {
            cout << "substring was found";
            break;
        }
    }
    

}

string up(string& str) {
    for (int i = 0; i < size(str) ; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
        
    }
    return str;

}
string low(string& str) {
    for (int i = 0; i < size(str);i++) {
        str[i] = tolower(str[i]);

    }
    return str;
}

string* returnTest(string& str) {
    string* newStr = new string;
    *newStr = str ;
    return newStr;
}

int main()
{
    string strMain = "PENIS";
     string substring = "string in";
     string test = "test";
    //string s = "hello world";
    //string str = reverse(s);
     //sub(strMain, substring);
     //string ip = up(substring);
     //string lowwer = low(strMain);
    //cout << ip << endl;
     //cout << lowwer;
     string* newStr = returnTest(test);
     cout << newStr << endl;
     cout << *newStr << endl;
     cout << &*newStr << endl;
     cout << *&*newStr << endl;
     cout << &*&*newStr << endl;
     cout << *&*&*newStr << endl;

}

