#include <iostream>
using namespace std;

class Boss;
class Character;

class Boss {
    friend class Character;
    friend class Mage;
    friend class Warrior;
    friend class Assasin;
    friend class Paladin;
private:
    int hp;
public:

    Boss(int hp) {
        this->hp = hp;
    }
    int getHp() {
        return hp;
    }
    void attackHero(Character& character) {
        cout << "получай жук";
        character.hp -= 10;
    }
};

class Character {
    friend Boss;
private:
    int hp;
public:
    virtual int getHP() {
        return hp;
    }
    Character(int hp) {
        this->hp = hp;
    }
    Character() 
        {
            this->hp = 0;
        } 
    virtual void attack(Boss& boss) {
        boss.hp--;
        cout << "***";
        
    }
    
};
class Warrior :public Character {
    friend Boss;
   
private:
    int hp;
public:
    int getHP();
    Warrior(int hp) :Character(hp) {};
    void attack(Boss& boss) {
        boss.hp -= 20;
        cout << "на получай";
        
    }
};




class Mage :public Character {
    friend Boss;
public:
    int getHP();
    Mage(int hp) :Character(hp) {}
    void attack(Boss& boss) {
        boss.hp -= 30;
        cout << "скыдыщь";
        
    }
private:
    int hp;
};

class Paladin:public Character {
    friend Boss;
private:
    int hp;
public:
    int getHP();
    Paladin(int hp) :Character(hp) {}
    void attack(Boss& boss) {
        cout << "кчау";
        boss.hp -= 10;
    }
};

class Assasin :public Character {
    friend Boss;
private:
    int hp;
public:
    int getHP();
   
    Assasin(int hp) :Character(hp){}
    void attack(Boss& boss) {
        cout << "хрясь";
        boss.hp -= 15;
    }
    
};


int main()
{
    setlocale(LC_ALL, "rus");
    Character** character = new Character * [4];
    
    for (int i = 0; i < 4;i++) {
        switch (i) {
        case 0:
            character[i] = new Assasin(rand() % 10 * 10);
            break;
        case 1:
            character[i] = new Paladin(rand() % 10 * 10);
            break;
        case 2:
            character[i] = new Mage(rand() % 10 * 10);
            break;
        case 3:
            character[i] = new Warrior(rand() % 10 * 10);
            break;
        }
           
    }
    /*Mage mage;
    Warrior warrior;
    Paladin paladin;
    Assasin assasin;
    Character* c = new Character();
    c = &warrior;
    c->attack(boss);
    */
    int size;
    Boss boss = Boss(200);
    while (boss.getHp() >= 0) {
        for (int i = 0; i < 4;i++) {
            if (boss.getHp() == 0)
                break;
            Character* n = new Character();
            n = character[i];
            n->attack(boss);
            boss.attackHero(*n);
            cout<<n->getHP();
            cout << " ";
            cout << "Hp boss = " << boss.getHp() << endl;
        }
        cout << "босс убит";
   }
}


