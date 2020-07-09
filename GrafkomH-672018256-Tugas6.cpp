#include <Windows.h>
#include<glut.h>
#include<math.h>
#include<iostream>


void tampil(void);
void init(void);
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char, int, int);


float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;





void mouse(int button, int state, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;

	}

	else
		mouseDown = false;


	tampil();
}

void mouseMotion(int x, int y) {
	if (mouseDown) {
		yrot = x - xdiff;
		xrot = y + ydiff;

		glLoadIdentity();
		gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(xrot, 1.0, 0.0, 0.0);
		glRotatef(yrot, 0.0, 1.0, 0.0);

		glutPostRedisplay();
	}
}

void keyboard(unsigned char keybor, int x, int y) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	switch (keybor)
	{

	case 's':
	case 'S':
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case 'a':
	case 'A':
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;

	}
	tampil();


}






void tampil(void) {

	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);







	//atap depan
	glBegin(GL_TRIANGLES);
	glColor3f(128, 0, 0);
	glVertex3f(-42, 20, 40);
	glVertex3f(0.0, 40, 40);
	glVertex3f(42, 20, 40);
	glEnd();



	//atap belakang
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-42, 20, -20);
	glVertex3f(0.0, 40, -20);
	glVertex3f(42, 20, -20);
	glEnd();

	//jendela2
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(25.0, -10.0, 20.0);
	glVertex3f(25.0, 10.0, 20.0);
	glVertex3f(30.0, 10.0, 20.0);
	glVertex3f(30.0, -10.0, 20.0);
	glEnd();

	//jendela1
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(20.0, -10.0, 20.0);
	glVertex3f(20.0, 10.0, 20.0);
	glVertex3f(35.0, 10.0, 20.0);
	glVertex3f(35.0, -10.0, 20.0);
	glEnd();



	//ventilasi1
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(20.0, 11.0, 20.0);
	glVertex3f(20.0, 13.0, 20.0);
	glVertex3f(35.0, 13.0, 20.0);
	glVertex3f(35.0, 11.0, 20.0);
	glEnd();

	//kotak kiri 1
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(3.0, 6.0, 20.0);
	glVertex3f(3.0, 1.0, 20.0);
	glVertex3f(6.0, 1.0, 20.0);
	glVertex3f(6.0, 6.0, 20.0);
	glEnd();

	//kotak kiri 2
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(3.0, -8.0, 20.0);
	glVertex3f(3.0, -3.0, 20.0);
	glVertex3f(6.0, -3.0, 20.0);
	glVertex3f(6.0, -8.0, 20.0);
	glEnd();


	//kotak kiri 3
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(3.0, -18.0, 20.0);
	glVertex3f(3.0, -13.0, 20.0);
	glVertex3f(6.0, -13.0, 20.0);
	glVertex3f(6.0, -18.0, 20.0);
	glEnd();


	//kotak kanan 1
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(10.0, 6.0, 20.0);
	glVertex3f(10.0, 1.0, 20.0);
	glVertex3f(13.0, 1.0, 20.0);
	glVertex3f(13.0, 6.0, 20.0);
	glEnd();

	//kotak kanan 2
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(10.0, -8.0, 20.0);
	glVertex3f(10.0, -3.0, 20.0);
	glVertex3f(13.0, -3.0, 20.0);
	glVertex3f(13.0, -8.0, 20.0);
	glEnd();

	//kotak kanan 3
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(10.0, -18.0, 20.0);
	glVertex3f(10.0, -13.0, 20.0);
	glVertex3f(13.0, -13.0, 20.0);
	glVertex3f(13.0, -18.0, 20.0);
	glEnd();

	//pintu utama
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, -20.0, 20.0);
	glVertex3f(1.0, 8.0, 20.0);
	glVertex3f(15.0, 8.0, 20.0);
	glVertex3f(15.0, -20.0, 20.0);
	glEnd();



	//pintu
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-16.0, -20.0, 20.0);
	glVertex3f(-16.0, 8.0, 20.0);
	glVertex3f(-9.0, 8.0, 20.0);
	glVertex3f(-9.0, -20.0, 20.0);
	glEnd();

	//pintu samping
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-20.0, -20.0, 23.0);
	glVertex3f(-20.0, 8.0, 23.0);
	glVertex3f(-20.0, 8.0, 30.0);
	glVertex3f(-20.0, -20.0, 30.0);
	glEnd();

	//jendela samping
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-20.0, -10.0, 32.0);
	glVertex3f(-20.0, 8.0, 32.0);
	glVertex3f(-20.0, 8.0, 39.0);
	glVertex3f(-20.0, -10.0, 39.0);
	glEnd();

	//teras kiri1
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-20.0, -20.0, 40.0);
	glVertex3f(-20.0, -14.0, 40.0);
	glVertex3f(-14.0, -14.0, 40.0);
	glVertex3f(-14.0, -20.0, 40.0);
	glEnd();

	//teras kiri2
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-14.0, -20.0, 38.0);
	glVertex3f(-14.0, -14.0, 38.0);
	glVertex3f(-14.0, -14.0, 40.0);
	glVertex3f(-14.0, -20.0, 40.0);
	glEnd();


	//teras kanan 1
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(40.0, -30.0, 20.0);
	glVertex3f(40.0, -14.0, 20.0);
	glVertex3f(40.0, -14.0, 40.0);
	glVertex3f(40.0, -30.0, 40.0);
	glEnd();

	//teras kanan 2
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(40.0, -14.0, 40.0);
	glVertex3f(38.0, -14.0, 40.0);
	glVertex3f(38.0, -14.0, -20.0);
	glVertex3f(40.0, -14.0, -20.0);
	glEnd();

	//tiang kanan1
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(40.0, -20.0, 40.0);
	glVertex3f(40.0, 20.0, 40.0);
	glVertex3f(38.0, 20.0, 40.0);
	glVertex3f(38.0, -20.0, 40.0);
	glEnd();

	//tiang kanan2
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(40.0, -20.0, 40.0);
	glVertex3f(40.0, 20.0, 40.0);
	glVertex3f(40.0, 20.0, 38.0);
	glVertex3f(40.0, -20.0, 38.0);
	glEnd();


	//tiang tengah1
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(14.0, -20.0, 40.0);
	glVertex3f(14.0, 20.0, 40.0);
	glVertex3f(16.0, 20.0, 40.0);
	glVertex3f(16.0, -20.0, 40.0);
	glEnd();

	//tiang tengah2
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(16.0, -20.0, 40.0);
	glVertex3f(16.0, 20.0, 40.0);
	glVertex3f(16.0, 20.0, 38.0);
	glVertex3f(16.0, -20.0, 38.0);
	glEnd();

	//tiang tengah3
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(14.0, -20.0, 40.0);
	glVertex3f(14.0, 20.0, 40.0);
	glVertex3f(14.0, 20.0, 38.0);
	glVertex3f(14.0, -20.0, 38.0);
	glEnd();

	//tiang kiri1
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-14.0, -20.0, 40.0);
	glVertex3f(-14.0, 20.0, 40.0);
	glVertex3f(-15.0, 20.0, 40.0);
	glVertex3f(-15.0, -20.0, 40.0);
	glEnd();

	//tiang kiri2
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-14.0, -20.0, 40.0);
	glVertex3f(-14.0, 20.0, 40.0);
	glVertex3f(-14.0, 20.0, 38.0);
	glVertex3f(-14.0, -20.0, 38.0);
	glEnd();


	//tiang kiri2
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-15.0, -20.0, 40.0);
	glVertex3f(-15.0, 20.0, 40.0);
	glVertex3f(-15.0, 20.0, 38.0);
	glVertex3f(-15.0, -20.0, 38.0);
	glEnd();



	//jendela2
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-6.0, -10.0, 20.0);
	glVertex3f(-6.0, 10.0, 20.0);
	glVertex3f(-1.0, 10.0, 20.0);
	glVertex3f(-1.0, -10.0, 20.0);
	glEnd();

	//depan
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-40.0, -20.0, 20.0);
	glVertex3f(-40.0, 20.0, 20.0);
	glVertex3f(40.0, 20.0, 20.0);
	glVertex3f(40.0, -20.0, 20.0);
	glEnd();

	//belakang
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-40.0, -30.0, -20.0);
	glVertex3f(-40.0, 20.0, -20.0);
	glVertex3f(40.0, 20.0, -20.0);
	glVertex3f(40.0, -30.0, -20.0);
	glEnd();

	//tangga 1
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.0, -23.0, 43.0);
	glVertex3f(10.0, -23.0, 43.0);
	glVertex3f(10.0, -23.0, 40.0);
	glVertex3f(2.0, -23.0, 40.0);
	glEnd();

	//tangga 1
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.0, -23.0, 43.0);
	glVertex3f(10.0, -23.0, 43.0);
	glVertex3f(10.0, -25.0, 43.0);
	glVertex3f(2.0, -25.0, 43.0);
	glEnd();

	//tangga 2
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.0, -25.0, 45.0);
	glVertex3f(10.0, -25.0, 45.0);
	glVertex3f(10.0, -25.0, 43.0);
	glVertex3f(2.0, -25.0, 43.0);
	glEnd();


	//tangga 2
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.0, -25.0, 45.0);
	glVertex3f(10.0, -25.0, 45.0);
	glVertex3f(10.0, -29.0, 45.0);
	glVertex3f(2.0, -29.0, 45.0);
	glEnd();
	//tangga 2
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.0, -29.0, 45.0);
	glVertex3f(10.0, -29.0, 45.0);
	glVertex3f(10.0, -29.0, 40.0);
	glVertex3f(2.0, -29.0, 40.0);
	glEnd();

	//tehel
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-40.0, -20.0, 40.0);
	glVertex3f(40.0, -20.0, 40.0);
	glVertex3f(40.0, -20.0, -20.0);
	glVertex3f(-40.0, -20.0, -20.0);
	glEnd();




	//bangku1
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(35.0, -15.0, 23.0);
	glVertex3f(20.0, -15.0, 23.0);
	glVertex3f(20.0, -15.0, 20.0);
	glVertex3f(35.0, -15.0, 20.0);
	glEnd();

	//bangku2
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(35.0, -16.0, 23.0);
	glVertex3f(20.0, -16.0, 23.0);
	glVertex3f(20.0, -16.0, 20.0);
	glVertex3f(35.0, -16.0, 20.0);
	glEnd();

	//bangku3
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(35.0, -15.0, 23.0);
	glVertex3f(20.0, -15.0, 23.0);
	glVertex3f(20.0, -16.0, 23.0);
	glVertex3f(35.0, -16.0, 23.0);
	glEnd();
	//bangku4
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(35.0, -20.0, 23.0);
	glVertex3f(35.0, -13.0, 23.0);
	glVertex3f(35.0, -13.0, 20.0);
	glVertex3f(35.0, -20.0, 20.0);
	glEnd();

	//bangku5
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(36.0, -20.0, 23.0);
	glVertex3f(36.0, -13.0, 23.0);
	glVertex3f(36.0, -13.0, 20.0);
	glVertex3f(36.0, -20.0, 20.0);
	glEnd();

	//bangku6
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(36.0, -13.0, 23.0);
	glVertex3f(35.0, -13.0, 23.0);
	glVertex3f(35.0, -20.0, 23.0);
	glVertex3f(36.0, -20.0, 23.0);
	glEnd();

	//bangku7
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(36.0, -13.0, 23.0);
	glVertex3f(35.0, -13.0, 23.0);
	glVertex3f(35.0, -13.0, 20.0);
	glVertex3f(36.0, -13.0, 20.0);
	glEnd();


	//bangku8
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(20.0, -20.0, 23.0);
	glVertex3f(20.0, -13.0, 23.0);
	glVertex3f(20.0, -13.0, 20.0);
	glVertex3f(20.0, -20.0, 20.0);
	glEnd();

	//bangku9
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(19.0, -20.0, 23.0);
	glVertex3f(19.0, -13.0, 23.0);
	glVertex3f(19.0, -13.0, 20.0);
	glVertex3f(19.0, -20.0, 20.0);
	glEnd();

	//bangku10
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(20.0, -13.0, 23.0);
	glVertex3f(19.0, -13.0, 23.0);
	glVertex3f(19.0, -20.0, 23.0);
	glVertex3f(20.0, -20.0, 23.0);
	glEnd();

	//bangku11
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, -13.0, 23.0);
	glVertex3f(19.0, -13.0, 23.0);
	glVertex3f(19.0, -13.0, 20.0);
	glVertex3f(20.0, -13.0, 20.0);
	glEnd();


	//vass1
	glBegin(GL_QUADS);
	glColor3f(0.1, 0.0, 0.0);
	glVertex3f(27.0, -10.0, 27.0);
	glVertex3f(26.0, -10.0, 27.0);
	glVertex3f(26.0, -12.0, 27.0);
	glVertex3f(27.0, -12.0, 27.0);
	glEnd();

	//vass2
	glBegin(GL_QUADS);
	glColor3f(0.1, 0.0, 0.0);
	glVertex3f(27.0, -10.0, 26.0);
	glVertex3f(26.0, -10.0, 26.0);
	glVertex3f(26.0, -12.0, 26.0);
	glVertex3f(27.0, -12.0, 26.0);
	glEnd();

	//vass3
	glBegin(GL_QUADS);
	glColor3f(0.1, 0.0, 0.0);
	glVertex3f(27.0, -10.0, 26.0);
	glVertex3f(27.0, -10.0, 27.0);
	glVertex3f(27.0, -12.0, 27.0);
	glVertex3f(27.0, -12.0, 26.0);
	glEnd();

	//vass4
	glBegin(GL_QUADS);
	glColor3f(0.1, 0.0, 0.0);
	glVertex3f(26.0, -10.0, 26.0);
	glVertex3f(26.0, -10.0, 27.0);
	glVertex3f(26.0, -12.0, 27.0);
	glVertex3f(26.0, -12.0, 26.0);
	glEnd();

	//vass4
	glBegin(GL_QUADS);
	glColor3f(0.1, 0.0, 0.0);
	glVertex3f(26.0, -10.0, 26.0);
	glVertex3f(26.0, -10.0, 27.0);
	glVertex3f(27.0, -10.0, 27.0);
	glVertex3f(27.0, -10.0, 26.0);
	glEnd();


	//meja1
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(30.0, -12.0, 30.0);
	glVertex3f(24.0, -12.0, 30.0);
	glVertex3f(24.0, -12.0, 24.0);
	glVertex3f(30.0, -12.0, 24.0);
	glEnd();

	//meja2
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(30.0, -13.0, 30.0);
	glVertex3f(24.0, -13.0, 30.0);
	glVertex3f(24.0, -13.0, 24.0);
	glVertex3f(30.0, -13.0, 24.0);
	glEnd();

	//meja3
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(30.0, -12.0, 30.0);
	glVertex3f(24.0, -12.0, 30.0);
	glVertex3f(24.0, -13.0, 30.0);
	glVertex3f(30.0, -13.0, 30.0);
	glEnd();

	//meja3
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(30.0, -13.0, 30.0);
	glVertex3f(30.0, -12.0, 30.0);
	glVertex3f(30.0, -12.0, 24.0);
	glVertex3f(30.0, -13.0, 24.0);
	glEnd();

	//meja4
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(24.0, -13.0, 30.0);
	glVertex3f(24.0, -12.0, 30.0);
	glVertex3f(24.0, -12.0, 24.0);
	glVertex3f(24.0, -13.0, 24.0);
	glEnd();

	//meja5
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(28.0, -13.0, 27.0);
	glVertex3f(26.0, -13.0, 27.0);
	glVertex3f(26.0, -20.0, 27.0);
	glVertex3f(28.0, -20.0, 27.0);
	glEnd();

	//meja6
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(28.0, -13.0, 28.0);
	glVertex3f(26.0, -13.0, 28.0);
	glVertex3f(26.0, -20.0, 28.0);
	glVertex3f(28.0, -20.0, 28.0);
	glEnd();

	//meja7
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(28.0, -20.0, 27.0);
	glVertex3f(28.0, -13.0, 27.0);
	glVertex3f(28.0, -13.0, 28.0);
	glVertex3f(28.0, -20.0, 28.0);
	glEnd();

	//meja8
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(26.0, -20.0, 27.0);
	glVertex3f(26.0, -13.0, 27.0);
	glVertex3f(26.0, -13.0, 28.0);
	glVertex3f(26.0, -20.0, 28.0);
	glEnd();

	//lampu1
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(-8.0, 20.0, 28.0);
	glVertex3f(-7.0, 20.0, 28.0);
	glVertex3f(-7.0, 19.0, 28.0);
	glVertex3f(-8.0, 19.0, 28.0);
	glEnd();

	//lampu2
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(-8.0, 20.0, 27.0);
	glVertex3f(-7.0, 20.0, 27.0);
	glVertex3f(-7.0, 19.0, 27.0);
	glVertex3f(-8.0, 19.0, 27.0);
	glEnd();


	//lampu3
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(-8.0, 20.0, 27.0);
	glVertex3f(-8.0, 20.0, 28.0);
	glVertex3f(-8.0, 18.0, 28.0);
	glVertex3f(-8.0, 18.0, 27.0);
	glEnd();

	//lampu1
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(-1.0, 20.0, 28.0);
	glVertex3f(0.0, 20.0, 28.0);
	glVertex3f(0.0, 19.0, 28.0);
	glVertex3f(-1.0, 19.0, 28.0);
	glEnd();

	//lampu2
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(-1.0, 20.0, 27.0);
	glVertex3f(0.0, 20.0, 27.0);
	glVertex3f(0.0, 19.0, 27.0);
	glVertex3f(-1.0, 19.0, 27.0);
	glEnd();


	//lampu3
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(0.0, 20.0, 27.0);
	glVertex3f(0.0, 20.0, 28.0);
	glVertex3f(0.0, 18.0, 28.0);
	glVertex3f(0.0, 18.0, 27.0);
	glEnd();
	
	

	//lampu1
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-8.0, 19.0, 27.0);
	glVertex3f(0.0, 19.0, 27.0);
	glVertex3f(0.0, 18.0, 27.0);
	glVertex3f(-8.0, 18.0, 27.0);
	glEnd();

	//lampu2
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-8.0, 19.0, 28.0);
	glVertex3f(0.0, 19.0, 28.0);
	glVertex3f(0.0, 18.0, 28.0);
	glVertex3f(-8.0, 18.0, 28.0);
	glEnd();

	//lampu2
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-8.0, 18.0, 28.0);
	glVertex3f(0.0, 18.0, 28.0);
	glVertex3f(0.0, 18.0, 27.0);
	glVertex3f(-8.0, 18.0, 27.0);
	glEnd();


	//tehel2
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, -20.0, 40.0);
	glVertex3f(-20.0, -30.0, 40.0);
	glVertex3f(40.0, -30.0, 40.0);
	glVertex3f(40.0, -20.0, 40.0);
	glEnd();



	//plafon
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-40.0, 20.0, 40.0);
	glVertex3f(40.0, 20.0, 40.0);
	glVertex3f(40.0, 20.0, -20.0);
	glVertex3f(-40.0, 20.0, -20.0);
	glEnd();

	//depan depan
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-40.0, -30.0, 40.0);
	glVertex3f(-40.0, 20.0, 40.0);
	glVertex3f(-20.0, 20.0, 40.0);
	glVertex3f(-20.0, -30.0, 40.0);
	glEnd();

	//pagar kiri 1
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(-40.0, -30.0,55.0);
	glVertex3f(-40.0, -10.0, 55.0);
	glVertex3f(-1.0, -10.0, 55.0);
	glVertex3f(-1.0, -30.0, 55.0);
	glEnd();



	//pagar kiri 2
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(-40.0, -30.0, 57.0);
	glVertex3f(-40.0, -10.0, 57.0);
	glVertex3f(-1.0, -10.0, 57.0);
	glVertex3f(-1.0, -30.0, 57.0);
	glEnd();

	//pagar kiri 3
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(-40.0, -30.0, 57.0);
	glVertex3f(-40.0, -10.0, 57.0);
	glVertex3f(-40.0, -10.0, 55.0);
	glVertex3f(-40.0, -30.0, 55.0);
	glEnd();

	//pagar kiri 4
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(-1.0, -30.0, 57.0);
	glVertex3f(-1.0, -10.0, 57.0);
	glVertex3f(-1.0, -10.0, 55.0);
	glVertex3f(-1.0, -30.0, 55.0);
	glEnd();

	//pagar kiri 5
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(-40.0, -10.0, 57.0);
	glVertex3f(-1.0, -10.0, 57.0);
	glVertex3f(-1.0, -10.0, 55.0);
	glVertex3f(-40.0, -10.0, 55.0);
	glEnd();

	//lampu pagar kiri 1
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-5.0, -8.0, 56.0);
	glVertex3f(-6.0, -8.0, 56.0);
	glVertex3f(-6.0, -10.0, 56.0);
	glVertex3f(-5.0, -10.0, 56.0);
	glEnd();


	//lampu pagar kiri 2
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-5.0, -8.0, 55.0);
	glVertex3f(-6.0, -8.0, 55.0);
	glVertex3f(-6.0, -10.0, 55.0);
	glVertex3f(-5.0, -10.0, 55.0);
	glEnd();

	//lampu pagar kiri 3
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-6.0, -8.0, 56.0);
	glVertex3f(-6.0, -8.0, 55.0);
	glVertex3f(-6.0, -10.0, 55.0);
	glVertex3f(-6.0, -10.0, 56.0);
	glEnd();

	//lampu pagar kiri 4
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-5.0, -8.0, 56.0);
	glVertex3f(-5.0, -8.0, 55.0);
	glVertex3f(-5.0, -10.0, 55.0);
	glVertex3f(-5.0, -10.0, 56.0);
	glEnd();

	//lampu pagar kiri 5
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-2.0, -5.0, 54.0);
	glVertex3f(-8.0, -5.0, 54.0);
	glVertex3f(-8.0, -8.0, 54.0);
	glVertex3f(-2.0, -8.0, 54.0);
	glEnd();

	//lampu pagar kiri 6
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-2.0, -5.0, 58.0);
	glVertex3f(-8.0, -5.0, 58.0);
	glVertex3f(-8.0, -8.0, 58.0);
	glVertex3f(-2.0, -8.0, 58.0);
	glEnd();

	//lampu pagar kiri 7
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-2.0, -5.0, 54.0);
	glVertex3f(-2.0, -5.0, 58.0);
	glVertex3f(-2.0, -8.0, 58.0);
	glVertex3f(-2.0, -8.0, 54.0);
	glEnd();

	//lampu pagar kiri 8
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-8.0, -5.0, 54.0);
	glVertex3f(-8.0, -5.0, 58.0);
	glVertex3f(-8.0, -8.0, 58.0);
	glVertex3f(-8.0, -8.0, 54.0);
	glEnd();

	//lampu pagar kiri 9
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-8.0, -5.0, 54.0);
	glVertex3f(-8.0, -5.0, 58.0);
	glVertex3f(-2.0, -5.0, 58.0);
	glVertex3f(-2.0, -5.0, 54.0);
	glEnd();


	//pagar kanan 1
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(40.0, -30.0, 55.0);
	glVertex3f(40.0, -10.0, 55.0);
	glVertex3f(15.0, -10.0, 55.0);
	glVertex3f(15.0, -30.0, 55.0);
	glEnd();

	//pagar kanan 2
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(40.0, -30.0, 57.0);
	glVertex3f(40.0, -10.0, 57.0);
	glVertex3f(15.0, -10.0, 57.0);
	glVertex3f(15.0, -30.0, 57.0);
	glEnd();

	//pagar kanan 3
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(40.0, -30.0, 57.0);
	glVertex3f(40.0, -10.0, 57.0);
	glVertex3f(40.0, -10.0, 55.0);
	glVertex3f(40.0, -30.0, 55.0);
	glEnd();

	//pagar kanan 4
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(15.0, -30.0, 57.0);
	glVertex3f(15.0, -10.0, 57.0);
	glVertex3f(15.0, -10.0, 55.0);
	glVertex3f(15.0, -30.0, 55.0);
	glEnd();

	//pagar kiri 5
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(40.0, -10.0, 57.0);
	glVertex3f(15.0, -10.0, 57.0);
	glVertex3f(15.0, -10.0, 55.0);
	glVertex3f(40.0, -10.0, 55.0);
	glEnd();



	//jendela kiri3
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-40.0, 5.0, -5.0);
	glVertex3f(-40.0, -10.0, -5.0);
	glVertex3f(-40.0, -10.0, -10.0);
	glVertex3f(-40.0, 5.0, -10.0);
	glEnd();

	//jendela kiri3
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-40.0, 5.0, 0.0);
	glVertex3f(-40.0, -10.0, 0.0);
	glVertex3f(-40.0, -10.0, 5.0);
	glVertex3f(-40.0, 5.0, 5.0);
	glEnd();


	//depan kiri
	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(-20.0, 20.0, 40.0);
	glVertex3f(-20.0, -30.0, 40.0);
	glVertex3f(-20.0, -30.0, -20.0);
	glVertex3f(-20.0, 20.0, -20.0);
	glEnd();
	//depan kanan
	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(-40.0, 20.0, 40.0);
	glVertex3f(-40.0, -30.0, 40.0);
	glVertex3f(-40.0, -30.0, -20.0);
	glVertex3f(-40.0, 20.0, -20.0);
	glEnd();


	//jendela kanan3
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(40.0, 5.0, -5.0);
	glVertex3f(40.0, -10.0, -5.0);
	glVertex3f(40.0, -10.0, -10.0);
	glVertex3f(40.0, 5.0, -10.0);
	glEnd();

	//jendela kanan3
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(40.0, 5.0, 0.0);
	glVertex3f(40.0, -10.0, 0.0);
	glVertex3f(40.0, -10.0, 5.0);
	glVertex3f(40.0, 5.0, 5.0);
	glEnd();


	//kanan
	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(40.0, 20.0, 20.0);
	glVertex3f(40.0, -30.0, 20.0);
	glVertex3f(40.0, -30.0, -20.0);
	glVertex3f(40.0, 20.0, -20.0);
	glEnd();




	//kiri
	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(-40.0, 20.0, 20.0);
	glVertex3f(-40.0, -30.0, 20.0);
	glVertex3f(-40.0, -30.0, -20.0);
	glVertex3f(-40.0, 20.0, -20.0);
	glEnd();


	//bawah
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.5, 0.0);
	glVertex3f(-40.0, -30.0, 40.0);
	glVertex3f(40.0, -30.0, 40.0);
	glVertex3f(40.0, -30.0, -20.0);
	glVertex3f(-40.0, -30.0, -20.0);
	glEnd();

	//atap kanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.0, 10.0 + 30.0, 40.0);
	glVertex3f(42.0, -20.0 + 40.0, 40.0);
	glVertex3f(42.0, -20.0 + 40.0, -20.0);
	glVertex3f(-0.0, 10.0 + 30.0, -20.0);
	glEnd();

	//atap kiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 10.0 + 30.0, 40.0);
	glVertex3f(-42.0, -20.0 + 40.0, 40.0);
	glVertex3f(-42.0, -20.0 + 40.0, -20.0);
	glVertex3f(0.0, 10.0 + 30.0, -20.0);
	glEnd();



	glPushMatrix();
	glPopMatrix();
	glutSwapBuffers();


}


void idle() {
	if (!mouseDown) {
		xrot += 0.3f;
		yrot += 0.4f;
	}

	glutPostRedisplay();
}

void ukuran(int lebar, int panjang) {
	if (panjang == 0) panjang = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, lebar / panjang, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);

}


void init(void) {

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	is_depth = 1;
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);


}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("GABRIELA MILITIA MOMOLE 672018256");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

