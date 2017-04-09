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

void IdleCallback()
{
	scena.Idle();

}


cScene::cScene() : active(-1), xmin(-1.0), ymin(-1.0), xmax(1.0), ymax(1.0)
{

}

cScene::~cScene()
{
}

void cScene::Idle()
{
	scena.Aktualizuj();
	glutPostRedisplay();
	//Sleep(1);

}

void cScene::Init()
{
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow("Rybki w akwarium");
	glClearColor(1.000, 0.753, 0.796, 1);
	
	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -.1, .1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/

	cOkrag *pilka = new cOkrag(0, 0, .1);
	pilka->setFizyka(8.91*1E-6, -90);
	pilka->setPredkosc(0, -30);
	obiekty.push_back(pilka);

	cProstokat *podloga = new cProstokat(0, -.8, 1.6, .1);
	podloga->setPredkosc(0, 0);
	podloga->setFizyka(0, 0);
	obiekty.push_back(podloga);

	cProstokat *podloga1 = new cProstokat(-.75, -.3, .1, 1);
	podloga1->setPredkosc(0, 0);
	podloga1->setFizyka(0, 0);
	obiekty.push_back(podloga1);

	cProstokat *podloga2 = new cProstokat(.75, -.3, .1, 1);
	podloga2->setPredkosc(0, 0);
	podloga2->setFizyka(0, 0);
	obiekty.push_back(podloga2);

	cProstokat *podloga3 = new cProstokat(0, .35, 1.6, .1);
	podloga3->setPredkosc(0, 0);
	podloga3->setFizyka(0, 0);
	obiekty.push_back(podloga3);

	glutIdleFunc(IdleCallback);
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

void cScene::Aktualizuj()
{
	std::cout << obiekty.size() << std::endl;
	int czas = GetTickCount(); //zwraca czas w [ms]
	for (int i = 0; i < obiekty.size();i++)
	{
		obiekty[i]->Aktualizuj(czas); //obliczanie nowych polozen
	}						 //wykrywanie kolizji
	for (int i = 0; i < obiekty.size();i++) {
		for (int j = i + 1;j < obiekty.size();j++)
			if (obiekty[i]->Kolizja(*obiekty[j])) //znajduje kolizje
			{
				std::cout << "Kolizja" << std::endl;
			}
	}
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
		cProstokat *tmp = new cProstokat(.1,.1,.15,.19);
		tmp->setFizyka(8.91*1E-6, 90);
		tmp->setPredkosc(0, 31);
		obiekty.push_back(tmp);
		active = obiekty.size() - 1;
		break;
	}
	case 'o':
		{
		cOkrag *tmp = new cOkrag(.2,.2,.1);
		tmp->setFizyka(8.91*1E-6, 0);
		tmp->setPredkosc(0, -71);
		obiekty.push_back(tmp);
		active = obiekty.size() - 1;
		break;
		}
	case 't':
		{
		cTrojkat *tmp = new cTrojkat;
		tmp->setFizyka(8.91*1E-6, -90);
		tmp->setPredkosc(0, 45);
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
