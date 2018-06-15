// NOMBRE y APELLIDOS:
// DNI:
// Grupo de Practicas:

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class  SecuenciaEnteros{
private:
   static  const  int  TAMANIO  =  50;
   int  vector_privado[TAMANIO];
   int  total_utilizados;

public:
   SecuenciaEnteros()
	{total_utilizados = 0;
    }

   int  TotalUtilizados(){
      return  total_utilizados;
   }

   void  Aniade(int  nuevo){
      if (total_utilizados  <  TAMANIO){
         vector_privado[total_utilizados]  =  nuevo;
         total_utilizados++;
      }
   }

   int  Elemento(int  indice){
      return  vector_privado[indice];
   }

   void Modifica (int indice_componente, int nuevo){
      if (indice_componente >= 0  &&  indice_componente < total_utilizados)
         vector_privado[indice_componente] = nuevo;
   }
  
// ..................................

};

void mostrar(SecuenciaEnteros s)
{int n = s.TotalUtilizados();
 for(int i=0; i < n; i++)
  cout << s.Elemento(i) << ", ";

 cout << endl << endl;
}

int main(){
	
   SecuenciaEnteros se1;
	
}

 
