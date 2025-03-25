#include <iostream>
#include<string>
using namespace std;
class Encryptor {
public:
    virtual string crypt(string message) = 0;
    virtual string Salt(string password, string salt) = 0;
};
class Atbash : public Encryptor
{
    string crypt(string message) override {
        if (message.empty()) return "пустая строка";
        string result = message;
        for (int i = 0; i < size(message);i++) {
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
    string Salt(string password, string salt) {
        int salt_hash = hash<string>{}(salt);
        string salted = password;

        for (int i = 0; i < salted.length(); ++i) {
            salted[i] = salted[i] + (salt_hash % 256);
        }

        return salted + to_string(salt_hash);
    }
};
     
class Caesar:public Encryptor{
private:
    int shift;
public:
    Caesar(int shift) {
        this->shift = shift;
    }
    Caesar() {
        this->shift = 3;
    }
    string crypt(string message) override {
        string result = message;
        for (char& c : result) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = base + (c - base + shift + 26) % 26;
            }
        }
        return result;
    }
    string Salt(string password,string salt) override {
        

        int salt_hash = hash<string>{}(salt);
        string salted = password;

        for (int i = 0; i < salted.size(); ++i) {
            salted[i] = salted[i] + (salt_hash % 256);
        }

        return salted + to_string(salt_hash);
    }

};
class XOR:public Encryptor {
private:
    string key;
public:
    string crypt(string message) override {
        string result = message;
        for (int i = 0; i < result.size(); ++i) {
            result[i] = result[i] ^ key[i % key.size()];
        }
        
        return result;
    }
    string Salt(string password,string salt) override {
        string salted;
        for (int i = 0; i < password.size(); ++i) {
            char c = password[i];
            char s = salt[i % salt.size()];
            char k = key[i % key.size()];
            salted += (c + s + k) % 128;
        }

        return salted;
    }

};
void View(Encryptor& encryptor,string message,string salt) {
    cout << "введёное сообщение: " << message << endl;
    string encr = encryptor.crypt(message);
    cout << "шифрование слово: " << encr << endl;
    string salted = encryptor.Salt(encr, salt);
    cout << "соленое: " << salted;
    
}
int main()
{
    setlocale(LC_ALL, "RUS");
    Atbash atbash;
    View(atbash, "hello", "peper");
    Caesar caesar;
    View(caesar, "hello", "peper");
    XOR xr;
    View(xr, "hello", "peper");

}
