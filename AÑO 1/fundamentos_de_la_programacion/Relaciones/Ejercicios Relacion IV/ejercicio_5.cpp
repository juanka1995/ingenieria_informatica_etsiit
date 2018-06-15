/*

Añada el método IntercambiaComponentes para intercambiar dos componentes
de la secuencia. Por ejemplo, si la secuencia contiene {'h','o','l','a'}, después
de intercambiar las componentes 1 y 3, se quedaría con {'h','a','l','o'}.
¿Qué debería hacer este método si los índices no son correctos?
Modifique la implementación del método Invierte del ejercicio 4, para que lo haga
llamando a IntercambiaComponentes.
Imprima las componentes de la secuencia desde el main, antes y después
de llamar a dicho método. Para ello, use el método ToString() de la clase
SecuenciaCaracteres.

*/
#include <iostream>
#include <cmath>

using namespace std;


class SecuenciaCaracteres {
	private:
		static const int TAMANIO = 50;
		char vector_privado[TAMANIO];
		int total_utilizados;
	public:
		SecuenciaCaracteres()
			:total_utilizados(0){
			}
		int TotalUtilizados(){
			return total_utilizados;
		}
		int Capacidad(){
			return TAMANIO;
		}
		void Aniade(char nuevo){
			if (total_utilizados < TAMANIO){
				vector_privado[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}
		char Elemento(int indice){
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
		string ToString(){
			string cadena;
			for (int i=0; i<total_utilizados; i++)
				cadena = cadena + vector_privado[i];
			return cadena;
		}
		bool EsPalindromo(){
			int mitad=total_utilizados/2;
			int puntero=total_utilizados-1;
			bool es_palindromo;
			for(int c=0;c<mitad;c++){
				if(vector_privado[c]==vector_privado[puntero]){
					puntero--;
					es_palindromo=true;
				}
				else{
					es_palindromo=false;
					break;
				}
			}
			return es_palindromo;
		}
		void Invierte(){
			int mitad=total_utilizados/2;
			int puntero=total_utilizados-1;
			char aux;
			for(int c=0;c<mitad;c++){
				IntercambiaComponentes(c,puntero);
				puntero--;
			}
		}
		int NumeroMayusculas(){
			int num_may;
			for(int c=0;c<total_utilizados-1;c++){
				if(vector_privado[c]>='A' && vector_privado[c]<='Z')
					num_may++;
			}
			return num_may;
		}
		void IntercambiaComponentes(int pos1, int pos2){
			char aux;
			if(pos1 >= 0 && pos1 < total_utilizados && pos2 >= 0 && pos2 < total_utilizados){
				aux=vector_privado[pos1];
				vector_privado[pos1]=vector_privado[pos2];
				vector_privado[pos2]=aux;
			}
		}
};


int main(){
	
	char letra;
	int num_may,comp1,comp2;
	
	SecuenciaCaracteres secuencia;
	
	while(letra!='-'){
		cout << "Introduce el caracter a aniadir (escribe - para salir): ";
		cin >> letra;
		if(letra!='-')
			secuencia.Aniade(letra);
	}
	
	cout << "\nIntroduce los componentes que deseas intercambiar separados por un espacio: ";
	cin >> comp1;
	cin >> comp2;
	
	cout << secuencia.ToString();
	
	secuencia.IntercambiaComponentes(comp1,comp2);
	
	cout << "\n" << secuencia.ToString();
	
	secuencia.Invierte();
	
	cout << "\n" << secuencia.ToString();
	
}
