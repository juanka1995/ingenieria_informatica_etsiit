#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctype.h>
#include "refranes_hash.h"
using namespace std;


string TodoMinuscula(const string &cad){
  string caux; 
  for (unsigned char i=0;i<cad.size();++i)
     caux.push_back(tolower(cad[i]));
  return caux;
}  

int main(int argc, char * argv[]){
  if (argc!=3 && argc!=2){
      cout<<"Los parametros son:"<<endl;
      cout<<"1.Dime el nombre del fichero los refranes"<<endl;
      cout<<"2.-[Opcional] Prefijo de los refranes"<<endl;
      return 0;
  }    
  
  ifstream fin(argv[1]);
  if (!fin){
      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
  }
  int len=3;
  if (argc==3)
    len=atoi(argv[2]);
  Refranes refs(len);
  cout<<"Creado los refranes"<<endl;
  fin>>refs;
  
  cout<<"Refranes leidos :"<<endl;
  //cout << refs.size() << endl;
  cout<<refs<<endl;
  
  cout<<"Dime un Refran: ";
  string refran;
  getline(cin,refran);
  string rr=TodoMinuscula(refran);
  pair<bool, Refranes::iterator> a =refs.Esta(rr);
  if (a.first){
    cout<<"El refrán "<<refran<<" si esta"<<endl;
    //refs.BorrarRefran(refran);
    //cout << refs << endl;
  }
  else
    cout<<"No esta"<<endl;
  
  //Implementar la busqueda de una subcadena en todos los refranes.
  string patron;
  cout<<"Dime un secuencia a buscar en los refranes:";
  getline(cin,patron);
  patron=TodoMinuscula(patron);
  Refranes::iterator it;
  cout<<endl;
  for (it=refs.begin(); it!=refs.end();++it){
    
      size_t found = (*it).find(patron);
      if (found!=string::npos)//si lo ha encontrado
	cout<<*it<<endl;
      
  }
  
}  