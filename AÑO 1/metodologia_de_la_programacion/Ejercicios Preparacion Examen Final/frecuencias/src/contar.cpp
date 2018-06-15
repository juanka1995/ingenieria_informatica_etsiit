#include <iostream>
#include "frecuencias.h"
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {
  Frecuencias f;
  int k;
  if(argc==1){
    cout << "Introduce un numero entero: ";
    cin >> k;
    while(!cin.eof()){
      f.Add(k);
      cin >> k;
    }
    cout << f;
  }
  else{
    ifstream f1(argv[1]);
    if(!f1){
      cerr << "Error en la apertura del fichero" << endl;
      return 1;
    }
    while(!f1.eof()){
      f1 >> k;
      f.Add(k);
    }
    cout << f;
  }
  return 0;
}
