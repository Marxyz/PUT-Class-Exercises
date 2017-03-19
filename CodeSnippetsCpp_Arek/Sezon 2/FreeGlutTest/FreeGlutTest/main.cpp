#include <iostream>
#define NDEBUG
#include <GL/freeglut.h>
#include <vector>
#include <ctime>

using namespace std;

/*class Prostokat
{


// Globalny prostokat, metody dzialajace nanim
// Globalny vector<Prostokat> tab; w kotrym po iteracji robi sie draw,
// wcisniecie klawisza n dodaje nowy prostokat
// d - usuwanie
// przesuwanie kazdego z nich
// globalne current id - numer aktywnego prostokata. tab[current].move();
// wsad - operujace na aktualnym elemencie
// +-, zwieksza i zmniejsza current o 1


};*/



class Prostokat
{
private:
	double _dlugosc;
	double _wysokosc;
	double _x_sr, _y_sr;
	double c_r, c_g, c_b;
	double _speed;
	double _alpha;



public:

	void Draw();
	void Rotate(double dalpha);
	void MoveTo(int x, int y);
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void SetColor(double r, double g, double b);
	Prostokat(int dlugosc, int wysokosc, double speed);
	Prostokat();
	~Prostokat();
};

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

void Prostokat::Draw()
{

	glPushMatrix();
	// TODO
	// test functions below (glTranslated, glRotated, glColor3d) - what happens when you change their arguments?
	// does their order change the result?
	glTranslated(_x_sr, _y_sr, 0);
	glRotated(_alpha, 0.0, 0.0, 1.0);
	glColor3d(c_r, c_g, c_b);
	glBegin(GL_POLYGON);
	{

		glVertex3d(-_dlugosc / 2, _wysokosc / 2, 0);

		glVertex3d(_dlugosc / 2, _wysokosc / 2, 0);

		glVertex3d(_dlugosc / 2, -_wysokosc / 2, 0);

		glVertex3d(-_dlugosc / 2, -_wysokosc / 2, 0);
	}
	glEnd();
	glPopMatrix();
}

void Prostokat::Rotate(double dalpha)
{
	_alpha += dalpha;
	if (_alpha > 360)
	{
		_alpha = 0;
	}
}

void Prostokat::MoveTo(int x, int y)
{

}

void Prostokat::MoveLeft()
{
	this->_x_sr -= _speed;
}

void Prostokat::MoveRight()
{
	this->_x_sr += _speed;
}

void Prostokat::MoveUp()
{
	this->_y_sr += _speed;
}

void Prostokat::MoveDown()
{
	this->_y_sr -= _speed;
}


void Prostokat::SetColor(double r, double g, double b)
{
	this->c_r = r;
	this->c_g = g;
	this->c_b = b;
}

Prostokat::Prostokat(int dlugosc, int wysokosc, double speed) : _dlugosc(dlugosc), _wysokosc(wysokosc), _x_sr(0), _y_sr(0), _speed(speed), _alpha(0)
{
	this->c_r = fRand(0, 1);
	this->c_g = fRand(0, 1);
	this->c_b = fRand(0, 1);

}

Prostokat::Prostokat()
{

}


Prostokat::~Prostokat()
{
}




vector<Prostokat> Zbior_prostokatow;

int actual = 1;

void UsunProstokat(vector<Prostokat> &zbior_prostokatow, int actual)
{
	zbior_prostokatow.erase(zbior_prostokatow.begin() + actual);
}

void DodajProstokat(vector<Prostokat> &zbior_prostokatow)
{
	double dlugosc, wysokosc, predkosc;
	cout << "Podaj dlugosc: " << endl;
	cin >> dlugosc;
	cout << "Podaj wysokosc: " << endl;
	cin >> wysokosc;
	cout << "Podaj predkosc: " << endl;
	cin >> predkosc;
	Prostokat tmp(dlugosc, wysokosc, predkosc);
	zbior_prostokatow.push_back(tmp);
}

/* GLUT callback Handlers */
void resize(int width, int height)
{
	const float ar = (float)width / (float)height; //aspectratio

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void idle()
{

	if (Zbior_prostokatow.size() > 0)
	{
		for (int i = 0; i < Zbior_prostokatow.size(); i++)
		{
			if (i!= actual)
			{
				Zbior_prostokatow[i].Rotate(0.05);
			}
		}
	}
	glutPostRedisplay();
}

void DrawRectangle(double width, double height)
{

}

void display()
{
	//gdy okno wymaga przerysowania

	// clear the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (Zbior_prostokatow.size() > 0)
	{
		for (auto itr = Zbior_prostokatow.begin(); itr != Zbior_prostokatow.end(); ++itr)
		{
			itr->Draw();
		}
	}

	glPushMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void InitGLUTScene(char* window_name)
{
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);

	// set white as the clear colour
	glClearColor(0, 1, 1, 1); // Ostatnie to przezroczystosc

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}


void FunkcjaDoObslugiKlawiatury(unsigned char key, int mouse_x, int mouse_y)
{
	std::cout << "Naciœniêto klawisz: " << key << ", a myszka znajduje siê w pozycji: " << mouse_x << ", " << mouse_y << "(w pikselach)" << std::endl;
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
			if (actual + 1 != Zbior_prostokatow.size())
			{
				actual++;
			}
			break;
		}
		case '-':
			if (actual - 1 != -1)
			{
				actual--;
			}
			break;
		case 'r':
		{
			UsunProstokat(Zbior_prostokatow, actual);
			actual = Zbior_prostokatow.size() - 1;
			break;
		}
		case 'n':
		{
			DodajProstokat(Zbior_prostokatow);
			actual = Zbior_prostokatow.size() - 1;
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
			DodajProstokat(Zbior_prostokatow);
			actual = Zbior_prostokatow.size() - 1;
			break;
		}
		}
	}
}
void SetCallbackFunctions()
{
	// glut timer func
	// Tu robi main window loop
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(FunkcjaDoObslugiKlawiatury);
}

int main(int argc, char *argv[])
{
	srand(time(0));
	// it's still possible to use console to print messages
	printf("Hello openGL world!");
	// the same can be done with cout / cin

	Prostokat rec1(1, 1, 0.1);
	Prostokat rec(1, 1, 0.1);
	Prostokat rec3(1, 1, 0.1);

	Zbior_prostokatow.push_back(rec);
	Zbior_prostokatow.push_back(rec1);
	Zbior_prostokatow.push_back(rec3);


	glutInit(&argc, argv);
	InitGLUTScene("freeglut template");
	SetCallbackFunctions();

	// start GLUT event loop. It ends when user close the window.
	glutMainLoop();

	return 0;
}