#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct Persona{
  char nombre[60];
  int edad;
  Persona *amigos;
};

void mostrarPersona(const Persona *p){
  if(p->amigos!=NULL)
    cout << p->nombre << " " << p->edad << " " << p->amigos->nombre << endl;
  else
    cout << p->nombre << " " << p->edad << " " << p->amigos << endl;
}

int main(int argc, char const *argv[]) {
  const int NUM_PERS=3;
  string nombre;
  int edad;
  Persona *pers=new Persona[NUM_PERS];

  for(int i=0;i<NUM_PERS;i++){
    cout << "Introduce el nombre de la persona " << i << ": ";
    cin >> nombre;
    strcpy(pers[i].nombre,nombre.c_str());
    cout << "Introduce la edad de la persona " << i << ": ";
    cin >> edad;
    pers[i].edad=edad;
    pers[i].amigos=NULL;
  }

  pers[0].amigos=&pers[2];
  pers[2].amigos=&pers[0];

  for(int i=0;i<NUM_PERS;i++)
    mostrarPersona(&pers[i]);

  delete [] pers;
  pers=NULL;
  return 0;
}
