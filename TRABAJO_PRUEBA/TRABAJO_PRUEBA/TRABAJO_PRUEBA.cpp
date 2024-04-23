// trabajo_ajedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
#include "freeglut.h"

struct Mundo {
	float x;
	float y;
	float z;
};
Mundo mundo = { 0.0f,0.0f,20.0f }; //coordenadas punto de vista del observador

void Tablero(void);


int main(int argc, char* argv[]) {

	//Inicializar el gestor de ventanas FREEGLUT
//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(Tablero);
	

	//pasarle el control a FREEGLUT,que llamara a los callbacks
	glutMainLoop();
	return 0;

}


void Tablero(void)
{
	//Borrado de la pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(mundo.x, mundo.y, mundo.z, //posicion del ojo
		0.0, 0, 0.0, //hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0); //definimos hacia arriba

	//dibujamos cuadricula en el tablero
	bool color = false; //lo utilizamos para cambiar el color

	for (int i = -4; i < 4; i++) {  //bucle filas (8 filas)
		for (int j = -4; j < 4; j++) {  //bucle columnas (8 columnas)
			glBegin(GL_POLYGON);
			if (color) {
				glColor3ub(50, 100, 100);  //color oscuro
			}
			else {
				glColor3ub(200, 200, 200);  //color claro
			}
			glVertex3f(i, j, 0.0f);
			glVertex3f(i + 1, j, 0.0f);
			glVertex3f(i + 1, j + 1, 0.0f);
			glVertex3f(i, j + 1, 0.0f);
			glEnd();

			color = !color;  //invertimos valor de color para que se produzca el cambio de color
		}
		color = !color; //xambia color cuando empieza una nueva fila
	}
	

	
//no borrar esta linea ni poner nada despues
	glutSwapBuffers();

}
