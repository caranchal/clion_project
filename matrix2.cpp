#include<iostream>
#include "windows.h"
using namespace std;
int** getRandomMatrix(int size_X, int size_Y){
    int** matrix = new int*[size_X];

    for(int i = 0; i < size_X; i++){
        matrix[i] = new int[size_Y];

        for(int j = 0; j < size_Y; j++){
            matrix[i][j] = rand();
        }
    }

    return matrix;
}

void transponMatrix(int**& matrix, int size_X, int size_Y)
{

    int** matrixResult = new int*[size_Y];

    for(int i = 0; i < size_Y; i++){
        matrixResult[i] = new int[size_X];

        for(int j = 0; j < size_X; j++){
            matrixResult[i][j] = matrix[j][i];
        }

    }

    for(int i = 0; i < size_X; i++){
        delete matrix[i];
    }
    delete matrix;

    matrix = matrixResult;
}


//Функция для вывода динамической матрицы
void printMatrix(int** matrix, int size_X, int size_Y){
    for(int i = 0; i < size_X; i++){


        for(int j = 0; j < size_Y; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//Функция создания динамической матрицы размера size_X по вертикали и size_Y горизонтали



int main()
{
    int** matrix = getRandomMatrix(5,5);
    transponMatrix(matrix,5,5);
    printMatrix(matrix,5,5);

    return 0;
}