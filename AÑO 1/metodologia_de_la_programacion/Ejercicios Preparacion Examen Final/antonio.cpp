#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  ofstream f1("prueba.txt"), f2("prueba.dat", ios::binary|ios::out);
  if(!f1 || !f2) {
    cerr << "No se pudo abrir los ficheros" << endl;
    return 1;
  }

  const char *cadena = "1como mola david! (o no...)";

  // int valor = 123456;
  // f1 << valor;
  // // f2.write((char*)(&valor), sizeof(int));
  // // Nota para David: Le decimos al compilador "Ni puto caso"
  // f2.write(reinterpret_cast<char*>(&valor), sizeof(int));
  f1 << cadena;
  f2.write(cadena, sizeof(char)*strlen(cadena));

  f1.close();
  f2.close();

  return 0;
}
