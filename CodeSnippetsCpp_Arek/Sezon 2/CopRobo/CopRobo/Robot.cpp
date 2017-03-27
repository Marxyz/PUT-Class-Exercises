#include "Robot.h"
#include "GL/freeglut.h"

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}


void Robot::Aktualizuj(double czas)
{
	_yAktualizacji = _wewnetrznaMacierzKatow[_iterAktualizacji][1];
	_xAktualizacji = _wewnetrznaMacierzKatow[_iterAktualizacji][0];
	if (_iterAktualizacji + 1 == _wewnetrznaMacierzKatow.size())
	{
		return;
	}
	double roznicaX = _wewnetrznaMacierzKatow[_iterAktualizacji + 1][0] - _wewnetrznaMacierzKatow[_iterAktualizacji][0];
	double roznicaY = _wewnetrznaMacierzKatow[_iterAktualizacji + 1][1] - _wewnetrznaMacierzKatow[_iterAktualizacji][1];

	_yAktualizacji += 1.0*roznicaY / czas;
	_xAktualizacji += 1.0*roznicaX / czas;



	glPushMatrix();
	glTranslated(_xAktualizacji, _yAktualizacji, 0);
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
	/*for (int i = 0; i < Zbior_Segementow.size(); i++)
	{
		Zbior_Segementow[i].Rysuj();
	}*/
	glPopMatrix();

}

bool Robot::CzyZaktualizowane()
{
	return true;
}

void Robot::ZapamietajPunkt()
{
	_wewnetrznaMacierzKatow.push_back(std::vector<double>());
	_wewnetrznaMacierzKatow[_iterZapisu].push_back(_x_glowne);
	_wewnetrznaMacierzKatow[_iterZapisu].push_back(_y_glowne);
	for ( int i = 0; i < this->Rozmiar(); i++)
	{
		_wewnetrznaMacierzKatow[_iterZapisu].push_back(Zbior_Segementow[i].ZwrocKatPoczakowy());
	}
	_iterZapisu++;
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

Robot::Robot() : _x_glowne(0), _y_glowne(0), _aktywnySegment(0), _szerokoscBazy(1), _wysokoscBazy(1)
{
	_r = fRand(0, 1);
	_g = fRand(0, 1);
	_b = fRand(0, 1);
}
