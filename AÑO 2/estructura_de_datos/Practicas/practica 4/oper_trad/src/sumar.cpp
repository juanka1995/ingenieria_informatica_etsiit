#include "traductor.h"
#include <fstream>
#include <iostream>
using namespace std;

void GetTraductorSumado(const Traductor & t_origen, const Traductor & t_origen2, Traductor & t_des){
  Traductor::const_iterator it_orig, it_orig2;
  // Recorro el primer traductor
  for (it_orig = t_origen.begin(); it_orig != t_origen.end(); ++it_orig) {
    // Inserto todas sus traducciones en el nuevo traductor
    t_des.InsertarFrase((*it_orig).second);
  }
  // Recorro el segundo traductor
  for (it_orig2 = t_origen2.begin(); it_orig2 != t_origen2.end(); ++it_orig2) {
    // Inserto todas sus traducciones en el nuevo traductor
    t_des.InsertarFrase((*it_orig2).second);
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

  if (argc!=3 && argc!=4){
      cout<<"Error en el numero de argumentos."<<endl;
      cout<<"USO:\tconcatenar <primer_traductor> <segundo_traductor> <traductor_salida>"<<endl;
      cout << "Ejemplo:\tsumar ingles_espanhol.txt ingles_espanhol2.txt ingles_espanhol_completo.txt" << endl;
      cout << "¡NOTA el nombre del traductor de salida es opcional!";
      return 0;
   }

   ifstream f (argv[1]);
   ifstream f2 (argv[2]);
   if (!f || !f2){
    cout<<"No puedo abrir alguno de los ficheros "<< argv[1] << ", " << argv[2] << endl;
    return 0;
   }

   Traductor t_ori;
   Traductor t_ori2;
   f>>t_ori; //Cargamos en memoria, en el traductor.
   f2>>t_ori2;
   Traductor t_des;

   GetTraductorSumado(t_ori,t_ori2,t_des);

   if (argc==3)
      ImprimeTraductor(t_des,cout);
   else{
     ofstream fout(argv[3]);
     if (!fout){
    	cout<<"No puedo crear el fichero "<<argv[3]<<endl;
    	return 0;
     }
      ImprimeTraductor(t_des,fout);
   }
}
