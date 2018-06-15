#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {
  char texto[]="# Hola amigo de mi";
  int *ncolumnas=new int[3];
  int *ncolumnas2=new int[3];
  for (int i = 0; i < 3; i++) {
    ncolumnas[i]=2+i;
  }
  double **datos=new double *[3];
  double **datos2=new double *[3];
  for (int i = 0; i < 3; i++) {
    datos[i]=new double [ncolumnas[i]];
    datos2[i]=new double [ncolumnas[i]];
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < ncolumnas[i]; j++) {
      datos[i][j]=3*j;
    }
  }

  for(int i=0;i<3;i++){
    cout << ncolumnas[i] << endl;
    for(int j=0;j<ncolumnas[i];j++)
      cout << datos[i][j] << " ";
    cout << endl;
  }

  ofstream f1("fich.txt");
  f1 << "MP" << endl;

  if(strlen(texto)>0 && texto[0]=='#')
    f1 << texto << endl;

  for(int i=0;i<3;i++){
    f1.write(reinterpret_cast<char*>(&ncolumnas[i]),sizeof(int));
    f1.write(reinterpret_cast<char*>(datos[i]),sizeof(double)*ncolumnas[i]);
  }

  f1.close();

  ifstream f2("fich.txt");
  char basura[100];
  f2.getline(basura,100);
  f2.getline(basura,100);

  for(int i=0;i<3;i++){
    f2.read(reinterpret_cast<char*>(&ncolumnas2[i]),sizeof(int));
    f2.read(reinterpret_cast<char*>(datos2[i]),sizeof(double)*ncolumnas2[i]);
  }

  cout << endl << endl;

  for(int i=0;i<3;i++){
    cout << ncolumnas2[i] << endl;
    for(int j=0;j<ncolumnas2[i];j++)
      cout << datos2[i][j] << " ";
    cout << endl;
  }

  //FALTA LIBERAR MEMORIA
  
  return 0;
}
