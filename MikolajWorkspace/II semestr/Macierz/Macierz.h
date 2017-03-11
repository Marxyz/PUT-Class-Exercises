#pragma once
#ifndef MACIERZ_H
#define MACIERZ_H

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
	Macierz(Macierz &M);
	
	void SetMacierz();
	//Macierz GetMacierz();
	void DispMacierz();
	Macierz operator+(const Macierz &M);
	Macierz operator+(int x);
	Macierz operator*(const Macierz &M);
	Macierz operator*(int x);
	int Wyznacznik();
};

Macierz operator+(int x, const Macierz&M);
Macierz operator*(int x, const Macierz&M);
#endif 


