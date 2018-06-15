/*

Construya una clase CaminoComeCocos para representar el camino seguido por el
usuario en el juego del ComeCocos (Pac-Man). Internamente debe usar un vector de
char como dato miembro privado. Tendrá métodos para subir, bajar, ir a la izquierda
e ir a la derecha. Dichos métodos únicamente añadirán el carácter correspondiente
's', 'b', 'i', 'd' al vector privado.
Añada a la clase un método PosicionMovimientosConsecutivos que calcule
la posición donde se encuentre la primera secuencia de al menos n movimientos
consecutivos iguales a uno dado (que pasaremos como parámetro al método).
Por ejemplo, en el camino de abajo, si n = 3 y el movimiento buscado es 's', entonces
dicha posición es la 6.
{'b','b','i','s','s','b','s','s','s','s','i','i','d'}
Cree un programa principal que lea desde un fichero los caracteres que representan
las posiciones hasta llegar a un punto ('.'), lea un carácter c y un entero n e imprima
en pantalla la posición de inicio de los n movimientos iguales a c.

*/

#include <iostream>
#include <string>

using namespace std;

class PacMan{
	private:
		char vector[100];
		int total_utilizados;
	public:
		PacMan()
		{
			total_utilizados=0;
		}
		void Subir(char car){
			vector[total_utilizados]=car;
			total_utilizados++;
		}
		void Bajar(char car){
			vector[total_utilizados]=car;
			total_utilizados++;
		}
		void Izquierda(char car){
			vector[total_utilizados]=car;
			total_utilizados++;
		}
		void Derecha(char car){
			vector[total_utilizados]=car;
			total_utilizados++;
		}
		char PosicionMovimientosConsecutivos(char caracter, int num_rep){
			int c=0;
			bool no_existe,existe=false;
			
			while(c<(total_utilizados-num_rep) && existe==false){
				no_existe=false;
				if(vector[c]==caracter){
					int i=c+1,contador=1;
					while(i<c+num_rep && no_existe==false){
						if(vector[i]==caracter){
							contador++;
							i++;
						}
						else
							no_existe=true;
					}
					if(contador==num_rep){
						existe=true;
						return c;
					}
				}
				c++;
			}
			if(existe=false){
				c=-1;
				return c;	
			}
		}
			
};



int main(){
	
	const string SMS1="Introduce hacia donde deseas mover a Pac-Man ( . para salir): ";
	int total_utilizados=0,consecutivos,posicion;
	char caracter,vector[1000];
	
	cout << "Instrucciones: \n\n";
	cout << "Subir --> s\n";
	cout << "Bajar --> b\n";
	cout << "Izquierda --> i\n";
	cout << "Derecha --> d\n\n";
	
	while(caracter!='.'){
		
		cout << SMS1;
		cin >> caracter;
		if(caracter == 's' || caracter == 'b' || caracter == 'd' || caracter == 'i'){
			vector[total_utilizados]=caracter;
			total_utilizados++; 
		}
	}
	
	PacMan juego;
	
	for(int c=0;c<total_utilizados;c++){
		switch(vector[c]){
		case 's':
			juego.Subir(vector[c]);
		break;
		case 'b':
			juego.Bajar(vector[c]);
		break;
		case 'd':
			juego.Derecha(vector[c]);
		break;
		case 'i':
			juego.Izquierda(vector[c]);
		break;
		}
	}
	
	while(consecutivos<0 || (caracter != 's' && caracter != 'b' && caracter != 'd' && caracter != 'i')){
		cout << "Introduce el caracter a buscar (s,b,d,i): ";
		cin >> caracter;
		cout << "Introduce cuantas veces consecutivas deseas buscar dicho caracter: ";
		cin >> consecutivos;
	}
	
	posicion=juego.PosicionMovimientosConsecutivos(caracter,consecutivos);
	
	if(posicion!=-1)
		cout << "La posicion donde comienza la secuencia es la: " << posicion+1;
	else
		cout << "No existe dicha secuancia.";
		
}
