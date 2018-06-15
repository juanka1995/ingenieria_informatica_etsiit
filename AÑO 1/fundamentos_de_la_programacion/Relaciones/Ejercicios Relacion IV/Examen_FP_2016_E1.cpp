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
   		Este metodo privado se encarga de comprobar si un numero ya existe en el vector privado de la instancia secuencia_aux de
   		SecuenciaEnteros.   		
   	*/
	bool YaExiste(int numero){
		bool esta_repetido=false;
		for(int j=0;!esta_repetido && j<total_utilizados;j++)
			if(numero==vector_privado[j])
				esta_repetido=true;
		return esta_repetido;
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
		Este metodo se encarga de mostrar cuantas veces aparece un valor determinado
	*/
	int Frecuencia(int num){
		int frecuencia=0;
		bool existe=false;
		for(int i=0;i<total_utilizados;i++)
			if(vector_privado[i]==num)
				frecuencia++;	
		return frecuencia;
	}
	/*
		Este metodo crea otra instancia de la clase SecuenciaEnteros y se encarga de generar una nueva secuencia de enteros
		a partir de la principal pero eliminando los repetidos. Para esto utiliza el 
	*/
	SecuenciaEnteros sinRepetidos(){
		SecuenciaEnteros secuencia_aux;
		for(int i=0;i<total_utilizados;i++){
			if(!YaExiste(secuencia_aux.YaExiste(vector_privado[i])))
				secuencia_aux.Aniade(vector_privado[i]);
		}
		return secuencia_aux;		
	}
	/*
		Este metodo recibe otra instancia de la clase Secuencia enteros y se encarga de crear y devolver una secuencia de 
		caracteres nueva con los enteros que son iguales entre la secuencia original y la secuencia recibida. 
	*/
	SecuenciaEnteros interseccion(SecuenciaEnteros sec){
		SecuenciaEnteros secuencia_aux;
		for(int i=0;i<total_utilizados;i++)
			for(int j=0;j<sec.TotalUtilizados();j++)
				if(vector_privado[i]==sec.Elemento(j) && !YaExiste(secuencia_aux.YaExiste(vector_privado[i])))
					secuencia_aux.Aniade(vector_privado[i]);
		return secuencia_aux;
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
	cout << "\nSecuencia original sin repetidos:\n";
	mostrar(secuencia.sinRepetidos());
	
	cout << "\n[Secuencia 2] Introduce el numero que deseas aniadir (pulsa -1 para salir): ";
   	cin >> numero;
   
   	while(numero!=-1){
   		secuencia2.Aniade(numero);
   		cout << "[Secuencia 2] Introduce el numero que deseas aniadir (pulsa -1 para salir): ";
   		cin >> numero;
   	}
   	
   	
   	cout << "\nSecuencia original:\n";
   	mostrar(secuencia);
   	cout << "\nSegunda secuencia:\n";
   	mostrar(secuencia2);
   	cout << "\nInterseccion de ambas secuencias:\n";
   	mostrar(secuencia.interseccion(secuencia2));
}

 
