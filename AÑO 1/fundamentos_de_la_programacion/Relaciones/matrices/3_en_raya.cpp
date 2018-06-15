/*



*/

#include <iostream>
#include <string>

using namespace std;

class Tres_En_Raya{
	private:
		static const int MAX_FILAS=3, MAX_COL=3;
		char tablero[MAX_FILAS][MAX_COL],huecos_restantes;
		void Insertar(char numero,char ficha_jug){
			for(int i=0;i<MAX_FILAS;i++)
				for(int j=0;j<MAX_COL;j++)
					if(tablero[i][j]==numero)
						tablero[i][j]=ficha_jug;
			huecos_restantes--;
		}
	public:
		Tres_En_Raya(){
			huecos_restantes=9;
			char c='1';
			for(int i=0;i<MAX_FILAS;i++)
				for(int j=0;j<MAX_COL;j++){
					tablero[i][j]=c;
					c++;
				}
		}
		int Huecos_restantes(){
			return huecos_restantes;
		}
		int Mostrar_tablero(){
			system("cls");
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++)
					cout << tablero[i][j] << " ";
				cout << "\n";
			}
		}
		bool Esta_Libre(char numero){
			bool esta_libre=false;
			for(int i=0;i<MAX_FILAS && !esta_libre;i++)
				for(int j=0;j<MAX_COL && !esta_libre;j++)
					if(tablero[i][j]==numero)
						esta_libre=true;
			return esta_libre;
		}
		void Comprobar_ganador(){
			int cont_j1=0,cont_j2=0;
			bool j1_ganador=false,j2_ganador=false;
			// Compruebo los ganadores en el sentido de filas por columnas
			for(int i=0;i<MAX_FILAS && (!j1_ganador || !j2_ganador);i++){
				for(int j=0;j<MAX_COL && (!j1_ganador || !j2_ganador);j++)
					if(tablero[i][j]=='X'){
						cont_j1++;
						if(cont_j1==3)
							j1_ganador=true;
					}
					else{
						cont_j2++;
						if(cont_j2==3)
							j2_ganador=true;
					}
				cont_j1=0;
				cont_j2=0;
			}	
			
			// Compruebo los ganadores en el sentido de columnas por filas
			for(int i=0;i<MAX_FILAS && (!j1_ganador || !j2_ganador);i++){
				for(int j=0;j<MAX_COL && (!j1_ganador || !j2_ganador);j++)
					if(tablero[j][i]=='X'){
						cont_j1++;
						if(cont_j1==3)
							j1_ganador=true;
					}
					else{
						cont_j2++;
						if(cont_j2==3)
							j2_ganador=true;
					}	
				cont_j1=0;
				cont_j2=0;
			}
						
			// Compruebo los ganadores en la diagonal principal
			for(int i=0;i<MAX_FILAS && (!j1_ganador || !j2_ganador);i++)
				if(tablero[i][i]=='X'){
						cont_j1++;
						if(cont_j1==3)
							j1_ganador=true;
					}
					else{
						cont_j2++;
						if(cont_j2==3)
							j2_ganador=true;
					}
			cont_j1=0;
			cont_j2=0;
			// Compruebo los ganadores en la otra diagonal
			for(int i=MAX_FILAS-1;i>=0;i--)
				if(tablero[i][(MAX_FILAS-1)-i]=='X'){
					cont_j1++;
					if(cont_j1==3)
						j1_ganador=true;
				}
				else{
					cont_j2++;
					if(cont_j2==3)
						j2_ganador=true;
				}
			
			if(j1_ganador && !j2_ganador)
				cout << "\nHa ganado el jugador 1";
			else if(!j1_ganador && j2_ganador)
				cout << "\nHa ganado el jugador 2";
			else if(j1_ganador && j2_ganador)
				cout << "\nHa habido un empate";
			else
				cout << "\nNo hay ganador";			
					
		}
		void Limpiar(){
			huecos_restantes=9;
			char c='1';
			for(int i=0;i<MAX_FILAS;i++)
				for(int j=0;j<MAX_COL;j++){
					tablero[i][j]=c;
					c++;
				}
		}
		void Introducir_mov(char numero,int num_jug){
			if(numero>'0' && numero <='9' && (num_jug==1 || num_jug==2))
				if(num_jug==1 && Esta_Libre(numero)){
					Insertar(numero,'X');
				}
				else if(Esta_Libre(numero)){
					Insertar(numero,'0');
				}
			if(huecos_restantes>=0)
				Mostrar_tablero();
		}
		
		
		
};

int main(){
	
	char pos_j1,pos_j2,jugar;
	bool salir=false,turno=true; // True es el turno del jugador 1 y false el turno del jugador 2.
	
	Tres_En_Raya partida;	
	
	while(!salir){
	
		partida.Mostrar_tablero();
		
		while(partida.Huecos_restantes()!=0){
			if(turno){
				do{
					cout << "\nJugador 1 (X). Introduzca la posicion a ocupar: ";
					cin >> pos_j1;	
				}while(pos_j1<'1' || !partida.Esta_Libre(pos_j1));
				partida.Introducir_mov(pos_j1,1);
				turno=false;
			}
			else{
				do{
					cout << "\nJugador 2 (0). Introduzca la posicion a ocupar: ";
					cin >> pos_j2;	
				}while(pos_j2<'1' || !partida.Esta_Libre(pos_j2));
				partida.Introducir_mov(pos_j2,2);
				turno=true;
			}
		}
	
		partida.Comprobar_ganador();
		
		do{
			cout << "\n\nDesea volver a jugar?(s/n): ";
			cin >> jugar;
		}while(jugar!='s' && jugar!='n');
		
		if(jugar=='s'){
			turno=true;
			partida.Limpiar();
		}
		else{
			salir=true;
			cout << "HASTA LA VISTA CABEZA HUEVO!";
		}
			
		
	}	
	
	
		
	
}
