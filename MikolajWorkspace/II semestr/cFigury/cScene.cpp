#include "cScene.h"

cScene scena;

//CALLBACKS FUNCTIONS

void MouseCallback(int button, int state, int x, int y)
{
	scena.Mouse(button,state,x,y);
}


void DrawCallback()
{
	scena.Draw();
}
void KeyboardCallback(unsigned char key, int x, int y)
{
	scena.Keyboard(key, x, y);
}

void ResizeCallback(int a, int b)
{
	scena.Resize(a, b);
}

void Idle()
{
	glutPostRedisplay();

}


cScene::cScene() : active(-1), xmin(-1.0), ymin(-1.0), xmax(1.0), ymax(1.0)
{

}

cScene::~cScene()
{
}

void cScene::Init()
{
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow("Robot");
	glClearColor(1, 1, 1, 1);
	
	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -.1, .1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/

	glutIdleFunc(Idle);
	glutDisplayFunc(DrawCallback);
	glutKeyboardFunc(KeyboardCallback);
	glutMouseFunc(MouseCallback);
	glutReshapeFunc(ResizeCallback);

}

void cScene::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	for (cFigura* element : obiekty)
	{
		element->Draw();
	}
	glPopMatrix();

	glutSwapBuffers();
}

void cScene::Resize(int width, int height)
{
	const auto ar = static_cast<float>(width) / static_cast<float>(height);
	this->xmin = -ar;
	this->xmax = ar;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(xmin, xmax, ymin, ymax, -.1, .1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}



void cScene::Keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'a': {
		if(active >=0) obiekty[active]->Move(-0.01, 0.0);
		break;
	}
	case 'd': {
		if (active >= 0) obiekty[active]->Move(0.01, 0.0);
		break;
	}
	case 'w': {
		if (active >= 0) obiekty[active]->Move(0.0, 0.01);
		break;
	}
	case 's': {
		if (active >= 0) obiekty[active]->Move(0.0, -0.01);
		break;
	}
	case 'y':
	{
		if (active >= 0) obiekty[active]->Rotate(5);
		break;
	}
	case 'r':
	{
		if (active >= 0) obiekty[active]->Rotate(-5);
		break;
	}
	case 'p': {
		cProstokat *tmp = new cProstokat;
		obiekty.push_back(tmp);
		active = obiekty.size() - 1;
		break;
	}
	case 'o':
		{
		cOkrag *tmp = new cOkrag;
		obiekty.push_back(tmp);
		active = obiekty.size() - 1;
		break;
		}
	case 't':
		{
		cTrojkat *tmp = new cTrojkat;
		obiekty.push_back(tmp);
		active = obiekty.size() - 1;
		break;
		}
	case 'e': {
		if (obiekty.size() > 0) {
			obiekty.erase(obiekty.begin() + active);
			active = obiekty.size() - 1;
		}
		break;
	}
	case '+': {
		if (active < obiekty.size() - 1) {
			active++;
		}
		break;
	}
	case '-': {
		if (active > 0) {
			active--;
		}
		break;
	}

	}
}

void cScene::Mouse(int button, int state, int x, int y)
{
	
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		double windowWidth = glutGet(GLUT_WINDOW_WIDTH);
		double windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
		//std::cout << windowWidth << std::endl;

		double xU = xmin + x / windowWidth * (xmax - xmin);
		double yU = ymax - y / windowHeight * (ymax - ymin);
		for (auto i = 0; i < obiekty.size(); i++)
		{
			if (obiekty[i]->IsActive(xU, yU))
			{
				active = i;
				break;
			}
		}
	}
	

}
