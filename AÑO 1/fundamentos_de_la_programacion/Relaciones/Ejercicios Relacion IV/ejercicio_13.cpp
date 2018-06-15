/*

Cread una clase Permutacion para representar una permutación de enteros. Para
almacenar los valores enteros usaremos como dato miembro privado un vector clásico
de enteros. La clase debe proporcionar, al menos, los siguientes métodos:
 Aniade para añadir un número a la permutación.
 EsCorrecta para indicar si los valores forman una permutación correcta, es
decir, que contiene todos los enteros sin repetir entre el mínimo y el máximo de
dichos valores. Por ejemplo, (2,3,6,5,4) es una permutación correcta pero no
lo es (7,7,6,5) (tiene el 7 como valor repetido) ni tampoco (7,6,4) (le falta
el 5).
 NumLecturas para saber el número de lecturas de la permutación. Una permutación
de un conjunto de enteros tiene k lecturas, si para leer sus elementos en
orden creciente (de izquierda a derecha) tenemos que recorrer la permutación k
veces. Por ejemplo, la siguiente permutación del conjunto f0; : : : ; 8g:
4 0 8 1 2 5 3 6 7
necesita 3 lecturas. En la primera obtendríamos 0, 1, 2 y 3. En la segunda 4, 5, 6
y 7 y finalmente, en la tercera, 8.
Cread un programa principal que lea desde un fichero los valores de la permutación e
imprima el número de lecturas de dicha permutación.

*/
#include <iostream>
#include <cmath>

using namespace std;

class Permutacion{
	private:
		static const int TAMANIO=50;
		int vector_privado[TAMANIO],total_utilizados;
	public:
		Permutacion()
			:total_utilizados(0)
			{
			}
		void Aniade(int numero){
			vector_privado[total_utilizados]=numero;
			total_utilizados++;
		}
		int Maximo(){
			int maximo=vector_privado[0];
			for(int c=0;c<total_utilizados;c++)
				if(vector_privado[c]>maximo)
					maximo=vector_privado[c];
			return maximo;
		}
		int Minimo(){
			int minimo=vector_privado[0];
			for(int c=0;c<total_utilizados;c++)
				if(vector_privado[c]<minimo)
					minimo=vector_privado[c];
			return minimo;
		}
		// Comprueba si el vector de enteros es una permutacion o no.
		bool EsCorrecta(){
			int max=Maximo(),min=Minimo(),n_elementos=max-min+1;
			bool es_correcto=true,encontrado;
			if(n_elementos==total_utilizados){
				for(int c=min+1;c<max && es_correcto;c++){
					encontrado=false;
					for(int i=0;i<total_utilizados && !encontrado;i++)
						if(vector_privado[i]==c)
							encontrado=true;
					if(!encontrado)
						es_correcto=false;
				}	
			}
			else{
				es_correcto=false;
			}
			return es_correcto;
		}
		// Calcula el numero de lecturas necesarias para leer la permutación existente en dicho vector.
		int NumLecturas(){
			int max=Maximo(),min=Minimo(),num_lecturas=0;
			while(min<=max){
				for(int c=0;c<total_utilizados;c++)
					if(vector_privado[c]==min)
						min++;
				num_lecturas++;
			}
			return num_lecturas;
		}
};

int main(){
	
	Permutacion ejemplo;
	
	ejemplo.Aniade(4);
	ejemplo.Aniade(5);
	ejemplo.Aniade(8);
	ejemplo.Aniade(7);
	ejemplo.Aniade(6);

	
	if(ejemplo.EsCorrecta())
		cout << "El numero de lecturas ha sido: " << ejemplo.NumLecturas();
	else
		cout << "No existe permutacion.";
	
}
