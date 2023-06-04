#pragma once
#ifndef __FUNCS_H__
#define __FUNCS_H__
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include "GL/freeglut.h"
#include <array>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
//фоновая музыка
void Sound()

{

	PlaySound("MainTheme.wav", NULL, SND_ASYNC);

}
//стрелочка направлени (миникарта)
void Strelka()

{
	glLineStipple(2, 58360);
	glBegin(GL_LINE_LOOP);
	//1
	glColor3d(1, 0, 0);
	glVertex3d(0, 0, 0);
	//2
	glColor3d(1, 0, 0);
	glVertex3d(0, 0, 1);
	//3
	glColor3d(1, 0, 0.5);
	glVertex3d(-0.5, 0, -1);
	//4
	glColor3d(1, 0, 0);
	glVertex3d(0, 0, 0);
	//5
	glColor3d(1, 0, 0.5);
	glVertex3d(0.5, 0, -1);
	//6
	glColor3d(1, 0, 0);
	glVertex3d(0, 0, 1);

	glEnd();
}
//направления небесных тел на 3д ракете
void Kompas()
{
	glColor3f(0.5f, 0.0f, 0.3f);
	glTranslatef(50, 0, -40);
	glutSolidSphere(0.8f, 20, 20);
	glEnd();
}
//луна 
void Moon()
{
	glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
	glTranslatef(100, 0, -40); //Сместили
	glutSolidSphere(10, 80, 80);  //Рисуем сферу

}
//солнце
void Sun()
{
	glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
	glTranslatef(-900, 0, -300); //Сместили
	glutSolidSphere(40, 80, 80);  //Рисуем сферу

}
//земля 
void Earth()
{
	glColor3f(0.0f, 0.7f, 0.9f);
	glTranslatef(-450, 0, 350); //Сместили
	glutSolidSphere(20, 80, 80);  //Рисуем сферу

}
//марс
void Venera()
{
	glColor3f(0.3f, 0.15f, 0.0f);
	glTranslatef(-450, 50, 300); //Сместили
	glutSolidSphere(17, 80, 80);  //Рисуем сферу

}
//
void Mars()
{
	glColor3f(0.3f, 0.0f, 0.0f);
	glTranslatef(-450, 0, 400); //Сместили
	glutSolidSphere(19, 80, 80);  //Рисуем сферу

}
#endif __FUNCS_H__