/*

Ejercicio que simula la traccion de una bicicleta con el uso de clases.

*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Clase TraccionBicicleta

class TraccionBicicleta{
	private:
		int estrella=1,pinion=1;
	public:
		//Funcion que define los valores de estrella
		void SetEstrella(int valor){
			if(estrella+valor>3)
				estrella=3;
			else if(estrella+valor<1)
				estrella=1;
			else
				estrella=estrella+valor;
		}
		//Funcion que define los valores de los piniones
		void SetPinion(int valor){
			if(pinion+valor<1)
				pinion=1;
			else if(pinion+valor>7)
				pinion=7;
			else
				pinion=pinion+valor;
		}
		int GetEstrella(){
			return estrella;
		}
		int GetPinion(){
			return pinion;
		}
		//Funcion que identifica si subir la estrella o el pinion
		void Subir(char pieza, char mover){
			int cantidad;
			if(mover == 'S')
				cantidad=1;
			else
				cantidad=2;
			if(pieza == 'E')
				SetEstrella(cantidad);
			else
				SetPinion(cantidad);
		}
		//Funcion que identifica si bajar la estrella o el pinion
		void Bajar(char pieza, char mover){
			int cantidad;
			if(mover == 'B')
				cantidad=-1;
			else
				cantidad=-2;
			if(pieza == 'E')
				SetEstrella(cantidad);
			else
				SetPinion(cantidad);
		}
		//Funcion que identifica la direccion de la pieza a mover
		void Direccion(char pieza,char mover){
			if(mover == 'S' || mover == 'T')
				Subir(pieza,mover);
			else
				Bajar(pieza,mover);
		}
};

//Funcion encargada de recoger la pieza a mover
char PiezaParaMover(string sms){
	char pieza;
	do{
		cout << sms;
		cin >> pieza;
	}while(pieza != 'P' && pieza != 'E');
	return pieza;
}

//Funcion encargada de filtrar los movimientos posibles de cada pieza
char Movimiento(string sms, char pieza){
	char mover;
	if(pieza=='P'){
		do{
			cout << sms;
			cin >> mover;
		}while(mover != 'S' && mover != 'B' && mover != 'T' && mover != 'C');
	}
	else{
		do{
			cout << sms;
			cin >> mover;
		}while(mover != 'S' && mover != 'B');
	}
	return mover;
}



int main(){
	const string SMS1="Cambiar pinion o estrella? (P,E): ",SMS2="Cuantas posiciones desea mover?: ";
	int estrella_final,pinion_final;
	char pieza,si_no,mover;
	bool seguir_cambiando=true;
	
	//MENU
	cout << "INSTRUCCIONES:\n";
	cout << " S = subir una posicion.\n";
	cout << " B = bajar una posicion.\n";
	cout << " T = subir dos posiciones.\n";
	cout << " C = bajar dos posiciones.\n";
	cout << " NOTA!!!! T y C solo sirven para piniones\n\n";
	
	//Creamos la instacia de la clase TraccionBicicleta
	TraccionBicicleta bicicleta;
	
	while(seguir_cambiando){
		pieza=PiezaParaMover(SMS1);
		mover=Movimiento(SMS2,pieza);
		bicicleta.Direccion(pieza,mover);
		do{
			cout << "Desea seguir cambiando las marchas? (S/N): ";
			cin >> si_no;
		}while(si_no != 'S' && si_no != 's' && si_no != 'N' && si_no != 'n');
		switch(si_no){
			case 'S':
			case 's':
				seguir_cambiando=true;
			break;
			case 'N':
			case 'n':
				seguir_cambiando=false;
			break;
		}
	}
	cout << "\nLa posicion final de la estrella es la " << bicicleta.GetEstrella() << " y la del pinion es la " << bicicleta.GetPinion();
}
