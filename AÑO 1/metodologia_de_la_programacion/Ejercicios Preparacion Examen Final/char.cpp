#include <iostream>
#include <cstring>

using namespace std;

void intercambiar(char *p,char *nueva){
  p=nueva;
}

int main(int argc, char const *argv[]) {
  // char *p=new char[4];
  // p[0]='H';
  // p[1]='o';
  // p[2]='l';
  // p[3]='a';
  char v[]="Hola";
  char *aux=NULL;
  intercambiar(aux,v);
  for(int i=0;i<strlen(*aux);i++)
    cout << aux[i];
  // cout << aux;
  return 0;
}
