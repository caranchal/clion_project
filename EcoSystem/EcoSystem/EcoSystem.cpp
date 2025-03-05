#include <iostream>
#include<string>
using namespace std;
class Animals {
public:
    virtual string getName() = 0;
    virtual int getCount() = 0;
};

class Tiger:Animals {
    string gender;
    string name;
    int count;
    int hp;
    int speed;
    int damage;
    string diet;
    int ratio;
    int hunger;
public:
    Tiger(string gender, string name, int count, int hp, int speed, int damage, string diet, int ratio) {
        this->gender = gender;
        this->name = name;
        this->count = count;
        this->hp = hp;
        this->speed = speed;
        this->damage = damage;
        this->diet = diet;
        this->ratio = ratio;
    }
    string getName() { return name; }
    int getCount() { count; }
};
/*название,
класс (трава/куст/дерево),
съедобное или не съедобное,
ест ли оно животных,
количество таких растений на острове.*/

class Plants {
    string name;
    string type;
    bool isEdible;
    bool isEatAnimals;
    int count;
public:
    virtual string getName();
    virtual int getCount();
    virtual string getType();
};

class Pig:Animals {
    string gender;
    string name;
    int count;
    int hp;
    int speed;
    int damage;
    string diet;
    int ratio;
    int hunger;
public:
    Pig(string gender, string name, int count, int hp, int speed, int damage, string diet, int ratio) {
        this->gender = gender;
        this->name = name;
        this->count = count;
        this->hp = hp;
        this->speed = speed;
        this->damage = damage;
        this->diet = diet;
        this->ratio = ratio;
    }
    string getName() { return name; }
    int getCount() { count; }
};

class Cock :Animals {
    string gender;
    string name;
    int count;
    int hp;
    int speed;
    int damage;
    string diet;
    int ratio;
    int hunger;
public:
    Cock(string gender, string name, int count, int hp, int speed, int damage, string diet, int ratio) {
        this->gender = gender;
        this->name = name;
        this->count = count;
        this->hp = hp;
        this->speed = speed;
        this->damage = damage;
        this->diet = diet;
        this->ratio = ratio;
    }
    string getName() { return name; }
    int getCount() { count; }
};
class Gooseberry {
    string name;
    string type;
    bool isEdible;
    bool isEatAnimals;
    int count;
public:
    string getName() { return name; }
    int getCount() { return count; }
    string getType() { return type; }
};
class Raspberry {
    string name;
    string type;
    bool isEdible;
    bool isEatAnimals;
    int count;
public:
    string getName() { return name; }
    int getCount() { return count; }
    string getType() { return type; }
};


int main()
{
    std::cout << "Hello World!\n";
}

