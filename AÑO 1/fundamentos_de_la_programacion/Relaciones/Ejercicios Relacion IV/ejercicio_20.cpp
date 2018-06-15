/*

(Examen Septiembre Doble Grado 2013) Defina la clase SecuenciaEnteros análoga
a SecuenciaCaracteres. Defina lo que sea necesario para calcular el número
de secuencias ascendentes del vector. Por ejemplo, el vector {2,4,1,1,7,2,1} tiene
4 secuencias que son {2,4}, {1,1,7}, {2}, {1}.

*/
#include <iostream>
#include <cmath>

using namespace std;

class SecuenciaEnteros {
	private:
		static const int TAMANIO = 50;
		int vector_privado[TAMANIO];
		int total_utilizados;
	public:
		SecuenciaEnteros(){
			total_utilizados=0;
		}
		int TotalUtilizados(){
			return total_utilizados;
		}
		int Capacidad(){
			return TAMANIO;
		}
		void Aniade(int nuevo){
			if (total_utilizados < TAMANIO){
				vector_privado[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}
		int Elemento(int indice){
			return vector_privado[indice];
		}
		void Elimina (int posicion){
			if (posicion >= 0 && posicion < total_utilizados){
				int tope = total_utilizados-1;
				for (int i = posicion ; i < tope ; i++)
					vector_privado[i] = vector_privado[i+1];
				total_utilizados--;
			}
		}
		int NumeroSecuenciasAscendentes(){
			int n_secuencias=1;
			for(int c=0;c<total_utilizados-1;c++)
				if(vector_privado[c]>vector_privado[c+1])
					n_secuencias++;
			return n_secuencias;
		}
};


int main(){
	
	int numero;
	
	SecuenciaEnteros secuencia;
	
	cout << "Introduce el numero a aniadir (escribe -1 para salir): ";
	cin >> numero;
	
	while(numero!=-1){
			secuencia.Aniade(numero);
			cout << "Introduce el numero a aniadir (escribe -1 para salir): ";
			cin >> numero;
	}

	cout << "\nEl numero de secuencias del vector es de: " << secuencia.NumeroSecuenciasAscendentes();
	
}
