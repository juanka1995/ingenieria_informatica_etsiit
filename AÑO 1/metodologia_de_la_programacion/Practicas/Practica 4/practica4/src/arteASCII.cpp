#include<iostream>
#include<imagen.h>
#include<string.h> // strcat
#include<fstream>

using namespace std;

int main(){
  const int MAX_CARAC=128,MAX_ASCII=4501;
  char grises[MAX_CARAC],ruta[MAX_CARAC],cadena[MAX_CARAC],n_salida[MAX_CARAC],extension[MAX_CARAC]="0.txt";
  char arteASCII[MAX_ASCII]; // 4500 + el \0
  string nombre_s;
  int num_cadenas;

  Imagen origen;

  cout << "Introduce la ruta de la imagen: ";
  cin.getline(ruta,MAX_CARAC);

  cout << "Introduce la ruta del fichero de cadenas: ";
  cin.getline(grises,MAX_CARAC);

  cout << "Introduce el nombre del fichero de salida: ";
  cin.getline(n_salida,MAX_CARAC);

  if(origen.leerImagen(ruta)){
    ifstream fentrada(grises); //Creo y abro el fichero de entrada
    if(fentrada){
      fentrada.getline(cadena,MAX_CARAC); //Evitamos la primera linea del fichero grises.txt
      fentrada >> num_cadenas; //Guardo el numero de cadenas existentes en el fichero grises.txt
      ofstream fsalida; //Creo el fichero de salida
      strcat(n_salida,extension); //Concateno el nombre del fichero de salida con la extension
      for(int i=0;i<num_cadenas;i++){
        fentrada >> cadena;
        if(origen.aArteASCII(cadena,arteASCII,MAX_ASCII)){
          n_salida[strlen(n_salida)-5]='1'+i; //Cambio el numero del nombre del fichero de salida
          fsalida.open(n_salida);
          fsalida << arteASCII;
          fsalida.close();
          cout << n_salida << " creado correctamente." << endl;
        }
       else
          cout << "La conversion no ha sido posible\n";
      }
      fentrada.close();
    }
    else
      cout << "Ruta del fichero de cadenas incorrecta\n";
  }
  else
    cout << "Ruta de la imagen incorrecta.\n";

}
