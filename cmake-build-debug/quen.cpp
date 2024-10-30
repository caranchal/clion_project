//
// Created by abrikosik on 30.10.2024.
//
#include <iostream>
using namespace std;
void queen(int x1, int y1, int x2, int y2){
    if(x1 == x2 || y1 == y2 || x1 - x2 == y1 - y2 ||-(x1-x2)==y1-y2||-(y1-x1)==y2-y1){
        cout<< "YES"<<endl;

    }
    else{
        cout<<"NO"<<endl;
    }
}
int main(){
    int x1, x2, y1, y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1 == x2 || y1 == y2 || x1 - x2 == y1 - y2 ||-(x1-x2)==y1-y2||-(y1-x1)==y2-y1){
        cout<< "YES"<<endl;

    }
    else{
        cout<<"NO"<<endl;
    }



}
