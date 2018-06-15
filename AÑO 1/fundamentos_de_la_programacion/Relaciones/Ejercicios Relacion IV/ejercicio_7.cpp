/*

A�ada el m�todo EliminaMayusculas para eliminar todas las may�sculas.
Por ejemplo, despu�s de aplicar dicho m�todo al vector
{'S','o','Y',' ','y','O'}, �ste debe quedarse con {'o',' ','y'}.
Un primer algoritmo para resolver este problema ser�a el siguiente (en ejercicios posteriores
se ver�n m�todos m�s eficientes):
Recorrer todas las componentes de la secuencia
Si la componente es una may�scula, borrarla
Queremos implementarlo llamando al m�todo Elimina (que borra un �nico car�cter):
class SecuenciaCaracteres{
.........
void EliminaMayusculasError(){
for (int i=0; i<total_utilizados; i++)
if (isupper(vector_privado[i]))
Elimina(i);
}
};
El anterior c�digo tiene un fallo. �Cu�l? Pru�belo con cualquier secuencia que tenga
dos may�sculas consecutivas, proponer una soluci�n e implementarla.

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
		void EliminaMayusculasApuntadores(){
			int puntero_escritura=0,tope=total_utilizados;
			for(int puntero_lectura=0;puntero_lectura<tope;puntero_lectura++)
				if(islower(vector_privado[puntero_lectura])){
					vector_privado[puntero_escritura]=vector_privado[puntero_lectura];
					puntero_escritura++;
				}
				else{
					total_utilizados--;
				}	
		}
};


int main(){
	
	char letra;
	int num_may,comp1,comp2;
	
	SecuenciaCaracteres secuencia;
	
	cout << "Introduce el caracter a aniadir (escribe - para salir): ";
	letra=cin.get();
	
	while(letra!='-'){
		if(letra!='\n')
			secuencia.Aniade(letra);
		cout << "Introduce el caracter a aniadir (escribe - para salir): ";
		letra=cin.get();
	}
	
	secuencia.EliminaMayusculasApuntadores();
	
	cout << "\n" << secuencia.ToString();
	
}
