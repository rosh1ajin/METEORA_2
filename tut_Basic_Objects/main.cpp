/*
00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
88																																				88
88		888888888		 8888888888 	888888888888	88		  88	888888888888	 888888888888			  88		88			88		88	
88		88		 88		88		  88	88				88		  88 	   	 88			888			88						8888		88		88	
88		88		 88		88		  88	  88			88		  88		 88			88 88		88			  88		88	88		88		88	
88		88		 88		88		  88		88			88    888888		 88			88	 88	    88			  88		88	  88	88		88
88		88	  88		88		  88		  88		888880    88		 88			88	  88	88			  88		88	  88	88		88	
88		88	88			88		  88		    88		88		  88		 88			88		88	88			  88		88		88	88		88	
88		88	   88		88		  88			  88	88		  88		 88			88		   888			  88		88		  8888      88
88		88		 88      8888888888 	888888888888	88		  88	888888888888	88			88	   88888888			88			88		88	
88																																				88
00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
*/



#include "track.h"
#include "GL/freeglut.h"
#include <array>
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")



float angle = 0.0f;  // ��� �������� ������
float Mangle = 0.0f; // ��� �������� ���������� 
float lx = 0.0f, lz = -1.0f, ly = 0.0f;
float x = 0.0f, z = 5.5f, y = 1.65f;
float deltaAngle = 0.0f;
float deltaMove = 0;
float sound1 = 5;
float sound2 = 1;
int xOrigin = -1;
int h, w;
int frame;
char s[50];
int mainWindow, subWindow1, subWindow2, subWindow3;
//�������
int border = 2;
//fov
void setProjection(int w1, int h1)
{
	float ratio;
	ratio = 1.0f * w1 / h1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w1, h1);
	gluPerspective(65, ratio, 0.1, 10000);
	glMatrixMode(GL_MODELVIEW);
}
//������� ����
void changeSize(int w1, int h1) {

	if (h1 == 0)
		h1 = 1;

	w = w1;
	h = h1;

	glutSetWindow(subWindow1);
	glutPositionWindow(border, border);
	glutReshapeWindow(w - 2 * border, h / 2 - border * 3 / 2);
	setProjection(w - 2 * border, h / 2 - border * 3 / 2);

	glutSetWindow(subWindow2);
	glutPositionWindow(border, (h + border) / 2);
	glutReshapeWindow(w / 2 - border * 3 / 2, h / 2 - border * 3 / 2);
	setProjection(w / 2 - border * 3 / 2, h / 2 - border * 3 / 2);

	glutSetWindow(subWindow3);
	glutPositionWindow((w + border) / 2, (h + border) / 2);
	glutReshapeWindow(w / 2 - border * 3 / 2, h / 2 - border * 3 / 2);
	setProjection(w / 2 - border * 3 / 2, h / 2 - border * 3 / 2);
}
//���������
void Meteora()
{
	glRotatef(Mangle, 0.0f, 0.0f, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, 1.5f, 0.0f);
	glutSolidSphere(0.8f, 20, 20);
	glEnd();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, 1.5f, 0.0f);
	glutSolidSphere(0.3f, 10, 10);
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, 4.5f, 1.0f);
	glutSolidSphere(0.3f, 10, 10);
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, -11.0f, -3.0f);
	glutSolidSphere(0.3f, 10, 10);
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, 1.5f, 0.0f);
	glutSolidSphere(0.3f, 10, 10); 
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, -3.0f, 1.0f);
	glutSolidSphere(0.2f, 5, 5);
	glutSolidSphere(0.3f, 10, 10);
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, 4.0f, 1.0f);
	glutSolidSphere(0.3f, 5, 5);
	glutSolidSphere(0.3f, 10, 10);
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, 4.0f, -3.0f);
	glutSolidSphere(0.3f, 10, 10);
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, 4.0f, 0.0f);
	glutSolidSphere(0.8f, 20, 20);
	glutSolidSphere(0.3f, 10, 10);
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(10.0f, -14.0f, 0.0f);
	glutSolidSphere(0.8f, 20, 20);
	Mangle += 0.002f;
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, -10.0f, 3.0f);
	glutSolidSphere(0.4f, 20, 20);
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(10.0f, -8.0f, 19.0f);
	glutSolidSphere(0.4f, 20, 20);
	glutSolidSphere(0.3f, 10, 10);
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, 8.0f, -3.0f);
}
void renderBitmapString(
	float x,
	float y,
	float z,
	void* font,
	char* string) {

	char* c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}
void restorePerspectiveProjection() {

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
void setOrthographicProjection() {
	glMatrixMode(GL_PROJECTION);
	//��������� ������������� ��������
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
}
void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}
//�-� ���������� ���� ������ �����, �����������2
void renderScene2() {		
	glEnd();

	for (int i = -8; i < 8; i++)
		for (int j = -8; j < 8; j++) {
			glPushMatrix();
			glTranslatef(i * 10.0f, 0.0f, j * 10.0f);
			Meteora();
			glPopMatrix();
		}
	for (int i = -1; i < 1; i++)
		for (int j = -1; j < 0; j++) {
			glPushMatrix();
			glTranslatef(i * 0.0f, 0.0f, j * 0.0f);
			Moon();
			Sun();
			Venera();
			Earth();
			Mars();
			glPopMatrix();
		}
}
void renderScene() {
	glutSetWindow(mainWindow);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}
void renderScenesw1() {

	glutSetWindow(subWindow1);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
	renderScene2();

	setOrthographicProjection();
	glPushMatrix();
	glLoadIdentity();
	renderBitmapString(5, 30, 0, GLUT_BITMAP_HELVETICA_12, s);
	glPopMatrix();
	restorePerspectiveProjection();

	glutSwapBuffers();
}
void renderScenesw2() { //� ���������
	glutSetWindow(subWindow2);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, y + 20, z,
		x, y - 1, z,
		lx, 0, lz);
	// ������� ���� � ������� �������� ������
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(x, y, z);
	glRotatef(180 - (angle + deltaAngle) * 180.0 / 3.14, 0.0, 1.0, 0.0);
	glutSolidSphere(0.28, 10, 10);

	Strelka();
	renderScene2();
	glutSwapBuffers();
}
//3 ���� ����� ������
void renderScenesw3() {

	glutSetWindow(subWindow3);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(x - lz * 10, y, z + lx * 10,
		x, y, z,
		0.0f, 1.0f, 0.0f);

	//  ���������� ������
	glPushMatrix();

	glColor3f(1, 0.3, 0);
	glTranslatef(x, y, z);

	glColor3f(0.4, 0.4, 0.4);
	glTranslatef(0, 0, 0.5);
	glutSolidCone(0.45, 2, 10, 10);

	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(0, 0, 0);
	glutSolidCube(0.85);

	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(0, 0, -0.8);
	glutSolidCube(0.85);

	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 0, -0.85);
	glutSolidCube(0.85);
	//gondola
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(-0.75, 0, 0);
	glutSolidCube(0.75);
	//gondola
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(1.55, 0, 0);
	glutSolidCube(0.75);
	//gondola VERH
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(-0.77, 0.77, 0);
	glutSolidCube(0.75);
	//gondola NIZ 
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, -1.5, 0);
	glutSolidCube(0.75);
	//
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(0, 0, 0.63);
	glutSolidCube(0.6);
	//
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(0, 1.45, 0);
	glutSolidCube(0.6);
	//prav
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(0.7, -0.72, 0);
	glutSolidCube(0.6);
	//lev
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(-1.4, 0, 0);
	glutSolidCube(0.6);
	//
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(0.7, 0, -1.5);
	glutSolidCone(0.3, 2, 7, 7);
	//
	glPushMatrix;
	glColor3f(0.6, 0.6, 0.0);
	glTranslatef(0, 0, -0.05);
	glutSolidTorus(0.09, 0.4, 20, 20);
	//
	glPushMatrix;
	glColor3f(0.6, 0.3, 0.0);
	glTranslatef(0, 0, -0.15);
	glutSolidTorus(0.09, 0.45, 20, 20);
	//
	glPushMatrix;
	glColor3f(0.6, 0.15, 0.0);
	glTranslatef(0, 0, -0.22);
	glutSolidTorus(0.09, 0.49, 20, 20);
	//

	//
	glPopMatrix();

	Kompas();

	glutSwapBuffers();
}
//���������
void soundtrack() {
	 Sound();
}
void renderSceneAll() {

	if (deltaMove)
		computePos(deltaMove);

	renderScenesw1();
	renderScenesw2();
	renderScenesw3();

}
//����������
void processNormalKeys(unsigned char key, int xx, int yy) {

	if (key == 27) {
		glutDestroyWindow(subWindow1);
		glutDestroyWindow(subWindow2);
		glutDestroyWindow(subWindow3);
		glutDestroyWindow(mainWindow);
		exit(0);
	}
}
void pressKey(int key, int xx, int yy) {

	switch (key) {
		deltaAngle = (x - 1) * 0.001f;
	case GLUT_KEY_UP: deltaMove = 1.5f; break;
	case GLUT_KEY_DOWN: deltaMove = -1.5f; break;
	}
}
void releaseKey(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_UP:
	case GLUT_LEFT_BUTTON:
	case GLUT_KEY_DOWN: deltaMove = 0; break;
	}
}
//������� ����
void mouseMove(int x, int y)
{
	// ������ ����� ����� ������ �� �������
	if (xOrigin >= 0)
	{
		// �������� deltaAngle
		deltaAngle = (x - xOrigin) * 0.002f;
		// �������� ����������� ������
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}
void mouseButton(int button, int state, int x, int y)
{
	// ������ ������ ��������, ���� ����� ������ ���� ������
	if (button == GLUT_LEFT_BUTTON)
	{
		// ����� ������ ��������
		if (state == GLUT_UP)
		{
			angle += deltaAngle;
			xOrigin = -1;
		}
		else
		{// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}
//main()
void init() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1920, 1080);
	mainWindow = glutCreateWindow("Meteora by Rosh1ajin");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderSceneAll);
	init();
	subWindow1 = glutCreateSubWindow(mainWindow, border, border, w - 2 * border, h / 2 - border * 3 / 2);
	glutDisplayFunc(renderScenesw1);
	init();
	subWindow2 = glutCreateSubWindow(mainWindow, border, (h + border) / 2, w / 2 - border * 3 / 2, h / 2 - border * 3 / 2);
	glutDisplayFunc(renderScenesw2);
	init();
	subWindow3 = glutCreateSubWindow(mainWindow, (w + border) / 2, (h + border) / 2, w / 2 - border * 3 / 2, h / 2 - border * 3 / 2);
	glutDisplayFunc(renderScenesw3);
	init();
	soundtrack();
	glutMainLoop();
	return 1;
}













