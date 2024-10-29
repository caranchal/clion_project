#include <windows.h>
#include <iostream>
using namespace std;
void triangle(double x, double y) {
    if ((y >= 2 * x - 1) && (y <= 2 * x + 1) && (y <= -2 * x + 1) && (y >= -2 * x - 1)) {
       cout << "точка лежит"<<endl;
    }
    else {
        cout<<"точка не лежит"<<endl;
    }
}
void kapelka(double x, double y){
    if ((x * x + y * y <= 1) && (x >=0) && (y >= -0.5 * x -1) && (y <= 0.5 * x + 1)){
        cout<<"лежит"<<endl;
        
    }
    else{
        cout<<"не лежит"<<endl;
    }
    
    
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    double x;
    double y;
    for(int i = 0; i < 5;++i){
        if ((x * x + y * y <= 1) && (x >=0) && (y >= -0.5 * x -1) && (y <= 0.5 * x + 1)){
            cout<<"лежит"<<endl;

        }
        else{
            cout<<"не лежит"<<endl;
        }
        switch(i){
            case 0:
                 x = -2.5;
                 y = -0.1;
                break;

            case 1:
                 x = -1.5;
                 y = 0.1;
                break;
            case 2:
             x = -0.5;
             x = 0.5;
            break;
            case 3:
                x = 1.5;
                y = 0.5;
                break;
            case 4:
                x = 0.5;
                y = 1.1;
                break;
            default:
                break;

        }

    }

   /* triangle(0.4,0.2);
    printf("helкпкlo");
*/
    return 0;
}

        
