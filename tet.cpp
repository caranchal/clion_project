#include <iostream>
#include "windows.h"
#include <stdio.h>
#include<conio.h>
using namespace std;

char** getMatrix(int size_x, int size_y) {
    char** mat = new char* [size_x];
    for (int i = 0; i < size_x; i++) {
        mat[i] = new char[size_y];
        for (int j = 0; j < size_y; j++) {
            mat[i][j] = ' ' + ' ';
        }
    }
    return mat;
}

void printMat(char** mat, int size_x, int size_y) {
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

}

struct Fig {
    int id = 1;
    char field[4][4];
    

};


char** palca(char** array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j > 0)
                array[i][j] = ' ';
            array[i][j] = '*';
            

        }
    }
    return array;
}
void figure(char array[4][4],int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void RotateMatrix(char fig[4][4], int angle) {
    char newFig[4][4];
    switch (angle) {
    case 0:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                newFig[i][j] = fig[i][j];
            }
        }
        break;
    case 1:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                newFig[j][4 - 1 - i] = fig[i][j];
            }
        }
        break;

    case 2:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                newFig[4 - 1 - i][4 - 1 - j] = fig[i][j];
            }
        }
        break;

    case 3:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                newFig[4-1-j][i] = fig[i][j];
            }
        }
        break;

    }


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            fig[i][j] = newFig[i][j];
        }
    }

}

/*void redrawPlace() {
    Sleep(100);
    system("cls");
}*/

int main()
{
    int size = 4;

        char figure1[4][4] = {
        {'*',' ',' ',' '},
        {'*',' ',' ',' '},
        {'*',' ',' ',' '},
        {'*',' ',' ',' '}
    };
    

    char figure2[4][4] = {
        {'*',' ',' ',' '},
        {'*',' ',' ',' '},
        {'*',' ',' ',' '},
        {'*','*',' ',' '}
    };
    char figure3[4][4] = {
       {'*','*',' ',' '},
       {'*','*',' ',' '},
       {'*','*',' ',' '},
       {'*','*',' ',' '}
    };
    char figure4[4][4] = {
       {'*','*',' ',' '},
       {'*','*',' ',' '},
       {' ',' ',' ',' '},
       {' ',' ',' ',' '}
    };
    char figure5[4][4] = {
      {' ',' ',' ',' '},
      {' ',' ',' ',' '},
      {' ','*','*',' '},
      {'*','*',' ',' '}
    };
    char figure6[4][4] = {
     {' ',' ',' ',' '},
     {' ',' ',' ',' '},
     {' ','*',' ',' '},
     {'*','*','*',' '}
    };
    /*char** mat = getMatrix(5, 5);
    //printMat(mat, 5, 5);
    char** fig = palca(mat, 4);
    printMat(fig, 4, 4);
    */
    int i = 4;
    char c = getch();
    while (true) {
        switch (rand() % 6) {
            Sleep(200);
        case 0:
            RotateMatrix(figure1, c);
            figure(figure1, size);
            Sleep(200);
            system("cls");
            i--;
            break;

        case 1: 
            RotateMatrix(figure2, c);
            figure(figure2, size);
            Sleep(200);

            system("cls");
            i--;
            break;

        case 2:
            RotateMatrix(figure3, c);
            figure(figure3, size);
            Sleep(200);
            system("cls");
            i--;
            break;

        case 3:
            RotateMatrix(figure4, c);
            figure(figure4, size);
            Sleep(200);

            system("cls");
            i--;
            break;
            
        case 4:
            RotateMatrix(figure5, c);
            figure(figure5, size);
            Sleep(200);
            system("cls");
            i--;
            break;

        case 5:
            RotateMatrix(figure6, c);
            figure(figure6, size);
            Sleep(200);


            system("cls");
            i--;
            break;

        }
    }
}
