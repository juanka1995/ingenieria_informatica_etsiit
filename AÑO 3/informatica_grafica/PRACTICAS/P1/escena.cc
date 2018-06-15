/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"
#include "cubo.h"
#include "tetraedro.h"
#include "rombo.h"
#include "piramide.h"


Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);

    // Creamos inicializo el objeto tetraedro, cubo y rombo
    Tetraedro miTetraedro(85.0, 65.0, Color(255.0,0.0,0.0));
    Cubo miCubo(40.0, Color(255.0,0.0,0.0));
    Rombo miRombo(100.0, 80.0, Color(255.0,0.0,0.0));
    Piramide miPiramide(90.0, 75.0, Color(255.0,0.0,0.0));
    objetos.push_back(miTetraedro);
    objetos.push_back(miCubo);
    objetos.push_back(miRombo);
    objetos.push_back(miPiramide);

    //Ponemos el modo de pintar en solido por defecto
    pintaAlambre = pintaPuntos = pintaAjedrez = false;
    pintaSolido = true;

    // No pintar nada por defecto
    objetoActivo = -1;
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {
  // Miramos el modo de dibujar activo y llamamos a la funcion determinada
  if(objetoActivo != -1){
    if(pintaAlambre)
      objetos[objetoActivo].dibujarAlambre();
    else if(pintaPuntos)
      objetos[objetoActivo].dibujarPuntos();
    else if(pintaSolido)
      objetos[objetoActivo].dibujarSolido();
    else
      objetos[objetoActivo].dibujarAjedrez();
  }
}


void Escena::dibujar() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {
  std::cout << "Tecla " << Tecla1<< std::endl;
	if (toupper(Tecla1)=='Q')
    return 1;
  else if(toupper(Tecla1)=='P') // Puntos
    return 2;
  else if(toupper(Tecla1)=='L') // Lineas/Aristas
    return 3;
  else if(toupper(Tecla1)=='F') // Relleno
    return 4;
  else if(toupper(Tecla1)=='C') // Ajedrez
    return 5;
  else if(toupper(Tecla1)=='1') // Activar tetraedro
    return 6;
  else if(toupper(Tecla1)=='2') // Activar cubo
    return 7;
  else if(toupper(Tecla1)=='3') // Activar rombo
    return 8;
  else if(toupper(Tecla1)=='4') // Activar piramide
    return 9;
  else if(toupper(Tecla1)=='0') // Activar modo no pintar
    return 10;
	else return 0;
}

void Escena::setPintaAjedrez(){
  if(objetoActivo != -1){
    pintaAlambre = pintaPuntos = pintaSolido = false;
    pintaAjedrez = true;
  }
}

void Escena::setPintaAlambre(){
  if(objetoActivo != -1){
    pintaAjedrez = pintaPuntos = pintaSolido = false;
    pintaAlambre = true;
  }
}

void Escena::setPintaPuntos(){
  if(objetoActivo != -1){
    pintaAlambre = pintaAjedrez = pintaSolido = false;
    pintaPuntos = true;
  }
}

void Escena::setPintaSolido(){
  if(objetoActivo != -1){
    pintaAlambre = pintaPuntos = pintaAjedrez = false;
    pintaSolido = true;
  }
}

void Escena::setObjetoActivo(int numObjeto){
  objetoActivo = numObjeto;
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformaci�n de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformaci�n de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}
