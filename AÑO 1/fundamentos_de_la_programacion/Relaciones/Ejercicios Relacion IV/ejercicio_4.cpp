/*

Añada los métodos EsPalindromo, Invierte y NumeroMayusculas a la clase
SecuenciaCaracteres que implementen las tareas descritas en el ejercicio 1 de
esta relación de problemas.
Incluya un programa principal de prueba similar al del ejercicio 1.

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
				aux=vector_privado[c];
				vector_privado[c]=vector_privado[puntero];
				vector_privado[puntero]=aux;
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
};


int main(){
	
	char letra;
	int num_may;
	
	SecuenciaCaracteres secuencia;
	
	while(letra!='-'){
		cout << "Introduce el caracter a aniadir (escribe - para salir): ";
		cin >> letra;
		if(letra!='-')
			secuencia.Aniade(letra);
	}
	
	cout << "El vector original es: " << secuencia.ToString();
	
	secuencia.Invierte();
	cout << "\nEl vector inverso es: " << secuencia.ToString();
	
	cout << "\nEl numero de mayusculas del vector es: " << secuencia.NumeroMayusculas();
	
	if(secuencia.EsPalindromo())
		cout << "\nEl vector es palindromo";
	else
		cout << "\nEl vector no es palindromo";
}
