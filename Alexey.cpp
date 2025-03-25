#include <iostream>
#include<string>
#include <vector>

using namespace std;

class IStudy {
public:
    virtual void study() = 0;
    virtual string getName() = 0;
    virtual ~IStudy() {}
};
class Study {
protected:
    string name;
    int age;
    string gender;
public:
    Study(string name, int age, string gender) {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }
    Study() {
        this->name = "Default";
        this->age = 0;
        this->gender = "Unknown";
    }

};

class Student : public Study, public IStudy {
private:
    string group;
public:
    Student(string name, int age, string gender, string group) : Study(name, age, gender), IStudy() {
        this->group = group;
    }
    string getName() { return this->name; }
    void study() { cout << "Student studying..." << endl; }
    friend ostream& operator<<(ostream& os,Student& st)
    {
        os << st.name << st.age << st.gender << st.group;
    }
};



class Teacher : public Study, public IStudy {
public:
    Teacher(string name, int age, string gender) : Study(name, age, gender), IStudy() {}
    void study() {
        cout << "учит" << endl;
    }
    string getName() { return this->name; }
    friend ostream& operator<<(ostream& os, Teacher& t)
    {
        os << t.name << t.age << t.gender;
    }
};
class Audience :public Study, public IStudy {
private:
    vector<Student> students; 
    int numberOfPeople;
public:
    Audience(int numberOfPeople) : Study(), IStudy() {
        this->numberOfPeople = numberOfPeople;
    }
    string getName() { return this->name; }
    void addStudent(Student student) {
        students.push_back(student);
    }
    void study()     {
        cout << "учаться" << endl;
    }
    friend ostream& operator<<(ostream& os, Audience& audience) {
        for (int i = 0; i < audience.students.size();i++) {
            os << audience.students[i].getName() << endl;
        }
        return os;
    }

};
int main()
{
    setlocale(LC_ALL, "RUS");
    Audience ad = Audience(5);
    Student f = Student("игорь", 15, "мужик","светлячки");
    ad.addStudent(f);
    cout << ad;
}

