#include "Robot.h"
#include "GL/freeglut.h"

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}



int Robot::KtorySegmentZRzedu(int rzad)
{
	for (int i = 0; i < _wewnetrznaMacierzKatow[rzad].size(); i++)
	{
		if (Zbior_Segementow[i].ZwrocObecnyKat() != _wewnetrznaMacierzKatow[rzad][i])
		{
			return i;
		}
	}
}

int Robot::ZwrocRozmiarWew()
{
	return _wewnetrznaMacierzKatow.size();
}

void Robot::ZapiszKatyPoczatkowe()
{
	for (auto itr = Zbior_Segementow.begin(); itr != Zbior_Segementow.end(); ++itr)
	{
		itr->ZapiszKatPoczatkowy();
	}
}

void Robot::Aktualizuj(double czas)
{
	if (_wewnetrznaMacierzKatow.size() == 0)
	{
		Zaktualizowane = true;
		PosprzatajPoAktual();
		return;
	}
	for (int i = _wewnetrznaMacierzKatow.size() - 1; i >=0 ; i--)
	{
		Zaktualizowane = false;
		for (int j = _wewnetrznaMacierzKatow[i].size() -1; j >= 0; j--)
		{
			double kat = Zbior_Segementow[j].ZwrocObecnyKat();
			double roznica = abs(_wewnetrznaMacierzKatow[i][j] - kat);

			if (roznica > 0.001)
			{
				Zbior_Segementow[j].Obroc(-(Zbior_Segementow[j].ZwrocKatPocza() - _wewnetrznaMacierzKatow[i][j]) / czas);
				return;
			}
		}
		ZapiszKatyPoczatkowe();
		_wewnetrznaMacierzKatow.erase(_wewnetrznaMacierzKatow.begin() + i);
		return;
	}

}





void Robot::ZapamietajPunkt()
{
	_wewnetrznaMacierzKatow.push_back(std::vector<double>());
	for (int i = 0; i < this->Rozmiar(); i++)
	{
		_wewnetrznaMacierzKatow[_iterZapisu].push_back(Zbior_Segementow[i].ZwrocObecnyKat());
	}
	_iterZapisu++;
}

void Robot::PosprzatajPoAktual()
{
	_wewnetrznaMacierzKatow.clear();
	_iterZapisu = 0;
}

int Robot::Rozmiar()
{
	return this->Zbior_Segementow.size();
}
void Robot::ZniszczSegment()
{
	Zbior_Segementow.erase(Zbior_Segementow.begin() + this->Rozmiar() - 1);
	_aktywnySegment = Rozmiar() - 1;
}

void Robot::NastepnySegment()
{
	if (_aktywnySegment + 1 != Zbior_Segementow.size())
	{
		_aktywnySegment++;
	}
}

void Robot::PoprzedniSegment()
{
	if (_aktywnySegment - 1 != -1)
	{
		_aktywnySegment--;
	}
}


void Robot::PrzesunWGore(double dy)
{
	this->_y_glowne += dy;
}

void Robot::PrzesunWDol(double dy)
{
	this->_y_glowne -= dy;
}

void Robot::PrzesunWLewo(double dx)
{
	this->_x_glowne -= dx;
}

void Robot::PrzesunWPrawo(double dx)
{
	this->_x_glowne += dx;
}

void Robot::DodajSegment(SegmentRobota & segment)
{
	Zbior_Segementow.push_back(segment);
	_aktywnySegment = Rozmiar() - 1;

}

void Robot::DodajSegment()
{
	SegmentRobota tmp(0);
	this->DodajSegment(tmp);
}

void Robot::ObrocAktywnySegment(double kat)
{
	Zbior_Segementow[_aktywnySegment].Obroc(kat);
}

void Robot::RysujCalosc()
{

	glPushMatrix();
	glTranslated(_x_glowne, _y_glowne, 0);
	glRotated(0, 0.0, 0.0, 1.0);
	glColor3d(_r, _g, _b);
	glBegin(GL_POLYGON);
	{
		glVertex3d(-_szerokoscBazy / 2, 0, 0);
		glVertex3d(-_szerokoscBazy / 2, -_wysokoscBazy, 0);
		glVertex3d(_szerokoscBazy / 2, -_wysokoscBazy, 0);
		glVertex3d(_szerokoscBazy / 2, 0, 0);
	}
	glEnd();
	for (int i = 0; i < Zbior_Segementow.size(); i++)
	{
		Zbior_Segementow[i].Rysuj();
	}
	glPopMatrix();
}

Robot::Robot() : _x_glowne(0), _y_glowne(0), _aktywnySegment(0), _szerokoscBazy(1), _wysokoscBazy(1), _iterZapisu(0),Zaktualizowane(true)
{
	_r = fRand(0, 1);
	_g = fRand(0, 1);
	_b = fRand(0, 1);
}
