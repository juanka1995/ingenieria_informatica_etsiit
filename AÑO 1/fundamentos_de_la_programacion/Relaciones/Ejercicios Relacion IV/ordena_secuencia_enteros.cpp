// NOMBRE y APELLIDOS: Juan Carlos Ruiz Garcia
// DNI: 26510953-A
// Grupo de Practicas: Miercoles

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
/*
	SecuenciaEnteros
	- TAMANIO
	- vector_privado[TAMANIO]
	- total_utilizados
	+ SecuenciaEnteros()
	+ TotalUtilizados()
	+ Aniade(nuevo)
	+ Elemento(indice)
	+ Modifica(indice_componente, nuevo)
	+ Invierte()
	+ Moda(min,max)
	+ Sumatoria()
*/
using namespace std;
class  SecuenciaEnteros{
private:
   	static  const  int  TAMANIO  =  50;
   	int  vector_privado[TAMANIO];
   	int  total_utilizados;
   	/*
   		Este metodo se encarga de intercambiar las posiciones de dos elementos del vector privado.
   	*/
   	void IntercambiarNumeros(int pos1,int pos2){
   		int aux;
   		aux=vector_privado[pos1];
   		vector_privado[pos1]=vector_privado[pos2];
   		vector_privado[pos2]=aux;
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
		Este metodo se encarga de ordenar el vector privado en orden ascendente.
	*/
	void Ordenar(){
		for(int i=0;i<total_utilizados;i++)
			for(int j=total_utilizados-1;j>i;j--)
				if(vector_privado[j]<vector_privado[j-1])
					IntercambiarNumeros(j,j-1);
	}
};

void mostrar(SecuenciaEnteros s)
{int n = s.TotalUtilizados();
 for(int i=0; i < n; i++)
  cout << s.Elemento(i) << ", ";

 cout << endl;
}

int main(){
   
   	int numero;
   
   	SecuenciaEnteros secuencia,secuencia2;
   
   	cout << "[Secuencia 1] Introduce el numero que deseas aniadir (pulsa -1 para salir): ";
   	cin >> numero;
   
   	while(numero!=-1){
   		secuencia.Aniade(numero);
   		cout << "[Secuencia 1] Introduce el numero que deseas aniadir (pulsa -1 para salir): ";
   		cin >> numero;
   	}

	cout << "\nSecuencia original:\n";
	mostrar(secuencia);
	secuencia.Ordenar();
	cout << "\nSecuencia original sin repetidos:\n";
	mostrar(secuencia);
}

 
