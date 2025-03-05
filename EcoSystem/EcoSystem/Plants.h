#include<string>
using namespace std;
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