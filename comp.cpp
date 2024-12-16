#include <iostream> 

using namespace std;

struct complex {
    int re;
    int im;

    complex(int a, int b) {
        this->re = a;
        this->im = b;
    }

    void Print() {
        if (this->im > 0)
            cout << this->re << "+" << this->im << "i" << endl;
        else
            cout << this->re << this->im << "i" << endl;
    }

    complex& operator+(complex& add) {
        complex result(this->re + add.re, this->im + add.im);
        return result;
    }
};

template<typename T> void printComlex(T re1, T im1)
{
    if (im1 >= 0)
        cout << re1 << "+" << im1 << "i";
    else
        cout << re1 << "-" << im1 << "i";
}

template<typename T> void sum(T re1, T im1, T re2, T im2)
{
    T new_re1 = re1 + re2;
    T new_im1 = im1 + im2;

    printComlex(new_re1, new_im1);
}


void printComlex(int re1, int im1) {
    if (im1 >= 0)
        cout << re1 << "+" << im1 << "i" << endl;
    else
        cout << re1 << im1 << "i" << endl;
}

complex sum(int re1, int im1, int re2, int im2)
{

    int new_re1 = re1 + re2;
    int new_im1 = im1 + im2;
    complex result(new_re1, new_im1);
    return result;
    //printComlex(new_re1, new_im1); 
}


int main() {
    /*complex test(5, 6);
    test.Print();

    complex test1(4, -2);
    test1.Print();

    complex result = test + test1;
    result.Print();*/
    int a, b, c, d;
    int oper = 0;
    bool g = true;
    setlocale(LC_ALL, "Russian");
    cout << "калькулятор комлЕксный чисел веберите действие..." << endl;
    cout << "1.сложит комплексные числа" << endl;
    cout << "2.вывести комлЕксные числа" << endl;
    cin >> oper;

    complex res(0, 0);
    complex res1(0, 0);
    complex result = res + res1;

    do {
        switch (oper)
        {
        case 1:
            cout << "введите 4 числа" << endl;
            cin >> a >> b>> c>> d;
            complex res(a, b);
            complex res1(c, d);
            result = res + res1;
            result.Print();
            cout << endl;
            cout << "числа не складываются потому что они комплЕксные... вот так вот" << endl;
            g = false;
            break;

        case 2:
            cout << "введите 2 числа" << endl;
            cin >> a >> b;
            complex pri(a, b);
            pri.Print();
            g = false;
            break;
        }
    } while (g == true);

}
