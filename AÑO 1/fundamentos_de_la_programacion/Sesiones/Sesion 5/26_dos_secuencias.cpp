/*

Realizar un programa que lea dos secuencias de enteros desde teclado y nos diga
si todos los valores de la primera secuencia son mayores que todos los valores de la
segunda secuencia.
Realizad la lectura de los enteros dentro de sendos bucles sobre una única variable
llamada dato. El final de cada secuencia viene marcado cuando se lee el 0.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int dato,menor,contador=0;
	bool es_mayor;
	
	cout << "SECUENCIA 1";													// Recibe la primera secuencia de datos
	cout << "\nIntroduce un numero. (Pulsa 0 para terminar): ";
	cin >> dato;
	menor=dato;
	
	while(dato!=0){
		
		if(dato<menor)
			menor=dato;			// Calcula el menor de los datos de la Secuencia 1
			
		cout << "Introduce otro numero. (Pulsa 0 para terminar): ";
		cin >> dato;
		contador++;	
		
	}
	
	if(contador==0)
		cout << "No has introducido datos en la primera secuencia.";
	else{
		
		contador=0;
		cout << "\nSECUENCIA 2";											// Recibe la segunda secuencia de datos
		cout << "\nIntroduce un numero. (Pulsa 0 para terminar): ";
		cin >> dato;
		
		while(dato!=0){
		
			if(dato>menor)
				es_mayor=1;		//Compara si alguno de los datos introducidos es mayor que el menor de la primera secuencia
				
			cout << "Introduce otro numero. (Pulsa 0 para terminar): ";
			cin >> dato;
			contador++;
		
		}
		
		if(contador==0)
			cout << "No has introducido datos en la segunda secuencia.";
		else{
			
			if(es_mayor)
				cout << "ERROR! Existen datos de la Secuencia 2 mayores que de la Secuencia 1.";
			else
				cout << "CORRECTO. Todos los datos de la Secuencia 1 son mayores que de la Secuencia 2.";
			
		}
		
	}
	
}
