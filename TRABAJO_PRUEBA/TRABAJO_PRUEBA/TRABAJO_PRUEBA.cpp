 #include<Windows.h>
#include <cmath>
#include “freeglut.h”


void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);

struct camara
{
	float z = 20.0;
	float x = 0.0;
	float y = 0.0;
};

struct mov {
	float x = 0;
	float z = 0;

};

mov movrey = { 0,0 };
mov movpeon = { 0.0,0 };
mov movcaballo = { 0.0,0.0 };
mov movtablero = { 0.0,0.0 };

camara esfera = { 20,0,0 };

void tablero(mov r)
{
	bool color = false; // lo utilizamos para cambiar el color
	float size = 2.0f; // tamaño de los cuadrados

	for (int i = -8; i < 8; i += 2) {  // bucle filas (4 filas)
		for (int j = -8; j < 8; j += 2) {  // bucle columnas (4 columnas)
			glBegin(GL_POLYGON);
			if (color) {
				glColor3ub(50, 100, 100);  // color oscuro
			}
			else {
				glColor3ub(200, 200, 200);  // color claro
			}
			glVertex3f(i, 0.0f, j);  // esquina inferior izquierda
			glVertex3f(i + size, 0.0f, j);  // esquina inferior derecha
			glVertex3f(i + size, 0.0f, j + size);  // esquina superior derecha
			glVertex3f(i, 0.0f, j + size);  // esquina superior izquierda
			glEnd();

			color = !color;  // invertimos valor de color para que se produzca el cambio de color
		}
		color = !color; // cambia color cuando empieza una nueva fila
	}
}

//PEONES BLANCOS
//CREAR CLASE DE CADA COLOR Y FIGURA

void peon2A(mov r)
{
	int i = 0;
	glTranslatef(r.x, 0.0, r.z);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(-7.0, 2.1, 5.3); // Mueve el dibujo a la posición deseada

	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon2B(mov r)
{
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(-5.0, 2.1, 5.3); // Mueve el dibujo a la posición deseada

	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon2C(mov r)
{
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(-3.0, 2.1, 5.3); // Mueve el dibujo a la posición deseada

	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon2D(mov r)
{
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(-1.0, 2.1, 5.3); // Mueve el dibujo a la posición deseada

	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon2E(mov r)
{
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(1.0, 2.1, 5.3); // Mueve el dibujo a la posición deseada

	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon2F(mov r){
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(3.0, 2.1, 5.3); // Mueve el dibujo a la posición deseada

	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon2G(mov r) {
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(5.0, 2.1, 5.3); // Mueve el dibujo a la posición deseada

	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon2H(mov r) {
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(7.0, 2.1, 5.3); // Mueve el dibujo a la posición deseada

	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void torre1A(mov r)
{
	int i = 0;
	glTranslatef(r.x, 0.0, r.z);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(-7.1, 1.91, 7.2); // Mueve el dibujo a la posición deseada


	//CABEZA

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.6, 00.5, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0,-0.1,0.0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//cubo drch
	glTranslatef(0.6, 0.3, 0);
	glutSolidCube(0.25);
	//cubo izq
	glTranslatef(-1.25, 0.0, 0);
	glutSolidCube(0.25);
	//cubo abajo
	glTranslatef(0.6, 0.0, 0.67);
	glutSolidCube(0.25);
	//cubo arriba
	glTranslatef(0.0, 0.0, -1.32);
	glutSolidCube(0.25);
	glTranslatef(0.1, -0.50, 0.67);
	


	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.45, 20, 20);
	}


	//PIE

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.65, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.1, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.55, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.75, 0.3, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.05, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.75, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x



	glPopMatrix(); // Restaura la matriz de transformación origina

}
void torre1H(mov r)
{
	int i = 0;
	glTranslatef(r.x, 0.0, r.z);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(7.1, 1.91, 7.2); // Mueve el dibujo a la posición deseada


	//CABEZA

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.6, 00.5, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//cubo drch
	glTranslatef(0.6, 0.3, 0);
	glutSolidCube(0.25);
	//cubo izq
	glTranslatef(-1.25, 0.0, 0);
	glutSolidCube(0.25);
	//cubo abajo
	glTranslatef(0.6, 0.0, 0.67);
	glutSolidCube(0.25);
	//cubo arriba
	glTranslatef(0.0, 0.0, -1.32);
	glutSolidCube(0.25);
	glTranslatef(0.1, -0.50, 0.67);



	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.45, 20, 20);
	}


	//PIE

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.65, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.1, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.55, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.75, 0.3, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.05, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.75, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x



	glPopMatrix(); // Restaura la matriz de transformación origina

}
void rey1E(mov r)
{
	int i = 0;
	//cruz
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(1.0, 3.5, 7.2); // Mueve el dibujo a la posición deseada

	glutSolidCube(0.2);
	glTranslatef(0, -0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(0, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(0.2, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.4, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.2, -0.2, 0);


	//cabeza

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.6, 1, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.6, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.4, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.5, 0.6, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 15; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}

	//Pies

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.4, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.75, 0.6, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.05, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.75, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void alfil1C(mov r)
{
	int i = 0;
	//Cabeza

	glTranslatef(r.x, 0.0, r.z);


	glTranslatef(0.0, 0.0, 0.0);

	glPushMatrix(); // Guarda la tranformacion 
	glTranslatef(-2.9, 2.45, 7.2);
	glutSolidSphere(0.2, 20, 20);
	glTranslatef(0, -0.38 ,0);


	
	glScalef(0.5f, 0.5f, 0.5f); // Escala de 0.5 en x, y, y z

	// Dibujando la figura
	glutSolidOctahedron();

	glScalef(2.0f, 2.0f, 2.0f); // Escala de 0.5 en x, y, y z
	glTranslatef(0, -0.3, 0);

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
/*
	glTranslatef(0, -0.1, 0);

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	*/

	glTranslatef(0, -0.1, 0);

	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}

	
	//PIES
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x*/


	/*glTranslatef(0, -0.6, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.4, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.5, 0.9, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}
	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x*/


	glPopMatrix();
}
void alfil1F(mov r)
{
	int i = 0;
	//Cabeza

	glTranslatef(r.x, 0.0, r.z);


	glTranslatef(0.0, 0.0, 0.0);

	glPushMatrix(); // Guarda la transformacion
	glTranslatef(3.1, 2.45, 7.2);
	glutSolidSphere(0.2, 20, 20);
	glTranslatef(0, -0.38, 0);



	glScalef(0.5f, 0.5f, 0.5f); // Escala de 0.5 en x, y, y z

	// Dibujando la figura
	glutSolidOctahedron();

	glScalef(2.0f, 2.0f, 2.0f); // Escala de 0.5 en x, y, y z
	glTranslatef(0, -0.3, 0);

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	/*
		glTranslatef(0, -0.1, 0);

		glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
		glutSolidTorus(0.1, 0.4, 20, 20);
		glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
		*/

	glTranslatef(0, -0.1, 0);

	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//PIES
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x*/


	/*glTranslatef(0, -0.6, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.4, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.5, 0.9, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}
	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x*/


	glPopMatrix();
}
void caballo1B(mov r)
{
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(-5.5, 1.55, 7.2); // Mueve el dibujo a la posición deseada

	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0.20, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.20, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.20, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	//
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	//base
	glTranslatef(-0.2, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.2, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.2, 0.0, 0);

	glutSolidCube(0.2);
	glTranslatef(-0.2, 0.0, 0);
	glutSolidCube(0.2);

	//cuello
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);

	//
	glTranslatef(-0.05, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, 0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, 0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, 0, 0);
	glutSolidCube(0.2);


	glTranslatef(0.5, -0.9, 0);


	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.65, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.1, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.55, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.75, 0.3, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.05, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.75, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void caballo1G(mov r)
{
	glTranslatef(0.0, 0.0, 0.0);


	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(4.5, 1.55, 7.2); // Mueve el dibujo a la posición deseada

	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0.20, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.20, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.20, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	//
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	//base
	glTranslatef(-0.2, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.2, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.2, 0.0, 0);

	glutSolidCube(0.2);
	glTranslatef(-0.2, 0.0, 0);
	glutSolidCube(0.2);

	//cuello
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);

	//
	glTranslatef(-0.05, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, 0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, 0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, 0, 0);
	glutSolidCube(0.2);


	glTranslatef(0.5, -0.9, 0);


	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.65, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.1, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.55, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.75, 0.3, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.05, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.75, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}

void reina1D(mov r)
{
	int i = 0;

	glTranslatef(r.x, 0.0, r.z);

	glPushMatrix();
	
	glTranslatef(-1.0, 3.5, 7.5); // Mueve el dibujo a la posición deseada

	// Poner una corona sobre la cabeza de la reina
	glTranslatef(0, -0.3, 0); // Posicionar sobre la cabeza

	// Dibujar la corona
	glutSolidTorus(0.1, 0.3, 20, 0); // Parte inferior de la corona // el primer digito es el tamaño de la base de la corona
	glTranslatef(0.0f, 0.0f, 0.0f); // Ajustar posición (que esten todos los circulos concentricos)
	glutSolidTorus(0.1, 0.15, 20, 20); // Parte superior de la corona

	// Parte superior de la corona
	glutSolidCone(0.15, 0.1, 20, 20); // Picos de la corona
	glTranslatef(0.0f, 0.0f, 0.15f); // Ajustar posición
	glutSolidCone(0.1, 0.1, 20, 20); // Picos de la corona
	glTranslatef(0.0f, 0.0f, -0.3f); // Ajustar posición
	glutSolidCone(0.1, 0.1, 20, 20); // Picos de la corona
	// Cabeza
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.6, 1, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Deshacer la rotación alrededor del eje x
	glTranslatef(0, -0.6, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Deshacer la rotación alrededor del eje x
	glTranslatef(0, -0.4, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.5, 0.6, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Deshacer la rotación alrededor del eje x

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Deshacer la rotación alrededor del eje x

	//Cuerpo
	for (i = 0; i < 15; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}

	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	glPopMatrix(); // Restaura la matriz de transformación origina
}



//PEONES NEGROS
void peon7H(mov r) {
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(7.0, 2.1, -5.0); // Mueve el dibujo a la posición deseada


	glColor3ub(50, 100, 100);
	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon7G(mov r) {
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(5.0, 2.1, -5.0); // Mueve el dibujo a la posición deseada


	glColor3ub(50, 100, 100);
	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon7F(mov r) {
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(3.0, 2.1, -5.0); // Mueve el dibujo a la posición deseada


	glColor3ub(50, 100, 100);
	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon7E(mov r) {
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(1.0, 2.1, -5.0); // Mueve el dibujo a la posición deseada


	glColor3ub(50, 100, 100);
	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon7D(mov r) {
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(-1.0, 2.1, -5.0); // Mueve el dibujo a la posición deseada


	glColor3ub(50, 100, 100);
	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon7C(mov r) {
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(-3.0, 2.1, -5.0); // Mueve el dibujo a la posición deseada


	glColor3ub(50, 100, 100);
	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon7B(mov r) {
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(-5.0, 2.1, -5.0); // Mueve el dibujo a la posición deseada


	glColor3ub(50, 100, 100);
	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void peon7A(mov r) {
	int i = 0;
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(-7.0, 2.1, -5.0); // Mueve el dibujo a la posición deseada


	glColor3ub(50, 100, 100);
	//cabeza
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.35, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}

void torre8A(mov r)
{
	int i = 0;
	glTranslatef(r.x, 0.0, r.z);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(-7.1, -2.1, -6.8); // Mueve el dibujo a la posición deseada


	//CABEZA

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.6, 00.5, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//cubo drch
	glTranslatef(0.6, 0.3, 0);
	glutSolidCube(0.25);
	//cubo izq
	glTranslatef(-1.25, 0.0, 0);
	glutSolidCube(0.25);
	//cubo abajo
	glTranslatef(0.6, 0.0, 0.67);
	glutSolidCube(0.25);
	//cubo arriba
	glTranslatef(0.0, 0.0, -1.32);
	glutSolidCube(0.25);
	glTranslatef(0.1, -0.50, 0.67);



	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.45, 20, 20);
	}


	//PIE

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.65, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.1, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.55, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.75, 0.3, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.05, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.75, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x



	glPopMatrix(); // Restaura la matriz de transformación origina

}
void torre8H(mov r)
{
	int i = 0;
	glTranslatef(r.x, 0.0, r.z);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(7.1, -2.1, -6.8); // Mueve el dibujo a la posición deseada


	//CABEZA

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.6, 00.5, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//cubo drch
	glTranslatef(0.6, 0.3, 0);
	glutSolidCube(0.25);
	//cubo izq
	glTranslatef(-1.25, 0.0, 0);
	glutSolidCube(0.25);
	//cubo abajo
	glTranslatef(0.6, 0.0, 0.67);
	glutSolidCube(0.25);
	//cubo arriba
	glTranslatef(0.0, 0.0, -1.32);
	glutSolidCube(0.25);
	glTranslatef(0.1, -0.50, 0.67);



	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.45, 20, 20);
	}


	//PIE

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.65, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.1, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.55, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.75, 0.3, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.05, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.75, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x



	glPopMatrix(); // Restaura la matriz de transformación origina

}


void alfil8C(mov r)
{
	int i = 0;
	//Cabeza

	glTranslatef(r.x, 2.0, r.z);


	glTranslatef(0.0, 0.0, 0.0);

	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(-2.9, 0.43,-6.8);
	glutSolidSphere(0.2, 20, 20);
	glTranslatef(0, -0.38, 0);



	glScalef(0.5f, 0.5f, 0.5f); // Escala de 0.5 en x, y, y z

	// Dibujando la figura
	glutSolidOctahedron();

	glScalef(2.0f, 2.0f, 2.0f); // Escala de 0.5 en x, y, y z
	glTranslatef(0, -0.3, 0);

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	/*
		glTranslatef(0, -0.1, 0);

		glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
		glutSolidTorus(0.1, 0.4, 20, 20);
		glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
		*/

	glTranslatef(0, -0.1, 0);

	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//PIES
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x*/


	


	glPopMatrix();
}
void alfil8F(mov r)
{
	int i = 0;
	//Cabeza

	glTranslatef(r.x, 2.0, r.z);


	glTranslatef(0.0, 0.0, 0.0);

	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(3.1, -1.58, -6.8);
	glutSolidSphere(0.2, 20, 20);
	glTranslatef(0, -0.38, 0);



	glScalef(0.5f, 0.5f, 0.5f); // Escala de 0.5 en x, y, y z

	// Dibujando la figura
	glutSolidOctahedron();

	glScalef(2.0f, 2.0f, 2.0f); // Escala de 0.5 en x, y, y z
	glTranslatef(0, -0.3, 0);

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	/*
		glTranslatef(0, -0.1, 0);

		glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
		glutSolidTorus(0.1, 0.4, 20, 20);
		glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
		*/

	glTranslatef(0, -0.1, 0);

	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}


	//PIES
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x*/


	/*glTranslatef(0, -0.6, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.4, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.5, 0.9, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	//Cuerpo
	for (i = 0; i < 10; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}
	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x*/


	glPopMatrix();
}

void caballo8B(mov r)
{
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la matriz de transformación actual
	glTranslatef(-5.5, -2.5, -6.8); // Mueve el dibujo a la posición deseada

	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0.20, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.20, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.20, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	//
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	//base
	glTranslatef(-0.2, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.2, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.2, 0.0, 0);

	glutSolidCube(0.2);
	glTranslatef(-0.2, 0.0, 0);
	glutSolidCube(0.2);

	//cuello
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);

	//
	glTranslatef(-0.05, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, 0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, 0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, 0, 0);
	glutSolidCube(0.2);


	glTranslatef(0.5, -0.9, 0);


	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.65, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.1, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.55, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.75, 0.3, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.05, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.75, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}
void caballo8G(mov r)
{
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda transformación actual
	glTranslatef(4.5, -2.5, -6.8); // Mueve el dibujo a la posición deseada

	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0.20, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.20, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.20, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	glTranslatef(0.08, -00.10, 0);
	glutSolidCube(0.2);
	//
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, -00.15, 0);
	glutSolidCube(0.2);
	//base
	glTranslatef(-0.2, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.2, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.2, 0.0, 0);

	glutSolidCube(0.2);
	glTranslatef(-0.2, 0.0, 0);
	glutSolidCube(0.2);

	//cuello
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(0.1, 0.15, 0);
	glutSolidCube(0.2);

	//
	glTranslatef(-0.05, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.05, 0.15, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, 0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, 0, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.1, 0, 0);
	glutSolidCube(0.2);


	glTranslatef(0.5, -0.9, 0);


	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.65, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.1, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.65, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.55, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0.0, -0.15, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.75, 0.3, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.05, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.75, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}

void rey8E(mov r)
{
	int i = 0;
	//cruz
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); // Guarda la transformación actual
	glTranslatef(1.0, -0.5, -6.8); // Mueve el dibujo a la posición deseada

	glutSolidCube(0.2);
	glTranslatef(0, -0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(0, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(0, -0.1, 0);
	glutSolidCube(0.2);
	glTranslatef(0.2, 0.2, 0);
	glutSolidCube(0.2);
	glTranslatef(-0.4, 0.0, 0);
	glutSolidCube(0.2);
	glTranslatef(0.2, -0.2, 0);


	//cabeza

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.6, 1, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.6, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.4, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.5, 0.6, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	//Cuerpo
	for (i = 0; i < 15; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}

	//Pies

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.4, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.75, 0.6, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.05, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.75, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x


	glPopMatrix(); // Restaura la matriz de transformación origina
}

void reina8D(mov r)
{
	int i = 0;

	glTranslatef(r.x, 2.7, r.z);


	glPushMatrix();
	
	glTranslatef(-1.0, -3.2, -6); // Mueve el dibujo a la posición deseada



	// Poner una corona sobre la cabeza de la reina

	glTranslatef(0, -0.3, 0); // Posicionar sobre la cabeza

	// Dibujar la corona
	glutSolidTorus(0.1, 0.3, 20, 0); // Parte inferior de la corona // el primer digito es el tamaño de la base de la corona
	glTranslatef(0.0f, 0.0f, 0.0f); // Ajustar posición (que esten todos los circulos concentricos)
	glutSolidTorus(0.1, 0.15, 20, 20); // Parte superior de la corona

	// Parte superior de la corona
	glutSolidCone(0.15, 0.1, 20, 20); // Picos de la corona
	glTranslatef(0.0f, 0.0f, 0.15f); // Ajustar posición
	glutSolidCone(0.1, 0.1, 20, 20); // Picos de la corona
	glTranslatef(0.0f, 0.0f, -0.3f); // Ajustar posición
	glutSolidCone(0.1, 0.1, 20, 20); // Picos de la corona
	// Cabeza
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.6, 1, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Deshacer la rotación alrededor del eje x
	glTranslatef(0, -0.6, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.3, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Deshacer la rotación alrededor del eje x
	glTranslatef(0, -0.4, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.5, 0.6, 20, 20);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Deshacer la rotación alrededor del eje x

	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.1, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Deshacer la rotación alrededor del eje x

	//Cuerpo
	for (i = 0; i < 15; i++)
	{
		glTranslatef(0, -0.1, 0);
		glutSolidSphere(0.3, 20, 20);
	}

	//Pie
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.15, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.4, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.2, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidTorus(0.15, 0.6, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x

	glPopMatrix();
	
}


void Mueve(camara e)
{
	gluLookAt(e.x, e.y, e.z, // posicion del ojo
		0.0, 0, 0.0, // hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
}




int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas FREEGLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");
	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//25 ms
	glutKeyboardFunc(OnKeyboardDown);
	//pasarle el control a FREEGLUT,que llamara a los callbacks
	glutMainLoop();
	return 0;
}

void OnDraw(void)
{
	int i = 0;
	//Borrado de la pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Mueve(esfera);




	tablero(movtablero);
	

	//PIEZAS BLANCAS
	rey1E(movrey);
	peon2A(movpeon);
	peon2B(movpeon);
	peon2C(movpeon);
	peon2D(movpeon);
	peon2E(movpeon);
	peon2F(movpeon);
	peon2G(movpeon);
	peon2H(movpeon);
	caballo1B(movcaballo); 
	caballo1G(movcaballo);
	torre1A(movpeon);
	torre1H(movpeon);
	alfil1C(movpeon);
	alfil1F(movpeon);
	reina1D(movpeon);
	
	//PIEZAS NEGRAS
	peon7A(movpeon);
	peon7B(movpeon);
	peon7C(movpeon);
	peon7D(movpeon);
	peon7E(movpeon);
	peon7F(movpeon);
	peon7G(movpeon);
	peon7H(movpeon);
	alfil8C(movpeon);
	alfil8F(movpeon);
	caballo8B(movcaballo);
	caballo8G(movcaballo);
	torre8A(movpeon);
	torre8H(movpeon);
	rey8E(movrey);
	reina8D(movpeon);


	


	

	//Al final, cambiar el buffer (redibujar)
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}


void OnTimer(int value)
{
	
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{

	if (key == 'x')
		esfera.x += 0.5f;
	if (key == 'y')
		esfera.y += 0.5f;
	if (key == 'z')
		esfera.z += 0.5f;
	if (key == 's')
		esfera.x -= 0.5f;
	if (key == 'i')
		esfera.y -= 0.5f;
	if (key == 'c')
		esfera.z -= 0.5f;


	glutPostRedisplay();


}
