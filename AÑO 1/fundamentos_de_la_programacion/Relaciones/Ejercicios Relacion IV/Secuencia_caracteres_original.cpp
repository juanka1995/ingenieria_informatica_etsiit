
#include <iostrem>
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
};


int main(){
	
	
}
