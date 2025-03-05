#include"Animals.h"

class Tiger :Animals {
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

class Pig :Animals {
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