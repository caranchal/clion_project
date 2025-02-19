#include<iostream>
using namespace std;

class Animals {
public:
     virtual void Say() {
        cout << "***";
    }
};

class Cow:public Animals {
public:
    void Say() {
        cout << "myyy";
    }
};
class Dog :public Animals {
public:
    void Say() {
        cout << "huv";
    }
};
class Cat :public Animals {
public:
    void Say() {
        cout << "meuw";
    }
};

int main()
{
    Dog dog;
    Cat cat;
    Cow cow;
    //dog.Say();
    Animals* an = new Animals;
    an = &dog;
    an->Say();
    an = &cat;
    an->Say();
    an = &cow;
    an->Say();
}
