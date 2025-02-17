#include <iostream>
#include<string>
using namespace std;

void checkPass(string pass) {

    try 
    {
        if (pass.size() < 8) {
            throw "Error: короткий пароль";
        }
        if (pass.size() >= 8) {
            for (int i = 0; i < pass.size(); i++) {
                if (pass[i] == '.' || pass[i] == ',' || pass[i] == '/')
                    throw "Error: недопустимые символы";
            }
        }
        else
            cout << "пароль принят";
    }
    catch (const char* error) {
        cout << error << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    string pass;
    cout << "введите пароль - ";
    cin >> pass;
    checkPass(pass);

    
}

