#include "cScene.h"
#include "cKlocek.h"
#include <ctime>
#include "cKlocekBonus.h"

cScene scena;

//CALLBACKS FUNCTIONS

void MouseCallback(int button, int state, int x, int y)
{
	scena.Mouse(button,state,x,y);
}

void MouseMoveCallback(int x, int y) 
{
	scena.MouseMove(x, y);
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



cScene::cScene() : active(-1), xmin(-10.0), ymin(-10.0), xmax(10.0), ymax(10.0), punkty(0), loose(false)
{

}

cScene::~cScene()
{
}

void cScene::Idle()
{
	scena.Aktualizuj();
	glutPostRedisplay();
	Sleep(20);
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
	
	srand(time(nullptr));

	cOkrag *pilka = new cOkrag(0, 0, .5);
	//pilka->setFizyka(1.91*1E-6, -90);
	pilka->setFizyka(0, 0);
	pilka->setPredkosc(0.022, -rand()%20-20);
	obiekty.push_back(pilka);

	cProstokat *paletka = new cProstokat(0, -9, 3, 1);
	paletka->setPredkosc(0, 0);
	paletka->setFizyka(0, 0);
	obiekty.push_back(paletka);

	cProstokat *podloga = new cProstokat(0, -10, 27, 1);
	podloga->setPredkosc(0, 0);
	podloga->setFizyka(0, 0);
	obiekty.push_back(podloga);

	cProstokat *podloga1 = new cProstokat(-13, 0, 1, 20);
	podloga1->setPredkosc(0, 0);
	podloga1->setFizyka(0, 0);
	obiekty.push_back(podloga1);

	cProstokat *podloga2 = new cProstokat(0, 10, 27, 1);
	podloga2->setPredkosc(0, 0);
	podloga2->setFizyka(0, 0);
	obiekty.push_back(podloga2);

	cProstokat *podloga3 = new cProstokat(13, 0, 1, 20);
	podloga3->setPredkosc(0, 0);
	podloga3->setFizyka(0, 0);
	obiekty.push_back(podloga3);

	/*cKlocek *klocus = new cKlocek();
	obiekty.push_back(klocus);*/

	for (float j = 0; j < 3; j++) {
		for (float i = -12; i <= 12; i ++)
		{
			if (rand()%10 == 1)
			{
				cKlocekBonus* tmp = new cKlocekBonus(i, 9 - j);
				obiekty.push_back(tmp);
			}
			else {
				cKlocek* tmp = new cKlocek(i, 9 - j);
				obiekty.push_back(tmp);
			}
		}
	}

	glutIdleFunc(IdleCallback);
	glutDisplayFunc(DrawCallback);
	glutKeyboardFunc(KeyboardCallback);
	glutMouseFunc(MouseCallback);
	glutPassiveMotionFunc(MouseMoveCallback);
	glutReshapeFunc(ResizeCallback);

}

void cScene::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glPushMatrix();
	for (cFigura* element : obiekty)
	{
		if (element->ZwracajWidoczny())
		{
			element->Draw();
		}
	}
	glPopMatrix();

	glutSwapBuffers();
	
}

void cScene::Resize(int width, int height)
{
	const auto ar = static_cast<float>(width) / static_cast<float>(height);
	//this->xmin = ar;
	//this->xmax = -ar;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(xmin*ar, xmax*ar, ymin, ymax, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

/*void cScene::Spawn()
{
	cKlocek *klocek = new cKlocek();
	obiekty.push_back(klocek);
}*/

void cScene::Aktualizuj()
{
	int czas = GetTickCount(); 
	for (int i = 0; i < obiekty.size();i++)
	{
		obiekty[i]->Aktualizuj(czas); 
	}						 
	/*for (int i = 0; i < obiekty.size();i++) {
		for (int j = i + 1;j < obiekty.size();j++)
			if (obiekty[i]->Kolizja(*obiekty[j])) //znajduje kolizje
			{
				std::cout << "Kolizja" << std::endl;
			}
	}*/
	
	//kolizje tylko dla pi³eczki
	for(auto i = 1; i<obiekty.size(); i++)
	{
		if(obiekty[0]->Kolizja(*obiekty[i]))
		{
			if(i==2)
			{
				glutLeaveMainLoop();
				std::cout << "Zdobyles " << punkty << " punktow" << std::endl;

			}
			
			cKlocek*klocek=dynamic_cast<cKlocek*>(obiekty[i]);
			if(klocek!=nullptr)
			{
				punkty += klocek->GetPunkty();
			}

			cKlocekBonus*klocek2 = dynamic_cast<cKlocekBonus*>(obiekty[i]);
			if (klocek2 != nullptr)
			{
				punkty += klocek->GetPunkty();
				obiekty[0]->DodajPredkosc(klocek2->GetV());
			}

			/*cKlocek* p1 = dynamic_cast<cKlocek*>(obiekty[i]);
			try {
				punkty += p1->GetPunkty();
			}
			catch (const std::bad_cast& e)
			{
				//std::cout << "  Exception " << e.what() << std::endl;
			}
			//punkty += p1->GetPunkty();*/
			

			
		}
	}
	int ileWidocznych = 0;
	for(int i = 6; i<obiekty.size(); i++)
	{
		if (obiekty[i]->ZwracajWidoczny())
		{
			ileWidocznych++;
		}
	}
	if(ileWidocznych == 0)
	{
		glutLeaveMainLoop();
		std::cout << "Zdobyles " << punkty << " punktow" << std::endl;
	}
	
	
}

void cScene::Przegrana()
{
	glClearColor(1.000, 0.753, 0.796, 1);
}


void cScene::Keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'a': {
		obiekty[1]->Move(-1.5, 0);
		break;
	}
	case 'd': {
		obiekty[1]->Move(1.5, 0);
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

void cScene::MouseMove(int x, int y) {
	double windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	double windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
	double WHratio = windowWidth / windowHeight;

	double xU = WHratio*(xmin + x / windowWidth * (xmax - xmin)) ;
	//double yU = ymax - y / windowHeight * (ymax - ymin);
	obiekty[1]->MoveTo(xU,obiekty[1]->ZwracajY());
}
