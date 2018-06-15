/*

Añada un método EliminaRepetidos que quite los elementos repetidos, de forma
que cada componente sólo aparezca una única vez. Se mantendrá la primera aparición,
de izquierda a derecha. Por ejemplo, si la secuencia contiene
{'b','a','a','h','a','a','a','a','c','a','a','a','g'}
después de quitar los repetidos, se quedaría como sigue:
{'b','a','h','c','g'}

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
		void Elimina(int i){
			for(int c=i;c<total_utilizados-1;c++){
				vector_privado[c]=vector_privado[c+1];
			}
			total_utilizados--;
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
		void EliminaMayusculas(){
			for (int i=0; i<total_utilizados; i++)
				if (isupper(vector_privado[i])){
					Elimina(i);
					i--;
				}
		}
		void EliminaRepetidos(){
			for(int c=0;c<total_utilizados;c++)
				for(int i=c+1;i<total_utilizados;i++)
					if(vector_privado[c]==vector_privado[i]){
						Elimina(i);
						i--;
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
	
	secuencia.EliminaRepetidos();
	
	cout << "\n" << secuencia.ToString();
	
}
