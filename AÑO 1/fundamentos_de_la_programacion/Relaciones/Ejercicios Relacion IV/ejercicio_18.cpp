/*

Defina una clase Frase para almacenar
un conjunto de caracteres (similar a la clase SecuenciaCaracteres). Defina un
método para localizar la k-ésima palabra.
Una palabra es toda secuencia de caracteres delimitada por espacios en blanco a izquierda
y derecha. La primera palabra no tiene por qué tener espacios a su izquierda y
la última no tiene por qué tener espacios a su derecha. Puede haber varios caracteres
en blanco consecutivos.
Si k es mayor que el número de palabras, se considera que no existe tal palabra.
Por ejemplo, si la frase es {' ',' ','h','i',' ',' ','b','i',' '}. Si k =
1, la posición es 2. Si k = 2 la posición es 6. Si k = 3 la posición es -1.
Si la frase fuese {'h','i',' ','b','i',' '}, entonces

*/
#include <iostream>
#include <cmath>

using namespace std;

class Frase{
	private:
		static const int MAX=50;
		char vector[MAX];
		int total_utilizados;
	public:
		Frase(){
			total_utilizados=0;
		}
		void Aniade(char caracter){
			vector[total_utilizados]=caracter;
			total_utilizados++;
		}
		int NumeroPalabras(){
			int n_palabras=1;
			if(total_utilizados==0)
				n_palabras=0;
			else
				for(int c=0;c<total_utilizados;c++)
					if(vector[c]!=' ' && vector[c-1]==' ')
						n_palabras++;
			return n_palabras;
		}
		void EliminaBlancosIniciales(){
			while(vector[0]==' '){
				for(int c=0;c<total_utilizados;c++)
					vector[c]=vector[c+1];
				total_utilizados--;
			}
		}
		void EliminaBlancosFinales(){
			while(vector[total_utilizados-1]==' '){
				total_utilizados--;
			}
		}
		int LocalizarPalabra(int n_buscar){
			EliminaBlancosFinales();
			EliminaBlancosIniciales();
			int posicion=0,num_palabras=NumeroPalabras(),contador=0;
			char vector_posiciones[num_palabras];
			if(num_palabras==0 || n_buscar>num_palabras){
				posicion=-1;
			}
			else{
				// FALTA BUSCAR LA POSICION
			}		
			return posicion;
				
		}
		void MostrarVector(){
			for(int c=0;c<total_utilizados;c++)
				cout << vector[c];
		}
};

int main(){
		
	char caracter;
	int n_buscar;
	
	Frase frase1;
	
	cout << "Introduce un caracter (pulsa el . para salir): ";
	caracter=cin.get();
	
	while(caracter!='.'){
		if(caracter!='\n')
			frase1.Aniade(caracter);
		cout << "Introduce un caracter (pulsa el . para salir): ";
		caracter=cin.get();
	}
	
	cout << "Introduce el numero de palabra a buscar: ";
	cin >> n_buscar;
	
	//frase1.MostrarVector();
	
	cout << "\nLa posicion de la palabra " << n_buscar << " es la " << frase1.LocalizarPalabra(n_buscar);
	
	//cout << frase1.NumeroPalabras();
	
}
