#include <iostream>
#include<string>
using namespace std;

class IGeometricShape {
    virtual string getColor() = 0;
    virtual void WhoAmI() = 0;
};

class GeometricShape {
protected:
    string type;
    string color;
public:
    GeometricShape(string type,string color) {
        this->type = type;
        this->color = color;
    }
};

class Circle:public GeometricShape, public IGeometricShape {
private:
    int radius;
public:
    Circle(string type, string color, int radius) :GeometricShape(type, color) {
        this->radius = radius;
    }
    string getColor() override {
        return this->color;
    }
    void WhoAmI() override {
        cout << "я кружок"<<endl;
    }
    friend ostream& operator<<(ostream& os, Circle circle) {
        os << "цвет: " << circle.getColor() << "радиус: " << circle.radius;
        return os;
    }
};
class Line :public GeometricShape, public IGeometricShape {
private:
    int length;
public:
    Line(string type, string color, int length) :GeometricShape(type, color) {
        this->length = length;
    }
    string getColor() override{
        return this->color;
    }
    void WhoAmI() override{
        cout << "я линия" << endl;
    }
    friend ostream& operator<<(ostream& os, Line line) {
        os << "цвет: " << line.getColor() << "длина " << line.length;
        return os;
    }

};

class Filling :public GeometricShape, public IGeometricShape {
private:
    string visibility;
public:
    Filling(string type, string color, string visibility) :GeometricShape(type, color) {
        this->visibility = visibility;
    }
    string getColor() override {
        return this->color;
    }
    void WhoAmI() override {
        cout << "я заливка" << endl;
    }
    friend ostream& operator<<(ostream& os, Filling fill) {
        os << "цвет: " << fill.getColor() << " прозрачность: " << fill.visibility;
        return os;
    }
};
int main()
{
    setlocale(LC_ALL, "RUS");
    Filling fill = Filling("заливка", "красный", "прозрачный");
    cout << fill;
}

