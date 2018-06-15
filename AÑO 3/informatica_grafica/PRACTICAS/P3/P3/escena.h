/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "objeto3d.h"
#include <string>
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"
#include "cubo.h"
#include "tetraedro.h"
#include "rombo.h"
#include "piramide.h"
#include "objetoPLY.h"
#include "objetoPerfilRevolucion.h"
#include "objetoPerfilBarrido.h"
#include "modeloJerarquico/bartSimpson.h"

class Escena {
private:
	// tamaño de los ejes
	#define AXIS_SIZE 5000
	Ejes ejes;

	// Vector de objetos
	std::vector<Object3D*> objetos;

	// Objetos 3D
	Tetraedro miTetraedro;
	Cubo miCubo;
	Rombo miRombo;
	Piramide miPiramide;
	ObjetoPerfilRevolucion miObjetoPerfilRevolucion, miObjetoPerfilRevolucionPLY;
	ObjetoPLY miObjetoPLY;
	ObjetoPerfilBarrido miObjetoPerfilBarrido, miObjetoPerfilBarridoPLY;

	// Modelo jerarquico
	BartSimpson miBartSimpson;

	// Activar animacion
	bool animacionActiva;

	// Modo de pintar
	bool pintaAlambre, pintaPuntos, pintaSolido, pintaAjedrez;
	
	// Objeto ply bien cargado o no
	bool objetoPlyBienCargado;

	// Perfil ply bien cargado o no
	bool perfilPlyRevolucionBienCargado;

	// Perfil ply bien cargado o no
	bool perfilPlyBarridoBienCargado;

	// Activar pintar (0-->Tetraedro, 1-->Tetraedro, 2-->Cubo, 3-->Rombo,
	// 4-->Piramide, 5--> ObjetoPLY, 1-->No pintar)
	int objetoActivo;

	// 0-->Cabeza, 1-->BrazoDerecho, 2-->Tronco, 3-->BrazoIzquierdo, 4-->PiernaDerecha, 5-->PiernaIzquierda
	int parteBartAMover;

	// El primero sera el grado de mas arriba y el ultimo el de mas abajo
	// 0-->Primer grado de libertad selec, 1-->Segundo grado de libertad selec, 3-->Tercer grado de libertad selec
	int gradoLibertadSeleccionado;

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
	//Constructor para figuras introducidas a mano
	Escena();
	//Constructor para CARGAR figuras introducidas por fichero .ply
	Escena(const std::string &ply_file);
	//Constructor para REVOLUCIONAR perfil pasado por fichero .ply
	Escena(const std::string &ply_file, const int &nSegmentos, string eje);
	//Constructor para BARRER perfil pasado por fichero .ply
	Escena(const std::string &ply_file, const int &nSegmentos, const float &longitud);
	  
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight);

	// Dibujar
	void dibujar();

	// Asignar el modo de pintar
	void setPintaAlambre();
	void setPintaPuntos();
	void setPintaSolido();
	void setPintaAjedrez();
	void setObjetoActivo(int numObjeto);

	// Deja de dibujar figuras
	void setNoPintar();

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);

	// Mostras instruccione de uso
	void mostrarInstruccionesUso();

	// Controla las acciones a realizar sobre Bart dependiendo de las teclas pulsadas
	void controlDeTeclasBart(unsigned char Tecla);

	// Funcion encargada de animar a bart
	void animarBart();

	// Devuelve si la activacion esta activa o no
	bool getAnimacionActiva();
};
#endif
