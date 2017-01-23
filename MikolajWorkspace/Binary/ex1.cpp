#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

struct cialo_niebieskie {
	char nazwa[32];
	double masa; // w jottagramach
};

bool CzyLzejszy( cialo_niebieskie A,  cialo_niebieskie B) {
	return A.masa < B.masa;
	
}

int main() {

	fstream file("uklad_sloneczny.bin", ios::in | ios::binary);
	if (!file.is_open()) {
		cerr << "Nie otwarto pliku" << endl;
		return 1;
	}
	
	file.seekg(0, ios_base::end);
	int wielkoscPliku = file.tellg();
	file.seekg(0, ios_base::beg);

	int iloscObiektow = wielkoscPliku / sizeof(cialo_niebieskie);
	
	vector<cialo_niebieskie> wektorPlanet;
	cialo_niebieskie* tmp = new cialo_niebieskie;

	for (int i = 0; i < iloscObiektow; i++) {
		file.read((char*)tmp, sizeof(cialo_niebieskie));
		wektorPlanet.push_back(*tmp);
	}

	
	for (auto itr = wektorPlanet.begin(); itr != wektorPlanet.end(); itr++) {
		cout << itr->nazwa << " " << itr->masa << endl;
	}

	sort(wektorPlanet.begin(), wektorPlanet.end(), CzyLzejszy);
	
	fstream file2("wyniki.bin", ios::out |ios::in| ios::binary);
	if (!file2.is_open()) {
		cerr << "Nie otwarto pliku" << endl;
		return 1;
	}

	for (int i = 0; i < 3; i++) {
		file2.write((char*)&wektorPlanet[i], sizeof(cialo_niebieskie));
	}
	//Sprawdzenie zawartosci pliku2
	/*
	file2.seekg(0, ios_base::end);
	int wielkoscPliku2 = file2.tellg();
	file2.seekg(0, ios_base::beg);
	int iloscObiektow2 = wielkoscPliku2 / sizeof(cialo_niebieskie);
	vector<cialo_niebieskie> wektorPlanet2;
	cialo_niebieskie* tmp2 = new cialo_niebieskie;

	for (int i = 0; i < iloscObiektow2; i++) {
		file2.read((char*)tmp2, sizeof(cialo_niebieskie));
		wektorPlanet2.push_back(*tmp2);
	}
	cout << endl << endl << endl;
	for (auto itr = wektorPlanet2.begin(); itr != wektorPlanet2.end(); itr++) {
		cout << itr->nazwa << " " << itr->masa << endl;
	}
	delete tmp2;
	*/
	delete tmp;
	
	file2.close();
	file.close();


	return 0;
}