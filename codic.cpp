#include <iostream>
#include<cmath>
#include<string>
using namespace std;

int z(int x, int y) {
	int z = 0;
	if (x > y) {
		z = x - y;
	}
	else {
		z = y - x + 1;
	}
	return z;
}

int factorial(int i)
{
	if (i == 0) return 1;
	else return i * factorial(i - 1);
}

/*int sum(int x) {
	int index = 3;
	int answ = 0;
	if (index == 13) {
		return 1;
	}
	else {
		return answ += pow(x, index) / factorial(index);
		index += 2;
		if (index == 9) {
			return answ -= pow(x, index) / factorial(index);
		}
	}
	return x - answ;
}*/

int sum(int x) {
	int index = 3;
	int answ = 0;
	while (index != 5) {
		answ += pow(x, index) / factorial(index);
		index = index + 2;
		if (index == 11) {
			answ -= pow(x, index) / factorial(index);
			index += 2;
		}
	}
	return x - answ;


}

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
	return array[0] + max_array_a2(array, n);


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
	for (int i = 1; i < size;i = i + 2) {
		temp *= array[i];

	}
	return temp;

}

int** matrixx(int size_x, int size_y) {
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

/* int*** cub(int size_x, int size_y, int size_z) {
	int*** newMat = new int** [size_x];
	for (int i = 0; i < size_x; i++) {
		newMat[i] = new int*[size_y];
		for (int j = 0; j < size_y; j++) {
			newMat[i][j] = new int [size_z];
			for (int k = 0; k < size_z; k++) {
				newMat[i][j][k] = i + j + k;
			}
		}
	}

	return newMat;
}
*/
/*void print_cub(int*** mat, int size_x, int size_y, int size_z) {
	for (int i = 0; i < size_x;i++) {
		for (int j = 0; j < size_y;j++) {
			for (int k = 0; k < size_z;k++) {
				cout << mat[i][j][k] << " ";
			}cout << endl;
		}cout << endl;
	}


}
*/
string task1(string str) {

	string result = str;
	int temp = size(result);
	for (int i = 0; i < temp;i++) {
		if (result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u' || result[i] == 'y') {
			result[i] = '_';
		}

	}
	return result;

}

int main()
{
	
	//string str = "hello world";
	//cout<<task1(str);
	//int*** mat = cub(3,3,3);
	//print_cub(mat, 3, 3, 3);
	//int** matrix = matrixx(5, 5);
	//const int size = 8;
	//int arr[size] = {1,5,3,2,5,6,4,2};
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
	//cout << count_pozitive(matrix, 5, 5);


}
