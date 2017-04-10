#include "Scena.h"
#include <GL/freeglut.h>
#include <iostream>
#include <ctime>
#include "Kolo.h"
#include "Trojkat.h"


using namespace std;

Scena scena; //globalny obiekt sceny

void idle()
{
	scena.Idle();
	glutPostRedisplay();
	Sleep(15);
}

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
	for (auto el : Zbior_Obiektow)
	{
		el->Draw();
	}
	glPopMatrix();
	glutSwapBuffers();
}

void Scena::Klawisz(unsigned char key, int x, int y) {

	std::cout << "Naciœniêto klawisz: " << key << ", a myszka znajduje siê w pozycji: " << x << ", " << y << "(w pikselach)" << std::endl;
	if (Zbior_Obiektow.size() > 0)
	{
		switch (key)
		{
		case 'a':
		{
			Zbior_Obiektow[actual]->MoveLeft();
			break;
		}
		case 'd':
		{
			Zbior_Obiektow[actual]->MoveRight();
			break;
		}
		case 'w':
		{
			Zbior_Obiektow[actual]->MoveUp();
			break;
		}
		case 's':
		{
			Zbior_Obiektow[actual]->MoveDown();
			break;
		}
		case '+':
		{
			scena.setActual(++actual);
		}
		case '-':
			scena.setActual(--actual);
			break;
		case 'z':
		{
			scena.Zbior_Obiektow[actual]->Rotate(5);
			break;
		}
		case 'x':
		{

			scena.Zbior_Obiektow[actual]->Rotate(-5);
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
	
	Zbior_Obiektow.push_back(new Kolo(0.5, 0));
	Zbior_Obiektow[0]->setFizyka(8.91*1E-6, -70);
	Zbior_Obiektow[0]->GoTo(0, 20);
	Zbior_Obiektow.push_back(new Prostokat(4, 4, 0));
	Zbior_Obiektow.push_back(new Prostokat(4, 4, 0));
	Zbior_Obiektow[1]->GoTo(0, -10);
	Zbior_Obiektow[2]->GoTo(5, 0);
	Zbior_Obiektow.push_back(new Prostokat(3, 50, 0));
	Zbior_Obiektow[3]->GoTo(20, 5);
	Zbior_Obiektow.push_back(new Prostokat(40, 3,0));
	Zbior_Obiektow[4]->GoTo(0, -20);
	srand(time(nullptr));

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Arkanoid - gra wstepna");
	glClearColor(0, 1, 0.5, 1);
	glutDisplayFunc(przerysuj);
	glutReshapeFunc(resize);
	glutKeyboardFunc(klawisz);
	glutIdleFunc(idle);
}

void Scena::Mysz(int button, int state, int x, int y)
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
}

void Scena::Resize(int width, int height)
{
	_xmin = -20, _xmax = 20;
	_ymin = -20, _ymax = 20;
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	if (width >= height) {

		_xmin *= ar;
		_xmax *= ar;
	}
	else {

		_ymin /= ar;
		_ymax /= ar;
	}




	glOrtho(_xmin, _xmax, _ymin, _ymax, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Scena::Aktualizuj()
{
	int czas = GetTickCount(); //zwraca czas w [ms]
	for (int i = 0; i< Zbior_Obiektow.size(); i++)
		Zbior_Obiektow[i]->Aktualizuj(czas); //obliczanie nowych polozen
									 //wykrywanie kolizji
	for (int i = 0; i< Zbior_Obiektow.size(); i++)
		for (int j = i + 1; j< Zbior_Obiektow.size(); j++)
			if (Zbior_Obiektow[i]->Kolizja(*Zbior_Obiektow[j])) //znajduje kolizje
			{
				// tu mozna zareagowac na kolizje np. usuwajac „zbity” obiekt itp...
			}
}

void Scena::setActual(int i)
{
	if (i != Zbior_Obiektow.size() && i != -1)
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
	Zbior_Obiektow.push_back(new Prostokat(dlugosc, wysokosc, predkosc));
}

void Scena::UsunProstokat()
{
	Zbior_Obiektow.erase(Zbior_Obiektow.begin() + actual);
}
Scena::Scena() : actual(0), _xmin(-10), _ymin(-10), _xmax(10), _ymax(10)
{

}

void Scena::Idle()
{
	this->Aktualizuj();
}
