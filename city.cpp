#include <iostream>
#include <String>
#include <vector>
using namespace std;

struct City {
	string name;
	int population;

	City(string n, int p) : name(n), population(p) {}
};

vector<City> Findmill(vector<City>& c) {
	vector<City> res;
	for (const auto & city : c) {
		if (city.population > 1000000) {
			res.push_back(city);
		}
	}
	return res;
}
int main()
{

	setlocale(LC_ALL, "RUssian");

	vector<City> c;

	c.push_back(City("Москва", 11920000));
	c.push_back(City("Житомир", 110000));
	c.push_back(City("Лисабон", 20000090));
	c.push_back(City("Красноярск", 1500000));

	vector<City> Large = Findmill(c);


for (const auto &city : Large) {
	cout << "Город: " << city.name << ", Население: " << city.population << endl;
}


}

