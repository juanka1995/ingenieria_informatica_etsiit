#include <iostream>
#include <fstream>
#include <cstdlib>
#include "conjuntofrases.h"
using namespace std;


int main(int argc, char * argv[]){
  if (argc!=2){
      cout<<"Los parametros son:"<<endl;
      cout<<"1.Dime el nombre del fichero con las frases "<<endl;
      return 0;
  }

  ifstream fin(argv[1]);
  if (!fin){
      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
  }

  ConjuntoFrases CF;

  fin>>CF;
  cout<<"Leidas las frases. Numero Total : "<<CF.Size()<<endl;

  cout<<"************************************";
  //Escribimos las frases ordenadas
  cout<<"Frases leidas "<<endl;
  cout<<CF<<endl;

  cout<<"Dime una frase en el idioma origen:"<<endl;
  string ff;
  getline(cin,ff);

  //no distingue entre mayusculas y minusculas
  if (CF.Esta(ff)){
	 Frase f =CF.GetTraducciones(ff);
	 for (unsigned int i=0;i<f.GetDestino().size();++i)
	    cout<<f.GetDestino()[i]<<endl;
  }
  else{
      cout<<"Esa frase no esta ";
  }

  //Construimos un conjunto de frases que contenga una subcadena
  cout<<endl;
  cout<<"Dime una subcadena  que quieras buscar en la frase origen con sus traducciones:";
  string c;
  getline(cin,c);
  ConjuntoFrases CF_consub=CF.Contenga(c);

  //Visualizamos todas las frases con sus traducciones que contienen
  //la subcadena de entrada
  cout<<CF_consub;
}
