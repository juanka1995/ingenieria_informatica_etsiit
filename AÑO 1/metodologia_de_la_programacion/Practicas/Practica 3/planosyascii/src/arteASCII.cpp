#include<iostream>
#include<imagen.h>
#include<string>

using namespace std;

int main(){
  const int MAX_CARAC=128,MAX_ASCII=4501;
  char grises[MAX_CARAC],ruta[MAX_CARAC];
  char arteASCII[MAX_ASCII]; // 4500 + el \0

  Imagen origen;

  cout << "Introduce la ruta de la imagen: ";
  cin.getline(ruta,MAX_CARAC);

  cout << "Introduce los caracteres ASCII para la conversion: ";
  cin.getline(grises,MAX_CARAC);

  if(origen.leerImagen(ruta)){
    if(origen.aArteASCII(grises,arteASCII,MAX_ASCII))
      cout << "Aqui tienes tu imagen convertida en ASCII:\n" << arteASCII;
    else
      cout << "La conversion no ha sido posible\n";
  }
  else
    cout << "Ruta de la imagen incorrecta.\n";

}
