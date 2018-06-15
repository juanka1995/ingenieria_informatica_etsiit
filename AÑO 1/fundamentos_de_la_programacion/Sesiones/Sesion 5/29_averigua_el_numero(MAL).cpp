/*

Se pide diseñar un programa para jugar a adivinar un número entre 1 y 100. El juego
tiene que dar pistas de si el número introducido por el jugador está por encima o por
debajo del número introducido. Como reglas de parada se consideran los siguientes
dos casos:
a) se ha acertado b) se decide abandonar el juego (decida cómo quiere especificar
esta opción)

La sentencia srand(time(&tiempo)) debe ejecutarse una única vez
al principio del programa y sirve para inicializar la secuencia de números
aleatorios. Posteriormente, cada vez que se ejecute la sentencia
incognita = (rand() \% NUM\_VALORES) + MIN; se obtendrá un valor
aleatorio (pseudoaleatorio).

*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	
	const int MIN=1,MAX=100;
	const int NUM_VALORES=MAX-MIN+1; // rango
	int incognita,num; // número generado
	bool salida=false;
	time_t tiempo;
	// Inicialización de la secuencia:
	srand(time(&tiempo));
	
	cout << "JUEGO. ADIVINA UN NUMERO ENTRE 1 Y 100";
	
	while(salida==false){
		
		// Generación de un número aleatorio incognita:
		// MIN <= incognita <= MAX
		incognita = (rand() % NUM_VALORES) + MIN;
		
		cout << "\n\nIntroduce un numero (pulsa 0 para salir): ";
		cin >> num;
		//es_valido=num > 0 && num < 100;
		if(num!=0){
		
		while(num!=incognita){
		
			if(num<incognita)
				cout << "\nEl numero que has introducido es MENOR que la incognita";
			else
				cout << "\nEl numero que has introducido es MAYOR que la incognita";
				
			cout << "\nIntroduce otro numero: ";
			cin >> num;
				
		}
		
		cout << "CORRECTO! El numero incognita era el " << incognita;
		cout << "\n JUGUEMOS DE NUEVO: \n";
	
		}
		else
			salida=true;
	}
	
		cout << "\nGracias por haber jugado :D";
	
}
