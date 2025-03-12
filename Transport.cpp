#include <iostream>
#include<string>
using namespace std;
class Transport {
private:
    string color;
    int date;
    int sead;
    string type;
public:
    Transport() {
        this->color = "неопределен";
        this->date = 1700;
        this->sead = 0;
    }
    Transport(string type, int date, int sead) {
        this->color = type;
        if (date > 1700 && date <= 2025)
            this->date = date;
        if (sead >= 0 && sead <= 1000)
            this->sead = sead;
    }
    bool operator==(Transport& transport) {
        if (color == transport.color && date == transport.date && sead == transport.sead)
            return true;
        return false;
    }
    Transport operator++(int) {
        sead++;
    }
    virtual void print();
    virtual string getType();
};

class Plane : public Transport {
private:
    string wings;
    int loadCapacity;
public:
    Plane() :Transport() {
        wings = "";
        loadCapacity = 0;
    }
    Plane(string color, int date, int sead, string wings, int loadCapacity) :Transport(color, date, sead) {
        this->wings = wings;
        if (loadCapacity >= 0)
            this->loadCapacity = loadCapacity;
    }
    string getType()override {
        return "самолёт";
    }
    bool operator==(Plane plane) {
        if (wings == plane.wings && loadCapacity == plane.loadCapacity)
            return true;
        return false;
    }
    bool operator>(Plane& plane) {
        if (loadCapacity > plane.loadCapacity)
            return true;
        return false;
    }
    bool operator<(Plane& plane) {
        if (loadCapacity < plane.loadCapacity)
            return true;
        return false;
    }
    void print() override {
        cout << "Самолёт";
    }

    Plane operator+(Plane& plane) {
        loadCapacity + plane.loadCapacity;
    }
    Plane operator++(int) {
        loadCapacity++;
    }
};
class Car : public Transport {
private:
    string model;
    int radiusWheels;
public:
    Car() :Transport() {
        this->model = "";
        this->radiusWheels = 0;
    }
    Car(string color, int date, int sead, string model, int radiusWheels) :Transport(color, date, sead) {
        this->model = model;
        this->radiusWheels = radiusWheels;
    }
    bool operator==(Car& car) {
        if (model == car.model && radiusWheels == car.radiusWheels)
            return true;
        return false;
    }
    bool operator>(Car& car) {
        if (radiusWheels > car.radiusWheels)
            return true;
        return false;
    }
    bool operator<(Car& car) {
        if (radiusWheels < car.radiusWheels)
            return true;
        return false;
    }
    void print() override {
        cout << "машина";
    }
    string getType()override {
        return "машина";
    }

    Car operator+(Car& car) {
        radiusWheels + car.radiusWheels;
    }
    Car operator++(int) {
        radiusWheels++;
    }
};
class Ship :public Transport {
private:
    int colvoBoat;
    string flag;
public:
    Ship() :Transport() {
        this->colvoBoat = 0;
        this->flag = "";
    }
    Ship(string color, int date, int sead, int colvoBoat, string flag) :Transport(color, date, sead) {
        if (colvoBoat >= 0)
            this->colvoBoat = colvoBoat;
        this->flag = flag;
    }
    string getType()override {
        return "корабль";
    }
    bool operator==(Ship& ship) {
        if (colvoBoat == ship.colvoBoat && flag == ship.flag)
            return true;
        return false;
    }
    bool operator>(Ship& ship) {
        if (colvoBoat > ship.colvoBoat)
            return true;
        return false;
    }
    bool operator<(Ship& ship) {
        if (colvoBoat < ship.colvoBoat)
            return true;
        return false;
    }
    void print() override {
        cout << "корабль";
    }

    Ship operator+(Ship& ship) {
        colvoBoat + ship.colvoBoat;
    }
    Ship operator++(int) {
        colvoBoat++;
    }
};

void disp() {
    cout << "1. добавить элемент" << endl;
    cout << "2. удалить элемент по индексу" << endl;
    cout << "3. вывод всех элементов списка "<< endl;
    cout << "3. Сравнение двух элементов на равенство (по индексам)" << endl;
    cout << "4. Завершение работы приложения" << endl;
}
void add(Transport** transport, int& size, int type) {
    Transport** newTransport = new Transport * [size];

}

int main()
{
    setlocale(LC_ALL, "RUS");
    int a = 0;
    int size = 0;

    Transport** transport = new Transport * [size];
    while (true) {
        disp();
        cin >> a;
        switch (a) {
        case 1:
            cout << "кого добавить?" << endl;
            cout << "1. машина" << endl;
            cout << "2. самолет" << endl;
            cout << "3. корабль" << endl;
            int type;
            cin >> type;
            switch (type) {
            case 1:
                transport[size] = new Car();
                size++;
                break;
            case 2:
                transport[size] = new Plane();
                size++;
                break;
            
            case 3:
                transport[size] = new Ship();
                size++;
                break;
        default:
            cout << "-вайб";
            continue;
        }
        case 2:
            cout << "Индекс?";
            int index;
            cin >> index;
            if (size == 0) {
                cout << "список пустой";
            }
            if (index >= 0 && index < size) {
                delete transport[index];
                for (int i = index; i < size - 1; ++i) {
                    transport[i] = transport[i + 1];
                }
                size--;
                cout << "Элемент удален." << endl;
            }
            else {
                cout << "Неверный индекс!" << endl;
            }
            break;
        case 3:
            if (size == 0) {
                cout << "Список пуст!" << endl;
            }
            else {
                for (int i = 0; i < size; ++i) {
                    cout << "Элемент " << i << ": ";
                    transport[i]->print();
                }
            }
            break;
        case 4: 
            if (size < 2) {
                cout << "Недостаточно элементов для сравнения" << endl;
                break;
            }

            cout << "индексы элементов";
            int index1, index2;
            cin >> index1 >> index2;

            if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size) {
                if (transport[index1]->getType() == transport[index2]->getType()) {
                    cout << "Элементы равны." << endl;
                }
                else {
                    cout << "Элементы не равны." << endl;
                }
            }
            else {
                cout << "Неверные индексы!" << endl;
            }
            break;
        case 5:
            cout << "пока";
            return 0;
        default:
            cout << "неверный выбор";
        }

    }

}
