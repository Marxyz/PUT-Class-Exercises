#include "Scena.h"

#include <GL/freeglut.h>
#include <iostream>

extern Scena scena;

void Scena::Init(char* window_name, int argc, char *argv[])
{
	glutInit(&argc, argv);
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

void Scena::KeyboardFunctions(unsigned char key, int mouse_x, int mouse_y)
{

	std::cout << "Naciœniêto klawisz: " << key << ", a myszka znajduje siê w pozycji: " << mouse_x << ", " << mouse_y << "(w pikselach)" << std::endl;
	if (_zbior_Prostokatow.size() > 0)
	{
		switch (key)
		{
		case 'a':
		{
			_zbior_Prostokatow[_actual].MoveLeft();
			break;
		}
		case 'd':
		{
			_zbior_Prostokatow[_actual].MoveRight();
			break;
		}
		case 'w':
		{
			_zbior_Prostokatow[_actual].MoveUp();
			break;
		}
		case 's':
		{
			_zbior_Prostokatow[_actual].MoveDown();
			break;
		}
		case '+':
		{
			if (_actual + 1 != _zbior_prostokatow.size())
			{
				_actual++;
			}
			break;
		}
		case '-':
			if (_actual - 1 != -1)
			{
				_actual--;
			}
			break;
		case 'r':
		{
			UsunProstokat(_zbior_Prostokatow, _actual);
			_actual = _zbior_Prostokatow.size() - 1;
			break;
		}
		case 'n':
		{
			DodajProstokat(_zbior_Prostokatow);
			_actual = _zbior_Prostokatow.size() - 1;
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
			DodajProstokat(_zbior_prostokatow);
			_actual = _zbior_prostokatow.size() - 1;
			break;
		}
		}
	}
}

void Scena::DisplayFunction()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glPopMatrix();
	glutSwapBuffers();
}

void Scena::IdleFunctions()
{
	glutPostRedisplay();
}

void Scena::ResizeFunctions(int width, int height)
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

void SetCallbackFunctions()
{
	glutReshapeFunc(scena.ResizeFunctions);
}


Scena::Scena()
{
}


Scena::~Scena()
{
}
