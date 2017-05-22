#include "Scena.h"
#include <GL/freeglut.h>
#include <iostream>
#include <ctime>
#include "Kolo.h"
#include "Klocek.h"
#include "Paletka.h"
#include "Klocek_Paletkowy.h"


using namespace std;

Scena scena; //globalny obiekt sceny

void idle()
{
	Sleep(12);
	scena.Idle();
	glutPostRedisplay();

}

void pasywnaMysz(int x, int y)
{
	scena.PasywnaMysz(x, y);
}


void przerysuj() //pomocnicza funkcja callback
{
	scena.Rysuj();
}

void resize(int width, int height) //pomocnicza funkcja callback
{
	scena.Resize(width, height);
}

void Scena::Rysuj() {


	Zbior_Obiektow[1]->GoTo(0, _ymax + 2);
	Zbior_Obiektow[2]->GoTo(0, _ymin - 1);
	Zbior_Obiektow[2]->SetColor(0.8, 0, 0);
	Zbior_Obiektow[3]->GoTo(_xmax + 2, 0);
	Zbior_Obiektow[4]->GoTo(_xmin - 2, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	for (auto el : Zbior_Obiektow)
	{
		if (el->ZwracajWidoczny())
		{
			el->Draw();
		}
	}
	glPopMatrix();
	glutSwapBuffers();
}

void Scena::Inicjuj() {


	srand(time(nullptr));

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Arkanoid - gra wstepna");
	glClearColor(1, 1, 1, 1);


	/*
		float width = glutGet(GLUT_WINDOW_WIDTH);
		float height = glutGet(GLUT_WINDOW_HEIGHT);
		const float ar = (float)width / (float)height;


		if (width >= height) {

			_xmin *= ar;
			_xmax *= ar;
		}
		else {

			_ymin /= ar;
			_ymax /= ar;
		}*/


	Zbior_Obiektow.push_back(new Kolo(0.75, 0));
	Zbior_Obiektow[0]->setPredkosc(predkosc, 45);

	//Ramka
	Zbior_Obiektow.push_back(new Prostokat(abs(_xmax - _xmin), 4, 0));
	Zbior_Obiektow.push_back(new Prostokat(abs(_xmax - _xmin), 4, 0));
	Zbior_Obiektow.push_back(new Prostokat(4, abs(_ymax - _ymin), 0));
	Zbior_Obiektow.push_back(new Prostokat(4, abs(_ymax - _ymin), 0));

	// 5 element to paletka
	Zbior_Obiektow.push_back(new Paletka(12, 2, 1));

	//Klocki
	int y_temp = -1;
	for (size_t i = 0; i < 50; i++)
	{
		if (i % 10 == 0)
		{
			y_temp++;
		}
		Klocek* kl;


		if (i % 6 == 0)
		{
			kl = new Klocek(10, 6, 20, 2);
		}
		else { kl = new Klocek(10, 6, 10, 1); }

		kl->GoTo(_xmin + 5 + i % 10 * 10, _ymax - 3 - y_temp * 6);
		Zbior_Obiektow.push_back(kl);
	}
	int helper = -1;
	for (int i = 0; i < 4; i++)
	{
		helper++;
		Zbior_Obiektow.push_back(new Klocek_Paletkowy(10, 6, 10, 2));
		Zbior_Obiektow[Zbior_Obiektow.size() - 1]->GoTo(_xmin + 5 + helper * 30, _ymax - 30 - 3);
	}
	
	// Ustawienie pilki i aktywna paletka
	Zbior_Obiektow[0]->GoTo(0, _ymin + 3);
	Zbior_Obiektow[5]->GoTo(0, _ymin + 2);
	scena.setActual(5);

	glutPassiveMotionFunc(pasywnaMysz);
	glutReshapeFunc(resize);
	glutDisplayFunc(przerysuj);
	glutIdleFunc(idle);
}

/*void Scena::Mysz(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		double window_width = glutGet(GLUT_WINDOW_WIDTH);
		double window_height = glutGet(GLUT_WINDOW_HEIGHT);

		double xp = _xmin + 1.0* x / window_width * abs(_xmax - _xmin);
		double yp = _ymax - 1.0* y / window_height * abs(_ymax - _ymin);
		for (int i = 0; i < Zbior_Obiektow.size(); i++)
		{
			if (Zbior_Obiektow[i]->czyKliknieta(xp, yp))
			{
				setActual(i);
				return;
			}
		}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		double window_width = glutGet(GLUT_WINDOW_WIDTH);
		double window_height = glutGet(GLUT_WINDOW_HEIGHT);

		double xp = _xmin + 1.0* x / window_width * abs(_xmax - _xmin);
		double yp = _ymax - 1.0* y / window_height * abs(_ymax - _ymin);

		Zbior_Obiektow[actual]->GoTo(xp, yp);
	}
}*/

void Scena::Resize(int width, int height)
{
	/*_xmin = -20, _xmax = 20;
	_ymin = -20, _ymax = 20;
	const float ar = (float)width / (float)height;
*/
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	/*
		if (width >= height) {

			_xmin *= ar;
			_xmax *= ar;
		}
		else {

			_ymin /= ar;
			_ymax /= ar;
		}*/




	glOrtho(_xmin, _xmax, _ymin, _ymax, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Scena::Aktualizuj()
{
	int elementy_widoczne = 0;
	int czas = GetTickCount(); //zwraca czas w [ms]
	for (int i = 0; i < Zbior_Obiektow.size(); i++)
	{
		Zbior_Obiektow[i]->Aktualizuj(czas);//obliczanie nowych polozen
		if (Zbior_Obiektow[i]->ZwracajWidoczny())
		{
			elementy_widoczne++;
		}
	}


	//wykrywanie kolizji
		for (int i = 0; i< Zbior_Obiektow.size(); i++)
			for (int j = i + 1; j< Zbior_Obiektow.size(); j++)
				if (Zbior_Obiektow[i]->Kolizja(*Zbior_Obiektow[j])) //znajduje kolizje
				{
					if (i==0)
					{
						if (j == 2)
						{
							scena.PrzerwijGre();
						}
						Klocek_Paletkowy* xdd = dynamic_cast<Klocek_Paletkowy*>(Zbior_Obiektow[j]);
						if (xdd != nullptr)
						{
							punktacja += xdd->Akcja(scena);
							cout << "Masz " << scena.punktacja << " punktow. GRATULACJE!" << endl;
							return;
						}
						Klocek* xd = dynamic_cast<Klocek*>(Zbior_Obiektow[j]);
						if (xd != nullptr)
						{
							punktacja += xd->Akcja(scena);
							cout << "Masz " << scena.punktacja << " punktow. GRATULACJE!" << endl;
						}
					}
				}
	if (elementy_widoczne == 6)
	{
		scena.PrzerwijGre();
	}
}

void Scena::PasywnaMysz(int x, int y)
{
	double window_width = glutGet(GLUT_WINDOW_WIDTH);

	double xp = _xmin + 1.0* x / window_width * abs(_xmax - _xmin);

	Zbior_Obiektow[5]->GoTo(xp, _ymin + 2);
}

void Scena::PrzerwijGre()
{
	glutLeaveMainLoop();
}


void Scena::setActual(int i)
{
	if (i != Zbior_Obiektow.size() && i >= 0)
	{
		actual = i;
	}

}


Scena::Scena() :_xmin(-50), _xmax(50), _ymin(-30), _ymax(30), punktacja(0), actual(0), predkosc(0.02)
{
}

void Scena::Idle()
{
	this->Aktualizuj();
}
