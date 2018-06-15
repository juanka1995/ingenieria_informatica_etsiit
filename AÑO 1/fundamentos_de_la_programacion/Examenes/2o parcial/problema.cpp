// NOMBRE y APELLIDOS: Juan Carlos Ruiz García
// DNI: 26510953-A
// Grupo de Practicas: Miercoles

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

/*

	[ SECUENCIA ENTEROS ]
	
	- TAMANIO
	- vector_privado[TAMANIO]
	- total_utilizados
	- Suma()
	
	+ SecuenciaEnteros()
	+ int TotalUtilizados()
	+ void Aniade()
	+ int Elemento()
	+ void Modifica()
	+ int puntoEquilibrio()
	+ SecuenciaEnteros rotar()
	+ SecuenciaEnteros insertar()

*/

class  SecuenciaEnteros{
private:
   static  const  int  TAMANIO  =  50;
   int  vector_privado[TAMANIO];
   int  total_utilizados;
   /*
   	Este metodo recibe dos posiciones y calcula la suma de los elementos del vector_privado que hay entre dichas posiciones.
   */
	int Suma(int pos_inicial,int pos_final){
		int suma=0;
		for(int c=pos_inicial;c<=pos_final;c++)
			suma+=vector_privado[c];
		return suma;
	}
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
   /*
   	Este metodo se encarga de calcular cual es la diferencia minima existente entre todos los elementos del vector_privado.
   */
   int puntoEquilibrio(){
   	int diferencia=Suma(0,total_utilizados-1),suma_izq,suma_der;
   	for(int i=0;i<total_utilizados;i++){
   		suma_izq=Suma(0,i);
   		suma_der=Suma(i+1,total_utilizados-1);
   		if(abs(suma_izq-suma_der)<diferencia)
   			diferencia=abs(suma_izq-suma_der);
   	}
   	return diferencia;
	}
	/*
		Este metodo se encarga de crear una nueva secuencia de enteros y devolver dicha secuencia rotada m veces hacia la 
		derecha.
	*/
	SecuenciaEnteros rotar(int m){
		SecuenciaEnteros secuencia_aux;
			for(int i=total_utilizados-m;i<total_utilizados;i++)
				secuencia_aux.Aniade(vector_privado[i]);
			for(int i=0;i<total_utilizados-m;i++)
				secuencia_aux.Aniade(vector_privado[i]);
		return secuencia_aux;
	}
	/*
		Este metodo se encarga de crear una nueva secuencia de enteros a partir de la original y otra que recibe. Concretamente
		inserta en la secuencia a devolver, la secuencia original con la secuencia recibida en la posicion j del la secuencia
		original.
	*/
	SecuenciaEnteros insertar(SecuenciaEnteros s,int j){
		SecuenciaEnteros secuencia_aux;
		for(int i=0;i<j;i++)
			secuencia_aux.Aniade(vector_privado[i]);
		for(int i=0;i<s.TotalUtilizados();i++)
			secuencia_aux.Aniade(s.Elemento(i));
		for(int i=j;i<total_utilizados;i++)
			secuencia_aux.Aniade(vector_privado[i]);
		return secuencia_aux;
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
   SecuenciaEnteros se1,se2;
	
	//Doy valores a se1
	se1.Aniade(3);
	se1.Aniade(4);
	se1.Aniade(5);
	se1.Aniade(1);
	se1.Aniade(10);
	se1.Aniade(5);
	
	//Muestro la secuencia original
	mostrar(se1);
	
	//Muestro el punto de equilibro de la se1
	cout << "La minima diferencia es: " << se1.puntoEquilibrio() << "\n\n";
	
	//Muestro la secuencia original rotada 2 veces
	mostrar(se1.rotar(2));
	
	//Doy valores a se2
	se2.Aniade(-3);
	se2.Aniade(-2);
	//Voy a mostrar la se2 en la posicion 2 de la se1 
	mostrar(se1.insertar(se2,2));

}

 
