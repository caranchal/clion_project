#include <iostream>
#include<string>
using namespace std;

class Bank {
private:
    int bankMoney;
    int moneyA;
    int moneyB;
    string clientA;
    string clientB;
public:
    Bank(int bankMoney, int MoneyA, int moneyB, string clienA, string clientB) {

        this->bankMoney = bankMoney;
        this->moneyA = MoneyA;
        this->moneyB = moneyB;
        this->clientA = clienA;
        this->clientB = clientB;
    }
    int getMoney() {
        return bankMoney;
    }
    string getClientA() {
        return clientA;
    }
    void setMoney(int money) {
        this->bankMoney = money;
    }
    void setClientA(string client) {
        this->clientA = client;
    }
    void plussMoneyA(int money) {
        this->moneyA += money;
    }
    void minusMoneyA(int money) {
        this->moneyA -= money;
    }
    void plussMoneyB(int money) {
        this->moneyB += money;
    }
    void minusMoneyB(int money) {
        this->moneyB -= money;
    }
    int getMoneyA() {
        return moneyA;
    }
    int getMoneyB() {
        return moneyB;
    }
    void setMoneyA(int money) {
        this->moneyA = money;
    }
    void setMoneyb(int money) {
        this->moneyB = money;
    }
    string getClientB() {
        return clientB;
    }
    void pushMoney(int money) {
        this->bankMoney -= money;
        this->plussMoneyA(money);
        

    }
    void pushToClient( int money) {
        this->minusMoneyA(money);
        this->plussMoneyB(money);
    }
};


class Currency {
private:
    int rubles;
    int cop;
public:
    Currency(int rubles, int cop) {
        this->rubles = rubles;
        this->cop = cop;
    }
    Currency() {
        this->rubles = 0;
        this->cop = 0;
    }

    int getRubles() {
        return rubles;
    }
    int getCop() {
        return cop;
    }
    void setRubles(int rubles) {
        this->rubles = rubles;
    }
    void setCop(int cop) {
        this->cop = cop;
    }
    void printCyrrency() {
        cout << rubles << " рублей . " << cop << " копеек";
    }
    Currency sum(Currency& one, Currency& two) {
        int s1, s2, s3;
        Currency answer;
        s1= (one.rubles * 100) + one.cop;
        s2= (two.rubles * 100) + two.cop;
        s3 = s1 + s2;
        one.rubles = s3 / 100;
        one.cop = s3 % 100;
        answer.setRubles(one.rubles);
        answer.setCop(one.cop);
        return answer;



    }

    Currency minus(Currency& one, Currency& two) {
        int s1, s2, s3;
        Currency answer;
        s1 = (one.rubles * 100) + one.cop;
        s2 = (two.rubles * 100) + two.cop;
        s3 = s1 - s2;
        one.rubles = s3 / 100;
        one.cop = s3 % 100;
        answer.setRubles(one.rubles);
        answer.setCop(one.cop);
        return answer;
    }
    Currency del(Currency& one, Currency& two) {
        int s1, s2, s3;
        Currency answer;
        s1 = (one.rubles * 100) + one.cop;
        s2 = (two.rubles * 100) + two.cop;
        s3 = s1 / s2;
        one.rubles = s3 / 100;
        one.cop = s3 % 100;
        answer.setRubles(one.rubles);
        answer.setCop(one.cop);
        return answer;
    }
    Currency um(Currency& one, Currency& two) {
        int s1, s2, s3;
        Currency answer;
        s1 = (one.rubles * 100) + one.cop;
        s2 = (two.rubles * 100) + two.cop;
        s3 = s1 * s2;
        one.rubles = s3 / 100;
        one.cop = s3 % 100;
        answer.setRubles(one.rubles);
        answer.setCop(one.cop);
        return answer;
    }
    //Currency operator+(Currency& one, Currency& two);
};

class Calendar {
private:
    int day;
    int month;
    int year;
public:
    int getDay() {
        return day;
    }

    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }
    void setDay(int day) {
        this->day = day;
    }
    void setMonth(int month) {
        this->month = month;
    }
    void setYear(int year) {
        this->year;
    }
    void printCalendar() {
        cout << "год" << year<<"месяц"<<month<<"день"<<day;
    }
};
int main()
{
    setlocale(LC_ALL, "rus");
    
    Currency n = Currency(10, 20);
    Currency g = Currency(10, 20);
    Currency l = l.sum(n, g);
    
    l.printCyrrency();
    
    
}

