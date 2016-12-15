#include <iostream>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<int> sum(const vector<int> &v1, const vector<int> &v2) {
	vector<int> v;
	if (v1.size() != v2.size()) {
		cout << "Wektory sa roznych rozmiarow" << endl;
		return v; // nie podoba mi siê to rozwiazanie, wolalbym nic nie zwracac niz pusty wektor
	}
	else {
		int range = max(v1.size(), v2.size());
		v.resize(range);
		for (int i = 0; i < range; i++) { //nie wiem czy da sie to zrobic z iteratorem
			v[i] = v1[i] + v2[i];
		}
		return v;
	}
}

int main() {

	vector<int> v1;
	vector<int> v2;
	vector<int> v;
	
	v1.resize(5);
	v2.resize(5);
	
	for (auto itr = v1.begin(); itr != v1.end();itr++) {
		int x;
		cin >> x;
		*itr = x;
	}
	for (auto itr = v2.begin(); itr != v2.end();itr++) {
		int x;
		cin >> x;
		*itr = x;
	}
	
	v = sum(v1, v2);
	for (auto itr = v.begin(); itr != v.end();itr++) {
		cout << *itr << endl;
	}

	system("PAUSE");
	return 0;
}