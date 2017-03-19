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
	Macierz(int a, int b);
	Macierz(Macierz &M);
	
	void SetMacierz();
	//Macierz GetMacierz();
	void DispMacierz();
	void Zerowa();
	void Jedynkowa();
	Macierz Dopelnienie(int x, int y);
	int Wyznacznik();

	
	Macierz operator+(const Macierz &M);
	//Macierz operator+(int x);
	Macierz operator*(const Macierz &M)const;
	Macierz operator*(int x)const;
	Macierz operator=(Macierz &M);
	

	friend istream& operator >> (istream &stream, Macierz&M);
	friend ostream& operator <<(ostream &stream, const Macierz &M);
};

Macierz operator*(int x, const Macierz&M);
#endif 


