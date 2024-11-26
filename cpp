#include <iostream>
#include <cmath>
using namespace std;

int z(int x, int y) {
    int z = 0;
    if (x > y) {
        z = x - y;
    }
    else {
        z = y - x + 1;
    }
    return z;
}

int factorial(int i)
{
    if (i == 0) return 1;
    else return i * factorial(i - 1);
}

/*int sum(int x) {
    int index = 3;
    int answ = 0;
    if (index == 13) {
        return 1;
    }
    else {
        return answ += pow(x, index) / factorial(index);
        index += 2;
        if (index == 9) {
            return answ -= pow(x, index) / factorial(index);
        }
    }
    return x - answ;
}*/

int sum(int x) {
    int index = 3;
    int answ = 0;
    while (index != 5) {
        answ += pow(x, index) / factorial(index);
        index = index + 2;
        if (index == 11) {
            answ -= pow(x, index) / factorial(index);
            index += 2;
        }
    }
    return x - answ;


}
int main()
{
    //cout<<z(1, 2);
    cout<<sum(3);

}
