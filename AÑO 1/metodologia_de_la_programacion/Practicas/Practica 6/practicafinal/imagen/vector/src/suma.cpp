#include <iostream>
#include <string>
#include "string.h"
#include<cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;

const int MAXLONG = 1000000;

int main(int argc, char *argv[]){
  if(argc==5){
    bool esBinario;
    char nombreSalida[MAXLONG];
    char ficheroImagen[MAXLONG];
    char ficheroImagen2[MAXLONG];
    Imagen img1,img2,img3;

    strcpy(ficheroImagen,argv[1]);
    strcpy(ficheroImagen2,argv[2]);
    strcpy(nombreSalida,argv[3]);

    if(strcmp(argv[4],"t")==0 || strcmp(argv[4],"b")==0){
      if(strcmp(argv[4],"t")==0)
        esBinario=false;
      else if(strcmp(argv[4],"b")==0)
        esBinario=true;

      // Leemos la primera imagen desde fichero
      if (!img1.leerImagen(ficheroImagen)){
  		cerr << "Error leyendo imagen " << ficheroImagen << endl;
  		return 1;
  		}

      // Leeemos la segunda imagen desde fichero
      if (!img2.leerImagen(ficheroImagen2)){
    	   cout << "Error leyendo imagen " << ficheroImagen << endl;
  		     return 1;
  		}

      img3=img1+img2;

      // Guardar la suma de las imagenes con el nombre se salida deseado
    	if (img3.escribirImagen(nombreSalida, esBinario)){
    		// si todo va bien
    		cout << nombreSalida << " guardado correctamente \n";
    		cout << "usa: display " << nombreSalida <<" para ver el resultado\n";
    	} else { // si error
    		cout << "Error guardando la imagen " << nombreSalida << endl;
    		return 1;
    	}
    }else
      cout << "Eliga bien el tipo de conversion t(texto) o b(binario)" << endl;
  }else
    cout << "Error en el numero de parametros" << endl;
}
