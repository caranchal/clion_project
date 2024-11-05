/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
int main()
{
    int counter;
    int temp;
int array[11] = {1, 5, 3, 6, -1, 1, 5, 3, 6, -1, 2};
    for(int i = 0; i < 11;++i){
        temp = array[i];
    }
    for(int i = 0;i < 11;++i){
        if (array[i] < 0) counter ++;
    }
    cout<<temp % 11<<endl;
    cout<<counter<<endl;
    
    int matrix[5][5];
    for(int i = 0; i < 5;++i){
        for(int j = 0; j < 5;++j){
            matrix[i][j] = i + j;
        }
    }
    for(int i = 0; i < 5;++i){
            for(int j = 0; j < 5;++j){
                cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    char matrixl[9][9];
    
    for(int i = 0; i < 9;++i){
        for(int j = 0; j < 9;++j){
            if(i % 4 == 0 || j % 4 == 0){
            matrixl[i][j] = '*';
                
            }
            else{
                matrixl[i][j] = ' ';
                
            }
        }
    }
    for(int i = 0; i < 9;++i){
            for(int j = 0; j < 9;++j){
                cout<<matrixl[i][j]<<" ";
        }
        cout<<endl;
    
    
}
    
}