#include "Klocek_Paletkowy.h"
#include "Paletka.h"
#include <GL/freeglut.h>
int Klocek_Paletkowy::Akcja(Scena& scena)
{
	_wytrzymalosc--;
	if (_wytrzymalosc == 1)
	{
		dynamic_cast<Paletka*>(scena.Zbior_Obiektow[5])->Zwieksz_Rozmiar(1.10);
	}
	scena.punktacja += _punktacja;

	if (_wytrzymalosc == 0)
	{
		this->widoczny = false;
	}
	return 0;
}

Klocek_Paletkowy::Klocek_Paletkowy(double dlugosc, double wysokosc, int punktacja, int wytrzymalosc):Klocek(dlugosc,wysokosc,punktacja,wytrzymalosc)
{
	this->setFizyka(0.000007,-90);
}



void Klocek_Paletkowy::Draw()
{
	if (_wytrzymalosc == 1)
	{
		Prostokat(*this).Draw();
	}
	else
	{
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
				glColor3d(1 - c_r, 1 - c_g, 1 - c_b);
				glVertex3d(1.0*-_dlugosc / 2, 1.0*-_wysokosc / 2, 0);
			}
			glEnd();
			glPopMatrix();

		}
	}
}