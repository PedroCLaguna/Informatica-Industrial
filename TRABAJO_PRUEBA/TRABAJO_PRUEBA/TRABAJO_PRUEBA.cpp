#include<Windows.h>
#include <cmath>
#include "freeglut.h"


void OnDraw(void);
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
mov movpeon = { 2,0 };
mov movcaballo = { 2.0,0.0 };
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

void peon(mov r)
{
	int i = 0;

	glTranslatef(-7, 1.9, 5);

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
}

void rey(mov r)
{
	int i = 0;

	//cruz
	glTranslatef(r.x, 3.2, r.z);
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
}

void caballo(mov r)
{
	glTranslatef(r.x, 1.4, r.z);

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
}
void alfil(mov r)
{
	int i = 0;
	//Cabeza
	glTranslatef(r.x, 2.5, r.z);
	glutSolidSphere(0.2, 20, 20);
	glTranslatef(0, -0.1, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glutSolidCone(0.6, 1, 20, 20);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
	glTranslatef(0, -0.6, 0);
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
	glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotar alrededor del eje x
}

void torre(mov r) {

	int i = 0;

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

	//Cuerpo
	for (i = 1; i < 6; i++)
	{
		glTranslatef(0, 0.3, 0);
		glutSolidSphere(0.6, 20, 20);
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
	//glTranslatef(0, -0.4, 0);
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
	rey(movrey);
	peon(movpeon);
	caballo(movcaballo);
	




	//Al final, cambiar el buffer (redibujar)
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
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
