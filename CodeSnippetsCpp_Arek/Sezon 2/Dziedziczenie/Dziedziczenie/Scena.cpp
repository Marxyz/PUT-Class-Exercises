#include "Scena.h"
#include <GL/freeglut.h>
#include <iostream>
#include <ctime>
#include "Kolo.h"
#include "Trojkat.h"


using namespace std;

Scena scena; //globalny obiekt sceny

void mysz(int button, int state, int x, int y)
{
	scena.Mysz(button, state, x, y);

}


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
	for (auto el : Zbior_Figur)
	{
		el->Draw();
	}
	glPopMatrix();
	glutSwapBuffers();
}

void Scena::Klawisz(unsigned char key, int x, int y) {

	std::cout << "Naciœniêto klawisz: " << key << ", a myszka znajduje siê w pozycji: " << x << ", " << y << "(w pikselach)" << std::endl;
	if (Zbior_Figur.size() > 0)
	{
		switch (key)
		{
		case 'a':
		{
			Zbior_Figur[actual]->MoveLeft();
			break;
		}
		case 'd':
		{
			Zbior_Figur[actual]->MoveRight();
			break;
		}
		case 'w':
		{
			Zbior_Figur[actual]->MoveUp();
			break;
		}
		case 's':
		{
			Zbior_Figur[actual]->MoveDown();
			break;
		}
		case '+':
		{
			scena.setActual(++actual);
		}
		case '-':
			scena.setActual(++actual);
			break;
		case 'z':
		{
			scena.Zbior_Figur[actual]->Rotate(5);
			break;
		}
		case 'x':
		{

			scena.Zbior_Figur[actual]->Rotate(-5);
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

	Zbior_Figur.push_back(new Prostokat(4, 4, 1));
	Zbior_Figur.push_back(new Prostokat(4, 4, 0.1));
	Zbior_Figur.push_back(new Prostokat(4, 4, 0.1));
	Zbior_Figur.push_back(new Kolo(2, 0.1));
	Zbior_Figur.push_back(new Trojkat(4, 4, 0.1));

	srand(time(nullptr));


	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Dziedziczenie i polimorfizm");
	glClearColor(0, 1, 0.5, 1);
	glutDisplayFunc(przerysuj);
	glutReshapeFunc(resize);
	glutKeyboardFunc(klawisz);
	glutMouseFunc(mysz);
}

void Scena::Mysz(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		double window_width = glutGet(GLUT_WINDOW_WIDTH);
		double window_height = glutGet(GLUT_WINDOW_HEIGHT);

		double xp = _xmin + 1.0* x / window_width * abs(_xmax - _xmin);
		double yp = _ymax - 1.0* y / window_height * abs(_ymax - _ymin);
		for (int i = 0; i < Zbior_Figur.size(); i++)
		{
			if (Zbior_Figur[i]->czyKliknieta(xp,yp))
			{
				setActual(i);
				return;
			}
		}
	}
	if (button ==  GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		double window_width = glutGet(GLUT_WINDOW_WIDTH);
		double window_height = glutGet(GLUT_WINDOW_HEIGHT);

		double xp = _xmin + 1.0* x / window_width * abs(_xmax - _xmin);
		double yp = _ymax - 1.0* y / window_height * abs(_ymax - _ymin);

		Zbior_Figur[actual]->GoTo(xp, yp);
	}
}

void Scena::Resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	/*if (width >= height) {
		glOrtho(_xmin , _xmax , _ymin, _ymax,-1,1);
	}
	else {
		glOrtho(_xmin, _xmax, _ymin,_ymax ,-1,1);
	}*/




	glOrtho(_xmin, _xmax, _ymin, _ymax, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Scena::setActual(int i)
{
	if (i != Zbior_Figur.size()  && i != -1)
	{
		actual = i;
	}
	
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
	Zbior_Figur.push_back(new Prostokat(dlugosc, wysokosc, predkosc));
}

void Scena::UsunProstokat()
{
	Zbior_Figur.erase(Zbior_Figur.begin() + actual);
}
Scena::Scena() : actual(0), _xmin(-10), _ymin(-10), _xmax(10), _ymax(10)
{

}
