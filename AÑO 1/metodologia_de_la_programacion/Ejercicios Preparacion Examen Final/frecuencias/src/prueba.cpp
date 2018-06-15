#include <iostream>
#include "frecuencias.h"

using namespace std;

int main(int argc, char const *argv[]) {
  Frecuencias f1;
  for(int i=0;i<6;i++)
    f1.Add(i*2);
  f1.Add(5);
  f1.Add(5);
  f1.Add(5);
  f1.Add(5);
  f1+=10;
  cout << f1;
  cout << endl;
  for(int i=0;i<f1.Getnpares();i++)
    cout << "Nº: " << f1.getDato(i) << " --> " << f1.Repeticiones(f1.getDato(i)) << " repeticiones" << endl;
  return 0;
}
