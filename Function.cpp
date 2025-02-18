#include <iostream>
#include<string>
using namespace std;

class Function {
private:
    double a;
    double b;
public:

    Function(double a,double b) {
        this->a = a;
        this->b = b;

    }
    double fun(double x) {
        return a * x + b;
    }
    friend void leg(const Function&);
    
};
void leg(const Function& fun, double x,double start,double end) {
    if (x < start || x>end)
        cout << "не лежит";
     cout<<"лежит";
}
//double sred(const Function& fun,double x)

int main()
{
    Function fun = Function(2, 2);
    
    cout << fun.fun(4);
    leg(fun, 5, 3, 4);
}

