#pragma once
#include<string>
using namespace std;
class Animals {
public:
    virtual string getName() = 0;
    virtual int getCount() = 0;
};