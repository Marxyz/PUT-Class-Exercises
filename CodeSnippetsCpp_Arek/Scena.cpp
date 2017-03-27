#include "Scena.h"
#include <GL/freeglut.h>
#include <iostream>
#include <ctime>


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
	for (auto el:Zbior_prostokatow)
	{
		el.Draw();
	}
	glPopMatrix();
	glutSwapBuffers();
}

void Scena::Klawisz(unsigned char key, int x, int y) {

	std::cout << "Naciœniêto klawisz: " << key << ", a myszka znajduje siê w pozycji: " << x << ", " << y << "(w pikselach)" << std::endl;
	if (Zbior_prostokatow.size() > 0)
	{
		switch (key)
		{
		case 'a':
		{
			Zbior_prostokatow[actual].MoveLeft();
			break;
		}
		case 'd':
		{
			Zbior_prostokatow[actual].MoveRight();
			break;
		}
		case 'w':
		{
			Zbior_prostokatow[actual].MoveUp();
			break;
		}
		case 's':
		{
			Zbior_prostokatow[actual].MoveDown();
			break;
		}
		case '+':
		{
			if (scena.actual + 1 !=Zbior_prostokatow.size())
			{

				scena.actual++;
				break;
			}
		}
		case '-':
			if (scena.actual- 1 != -1)
			{

				scena.actual--;
				break;
			}
		case 'z':
		{
			break;
		}
		case 'x':
		{

			break;
		}
		case 'n':
		{
			DodajProstokat();
			break;
		}
		case 'r':
		{
			UsunProstokat();
			break;
		}

		}
	}
	else
	{
		switch (key)
		{
		case 'n':
		{
			DodajProstokat();
			break;
		}
		}
	}
	glutPostRedisplay();

}

void Scena::Inicjuj() {

	Prostokat tmp(1,1,0.1), tmp1(1, 1, 0.1), tmp2(1, 1, 0.1);
	Zbior_prostokatow.push_back(tmp);
	Zbior_prostokatow.push_back(tmp1);
	Zbior_prostokatow.push_back(tmp2);
	
	srand(time(nullptr));


	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Przykladowy program");
	glClearColor(0, 1, 0.5, 1);
	glutDisplayFunc(przerysuj);
	glutReshapeFunc(resize);
	glutKeyboardFunc(klawisz);
}

void Scena::Resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//xs = xmin+ (xmax - xmin)/w * xmyszki
	//ymin = 
	glOrtho(-10, 10, -10, 10,-1, 1);

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
Scena::Scena()
{
}

