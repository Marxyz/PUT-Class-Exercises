#include <iostream>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

void sum(const vector<int> &v1, const vector<int> &v2, vector<int>& v)
{
	if (v1.size() != v2.size())
	{
		cout << "Wektory sa roznych rozmiarow" << endl;
		// nie podoba mi siê to rozwiazanie, wolalbym nic nie zwracac niz pusty wektor
		//-> Teraz funkcja odrazu koñczy wykonywanie
	}
	else {
		int range = max(v1.size(), v2.size());
		v.resize(range);
		for (int i = 0; i < range; i++) // -> Raczej ciêzko o to, iterator jest ekluzywny dla kontenera poprzez to vector.begin() i vector.end()
		{
			v[i] = v1[i] + v2[i];
		}
	}
}
int main()
{

	vector<int> v1;
	vector<int> v2;
	vector<int> v;

	v1.resize(5);
	v2.resize(5);

	cout << "Podaj elementy pierwszego wektora" << endl;
	for (auto itr = v1.begin(); itr != v1.end(); itr++) {

		int x;
		cin >> x;
		*itr = x;
	}
	cout << "Podaj elementy drugiego wektora" << endl;
	for (auto itr = v2.begin(); itr != v2.end(); itr++) {

		int x;
		cin >> x;
		*itr = x;
	}

	sum(v1, v2, v);
	for (auto itr = v.begin(); itr != v.end(); itr++) {
		cout << *itr << endl;
	}

	system("PAUSE");
	return 0;
}