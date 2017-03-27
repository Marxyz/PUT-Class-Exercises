#include "SegmentRobota.h"
#include "GL/freeglut.h"

double frand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}
void SegmentRobota::Rysuj()
{
	glRotated(_katPoczatkowy, 0, 0, 1);
	glPushMatrix();
	glColor3d(_r, _g, _b);
	glBegin(GL_POLYGON);
	{
		glVertex3d(-_szerokoscBoku / 2, 0, 0);
		glVertex3d(-_szerokoscBoku / 2, _dlugoscBoku, 0);
		glVertex3d(_szerokoscBoku / 2, _dlugoscBoku, 0);
		glVertex3d(_szerokoscBoku / 2, 0, 0);
	}
	glEnd();
	glPopMatrix();
	glTranslated(0, _dlugoscBoku, 0);
}

SegmentRobota::SegmentRobota() :_dlugoscBoku(1), _szerokoscBoku(0.5), _katPoczatkowy(0)
{
	_r = frand(0, 1);
	_g = frand(0, 1);
	_b = frand(0, 1);
}

SegmentRobota::SegmentRobota(double KatPoczatkowy) : _katPoczatkowy(KatPoczatkowy),_dlugoscBoku(1), _szerokoscBoku(0.5)
{
	_r = frand(0, 1);
	_g = frand(0, 1);
	_b = frand(0, 1);
}

void SegmentRobota::Obroc(double alfa)
{
	
	_katPoczatkowy += alfa;
	if (_katPoczatkowy > 360)
	{
		_katPoczatkowy = _katPoczatkowy - 360;
	}
}


double SegmentRobota::ZwrocKatPoczakowy()
{
	return this->_katPoczatkowy;
}
