#include "traductor.h"
#include <fstream>
#include <iostream>
using namespace std;

void GetTraductorConcatenado(const Traductor & t_origen, const Traductor & t_origen2, Traductor & t_des){
  Traductor::const_iterator it_orig, it_orig2;
  Frase::const_iterator fit_orig, fit_orig2;
  //Recorro el primer traductor
  for (it_orig = t_origen.begin(); it_orig != t_origen.end(); ++it_orig) {
    //Recorro todas las traducciones del it_orig elemento del primero traductor
    for (fit_orig = (*it_orig).second.begin(); fit_orig != (*it_orig).second.end(); ++fit_orig) {
      // Busco cada traduccion en las claves del segundo traductor
      it_orig2 = t_origen2.find((*fit_orig));
      // Si existe dicha traduccion como clave en el otro traductor se puede hacer el cambio de idioma
      if (it_orig2 != t_origen2.end()) {
        //Calculo la frase
        string cadena = (*it_orig).first + ";";
        for (fit_orig2 = (*it_orig2).second.begin(); fit_orig2 != (*it_orig2).second.end(); ++fit_orig2) {
          cadena = cadena + (*fit_orig2) + ";";
        }
        cadena.resize(cadena.size()-1);
        Frase ff(cadena);
        // La inserto en el nuevo traductor
        t_des.InsertarFrase(ff);
      }
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

  if (argc!=3 && argc!=4){
      cout<<"Error en el numero de argumentos."<<endl;
      cout<<"USO:\tconcatenar <primer_traductor> <segundo_traductor> <traductor_salida>"<<endl;
      cout << "Ejemplo:\tconcatenar ingles_espanhol.txt espanhol_frances.txt ingles_frances.txt" << endl;
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

   GetTraductorConcatenado(t_ori,t_ori2,t_des);

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
