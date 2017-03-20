#include <iostream>
#include <vector>
#include <algorithm>
#include "cRectangle.h"

#define NDEBUG
#include <GL/freeglut.h>


double x = 0, y = 0;
cRectangle prostokat(2.0,2.0);
std::vector<cRectangle> obiekty(0);
cRectangle p1;
int active=-1;


/* GLUT callback Handlers */
void resize(int width, int height)
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

void idle() 
{
	glutPostRedisplay();
}

void Keyboard(unsigned char key, int mouse_x, int mouse_y) {

	switch (key) {
	case 'a': {
		if (obiekty.size() > 0) obiekty[active].Move(-0.01, 0.0);
		break;
	}
	case 'd': {
		if (obiekty.size() > 0) obiekty[active].Move(0.01, 0.0);
		break;
	}
	case 'w': {
		if (obiekty.size() > 0) obiekty[active].Move(0.0, 0.01);
		break;
	}
	case 's': {
		if (obiekty.size() > 0) obiekty[active].Move(0.0, -0.01);
		break;
	}
	case 'n': {
		cRectangle *p = new cRectangle;
		obiekty.push_back(*p);
		active = obiekty.size() - 1;
		break;
	}
	case 'e': {
		if (obiekty.size() > 0) {
			int wsk = 0;
			for (auto itr = obiekty.begin(); itr != obiekty.end(); itr++) {
				if (wsk == active) {
					obiekty.erase(itr);
					break;
				}
				wsk++;
			}
			active=obiekty.size()-1;
		}
		break;
	}
	case '+' : {
		if (active<obiekty.size()-1) {
			active++;
		}
		break;
	}
	case '-': {
		if (active>0) {
			active--;
		}
		break;
	}
	}

}


void display() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	for (auto itr = obiekty.begin(); itr!=obiekty.end(); itr++){
		itr->Draw();
	}
	glPopMatrix();

	glutSwapBuffers();
}

void InitGLUTScene(char* window_name)
{
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE); 

	glutCreateWindow(window_name);

	// set white as the clear colour
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}

void SetCallbackFunctions()
{
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(Keyboard);
	glutIdleFunc(idle);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	InitGLUTScene("Prostokaty");
	
	SetCallbackFunctions();

	
	glutMainLoop();

	return 0;
}


