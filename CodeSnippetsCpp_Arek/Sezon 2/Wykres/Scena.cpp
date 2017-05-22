#include "Scena.h"
#include <GL/freeglut.h>

Scena scena;

void mousewheel(int button, int dir, int x, int y)
{
	scena.MouseWheel(button, dir, x, y);
}
void mysz(int button, int state, int x, int y)
{
	scena.Mysz(button, state, x, y);
}
void idle()
{
	scena.Idle();
}
void klawisz(unsigned char key, int x, int y)
{
	scena.Klawisz(key, x, y);
}
void przerysuj()
{
	scena.Rysuj();
}
void resize(int width, int height)
{
	scena.Resize(width, height);
}
void Scena::Resize(int width, int height)
{
	glViewport(0, 0, width, height);
	ProjektujWidok();
}

void Scena::Klawisz(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'z':
	{
		this->ZoomIn();
		break;
	}
	case 'x':
	{
		this->ZoomOut();
		break;
	}
	case 'f':
	{
		this->Fit();
		break;
	}
	case 'a':
	{
		this->XMaxSceny += 0.1;
		this->XMinSceny += 0.1;
		ProjektujWidok();
		break;
	}
	case 'd':
	{

		this->XMaxSceny += -0.1;
		this->XMinSceny += -0.1;
		ProjektujWidok();
		break;
	}
	case 'w':
	{

		this->YMaxSceny += -0.1;
		this->YMinSceny += -0.1;
		ProjektujWidok();
		break;
	}
	case 's':
	{

		this->YMaxSceny += 0.1;
		this->YMinSceny += 0.1;
		ProjektujWidok();
		break;
	}
	default:
		break;
	}
}

void Scena::ProjektujWidok() const
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(XMinSceny, XMaxSceny, YMinSceny, YMaxSceny, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Scena::MouseWheel(int button, int dir, int x, int y)
{
	if (dir > 0)
	{
		this->ZoomIn();
	}
	else
	{
		this->ZoomOut();
	}

}

void Scena::ZoomIn()
{
	XMaxSceny *= 0.9;
	XMinSceny *= 0.9;
	YMinSceny *= 0.9;
	YMaxSceny *= 0.9;
	ProjektujWidok();

}

void Scena::ZoomOut()
{
	XMaxSceny *= 1.1;
	XMinSceny *= 1.1;
	YMinSceny *= 1.1;
	YMaxSceny *= 1.1;
	ProjektujWidok();

}

void Scena::Fit()
{
	XMinSceny = Zbior_Wykresow[0].XMin;
	XMaxSceny = Zbior_Wykresow[0].XMax;
	YMinSceny = Zbior_Wykresow[0].YMin;
	YMaxSceny = Zbior_Wykresow[0].YMax;
	ProjektujWidok();
}

void Scena::Pan()
{

}

void Scena::setActual(int i)
{
	if (i < Zbior_Wykresow.size() - 1 && i != -1)
	{
		actual = i;
	}
}

Scena::Scena() : _mouse_x_down(0), _mouse_y_down(0), XMinSceny(-1), XMaxSceny(1), YMinSceny(-1), YMaxSceny(1), actual(0)
{
}

void Scena::Idle()
{
	ProjektujWidok();
	glutPostRedisplay();
}

void Scena::Rysuj()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	for (auto el : Zbior_Wykresow)
	{
		el.Rysuj();
	}
	glPopMatrix();
	glutSwapBuffers();
}

void Scena::Inicjuj()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Wykres");
	glClearColor(1, 1, 1, 1);
	glutDisplayFunc(przerysuj);
	glutReshapeFunc(resize);
	glutKeyboardFunc(klawisz);
	glutIdleFunc(idle);
	glutMouseFunc(mysz);
	glutMouseWheelFunc(mousewheel);
	Zbior_Wykresow.push_back(Wykres("wykres.txt"));
	this->Fit();
}

void Scena::Mysz(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		double window_width = glutGet(GLUT_WINDOW_WIDTH);
		double window_height = glutGet(GLUT_WINDOW_HEIGHT);

		double xp = XMinSceny + 1.0* x / window_width * abs(XMaxSceny - XMinSceny);
		double yp = YMaxSceny - 1.0* y / window_height * abs(YMaxSceny - YMinSceny);

		//Zapamietanie wspolrzednych "dolnego" klikniecia

		_mouse_x_down = xp;
		_mouse_y_down = yp;
		
		//cout << "X Sceny = " << xp << " Y Sceny = " << yp << endl;

	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{

		double window_width = glutGet(GLUT_WINDOW_WIDTH);
		double window_height = glutGet(GLUT_WINDOW_HEIGHT);


		//Projekcja zmiany wspolrzednych podczas "trzymania" myszki 
		double xp = XMinSceny + 1.0* x / window_width * abs(XMaxSceny - XMinSceny);
		double yp = YMaxSceny - 1.0* y / window_height * abs(YMaxSceny - YMinSceny);

		float deltaY = yp - _mouse_y_down;
		float deltaX = xp - _mouse_x_down;

		//Zmiana wspolrzednych sceny
		this->YMaxSceny -= deltaY;
		this->YMinSceny -= deltaY;

		this->XMaxSceny -= deltaX;
		this->XMinSceny -= deltaX;
	}
	
	this->ProjektujWidok();

}
