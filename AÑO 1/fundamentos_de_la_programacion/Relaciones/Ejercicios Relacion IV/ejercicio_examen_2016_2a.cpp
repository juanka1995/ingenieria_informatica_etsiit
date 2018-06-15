/*

Se decide informatizar el acta de un partido de baloncesto para saber qué equipo es el
ganador de un partido. El acta contiene una serie de anotaciones formadas por una pareja
de números cada una, con el dorsal del jugador y el número de puntos conseguidos
teniendo en cuenta que la última anotación es un valor -1
1 2 4 1 4 1 2 3 6 2 3 2 5 2 5 1 1 3 -1
Implemente una clase para la gestión del acta del partido con los métodos necesarios para
manejar un vector en el que se almacenarán los datos:
a) Constructor de la clase
b) Método que devuelva el total de elementos utilizados
c) Método que devuelva la capacidad
d) Método para añadir un jugador con su puntuación
e) Método que dado un índice devuelva los valores asociados a al jugador y su puntuación.
f) Método que devuelva el dorsal del jugador que más puntuación ha hecho en un partido.

*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class ActaBaloncesto{
	private:
		static const int MAX=50;
		int total_utilizados,vector_dorsales[MAX],vector_puntos[MAX],vector_aux[MAX];
		void TotalPuntosJugador(){
			int min=DorsalMinimo();
			for(int c=0;c<total_utilizados;c++)
				vector_aux[vector_dorsales[c]-min]=vector_puntos[c]+vector_aux[vector_dorsales[c]-min];
		}
	public:
		ActaBaloncesto(){
			total_utilizados=0;
		}
		int TotalUtilizados(){
			return total_utilizados;
		}
		void Aniade(int dorsal,int puntos){
			vector_dorsales[total_utilizados]=dorsal;
			vector_puntos[total_utilizados]=puntos;
			vector_aux[total_utilizados]=0;
			total_utilizados++;
		}
		int PuntuacionJugador(int dorsal){
			int puntuacion=0;
			for(int c=0;c<total_utilizados;c++)
				if(vector_dorsales[c]==dorsal)
					puntuacion=vector_puntos[c]+puntuacion;
			return puntuacion;
		}
		int DorsalMaximo(){
			int max=0;
			for(int c=0;c<total_utilizados;c++)
				if(vector_dorsales[c]>max)
					max=vector_dorsales[c];
			return max;
		}
		int DorsalMinimo(){
			int min=0;
			for(int c=0;c<total_utilizados;c++)
				if(vector_dorsales[c]<min)
					min=vector_dorsales[c];
			return min;
		}
		int JugadorMayorPuntuacion(){
			TotalPuntosJugador();
			int n_jugador_max,max=DorsalMaximo(),max_puntos=vector_aux[0],min=DorsalMinimo();
			for(int c=0;c<max;c++)
				if(vector_aux[c]>max_puntos)
					max_puntos=vector_aux[c];
			for(int i=0;i<max;i++)
				if(vector_aux[i]==max_puntos)
					n_jugador_max=i+min;
			return n_jugador_max;	
		}
		void MostrarVectores(){
			for(int c=0;c<total_utilizados;c++)
				cout << vector_dorsales[c] << " ";
			cout << "\n";
			for(int c=0;c<total_utilizados;c++)
				cout << vector_puntos[c] << " ";
			cout << "\n";
			for(int c=0;c<DorsalMaximo();c++)
				cout << vector_aux[c] << " ";
			cout << "\n";
		}
};

int main(){
	
	const string MENSAJE1="Introduce el dorsal del jugador (escribe -1 para salir): ", MENSAJE2="Introduce la puntuación del jugador (escribe -1 para salir): ";
	int puntuacion,dorsal,num_jugador;
	
	ActaBaloncesto acta;
	
	cout << MENSAJE1;
	cin >> dorsal;
	cout << MENSAJE2;
	cin >> puntuacion;
	
	while(dorsal != -1){
		acta.Aniade(dorsal,puntuacion);
		cout << MENSAJE1;
		cin >> dorsal;
		cout << MENSAJE2;
		cin >> puntuacion;
	}
	
	cout << "Introduce el dorsal del jugador que deseas saber sus puntuaciones: ";
	cin >> num_jugador;	
	while(num_jugador>acta.DorsalMaximo()){
		cout << "Introduce el dorsal del jugador que deseas saber sus puntuaciones: ";
		cin >> num_jugador;	
	}
	
	cout << "La puntuacion del jugador " << num_jugador << " es de: " << acta.PuntuacionJugador(num_jugador);
	
	cout << "\n";
	
	cout << "El jugador con mayor puntuacion tiene el dorsal numero " << acta.JugadorMayorPuntuacion();
	
	cout << "\n";
	
	acta.MostrarVectores();
	
}
