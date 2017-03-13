#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>
double alfa = 0;
double x = 0, y = 0;
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

void idle() //kiedy nie ma co robic xd; obczaic gluttimerfunc
{
	alfa +=  4;
	glutPostRedisplay();
}

void Keyboard(unsigned char key, int mouse_x, int mouse_y){
	std::cout << "Naciśnięto klawisz: " << key << ", a myszka znajduje się w pozycji: " << mouse_x << ", " << mouse_y << "(w pikselach)" << std::endl;
	switch (key){
	case 'a':{
		x -= .1;
		break;
	}
	case 'd':{
		x += .1;
		break;
	}
	case 'w':{
		y += .1;
		break;
	}
	case 's':{
		y -= .1;
		break;
	}
	}

}

void DrawRectangle(double width, double height)
{
	glPushMatrix(); //
	// TODO
	// test functions below (glTranslated, glRotated, glColor3d) - what happen when you change their arguments?
	// does their order change the result?
	glTranslated(0.0, 0.0, 0.0);
	glRotated(0, 1.0, 0.0, 0.0); //pierwszy argument to kat, drugi argument wzgleem ktorej osi
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);
	//glRotated(alfa, 0.0, 0.0, 0.1);
	glTranslated(x, y, 0.0);
	

	//glColor3d(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	{
		glColor3d(1.0, 0.0, 0.0);
		glVertex3d(-width / 2, height / 2, 0);
		glColor3d(0.0, 1.0, 0.0);
		glVertex3d(width / 2, height / 2, 0);
		glColor3d(0.0, 0.0, 1.0);
		glVertex3d(width / 2, -height / 2, 0);
		glColor3d(1.0, 1.0, 0.0);
		glVertex3d(-width / 2, -height / 2, 0);
	}
	glEnd();
	//glRotated(45, 0.0, 0.0, 0.1);
	glPopMatrix();
}

void display() //wywolywana kiedy okno wymaga przerysowania
{
	// clear the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	DrawRectangle(2.0, 1.0);
	glPopMatrix();

	glutSwapBuffers();
}

void InitGLUTScene(char* window_name)
{
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE); //GLUT_DOUBLE - double buffer, glut_depth - 

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
	// it's still possible to use console to print messages
	printf("Hello openGL world!");
	// the same can be done with cout / cin

	glutInit(&argc, argv);
	InitGLUTScene("freeglut template");
	SetCallbackFunctions();

	// start GLUT event loop. It ends when user close the window.
	glutMainLoop();

	return 0;
}


/* Napisac cRectangle, z polami dlugosc, wysokosc, polozenie srodka x,y, alfa do obrotu, R G B; z metodami: dwa konstruktory, przesun_o(dx,dy), przesun_do(x,y)
	rysuj(), obroc(dalfa), setcolor(r,g,b), resize(w,a)


	globalny obiekt rectangle + golablny vector<cRectangle> tab;
	zmienna globalna int currentID;
	'n' = dodaj nowy prostokat
	'e' = usun prostokat
	'+' - zwiekszanie current o 1;
	'-' zmniejszanie current o 1

	tab[currentID]. move - przesuneicie aktywnego obiektu
-*/
