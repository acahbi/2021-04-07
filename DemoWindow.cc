/*
 * DemoWindow.cc
 *
 *  Created on: 7 апр. 2021 г.
 *      Author: unyuu
 */

#include "DemoWindow.h"

DemoWindow::DemoWindow(int width, int height)
: Window(width, height)
{
	set_title("OpenGL Demo Window");
}

void DemoWindow::setup_gl()
{
	glClearColor(0.2f, 0.4f, 0.7f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(
			45.0,								// Угол обзора по вертикали
			double(width()) / double(height()),	// Соотношение сторон
			0.1,								// Расстояние до ближней ПО
			20.0);								// Расстояние до дальней ПО
	glMatrixMode(GL_MODELVIEW);
}


void cube(double cl1,
		  double cl2,
		  double cl3,

		  double d1,
		  double d2,
		  double d3,
		  double d4,
		  double d5,
		  double d6,
		  double d7,
		  double d8,
		  double d9,
		  double d10,
		  double d11,
		  double d12
		  ){
	glColor3d(cl1, cl2, cl3);
	glVertex3d(d1,  d2, d3);
	glVertex3d( d4,  d5, d6);
	glVertex3d( d7, d8, d9);
	glVertex3d(d10, d11, d12);
}

void cube_all(){
	glBegin(GL_QUADS);
		cube( 1.0, 0.0,  0.0,  // Нижняя грань, красная
			 -1.0, 1.0, -1.0,
			  1.0, 1.0, -1.0,
			  1.0,-1.0, -1.0,
			 -1.0,-1.0, -1.0
			 );
		cube( 0.0, 1.0, 1.0,  // Верхняя грань, бирюзовая
			 -1.0,-1.0, 1.0,
			  1.0,-1.0, 1.0,
			  1.0, 1.0, 1.0,
			 -1.0, 1.0, 1.0
			 );
		cube( 0.0, 1.0,  0.0,  // Боковая грань, зеленая
			 -1.0, 1.0, -1.0,
			  1.0, 1.0, -1.0,
			  1.0, 1.0,  1.0,
			 -1.0, 1.0,  1.0
			 );
		cube( 0.0, 0.0,  1.0,  // Боковая грань, синяя
			  1.0,-1.0,  1.0,
			  1.0, 1.0,  1.0,
			  1.0, 1.0, -1.0,
			  1.0,-1.0, -1.0
			 );
		cube( 0.5, 0.5,  0.5,  // Боковая грань, серый
			 -1.0,-1.0, -1.0,
			  1.0,-1.0, -1.0,
			  1.0,-1.0,  1.0,
			 -1.0,-1.0,  1.0
			 );
		cube( 0.3, 1.0,  0.8,  // Боковая грань, светло-зеленый
			 -1.0,-1.0, -1.0,
			 -1.0, 1.0, -1.0,
			 -1.0, 1.0,  1.0,
			 -1.0,-1.0,  1.0
			 );
	glEnd();
}


void DemoWindow::render()
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очистка

	glLoadIdentity(); // MV = единичная матрица

	gluLookAt(	15.0, 4.0, 5.0,		// Координаты камеры
				0.0,  0.0, 0.0,		// Координаты центра
				0.0,  0.0, 1.0);	// Направление вверх,	MV = C

	glRotated(_cube_angle, 0.0, 0.0, 1.0);
	//glScalef( 1.0, 1.0, 2.0 );

	glPushMatrix();  //  Запомнить начальные координаты
		cube_all();

		glTranslated(4.0, 0.0, 0.0);
		cube_all();

		glTranslated(-8.0, 0.0, 0.0);
		cube_all();
	glPopMatrix();  //  Получить начальные координаты

	glPushMatrix();
		glTranslated(2.0, 0.0, 2.0);
		cube_all();

		glTranslated(-4.0, 0.0, 0.0);
		cube_all();
		glPopMatrix();


	glPushMatrix();
		glTranslated(0.0, 0.0, 4.0);
		cube_all();
	glPopMatrix();
	/* TODO: задание для самостоятельной работы
	 * - Добавить оставшиеся грани куба
	 * - Выяснить, почему куб в текущем виде отображается неправильно
	 * - Исправить программу, чтобы куб начал правильно отображаться
	 * - Разобраться с основными преобразованиями:
	 * 		~ параллельный перенос;
	 * 		~ поворот;
	 * 		~ масштабирование.
	 * - Разобраться с функциями glPushMatrix() и glPopMatrix()
	 * - Построить из кубиков пирамидку:
	 *          +-+
	 *          |X|
	 *        +-+ +-+
	 *        |X| |X|
	 *      +-+ +-+ +-+
	 *      |X| |X| |X|
	 *      +-+ +-+ +-+
	 */
}

void DemoWindow::update()
{
	_cube_angle += 0.1;
	if (_cube_angle >= 360.0)
		_cube_angle -= 360.0;
}
