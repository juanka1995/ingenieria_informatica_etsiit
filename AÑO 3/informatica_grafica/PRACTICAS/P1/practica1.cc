/*
Juan Carlos Ruiz Garcia - Grupo C1
*/
//**************************************************************************
// Práctica 1
//
// F.J. melero
//
// GPL
//**************************************************************************
#ifdef _WIN32
#include <windows.h>
#endif
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "escena.h"

#include <iostream>

Escena *escena;


void draw_scene(void)  {
	if (escena!=NULL)	escena->dibujar();
	glutSwapBuffers();
}


//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int newWidth,int newHeight)  {
	if (escena!=NULL)	escena->redimensionar(newWidth,newHeight);
	glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)  {
	int accion=0;

	if (escena!=NULL)
		accion=escena->teclaPulsada(Tecla1,x,y);

	switch (accion) {
		case 1:	// Salir
			delete escena;
			exit(0);
		break;
		case 2:	// Puntos
			escena->setPintaPuntos();
		break;
		case 3:	// Lineas/Aristas
			escena->setPintaAlambre();
		break;
		case 4:	// Relleno
			escena->setPintaSolido();
		break;
		case 5:	// Ajedrez
			escena->setPintaAjedrez();
		break;
		case 6:	// Tetraedro
			escena->setObjetoActivo(0);
		break;
		case 7:	// Cubo
			escena->setObjetoActivo(1);
		break;
		case 8:	// Rombo
			escena->setObjetoActivo(2);
		break;
		case 9:
			escena->setObjetoActivo(3);
		break;
		case 10:	// No pintar
			escena->setObjetoActivo(-1);
		break;
	}

	glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y) {
	if (escena!=NULL)
		escena->teclaEspecial(Tecla1,x,y);
	glutPostRedisplay();
}



//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv) {

escena = new Escena();

// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=500,UI_window_height=500;

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);
// tamaño de la ventana (ancho y alto)
glutInitWindowSize(UI_window_width,UI_window_height);

// llamada para crear la ventana, indicando el titulo
glutCreateWindow("Practica 1: Juan Carlos Ruiz Garcia");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw_scene);
// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "tecla_normal" al evento correspondiente
glutKeyboardFunc(normal_keys);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_keys);

// funcion de inicialización
escena->inicializar(UI_window_width,UI_window_height);

// inicio del bucle de eventos
glutMainLoop();
return 0;
}
