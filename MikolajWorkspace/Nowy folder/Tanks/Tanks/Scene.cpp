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



Scene::Scene() :  xmin(-20.0), ymin(-20.0), xmax(20.0), ymax(20.0)
{

}

Scene::~Scene()
{
}

void Scene::Idle()
{
	scene.Update();
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

	Tank* tank = new Tank();
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

}


void Scene::Keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'w':
		{
		objects[0]->MoveUp();
		break;
		}
	case 's':
		{
		objects[0]->MoveDown();
		break;
		}
	case 'a':
		{
		objects[0]->Rotate(5);
		break;
		}
	case 'd':
	{
		objects[0]->Rotate(-5);
		break;
	}
	}
}

void Scene::Mouse(int button, int state, int x, int y)
{


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		double windowWidth = glutGet(GLUT_WINDOW_WIDTH);
		double windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
		//std::cout << windowWidth << std::endl;

		double xU = xmin + x / windowWidth * (xmax - xmin);
		double yU = ymax - y / windowHeight * (ymax - ymin);
	}

}

void Scene::MouseMove(int x, int y) {
	double windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	double windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
	double WHratio = windowWidth / windowHeight;

	double xU = (xmin + x / windowWidth * (xmax - xmin));
	double yU = (ymax - y / windowHeight * (ymax - ymin));

	double alfa = (atan2(objects[0]->GetY() - yU, objects[0]->GetX()-xU)*180.0 / 3.14) - objects[0]->GetAlpha();
	Tank*tmp = dynamic_cast<Tank*>(objects[0]);
	if (tmp != nullptr)
	{
		tmp->RotateTurret(alfa);
	}
}