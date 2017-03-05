#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct car {
	int rok;
	string kraj;
	string model;
	int szybkosc;
};

bool OdNajstarszego(const car &A, const car&B) {
	return A.rok < B.rok;
}

bool OdNajszybszego(const car &A, const car&B) {
	return A.szybkosc < B.szybkosc;
}

bool Wiecej300(const car&A){
	return A.szybkosc > 300;
}

bool Alfabetycznie(const car &A, const car&B) {
	return A.model < B.model;
}

void KtoryPierwszy(vector<car> cars) {
	sort(cars.begin(), cars.end(), OdNajstarszego);
	auto itr = find_if(cars.begin(), cars.end(), Wiecej300);
	cout << "Jako pierwszy bariere 300 km\\h przekroczyl " << itr->model << " w " << itr->rok << endl;
}

void IlePrzekroczylo300(vector<car> cars) {
	int counter = count_if(cars.begin(), cars.end(), Wiecej300);
	cout << "Bariere 300 km\\h przekroczylo " << counter << " samochodow" << endl;
}

void Najszbyszy(const vector<car> &cars) {
	/*sort(cars.begin(), cars.end(), OdNajszybszego);
	cout << cars[0].kraj << " " << cars[0].rok << " " << cars[0].model << " " << cars[0].szybkosc <<" km\\h" <<endl;*/
	auto itr = max_element(cars.begin(), cars.end(), OdNajszybszego);
	cout << itr->kraj << " " << itr->rok << " " << itr->model << " " << itr->szybkosc << " km\\h" << endl;
}
int main() {
	fstream file("cars.csv", ios::in);
	if (!file.is_open()) {
		cerr << "Unable to open" << endl;
		return 1;
	}
	vector<car> cars;
	
	while (!file.eof()) {
		car tmp;
		string rok, szybkosc;
		getline(file, rok, ';');
		if (rok == "") break;
		istringstream srok(rok);
		srok >> tmp.rok;
		getline(file, tmp.kraj, ';');
		getline(file, tmp.model, ';');
		getline(file, szybkosc);
		istringstream ss(szybkosc);
		ss>>tmp.szybkosc;
		
		cars.push_back(tmp);
		
	}

	sort(cars.begin(), cars.end(), Alfabetycznie);
	ofstream file2("cars_sorted.txt");
	if (!file2.is_open()) {
		cerr << "Unable to open" << endl;
		return 1;
	}
	for (auto itr = cars.begin(); itr != cars.end(); itr++) {
		file2 << itr->rok << ';' << itr->kraj << ';' << itr->model << ';' << itr->szybkosc << " km\\h" << "\r\n";
	}
	
	KtoryPierwszy(cars);
	IlePrzekroczylo300(cars);
	Najszbyszy(cars);
	
	
	file2.close();
	file.close();
	return 0;
}