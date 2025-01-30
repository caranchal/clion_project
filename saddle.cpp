#include <iostream>
using namespace std;

int** getRandomMatrix(int size_X, int size_Y) {
    int** matrix = new int* [size_X];

    for (int i = 0; i < size_X; i++) {
        matrix[i] = new int[size_Y];

        for (int j = 0; j < size_Y; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }

    return matrix;
}
void printMatrix(int** matrix, int size_X, int size_Y) {
    for (int i = 0; i < size_X; i++) {


        for (int j = 0; j < size_Y; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
bool FindPoint(int** matrix, int size_x, int size_y, int& sadx,int& sady ) {
    for (int i = 0; i < size_x; ++i) {
        
        int min = matrix[i][0];
        int sadx = 0; 

        for (int j = 1; j < size_y; ++j) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                sadx = j; 
            }
        }

      
        bool SaddlePoint = true;
        for (int k = 0; k < size_x; ++k) {
            if (matrix[k][sadx] > min) {
                SaddlePoint = false;
                break; 
            }
        }

        if (SaddlePoint) {
            sady = i;
            return true; 
        }
    }
    return false; 
}
int main()
{
    int** mat = getRandomMatrix(5, 5);
    int sadx, sady;
    if (FindPoint(mat, 5, 5, sadx, sady)) {
        cout << "Find row" << sadx << " col" << sady;
        cout << mat[sadx][sady] << endl;

    }
    else
        cout << "not find";

}

