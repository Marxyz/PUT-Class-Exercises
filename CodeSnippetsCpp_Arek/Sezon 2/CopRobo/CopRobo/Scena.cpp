#include "Scena.h"
#include <GL/freeglut.h>
#include <iostream>
#include <ctime>


Scena::Scena() :actual(0)
{
}
void idle()
{
	scena.Idle();
}
void Scena::Idle()
{
	if (scena._aktualizuj)
	{

		Zbior_robotow[actual].Aktualizuj(scena._czasIdle);
		glutPostRedisplay();
	}
}

using namespace std;

Scena scena; //globalny obiekt sceny

void przerysuj() //pomocnicza funkcja callback
{
	scena.Rysuj();
}

void klawisz(unsigned char znak, int x, int y) //pomocnicza funkcja callback
{
	scena.Klawisz(znak, x, y);
}

void resize(int width, int height) //pomocnicza funkcja callback
{
	scena.Resize(width, height);
}

void Scena::Rysuj() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	Zbior_robotow[0].RysujCalosc();
	glPopMatrix();
	glutSwapBuffers();
}

void Scena::Klawisz(unsigned char key, int x, int y) {

	std::cout << "Naciœniêto klawisz: " << key << ", a myszka znajduje siê w pozycji: " << x << ", " << y << "(w pikselach)" << std::endl;
	if (Zbior_robotow.size() > 0)
	{
		switch (key)
		{
		case 'a':
		{
			Zbior_robotow[actual].PrzesunWLewo(0.1);
			break;
		}
		case 'd':
		{
			Zbior_robotow[actual].PrzesunWPrawo(0.1);
			break;
		}
		case 'w':
		{
			Zbior_robotow[actual].PrzesunWGore(0.1);
			break;
		}
		case 's':
		{
			Zbior_robotow[actual].PrzesunWDol(0.1);
			break;
		}
		case '+':
		{

			Zbior_robotow[actual].NastepnySegment();

			break;
		}
		case '-':

			Zbior_robotow[actual].PoprzedniSegment();

			break;
		case 'z':
		{
			Zbior_robotow[actual].ObrocAktywnySegment(5);
			break;
		}
		case 'x':
		{
			Zbior_robotow[actual].ObrocAktywnySegment(-5);
			break;
		}
		case 'n':
		{
			Zbior_robotow[actual].DodajSegment();
			break;
		}
		case 'r':
		{
			Zbior_robotow[actual].ZniszczSegment();
			break;
		}
		case 'k':
		{
			Zbior_robotow[actual].ZapamietajPunkt();
			break;
		}
		case 'p':
		{
			scena._aktualizuj = true;
		}
		}
	}
	else
	{
		switch (key)
		{
		case 'n':
		{
			Zbior_robotow[actual].DodajSegment();
			break;
		}
		}
	}
	glutPostRedisplay();

}

void Scena::Inicjuj() {

	/*Prostokat tmp(1,1,0.1), tmp1(1, 1, 0.1), tmp2(1, 1, 0.1);
	Zbior_prostokatow.push_back(tmp);
	Zbior_prostokatow.push_back(tmp1);
	Zbior_prostokatow.push_back(tmp2);
	*/
	srand(time(nullptr));
	Robot rbt;
	SegmentRobota srbt;
	SegmentRobota srbt2(15);
	SegmentRobota srbt3(30);


	rbt.DodajSegment(srbt);
	rbt.DodajSegment(srbt2);
	rbt.DodajSegment(srbt3);
	Zbior_robotow.push_back(rbt);


	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Przykladowy program");
	glClearColor(0, 1, 0.5, 1);
	double czas_p, czas_k;
	czas_p = GetTickCount();
	glutDisplayFunc(przerysuj);
	czas_k = GetTickCount();
	scena._czasIdle = czas_k - czas_p;
	glutReshapeFunc(resize);
	glutKeyboardFunc(klawisz);
	glutIdleFunc(idle);

}

void Scena::Resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Scena::DodajProstokat()
{
	double dlugosc, wysokosc, predkosc;
	cout << "Podaj dlugosc: " << endl;
	cin >> dlugosc;
	cout << "Podaj wysokosc: " << endl;
	cin >> wysokosc;
	cout << "Podaj predkosc: " << endl;
	cin >> predkosc;
	Prostokat tmp(dlugosc, wysokosc, predkosc);
	Zbior_prostokatow.push_back(tmp);
}

void Scena::UsunProstokat()
{
	Zbior_prostokatow.erase(Zbior_prostokatow.begin() + actual);
}
