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
    void pushToClient(int money) {
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
        s1 = (one.rubles * 100) + one.cop;
        s2 = (two.rubles * 100) + two.cop;
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
    Currency operator+ (const Currency& secondCurrency)
    {
        int s1, s2, s3;
        Currency answer;
        s1 = (rubles * 100) + cop;
        s2 = (secondCurrency.rubles * 100) + secondCurrency.cop;
        s3 = s1 + s2;
        rubles = s3 / 100;
        cop = s3 % 100;
        answer.setRubles(rubles);
        answer.setCop(cop);
        return answer;
    }
    Currency operator+ (const int& addRubles)
    {
        return Currency(rubles + addRubles, cop);
    }
    Currency operator- (const Currency& secondCurrency)
    {
        int s1, s2, s3;
        Currency answer;
        s1 = (rubles * 100) + cop;
        s2 = (secondCurrency.rubles * 100) + secondCurrency.cop;
        s3 = s1 - s2;
        rubles = s3 / 100;
        cop = s3 % 100;
        answer.setRubles(rubles);
        answer.setCop(cop);
        return answer;
    }
    Currency operator* (const Currency& secondCurrency)
    {
        int s1, s2, s3;
        Currency answer;
        s1 = (rubles * 100) + cop;
        s2 = (secondCurrency.rubles * 100) + secondCurrency.cop;
        s3 = s1 * s2;
        rubles = s3 / 100;
        cop = s3 % 100;
        answer.setRubles(rubles);
        answer.setCop(cop);
        return answer;
    }
    Currency operator/ (const Currency& secondCurrency)
    {
        int s1, s2, s3;
        Currency answer;
        s1 = (rubles * 100) + cop;
        s2 = (secondCurrency.rubles * 100) + secondCurrency.cop;
        s3 = s1 / s2;
        rubles = s3 / 100;
        cop = s3 % 100;
        answer.setRubles(rubles);
        answer.setCop(cop);
        return answer;
    }
    Currency& operator++ () {
        rubles++;
        return *this;
    }
    Currency& operator++ (int)
    {
        Currency copy{ *this };
        ++(*this);
        return copy;
    }
    friend ostream& operator<<(ostream& stream, Currency& curr)
    {
        stream << "Рубли: " << curr.rubles << " копейки: " << curr.cop << endl;
        return stream;
    }
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
        cout << "год" << year << "месяц" << month << "день" << day;
    }
};

class Distance {
private:
    int km;
    int m;
public:
    Distance(int km, int m) {
        this->km = km;
        this->m = m;
    }
    Distance() {
        this->km = 0;
        this->m = 0;
    }
    int getKm() {
        return km;
    }
    int getM() {
        return m;
    }
    void setkm(int km) {
        this->km = km;
    }
    void setM(int m) {
        this->m = m;
    }
    Distance operator+(Distance& second) {
        int s1, s2, s3;
        Distance answer;
        s1 = (km * 100) + m;
        s2 = (second.km * 100) + second.m;
        s3 = s1 + s2;
        km = s3 / 100;
        m = s3 % 100;
        answer.setkm(km);
        answer.setM(m);
        return answer;
    }
    Distance operator+(int& n) {
        return Distance(km + n, m);
    }
    Distance operator-(Distance& second) {
        int s1, s2, s3;
        Distance answer;
        s1 = (km * 100) + m;
        s2 = (second.km * 100) + second.m;
        s3 = s1 - s2;
        km = s3 / 100;
        m = s3 % 100;
        answer.setkm(km);
        answer.setM(m);
        return answer;
    }
    Distance operator*(Distance& second) {
        int s1, s2, s3;
        Distance answer;
        s1 = (km * 100) + m;
        s2 = (second.km * 100) + second.m;
        s3 = s1 * s2;
        km = s3 / 100;
        m = s3 % 100;
        answer.setkm(km);
        answer.setM(m);
        return answer;
    }
    Distance operator/(Distance& second) {
        int s1, s2, s3;
        Distance answer;
        s1 = (km * 100) + m;
        s2 = (second.km * 100) + second.m;
        s3 = s1 / s2;
        km = s3 / 100;
        m = s3 % 100;
        answer.setkm(km);
        answer.setM(m);
        return answer;
    }
    Distance& operator++ () {
        km++;
        return *this;
    }
    Distance& operator++ (int)
    {
        Distance copy{ *this };
        ++(*this);
        return copy;
    }
    friend ostream& operator<<(ostream& stream, Distance& curr)
    {
        stream << "Киллометры: " << curr.km << " метры: " << curr.m << endl;
        return stream;
    }
    friend istream& operator>>(istream& stream, Distance& curr) {
        stream >> curr.km;stream>> curr.m;
        return stream;
    }
    Distance& operator==(Distance& second) {

    }
    
};
int main()
{
    setlocale(LC_ALL, "rus");

    Currency n = Currency(10, 20);
    Currency g = Currency(10, 20);
    Currency o = Currency(4, 30);
    Currency l = n + g;
    Currency e = n - o;
    cout << e;

    //l.printCyrrency();


}
