#include "cScene.h"
cScene scena;

//CALLBACKS FUNCTIONS

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
	int time = GetTickCount();
	scena.UpdateRobot(time);
	glutPostRedisplay();
	
	//Sleep(1000);
	


}


cScene::cScene():robot(.4,.4), active(-1)
{
	robot.SetColor(0.439, 0.502, 0.565);
}

void cScene::Init()
{
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow("Robot");
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	glOrtho(-1, 1, -1, 1, -.1, .1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutIdleFunc(Idle);
	glutDisplayFunc(DrawCallback);
	glutKeyboardFunc(KeyboardCallback);
	glutReshapeFunc(ResizeCallback);
	
}

void cScene::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	robot.Draw();
	glPopMatrix();

	glutSwapBuffers();
}

void cScene::Resize(int width, int height)
{
	const auto ar = static_cast<float>(width) / static_cast<float>(height);

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void cScene::UpdateRobot(int time)
{
	this->robot.Update(time);
}

void cScene::Keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'a': {
		robot.Move(-0.01, 0.0);
		break;
	}
	case 'd': {
		robot.Move(0.01, 0.0);
		break;
	}
	case 'w': {
		robot.Move(0.0, 0.01);
		break;
	}
	case 's': {
		robot.Move(0.0, -0.01);
		break;
	}
	case 'r':
		{
		robot.Rotate(5);
		break;
		}
	case 't':
	{
		robot.Rotate(-5);
		break;
	}
	case 'n': {
		robot.AddSegment();
		break;
	}
	case 'e': {
		robot.DeleteSegment();
		break;
	}
	case '+': {
		robot.NextSegment();
		break;
	}
	case '-': {
		robot.PrevSegment();
		break;
	}
	case'i':
		{
		robot.RotateSegment(5);
		break;
		}
	case'p':
	{
		robot.RotateSegment(-5);
		break;
	}
	case 'x':
		{
		robot.SavePosition();
		//robot.AutoMove();
		break;
		}
	case 'm': //DZIE DZIALA TAK JAK POWINNO
	{
		//robot.SavePosition();
		robot.MoveTo(0.0, 0.0);
		robot.RotateTo(0.0);
		robot.SetAutomove();
		break;
	}
	}

}
