#include <iostream>
#include<cmath>
using namespace std;

void dynamic_array(int* array, int n) {

	for (int i = 0; i < n; i++) {
		array[i] = i;
	}

}
/*int max_array(int* array, int n) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		temp = array[i];
		if (temp < array[i + 1]) {
			array[i] = temp;
		}
		else {
			array[i + 1] = temp;
		}

	}
	return array[n];
}
*/
int min_array(int* array, int n) {
	 
		int temp = 0;
		for (int i = 0; i < n; i++) {
			temp = array[i];
			if (temp < array[i + 1]) {
				array[i] = temp;
			}
			else {
				array[i + 1] = temp;
			}

		}
		return array[0];
	}
	
int max_array_a2(int* array, int n) {
	int temp = 0;
	for (int i = 1; i < n; i++) {
		temp = array[i];
		if (temp < array[i + 2]) {
			array[i] = temp;
		}
		else {
			array[i + 2] = temp;
		}

	}
	return array[n];
}


int min_a1(int* array, int n) {
	for (int i = 0; i < n; i++) {
		int temp = 0;
		temp = array[i];
		if (temp > array[i + 2]) {
			array[i] = temp;
		}
		else {
			array[i + 2] = temp;
		}

	}
	return array[0];
}

int min_a2_a4(int* array, int n) {
	int temp = 0;
	for (int i = 1; i < n; i++) {
		temp = array[i];
		if (temp > array[i + 2]) {
			array[i] = temp;
		}
		else {
			array[i + 2] = temp;
		}

	}
	return array[0] + max_array_a2(array,n);
	

}
int max_array_abs(int* array, int n) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		temp = abs(array[i]);
		if (temp < abs(array[i + 1])) {
			array[i] = abs(temp);
		}
		else {
			array[i + 1] = abs(temp);
		}

	}
	return array[n - 1];
}
int count_null(int* array, int size) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] == 0) {
			counter += 1;
		}

	}
	return counter;
}
int um(int array[], int size) {
	int temp = 1;
	for(int i = 1; i < size;i = i + 2){
		temp *= array[i];

	}
	return temp;

}

int** matrixx( int size_x, int size_y) {
	int** newMatrix = new int* [size_x];
	for (int i = 0; i < size_x; i++) {
		newMatrix[i] = new int[size_y];

		for (int j = 0; j < size_y; j++) {
			newMatrix[i][j] = rand();
		}
	}
	return newMatrix;


}

void printMatrix(int** matrix, int size_X, int size_Y) {
	for (int i = 0; i < size_X; i++) {


		for (int j = 0; j < size_Y; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
int sum_matrix(int** matrix, int size_x, int size_y) {
	int sum = 0;

	for (int i = 0; i < size_x;i++) {

		for (int j = 0; j < size_y; j++) {
			sum = sum + matrix[i][j];
		}

	}
	return sum;
}

int count_pozitive(int** matrix, int size_x, int size_y) {
	int counter = 0;
	for (int i = 0; i < size_x;i++) {
		for (int j = 0; j < size_y; j++) {
			if (matrix[i][j] > 0) {
				counter++;
			}

		}
	}

	return counter;
}

/*int** mat(int size_x, int size_y, int size_z) {
	int** newMatrix = new int* [size_x];
	for (int i = 0; i < size_x; i++) {
		newMatrix[i] = new int[size_y];

		for (int j = 0; j < size_y; j++) {
			newMatrix[j] = new int[size_z];
			for (int k = 0; k < size_z; k++) {

				newMatrix[i][j][k] = 1 + 1 + 1;
			}
		}
	}
	return newMatrix;


}
*/
int cub(int** mat, int size_x, int size_y, int size_z) {



}
int main()
{
	int mat[3][3][3]{ {1,1,1}, {1,1,1},{1,1,1} };
	int** matrix = matrixx(5, 5);
	const int size = 8;
	int arr[size] = {1,5,3,2,5,6,4,2};
	//int* array2 = new int[8] {1, 5, 0, 0, 7, 6, 5, 0};
	//int* array = new int[7] {2, 1, 3, 8, 5, 7, 10};
	//cout<<max_array_a2(array, 7);
	//cout << min_array(array, 5);
	//cout<<min_a1(array, 7);
	/*cout << endl;
	max_a2_a4(array, 5);
	cout << endl;
	min_a1_a3(array, 5);
	*/
	//cout << endl;
	//cout << min_a2_a4(array, 7);
	//cout << max_array_abs(array, 7);
	//cout << count_null(array2, 8) << endl;
	//cout << um(arr, size);

	//printMatrix(matrix, 5, 5);
	//cout << sum_matrix(matrix, 5, 5);
	cout << count_pozitive(matrix, 5, 5);
}

