#include "Klocek.h"
#include <GL/freeglut.h>
#include "Scena.h"

int Klocek::Zbicie(Scena& scena)
{
	_wytrzymalosc--;
	if (_wytrzymalosc == 1)
	{
		scena.predkosc *= 1.2;
		scena.Zbior_Obiektow[0]->setPredkosc(scena.predkosc, 45);
	}
	scena.punktacja += _punktacja;
	
	if (_wytrzymalosc == 0)
	{
		this->widoczny = false;
	}
	return 0;
}

void Klocek::Draw()
{
	if (_wytrzymalosc == 1)
	{
		Prostokat(*this).Draw();
	}
	else
	{
		glPushMatrix();
		glTranslated(_x, _y, 0);
		glRotated(_alpha, 0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		{
			glColor3d(c_r, c_g, c_b);
			glVertex3d(1.0 * -_dlugosc / 2, _wysokosc / 2, 0);
			glColor3d(1 - c_r, 1 - c_g, 1 - c_b);
			glVertex3d(1.0*_dlugosc / 2, 1.0*_wysokosc / 2, 0);
			glColor3d(c_r, c_g, c_b);
			glVertex3d(1.0*_dlugosc / 2, 1.0*-_wysokosc / 2, 0);
			glColor3d(1 - c_r, 1 - c_g,1 - c_b);
			glVertex3d(1.0*-_dlugosc / 2, 1.0*-_wysokosc / 2, 0);
		}
		glEnd();
		glPopMatrix();

	}
}

int Klocek::Akcja(Scena& scena)
{
	
	return this->Zbicie(scena);
}

Klocek::Klocek() :Prostokat()
{
	
}

Klocek::Klocek(double dlugosc, double wysokosc, int punktacja, int wytrzymalosc)  : Prostokat(dlugosc, wysokosc, 0),_punktacja(punktacja),_wytrzymalosc(wytrzymalosc)
{
	 
}

Klocek::Klocek(double dlugosc, double wysokosc) : Prostokat(dlugosc, wysokosc, 0), _punktacja(10), _wytrzymalosc(1)
{
}
