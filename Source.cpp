
#include<windows.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <list>
#include <ctime>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <mmsystem.h>
using namespace std;
int scor = 0;
int j = 0;
int nrbullets = 0;
int HEIGHT = 600;
int WIDTH = 800;
const float ASPECT = float(WIDTH) / HEIGHT;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

class button {

public:
	int x, y;
	button(int xx, int yy) {
		x = xx;
		y = yy;
	}
	void render() {
		glPushMatrix();
		glTranslated(x, y, 0);
		//Buton
		glColor3d(0.0, 0.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2d(-50, -50);
		glVertex2d(250, -50);
		glVertex2d(-50, 100);
		glEnd();

		glColor3d(0.0, 0.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2d(-50, 100);
		glVertex2d(250, 100);
		glVertex2d(250, -50);
		glEnd();

		glPopMatrix();
	}
}BUTON1(WIDTH / 2, 100);
button BUTON2(WIDTH / 2, 300);
button BUTON3(WIDTH / 2, 500);
button BUTON4(75, 100);

int verifpct(int xa, int xb, int xc, int ya, int yb, int yc, int xm, int ym)
{
	float Aabc, Aabm, Aacm, Abcm;

	Aabc = (xa*yb + xc*ya + xb*yc - xc*yb - ya*xb - yc*xa) / 2;
	Aabm = (xa*yb + xm*ya + xb*ym - xm*yb - ya*xb - ym*xa) / 2;
	Aacm = (xa*yc + xm*ya + xc*ym - xm*yc - ya*xc - ym*xa) / 2;
	Abcm = (xb*yc + xm*yb + xc*ym - xm*yc - yb*xc - ym*xb) / 2;


	bool inside = false;

	if (Aabc < 0)
		Aabc = Aabc*(-1);
	if (Aabm < 0)
		Aabm = Aabm*(-1);
	if (Aacm < 0)
		Aacm = Aacm*(-1);
	if (Abcm < 0)
		Abcm = Abcm*(-1);
	if (Aabc == Aabm + Aacm + Abcm)
		inside = true;
	return inside;

}


void litere(char *cuvant, int x, int y)
{
	int i, n, xx, yy;
	xx = x;
	yy = y;
	n = strlen(cuvant);
	for (i = 0; i < n; i++)
	{
		glColor3d(1.0, 1.0, 1.0);
		glRasterPos2i(xx, yy);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, cuvant[i]);
		xx = xx + 15;


	}
}

void litere2(int scor , int x, int y)
{
	int i, n, xx, yy;
	xx = x;
	yy = y;
		glColor3d(1.0, 1.0, 1.0);
		glRasterPos2i(xx, yy);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scor);


}

class bullet {

public:
	float x, y;
	float viteza;
	bool col = 0;
	bullet(int xx, int yy, float vv) {
		x = xx;
		y = yy;
		viteza = vv;
	}
	void render() {
		glPushMatrix();
		glColor3d(1, 1, 1);
		glTranslated(x, y, 0);
		glColor3d(1, 0, 1);
		//glBegin(GL_POINTS);
		//glVertex2d(-30, 0);
		//glVertex2d(30, 0);
		//glEnd();
		glRecti(-5, -5, 5, 5);
		glPopMatrix();
		y += viteza;
	}



};
class meteorit {

public:
	int x;
	float y;
	float viteza;
	bool col = 0;
	meteorit(int xx) {
		x = xx;
		y = HEIGHT - 10;
		//viteza = vv;
	}
	void render() {
		//x = rand() % WIDTH;
		glPushMatrix();
		glColor3d(0.3, 0.3, 0.3);
		glTranslated(x, y, 0);
		glColor3d(0.5, 0.5, 0.5);
		//model 1
		if (x % 3 == 0)
		{
			glColor3d(0.3, 0.3, 0.3);
			viteza = 0.21;
			glBegin(GL_POLYGON);
			glVertex2i(-45, 24);
			glVertex2i(-45, 21);
			glVertex2i(-37, 9);
			glVertex2i(-27, 4);
			glVertex2i(-24, 0);
			glVertex2i(-20, -6);
			glVertex2i(-5, -11);
			glVertex2i(11, -11);
			glVertex2i(21, -11);
			glVertex2i(33, -7);
			glVertex2i(39, -4);
			glVertex2i(45, -6);
			glVertex2i(60, -6);
			glVertex2i(69, -5);
			glVertex2i(77, 4);
			glVertex2i(81, 10);
			glVertex2i(84, 20);
			glVertex2i(82, 27);
			glVertex2i(76, 36);
			glVertex2i(74, 39);
			glVertex2i(78, 43);
			glVertex2i(81, 51);
			glVertex2i(81, 59);
			glVertex2i(81, 68);
			glVertex2i(81, 76);
			glVertex2i(80, 83);
			glVertex2i(69, 90);
			glVertex2i(61, 95);
			glVertex2i(49, 95);
			glVertex2i(41, 89);
			glVertex2i(34, 82);
			glVertex2i(20, 74);
			glVertex2i(07, 75);
			glVertex2i(-9, 76);
			glVertex2i(-9, 72);
			glVertex2i(-9, 62);
			glVertex2i(-8, 53);
			glVertex2i(-15, 44);
			glVertex2i(-28, 42);
			glVertex2i(-36, 40);
			glVertex2i(-45, 38);

			glEnd();

			/*
			glColor3d(1.0, 0.0, 0.0);
			glPointSize(10);
			glBegin(GL_POINTS);
			glVertex2d(-45, 0);
			glVertex2d(81, 0);
			glVertex2d(0, -11);
			glEnd();
			*/
		}
		//model 2
		if (x % 5 == 0)
		{
			glColor3d(0.3, 0.3, 0.3);
			viteza = 0.28;
			glBegin(GL_POLYGON);
			glVertex2i(-23, 17);
			glVertex2i(-14, -6);
			glVertex2i(-4, -14);
			glVertex2i(21, -17);
			glVertex2i(32, -7);
			glVertex2i(41, -7);
			glVertex2i(49, -12);
			glVertex2i(60, -8);
			glVertex2i(60, 2);
			glVertex2i(45, 19);
			glVertex2i(32, 16);
			glVertex2i(39, 26);
			glVertex2i(7, 31);
			glVertex2i(-12, 22);
			glVertex2i(-10, 13);
			glEnd();


			/*
			glColor3d(1.0, 0.0, 0.0);
			glPointSize(10);
			glBegin(GL_POINTS);
			glVertex2d(-23, 0);
			glVertex2d(60, 0);
			glVertex2d(0, -20);
			glEnd();
			*/
		}
		//model 3
		if (x % 7 == 0)
		{
			glColor3d(0.3, 0.3, 0.3);
			viteza = 0.2;
			glBegin(GL_POLYGON);
			glVertex2i(-28, 17);
			glVertex2i(-16, -11);
			glVertex2i(13, -26);
			glVertex2i(38, -20);
			glVertex2i(66, 4);
			glVertex2i(75, 14);
			glVertex2i(71, 32);
			glVertex2i(43, 40);
			glVertex2i(20, 41);
			glVertex2i(-2, 41);
			glVertex2i(-20, 34);
			glVertex2i(-27, 29);



			glEnd();
			/*
			glColor3d(1.0, 0.0, 0.0);
			glPointSize(10);
			glBegin(GL_POINTS);
			glVertex2d(-28, 0);
			glVertex2d(75, 0);
			glVertex2d(0, -26);
			glEnd();
			*/
		}
		//model 4
		if (x % 11 == 0)
		{
			glColor3d(0.3, 0.3, 0.3);
			viteza = 0.23;
			glBegin(GL_POLYGON);
			glVertex2i(6, -8);
			glVertex2i(-31, -4);
			glVertex2i(-49, 14);
			glVertex2i(-53, 23);
			glVertex2i(-54, 37);
			glVertex2i(-37, 45);
			glVertex2i(-15, 56);
			glVertex2i(4, 66);
			glVertex2i(23, 69);
			glVertex2i(44, 59);
			glVertex2i(54, 55);
			glVertex2i(66, 54);
			glVertex2i(79, 43);
			glVertex2i(84, 24);
			glVertex2i(84, 12);
			glVertex2i(80, 3);
			glVertex2i(59, -3);
			glVertex2i(42, -9);
			glVertex2i(25, -9);

			glEnd();


			/*
			glColor3d(1.0, 0.0, 0.0);
			glPointSize(10);
			glBegin(GL_POINTS);
			glVertex2d(-54, 0);
			glVertex2d(84, 0);
			glVertex2d(0, -9);
			glEnd();
			*/
		}


		//model 5
		if (x % 13 == 0)
		{
			glColor3d(0.3, 0.3, 0.3);
			viteza = 0.25;
			glBegin(GL_POLYGON);
			glVertex2i(-48, -15);
			glVertex2i(-30, -25);
			glVertex2i(-12, -12);
			glVertex2i(6, -10);
			glVertex2i(15, -17);
			glVertex2i(30, -15);
			glVertex2i(37, 4);
			glVertex2i(48, 26);
			glVertex2i(48, 27);
			glVertex2i(37, 33);
			glVertex2i(21, 39);
			glVertex2i(5, 41);
			glVertex2i(-5, 37);
			glVertex2i(-11, 31);
			glVertex2i(-19, 34);
			glVertex2i(-31, 41);
			glVertex2i(-48, 41);
			glVertex2i(-67, 37);
			glVertex2i(-70, 27);
			glVertex2i(-69, 15);
			glVertex2i(-63, 8);
			glVertex2i(-62, -1);
			glVertex2i(-67, -12);
			glVertex2i(-60, -27);
			glEnd();


			/*
			glColor3d(1.0, 0.0, 0.0);
			glPointSize(10);
			glBegin(GL_POINTS);
			glVertex2d(-70, 0);
			glVertex2d(48, 0);
			glVertex2d(0, -20);
			glEnd();
			*/
		}
		//model standard
		if (x % 3 != 0 && x % 5 != 0 && x % 7 != 0 && x % 11 != 0 && x % 13 != 0)
		{
			glColor3d(0.3, 0.3, 0.3);
			viteza = 0.20;
			glBegin(GL_POLYGON);
			glVertex2i(-52, -25);
			glVertex2i(-33, -41);
			glVertex2i(-12, -38);
			glVertex2i(3, -30);
			glVertex2i(22, -30);
			glVertex2i(34, -24);
			glVertex2i(51, -11);
			glVertex2i(52, 7);
			glVertex2i(48, 21);
			glVertex2i(24, 37);
			glVertex2i(-8, 40);
			glVertex2i(-26, 33);
			glVertex2i(-42, 24);
			glVertex2i(-56, 21);
			glVertex2i(-70, 7);
			glVertex2i(-67, -13);
			glEnd();

			/*
			glColor3d(1.0, 0.0, 0.0);
			glPointSize(10);
			glBegin(GL_POINTS);
			glVertex2d(-70, 0);
			glVertex2d(52, 0);
			glVertex2d(0, -30);
			glEnd();
			*/
		}



		glColor3d(0.3, 0.3, 0.3);
		glRecti(-5, -5, 5, 5);
		glPopMatrix();
		y = y - viteza;
	}



};

class nava {
public:
	int x, y;
	bool col = 0;
	nava(int xx, int yy) { x = xx; y = yy; }
	void render() {
		glPushMatrix();
		glTranslated(x, y, 0);


		//lansatoare
		glColor3d(1, 1, 0);
		glBegin(GL_TRIANGLES);
		glVertex2d(-30, 60);
		glVertex2d(-40, 40);
		glVertex2d(-20, 40);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2d(30, 60);
		glVertex2d(20, 40);
		glVertex2d(40, 40);
		glEnd();
		//motoare
		glColor3d(1, 0, 0);
		glRecti(-40, -40, -20, 40);
		glRecti(20, -40, 40, 40);

		//corp-nava
		glColor3d(0, 0, 1);
		glRecti(-20, -20, 20, 20);
		//aripi
		glColor3d(0, 0, 1);
		glBegin(GL_TRIANGLES);
		glVertex2d(-40, 20);
		glVertex2d(-80, -20);
		glVertex2d(-40, -20);
		glEnd();

		glBegin(GL_TRIANGLES);
		glVertex2d(40, 20);
		glVertex2d(80, -20);
		glVertex2d(40, -20);
		glEnd();

		//cabina
		glColor3d(0, 1, 1);
		glBegin(GL_TRIANGLES);
		glVertex2d(0, 50);
		glVertex2d(-20, 20);
		glVertex2d(20, 20);
		glEnd();


		glPopMatrix();
	}
}NAVA(WIDTH / 2, 100);
std::list<bullet> bullets;
std::list<meteorit> meteorits;
int timebla;
int check = 0;

void desen1(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	BUTON1.render();
	litere("Exit", BUTON1.x, BUTON1.y);
	BUTON2.render();
	litere("About", BUTON2.x, BUTON2.y);
	BUTON3.render();
	litere("Start", BUTON3.x, BUTON3.y);

	



	glPointSize(15);
	glBegin(GL_POINTS);

	//BUTONUL2
	glColor3d(1.0, 0.0, 0.0);
	glVertex2d(350, 400);
	glVertex2d(350, 250);
	glVertex2d(650, 400);
	glVertex2d(650, 250);

	//Butonul3
	glColor3d(1.0, 0.0, 1.0);
	glVertex2d(650, 200);
	glVertex2d(350, 200);
	glVertex2d(650, 50);
	glVertex2d(350, 50);

	//Butonul1
	glColor3d(0.0, 1.0, 1.0);
	glVertex2d(350, 600);
	glVertex2d(650, 600);
	glVertex2d(350, 450);
	glVertex2d(650, 450);



	glEnd();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

GLboolean CheckCollision(bullet &one, meteorit &two) // AABB - AABB collision
{
	//cout << "functie";
	if (one.x<two.x + 70 && one.x>two.x - 70 && one.y>two.y-1 && one.y<two.y+3)
	{
		one.col = 1;
		two.col = 1;
		cout << one.col << " " << two.col;
		return 1;
	}
	else
		return 0;

}
GLboolean CheckCollisionNava(nava &one, meteorit &two) // AABB - AABB collision
{
	//cout << "functie";
	if (((one.x+70<two.x + 70 && one.x+70>two.x - 70)|| (one.x-70<two.x + 70 && one.x-70>two.x - 70 ))&& ((one.y+60>two.y - 1 && one.y+60<two.y + 3) ||( one.y-60>two.y - 5 && one.y -60<two.y + 30)))
	{
		one.col = 1;
		two.col = 1;
		cout << one.col << " " << two.col;
		return 1;
	}
	else
		return 0;

}


void desen3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	BUTON4.render();
	litere("Back", BUTON4.x, BUTON4.y);
	litere("SPACE WAR", WIDTH / 2 - 200, HEIGHT / 2 + 200);
	litere("By", WIDTH / 2 - 150, HEIGHT / 2 + 175);
	litere("Marcu Cristian,", WIDTH / 2 - 200, HEIGHT / 2 + 150);
	litere("Multescu Andrei, ", WIDTH / 2 - 200, HEIGHT / 2 + 125);
	litere("Tudorache Liviu", WIDTH / 2 - 200, HEIGHT / 2 + 100);
	litere("Thanks for trying our game", WIDTH / 2, 100);
	//litere("Keepo", WIDTH / 2, 75);



	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void desen(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	NAVA.render();
	int i;
	auto it = bullets.begin();
	auto yt = meteorits.begin();
	
	int x, y;
	while (it != bullets.end())
	{

		it->render();
		it++;
	}

	bullets.remove_if([](bullet n) { return n.y > HEIGHT; });
	while (yt != meteorits.end())
	{
		int i = rand() % 10;
		yt->render();
		CheckCollisionNava(NAVA, *yt);
		yt++;
	}
	meteorits.remove_if([](meteorit n) { return n.y < 0; });

	//bullets.remove_if([](bullet n, meteorit p) {return p.y == n.y; });
	//meteorits.remove_if([](meteorit n, bullet p) { return n.y==p.y; });
	/*for(bullet n:bullets){
	std::cout << n.x << ' '<< n.y  << '\n ';
	}
	*/

	auto it2 = bullets.begin();
	auto yt2 = meteorits.begin();

		while (it2 != bullets.end())
	{

		while (yt2 != meteorits.end())
		{
			CheckCollision(*it2, *yt2);
			//if (CheckCollision(*it2, *yt2))
				//scor += 10;
			//CheckCollision(*it2, *yt2);
			yt2++;
			
		}
		it2++;
	}
		meteorits.remove_if([](meteorit n) { return n.col == 1; });
		bullets.remove_if([](bullet n) { return n.col == 1; });


		if (NAVA.col == 1)
		{
			
			exit(0);
		}
	/*
	time_t start = time(0);
	meteorits.push_back(meteorit(rand() % (WIDTH - 15) + 15));
	time_t end = time(0);
	double time = difftime(end, start) * 1000.0;*/
	if (check == 0)
		timebla = clock() / CLOCKS_PER_SEC;
	if (timebla % 1 == 0 && check == 0)
	{
		meteorits.push_back(meteorit(rand() % (WIDTH - 15) + 15));
		check = 1;
	}
	if (timebla != clock() / CLOCKS_PER_SEC)
		check = 0;

	/*for(i=0;i<bullets.size;i++){
	bullets[i]->render( );
	}*/

	//litere(scor, 100, 100);



	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}
void passive(int x1, int y1) {
	HEIGHT = glutGet(GLUT_WINDOW_HEIGHT);
	WIDTH = glutGet(GLUT_WINDOW_WIDTH);
	NAVA.x = x1;
	NAVA.y = HEIGHT - y1;

}

void OnMouseClick(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT&&state == GLUT_DOWN)
	{
		bullets.push_back(bullet(NAVA.x, NAVA.y + 50, 1));
		//PlaySound((LPCSTR) "C:\\Users\Liviu Tudorache\Desktop\PIU.WAV", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound("C:\\Users\Liviu Tudorache\Desktop\PIU.WAV", NULL, SND_SYNC);
		//bullets.push_back(bullet(NAVA.x + 30, NAVA.y + 50, 1));
		//meteorits.push_back(meteorit(rand() % (WIDTH - 15) + 15));
		//PlaySound("C:\Alahu.wav", NULL, SND_ASYNC);
	}

}

//void OnMouseClick3(int button, int state, int x, int y){


void OnMouseClick2(int button, int state, int x, int y)
{
	int i;
	i = 0;


	if (button == GLUT_LEFT&&state == GLUT_DOWN)
	{
		if (verifpct(350, 350, 650, 450, 600, 450, x, HEIGHT - y))
		{

			//Butonul1 tr jos
			cout << "butonul 1 a fost apasat";

			if (j == 0)
			{
				NAVA.col = 0;
				glutDisplayFunc(desen);
				glutMouseFunc(OnMouseClick);
				
			}
		}
		if (verifpct(650, 350, 650, 600, 600, 450, x, HEIGHT - y))
		{//Butonul1 tr sus

			cout << "butonul 1 a fost apasat";
			if (j == 0)
			{
				NAVA.col = 0;
				glutDisplayFunc(desen);
				glutMouseFunc(OnMouseClick);
			}

		}
		if (verifpct(350, 350, 650, 250, 400, 250, x, HEIGHT - y))
		{
			j = 1;
			//Butonul2 tr jos
			cout << "butonul 2 a fost apasat";
			glutDisplayFunc(desen3);
			//glutMouseFunc(OnMouseClick3);
		}
		if (verifpct(650, 350, 650, 400, 400, 250, x, HEIGHT - y))
		{
			//Butonul2 tr sus
			j = 1;
			cout << "butonul 2 a fost apasat";
			glutDisplayFunc(desen3);
			//glutMouseFunc(OnMouseClick3);
		}
		if (verifpct(350, 350, 650, 50, 200, 50, x, HEIGHT - y))
		{
			//Butonul3 tr jos
			cout << "butonul 3 a fost apasat";


			if (i == 0 && j == 0)
			{
				exit(0);
			}

		}
		if (verifpct(650, 350, 650, 200, 200, 50, x, HEIGHT - y))
		{
			//Butonul3 tr sus
			cout << "butonul 3 a fost apasat";

			if (i == 0 && j == 0)
			{
				exit(0);
			}

		}
	}


	if (verifpct(25, 25, 325, 50, 200, 50, x, HEIGHT - y))
	{
		j = 0;
		//Butonul1 tr jos
		cout << "butonul 4 a fost apasat";
		glutDisplayFunc(desen1);
		glutMouseFunc(OnMouseClick2);

	}
	if (verifpct(325, 25, 325, 200, 200, 50, x, HEIGHT - y))
	{//Butonul1 tr sus
		j = 0;
		cout << "butonul 4 a fost apasat";
		glutDisplayFunc(desen1);
		glutMouseFunc(OnMouseClick2);

	}

}


void reshapeScene(GLint width, GLint height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	int w = height * ASPECT;           // w is width adjusted for aspect ratio
	int left = (width - w) / 2;
	glViewport(0, 0, width, height);       // fix up the viewport to maintain aspect ratio
	gluOrtho2D(0, width, 0, height);   // only the window is changing, not the camera
	glMatrixMode(GL_MODELVIEW);

	glutPostRedisplay();
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);

	glutInitWindowPosition(100, 100);
	glutCreateWindow("Space Invaders");
	init();
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(desen1);
	//glutDisplayFunc(desen);

	glutReshapeFunc(reshapeScene);
	glutPassiveMotionFunc(passive);
	glutMouseFunc(OnMouseClick2);

	glutMainLoop();
}