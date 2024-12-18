#include <iostream> 

using namespace std;

struct Rectangle {
    double height;
    double width;

    Rectangle(double h, double w) {
        this->height = h;
        this->width = w;
    }
    double area() {
        return width * height;
    }

    double perimetr() {
        return 2 * (height + width);
    }

    void PrintRectangle() {
        std::cout << "Rectangle:" << std::endl;
        std::cout << "Width: " << width << std::endl;
        std::cout << "Height: " << height << std::endl;
    }

    Rectangle& operator+(Rectangle& add) {
        Rectangle result(this->height + add.height, this->width + add.width);
        return result;
    }
    Rectangle operator-(Rectangle& take) {
        double newWidht = this->width - take.width;
        double newHeight = this->height - take.height;
        return Rectangle(newWidht, newHeight);
    }
    
    int operator/(Rectangle& del) {

        int ctHeight = this->height / del.height;
        int ctWidth = this->width / del.width;
        return ctWidth * ctHeight;
    }
    Rectangle operator*(Rectangle& um) {
         
        return Rectangle(this->height * um.height, this->width * um.width);
    }
};


int main() {
    
    Rectangle rec = Rectangle(10.0, 20.0);
    rec.PrintRectangle();

}
