#include "traductor.h"
#include <fstream>
#include <iostream>
using namespace std;

void GetTraductorInverso(const Traductor & t_origen, Traductor & t_destino){
  Traductor::const_iterator it;
  Frase::const_iterator it2;
  // Recorro el traductor origen
  for (it = t_origen.begin(); it != t_origen.end(); ++it) {
    // Recorro todas las traducciones de dicho traductor
    for (it2  = (*it).second.begin(); it2 != (*it).second.end(); ++it2) {
      // Calculo la cadena inversa
      string cadena = (*it2) + ";" + (*it).first;
      Frase ff(cadena);
      // La inserto en el nuevo traductor
      t_destino.InsertarFrase(ff);
    }
  }
}

void ImprimeTraductor(const Traductor &T,ostream &os){
  Traductor::const_iterator it;
  for (it=T.begin(); it!=T.end();++it){
      os<<(*it).first<<";";
      Frase::const_iterator it_d;
      for (it_d=(*it).second.begin(); it_d!=(*it).second.end();++it_d)
          os<<(*it_d)<<";";
      os<<endl;
  }
}


int main(int argc, char * argv[]){

  if (argc!=2 && argc!=3){
      cout<<".-Dime el nombre de fichero del traductor origen"<<endl;
      cout<<".-[opcionalmente] El nombre de fichero del traductor destino"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Traductor t_ori;
   f>>t_ori; //Cargamos en memoria, en el traductor.
   Traductor t_des;

   GetTraductorInverso(t_ori,t_des);

   if (argc==2)
      ImprimeTraductor(t_des,cout);
   else{
     ofstream fout(argv[2]);
     if (!fout){
    	cout<<"No puedo crear el fichero "<<argv[2]<<endl;
    	return 0;
     }
      ImprimeTraductor(t_des,fout);
   }
}
