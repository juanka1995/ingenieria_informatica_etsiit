/**
 * lee cualquier imagen indicada por el usuario y un fichero con cadenas
 * de caracteres y crea ficheros de imagen transformadas, una por cadena
*/
#include<iostream>
#include<cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;

const int MAXLONG = 1000000;

int main(int argc, char *argv[]){
	if(argc==3){
		char ficheroGrises[MAXLONG];
    char ficheroImagen[MAXLONG];
		//Copiamos el los parametros obtenidos de la linea de ordenes
		//en sus vectores de char correspondientes.
		strcpy(ficheroGrises,argv[2]);
		strcpy(ficheroImagen,argv[1]);
		Imagen origen;
    Lista celdas;

    // Leer la imagen desde fichero
    if (!origen.leerImagen(ficheroImagen)){
		cerr << "Error leyendo imagen " << ficheroImagen << endl;
		return 1;
		}

		// Leer cadenas desde fichero
		if (celdas.leerLista(ficheroGrises)){
			// realizar las conversiones
			if (origen.listaAArteASCII(celdas)){
				cout << "Exito en la conversion." << endl;
				cout << "Chequee los ficheros asciiX.txt" << endl;
			}else{
				cerr << "La conversion no ha sido posible" << endl;
			}
		}else{
			cerr << "Error lista de grises " << ficheroGrises << endl;
		}
	}
	else{
		cerr << "Error en el numero de parametros" << endl;
	}
}
