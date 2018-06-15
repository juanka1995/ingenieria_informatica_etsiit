#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int **p=new int *[3];
  p[0]=new int[3];

  //Añade los elementos a la matriz
  for(int i=0;i<3;i++)
    p[0][i]=i*2;

  //Muestra los elementos como si fuera un vector
  for(int i=0;i<3;i++)
    cout << p[0][i] << " ";

  cout << endl;

  for(int i=0;i<3;i++)
    p[i]=&p[0][i];

  for(int i=0;i<3;i++)
    cout << *p[i] << " ";

  cout << endl;
  
  delete [] p[0];
  delete [] p;

  return 0;
}
