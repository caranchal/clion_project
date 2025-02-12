#include <iostream>
#include <string>
#include"math.h"
using namespace std;
class Sphere {
private:
    int radius;
public:
    void setRadius(int radius) {
        this->radius = radius;
    }
    int getRadius() {
        return radius;
    }
    Sphere() {
        this->radius = 0;
    }
    Sphere(int radius) {
        this->radius = radius;
    }
    ~Sphere(){}
    double findOb() {
        int m = 0;
        const double pi = 3.14;
        m = 4 * pi * pow(this->radius, 3);
        return m;
    }
    friend ostream& operator<<(ostream& stream, Sphere& s) {
        stream << "radius Sphere" << s.radius;
        return stream;

    }
    friend istream& operator>>(istream& istream, Sphere& s) {
        istream >> s.radius;
        return istream;
    }
};
class Detail:public Sphere
{
private:
    int plot;
    string material;
public:
    Detail():Sphere()
    {
        this->plot = 0;
        this->material = "";
    }
    
    Detail(int radius,int plot, string material) : Sphere(radius) {
        this->material = material;
        this->plot = plot;

    }
    double findMass() {
        int m = this->plot * getRadius();
        return m;


    }
    friend ostream& operator<<(ostream& stream, Detail& d) {
        stream << "radius Sphere" << d.getRadius()<<" detail plot  - "<<d.plot<<"detail material - "<<d.material;
        return stream;

    }
    friend istream& operator>>(istream& istream, Detail& d) {
        istream >> d.plot>>d.material;
        return istream;
    }
    bool operator>(Detail& second) {
        if (getRadius() > second.getRadius())
            return true;
        return false;
    }
    bool operator==(Detail& second) {
        if (material == second.material)
            return true;
        return false;
    }

};

int main()
{
    Sphere s = Sphere(10);
    Sphere p = Sphere(14);
    Sphere g = Sphere();
    cout << s.findOb();
    cout << endl;
    Detail d = Detail(10, 300, "бумага");
    cout << d.findMass();


}

