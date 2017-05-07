#include "Scene.h"
#include <ctime>
#include <iostream>

Scene scene;

void MouseCallback(int button, int state, int x, int y)
{
	scene.Mouse(button, state, x, y);
}

void MouseMoveCallback(int x, int y)
{
	scene.MouseMove(x, y);
}

void DrawCallback()
{
	scene.Draw();
}
void KeyboardCallback(unsigned char key, int x, int y)
{
	scene.Keyboard(key, x, y);
}

void ResizeCallback(int a, int b)
{
	scene.Resize(a, b);
}

void IdleCallback()
{
	scene.Idle();

}



Scene::Scene() :  xmin(-20.0), xmax(20.0), ymin(-20.0), ymax(20.0)
{

}

Scene::~Scene()
{
}

void Scene::Idle()
{
	scene.Update();
	scene.Clear();
	glutPostRedisplay();
	Sleep(20);
}

void Scene::Init()
{
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow("Kursk Battle V2");
	glClearColor(1, 1, 1, 1);

	srand(time(nullptr));

	Tank* tank = new Tank(17,-15);
	objects.push_back(tank);

	glutIdleFunc(IdleCallback);
	glutDisplayFunc(DrawCallback);
	glutKeyboardFunc(KeyboardCallback);
	glutMouseFunc(MouseCallback);
	glutPassiveMotionFunc(MouseMoveCallback);
	glutReshapeFunc(ResizeCallback);

}

void Scene::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glPushMatrix();
	for (Drawable* element : objects)
	{
		element->Draw();
	}
	glPopMatrix();

	glutSwapBuffers();
}

void Scene::Resize(int width, int height)
{
	const auto ar = static_cast<float>(width) / static_cast<float>(height);
	
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(xmin*ar, xmax*ar, ymin, ymax, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void Scene::Update()
{
	int time = GetTickCount();
	for (auto element : objects)
	{
		element->Update(time);
	}

}

void Scene::Clear()
{
	double windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	double windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
	double WHratio = windowWidth / windowHeight;

	if (objects.size() > 4) {
		for (std::vector<Drawable*>::iterator element = objects.begin(); element != objects.end();)
		{
			if ((*element)->GetX() > WHratio*xmax || (*element)->GetY() > ymax || (*element)->GetX() < WHratio*xmin || (*element)->GetY() < ymin)
			{
				delete *element;
				element = objects.erase(element);
			}
			else
			{
				element++;
			}
		}
	}
}


void Scene::Keyboard(unsigned char key, int x, int y)
{
	Tank*tmp = dynamic_cast<Tank*>(objects[0]);
	if (tmp != nullptr)
	{
		switch (key)
		{
		case 'w':
		{
			tmp->MoveUp();
			break;
		}
		case 's':
		{
			tmp->MoveDown();
			break;
		}
		case 'a':
		{
			tmp->Rotate(5);
			break;
		}
		case 'd':
		{
			tmp->Rotate(-5);
			break;
		}
		}
	}
}

void Scene::Mouse(int button, int state, int x, int y)
{


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		/*double windowWidth = glutGet(GLUT_WINDOW_WIDTH);
		double windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
		//std::cout << windowWidth << std::endl;

		double xU = xmin + x / windowWidth * (xmax - xmin);
		double yU = ymax - y / windowHeight * (ymax - ymin);*/
		Tank*tmp = dynamic_cast<Tank*>(objects[0]);
		if (tmp != nullptr)
		{
			//Bullet * bullet = new Bullet(tmp->GetX(), tmp->GetY());
			Bullet * bullet = new Bullet(-tmp->GetBarrel()*cos(tmp->getTurretAlpha()/180.0*3.141592) + tmp->GetX(), -tmp->GetBarrel()*sin(tmp->getTurretAlpha()/ 180.0*3.141592)+tmp->GetY());
			bullet->SetSpeed(0.022, tmp->getTurretAlpha());
			objects.push_back(bullet);
		}
		std::cout << objects.size() << std::endl;
	}

}

void Scene::MouseMove(int x, int y) {
	double windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	double windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
	double WHratio = windowWidth / windowHeight;

	double xU = (xmin + x / windowWidth * (xmax - xmin));
	double yU = (ymax - y / windowHeight * (ymax - ymin));

	//double alfa = (atan2(objects[0]->GetX() - yU, objects[0]->GetX()-xU)*180.0 / 3.14) - objects[0]->GetAlpha();
	Tank*tmp = dynamic_cast<Tank*>(objects[0]);
	double alfa = (atan2(yU- objects[0]->GetY(), objects[0]->GetX() - xU)*180.0 / 3.141592)-tmp->getTurretAlpha() / 180.0*3.141592;
	if (tmp != nullptr)
	{
		tmp->RotateTurret(-alfa);
	}
}