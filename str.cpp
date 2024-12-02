#include <iostream>
#include<string>
using namespace std;

string task2(string str) {
	string result = str;
	int temp = size(str);
	for (int i = 0; i < temp;i++) {
		result[i] = tolower(result[i]);



	}
	return  result;
}
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
//ну там ещё и верхний регистр сравнивать по хорошему

int main() {
	
	string str = "HeLLo WorLd";
	cout << task1(str) << endl;
	cout << task2(str);
}
