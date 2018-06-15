/*
Juan Carlos Ruiz Garcia - Grupo C1
*/
//**************************************************************************
// Práctica 4
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
#include <string>

#include <iostream>

Escena *escena;

void Mover(){
	if(escena->getAnimacionActiva()){
		escena->animarBart();
		glutPostRedisplay();
	}
}


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
		case 9: // Piramide
			escena->setObjetoActivo(3);
		break;
		case 10: // Objeto PLY (Ply normal, revolucion o barrido)
			escena->setObjetoActivo(6);
		break;
		case 11: // Objeto PerfilRevolucion estatico
			escena->setObjetoActivo(4);
		break;
		case 12: // Objeto PerfilBarrido estático
			escena->setObjetoActivo(5);
		break;
		case 13: // Modelo jerarquico
			escena->setObjetoActivo(7);
		break;
		case 14: // Escena P4
			escena->setObjetoActivo(8);
		break;
		case 15: // No pintar
			escena->setObjetoActivo(-1);
		break;
		case 16: // Textura
			escena->setObjetoActivo(9);
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
//***

void mostrarInstruccionesEjecucion(){
	system("clear");
	cout << endl << "#############  INSTRUCCIONES DE EJECUCION ################" << endl << endl;

	cout << "Opciones: " << endl;
	cout << "./practica3" << endl;
	cout << "./practica3 -c [ruta_fichero_ply]" << endl;
	cout << "./practica3 -r [ruta_perfil_ply_revolucion] -n [numero_segmentos] -e [eje_revolucion]" << endl;
	cout << "./practica3 -b [ruta_perfil_ply_barrido] -n [número_segmentos] -l [longitud_barrido]" << endl;

	cout << endl << "-c : cargar" << endl;
	cout << "-r : revolucionar" << endl;
	cout << "-b : barrer" << endl;
	cout << "-n : numero de segmentos (int)" << endl;
	cout << "-e : eje de revolucion (X, Y, Z) en MAYUSCULA" << endl;
	cout << "-l longitud del barrido (float)" << endl;

	cout << endl << "####################################################" << endl << endl;
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv) {

	if(argc == 2 && (argv[1] == std::string("-h") || argv[1] == std::string("--help")))
		mostrarInstruccionesEjecucion();
	else{
		if(argc == 7){
			if(argv[1] == std::string("-b") && argv[3] == std::string("-n") && argv[5] == std::string("-l")){
				// Llama al constructor de escena para barrido
				escena = new Escena(argv[2], stoi(argv[4]), stof(argv[6]));
			}
			else if(argv[1] == std::string("-r") && argv[3] == std::string("-n") && argv[5] == std::string("-e") &&
					(argv[6] == std::string("X") || argv[6] == std::string("Y") || argv[6] == std::string("Z"))){
				// Llama al constructor de escena para revolucionar
				string eje = argv[6];
				escena = new Escena(argv[2], stoi(argv[4]), argv[6]);
			}
			else{
				cout << "Agumentos incorrectos (Eje SIEMPRE en MAYUSCULA)" << endl;
				return 1;
			}
		}
		else if(argc == 3){
			if(argv[1] == std::string("-c")){
				// Constructor para cargar un fichero PLY
				escena = new Escena(argv[2]);
			}
			else{
				cout << "Argumentos incorrectos" << endl;
				return 1;
			}
		}
		else
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
		glutCreateWindow("Practica 4: Juan Carlos Ruiz Garcia");
	
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
	
		glutIdleFunc(Mover);

		// inicio del bucle de eventos
		glutMainLoop();

		escena->liberarTextura();

		return 0;	
	}
}
