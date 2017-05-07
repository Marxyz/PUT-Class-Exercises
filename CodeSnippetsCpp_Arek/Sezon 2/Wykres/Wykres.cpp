#include "Wykres.h"
#include <iostream>
#include <fstream>
#include <GL/freeglut.h>

float FloatRandom(float fMin, float fMax)
{

	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

void Wykres::Dodaj_Punkt(const Punkt& punkt)
{
	this->_Zbior_Punktow.push_back(punkt);
}

void Wykres::Sczytaj(string nazwaPliku)
{
	fstream plik;
	plik.open(nazwaPliku, ios_base::in);
	if (plik.good())
	{
		while (!plik.eof())
		{
			string linia;
			getline(plik, linia);
			bool res = SczytajLinie(linia);
			if (!res)
			{
				cout << "Blad parsowania linii." << endl;
			}
		}
	}
	else { cout << "Problem z otworzeniem pliku." << endl; }
}

bool Wykres::SczytajLinie(string linia)
{
	try
	{
		Punkt p;
		int pos = linia.find(";");
		if (pos == -1)
		{
			return false;
		}
		p.x = stof(linia.substr(0, pos));
		p.y = stof(linia.substr(pos + 1, linia.size() - 1));
		Dodaj_Punkt(p);
		return true;
	}
	catch (exception exception)
	{
		cout << exception.what() << endl;
		return false;
	}
}

void Wykres::UstawMinimalneWartosci()
{
	float x_min = _Zbior_Punktow[0].x;
	float x_max = _Zbior_Punktow[0].x;
	float y_min = _Zbior_Punktow[0].y;
	float y_max = _Zbior_Punktow[0].x;

	for (auto punkt : _Zbior_Punktow)
	{
		if (punkt.x < x_min)
		{
			x_min = punkt.x;
		}
		if (punkt.y < y_min)
		{
			y_min = punkt.y;
		}
		if (punkt.x > x_max)
		{
			x_max = punkt.x;
		}
		if (punkt.y > y_max)
		{
			y_max = punkt.y;
		}
	}

	this->XMax = x_max;
	this->XMin = x_min;
	this->YMax = y_max;
	this->YMin = y_min;
}



void Wykres::Rysuj()
{
	glPushMatrix();
	glTranslated(XMin, 0, 0);
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	glColor3d(0.1, 0.3, 0.5);
	for (auto punkt: _Zbior_Punktow)
	{
		glVertex3d(punkt.x, punkt.y, 0);
	}
	glEnd();
	glPopMatrix();
	glPopMatrix();
}

Wykres::Wykres(string NazwaPliku) 
{

	Sczytaj(NazwaPliku);
	UstawMinimalneWartosci();
}

