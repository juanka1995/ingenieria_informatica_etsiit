/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "objeto3d.h"

class Escena {
private:
	// tamaño de los ejes
	#define AXIS_SIZE 5000
	Ejes ejes;

	// Vector de objetos
	std::vector<Object3D> objetos;

	// Modo de pintar
	bool pintaAlambre, pintaPuntos, pintaSolido, pintaAjedrez;

	// Activar pintar (0-->Tetraedro, 1-->Cubo, 2-->Piramide, -1-->No pintar)
	int objetoActivo;

	// variables que definen la posicion de la camara en coordenadas polares
	GLfloat Observer_distance;
	GLfloat Observer_angle_x;
	GLfloat Observer_angle_y;

	// variables que controlan la ventana y la transformacion de perspectiva
	GLfloat Width,Height,Front_plane,Back_plane;

	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformación de cámara
	void change_projection();
	void change_observer();

public:
  Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar();

	// Asignar el modo de pintar
	void setPintaAlambre();
	void setPintaPuntos();
	void setPintaSolido();
	void setPintaAjedrez();
	void setObjetoActivo(int numObjeto);

	// Dejar de dibujarPuntos
	void setNoPintar();

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
};
#endif
