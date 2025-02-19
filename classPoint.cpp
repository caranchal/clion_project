#include <iostream>
using namespace std;

class Point;
class Function;
class Point {
    friend Function;
private:
    int x;
    int y;
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void print(){
        cout << "x = " << x << "y = " << y;
    }
};
class Function {
    friend Point;
    friend int averageFunction(Function&, int left, int right);
private:
    int a;
    int b;
    int c;
public:
    Function(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    bool isContains(Point& point) {
        return (point.y == a * point.x * point.x + b * point.x + c) ? true : false;
    }
};

/*int averageFunction(Function& fun, int left, int right) {
    int sum;
    int counter;
    for (int i = 0; i <= right;i++) {
        int x = 1;
        int y = fun.a * x * x + fun.b * x + fun.c;
        sum += y;
        counter++;
    }
    sum = sum / counter;
    return sum;

}*/
int averageFunction(Function& fun, int left, int right)
{
    int sum = 0;
    int counter = 0;
    for (int i = 0; i <= right;i++) {
        int x = 1;
        int y = fun.a * x * x + fun.b * x + fun.c;
        sum += y;
        counter++;
    }
    sum = sum / counter;
    return sum;
}
int main()
{
    Point point = Point(2, 2);
    Function fun = Function(2, 2,4);
    cout<<averageFunction(fun, -10, 10);

    
}


