
#include <iostream>
#include <cmath>
#include <string>

using namespace std;


class SecuenciaEnteros {
	private:
		static const int TAMANIO = 50;
		int vector_privado[TAMANIO];
		int total_utilizados;
	public:
		SecuenciaEnteros()
			:total_utilizados(0){
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
		int MostrarNumero(int pos){
			return vector_privado[pos];
		}
		void Invierte(){
			int mitad=total_utilizados/2, final=total_utilizados-1, aux;
			for(int c=0;c<mitad;c++){
				aux=vector_privado[c];
				vector_privado[c]=vector_privado[final];
				vector_privado[final]=aux;
				final--;
			}	
		}
		void Sumatoria(){
			for(int c=1;c<total_utilizados;c++)
				vector_privado[c]=vector_privado[c]+vector_privado[c-1];
		}
		int Moda(){
			int min=-5,max=5,tope=max-min+1,vector_aux[tope],max_rep=0,moda;
			for(int c=0;c<tope;c++)
				vector_aux[c]=0;
			for(int c=0;c<total_utilizados;c++)
				vector_aux[vector_privado[c]-min]++;
			for(int c=0;c<tope;c++)
				if(vector_aux[c]>max_rep){
					max_rep=vector_aux[c];
					moda=c+min;
				}
			return moda;		
		}
};


int main(){
	
	const string MENSAJE="Introduce el numero a aniadir (pulsa -6 para salir): ";
	int numero;
	
	SecuenciaEnteros secuencia;
	
	cout << MENSAJE;
	cin >> numero;
	
	while(numero!=-6 && secuencia.TotalUtilizados()<secuencia.Capacidad()){
		secuencia.Aniade(numero);
		cout << MENSAJE;
		cin >> numero;
	}
	
	for(int c=0;c<secuencia.TotalUtilizados();c++)
		cout << secuencia.MostrarNumero(c);
	
	cout << "\n";
	
	secuencia.Invierte();
	
	secuencia.Sumatoria();
	
	for(int c=0;c<secuencia.TotalUtilizados();c++)
		cout << secuencia.MostrarNumero(c);
		
	cout << "El numero que mas aparece es el: " << secuencia.Moda();
	
}
