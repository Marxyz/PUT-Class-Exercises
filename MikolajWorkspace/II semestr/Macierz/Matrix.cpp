#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Macierz {
private:
	vector<vector<int>> wektor;
public:
	Macierz();
	Macierz(int a, int b);
	Macierz(Macierz &M);

	void SetMacierz();
	void DispMacierz();
	void Zerowa();
	void Jedynkowa();
	Macierz Dopelnienie(int x, int y);
	int Wyznacznik();


	Macierz operator+(const Macierz &M);
	Macierz operator*(const Macierz &M)const;
	Macierz operator*(int x)const;
	Macierz operator=(Macierz &M);


	friend istream& operator >> (istream &stream, Macierz&M);
	friend ostream& operator <<(ostream &stream, const Macierz &M);
};

Macierz operator*(int x, const Macierz&M);

int main() {


	Macierz a;
	a.SetMacierz();

	cout << a.Wyznacznik();




	return 0;
}


Macierz::Macierz()
{
	wektor.resize(0);
}

Macierz::Macierz(int a, int b)
{
	wektor.resize(a);
	for (int i = 0; i < a; i++) {
		wektor[i].resize(b);
	}
}

Macierz::Macierz(Macierz & M)
{
	this->wektor = M.wektor;
}



void Macierz::SetMacierz()
{
	int a, b;
	cout << "Podaj wymiary macierzy." << endl;
	cin >> a >> b;
	wektor.resize(a);
	for (int i = 0; i < a; i++) {
		wektor[i].resize(b);
	}
	cout << "Wypelnij macierz." << endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> wektor[i][j];
		}
	}
}

void Macierz::DispMacierz()
{
	for (int i = 0; i < wektor.size(); i++) {
		for (int j = 0; j < wektor[i].size(); j++) {
			cout << wektor[i][j] << '\t';
		}
		cout << endl;
	}
}

void Macierz::Zerowa()
{
	for (int i = 0; i < wektor.size(); i++) {
		for (int j = 0; j < wektor[0].size(); j++) {
			this->wektor[i][j] = 0;
		}
	}
}

void Macierz::Jedynkowa()
{
	if (this->wektor.size() == this->wektor[0].size()) {
		this->Zerowa();
		for (int i = 0; i < wektor.size(); i++) {
			this->wektor[i][i] = 1;
		}
	}
}

Macierz Macierz::Dopelnienie(int x, int y)
{
	int a = this->wektor.size();
	int b = this->wektor[0].size();
	Macierz tmp(a - 1, b - 1);
	int wartW = 0;
	int wartKol = 0;
	for (int i = 0; i < a - 1;i++) {
		if (i >= x) wartW = 1;
		for (int j = 0; j < b - 1; j++) {
			if (j >= y) wartKol = 1;
			tmp.wektor[i][j] = this->wektor[i + wartW][j + wartKol];
		}
		wartKol = 0;
	}
	return tmp;
}

int Macierz::Wyznacznik()
{
	int det = 0;
	int n = this->wektor.size();
	if (n == 1) return this->wektor[0][0];
	else {
		for (int i = 0; i < this->wektor.size(); i++) {
			det += this->wektor[i][0] * pow(-1, i)*this->Dopelnienie(i, 0).Wyznacznik();
		}
		return det;
	}

}

Macierz Macierz::operator+(const Macierz & M)
{

	if (this->wektor.size() == M.wektor.size() && this->wektor[0].size() == M.wektor[0].size()) {
		Macierz tmp(M.wektor.size(), M.wektor[0].size());
		/*tmp.wektor.resize(M.wektor.size());
		for (int i = 0; i < M.wektor.size(); i++) {
		tmp.wektor[i].resize(M.wektor[i].size());
		}*/
		for (int i = 0; i < wektor.size(); i++) {
			for (int j = 0; j < wektor[0].size(); j++) {
				tmp.wektor[i][j] = this->wektor[i][j] + M.wektor[i][j];
			}
		}
		return tmp;
	}
	else {
		cout << "Operacja niemozliwa.";
	}

}

Macierz Macierz::operator*(const Macierz & M)const
{
	if (this->wektor[0].size() == M.wektor.size()) {
		Macierz tmp(this->wektor.size(), M.wektor[0].size());
		/*tmp.wektor.resize(this->wektor.size());
		for (int i = 0; i < tmp.wektor.size(); i++) {
		tmp.wektor[i].resize(M.wektor[0].size());
		}*/
		for (int i = 0; i < tmp.wektor.size(); i++) {
			for (int j = 0; j < tmp.wektor[0].size(); j++) {
				for (int k = 0; k < M.wektor.size(); k++) {
					tmp.wektor[i][j] += this->wektor[i][k] * M.wektor[k][j];
				}
			}
		}
		return tmp;
	}
}

Macierz Macierz::operator*(int x) const
{
	Macierz tmp(this->wektor.size(), this->wektor[0].size());
	/*tmp.wektor.resize(this->wektor.size());
	for (int i = 0; i < tmp.wektor.size(); i++) {
	tmp.wektor[i].resize(this->wektor[i].size());
	}*/
	for (int i = 0; i < tmp.wektor.size(); i++) {
		for (int j = 0; j < tmp.wektor[0].size();j++) {
			tmp.wektor[i][j] = x*this->wektor[i][j];
		}
	}
	return tmp;
}

Macierz Macierz::operator=(Macierz & M)
{
	this->wektor = M.wektor;
	return *this;
}

istream & operator >> (istream & stream, Macierz & M)
{
	int a, b;
	cout << "Podaj wymiary macierzy." << endl;
	stream >> a >> b;
	M.wektor.resize(a);
	for (int i = 0; i < a; i++) {
		M.wektor[i].resize(b);
	}
	cout << "Wypelnij macierz." << endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			stream >> M.wektor[i][j];
		}
	}
	return stream;
}

ostream & operator<<(ostream & stream, const Macierz & M)
{
	for (int i = 0; i < M.wektor.size(); i++) {
		for (int j = 0; j < M.wektor[i].size(); j++) {
			stream << M.wektor[i][j] << '\t';
		}
		stream << endl;
	}
	return stream;
}

Macierz operator*(int x, const Macierz & M)
{
	return M*x;
}
