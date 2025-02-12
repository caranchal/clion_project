#include <iostream>
#include<string>
using namespace std;

enum Currency
{
    RubToDollars = 0,
    DollarsToRub = 1
};
class Converter {
public:
    static constexpr double RubToDollars = 0.01;
    static constexpr double DollarsToRub = 100;
    static double Convert(double money,Currency cur) {
        switch (cur) {
        case 0:
            return money * RubToDollars;

        case 1:
            return money * DollarsToRub;

        }
        
    }
    
};
int main()
{
   cout<< Converter::Convert(100, Currency::DollarsToRub);
    
}

