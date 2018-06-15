/*

Modifiquemos el ejercicio 6 del capital y los intereses de la primera relación. Supongamos
ahora que se quiere reinvertir todo el dinero obtenido (el original C más los
intereses producidos) en otro plazo fijo a un año y así, sucesivamente. Construid un
programa para que lea el capital, el interés y un número de años N, y calcule e imprima
todo el dinero obtenido durante cada uno de los N años, suponiendo que todo
lo ganado (incluido el capital original C) se reinvierte a plazo fijo durante el siguiente
año. El programa debe mostrar una salida del tipo:

	Total en el año número 1 = 240
	Total en el año número 2 = 288
	Total en el año número 3 = 345.6

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	double capital,interes;
	int anios,c;
	
	cout << "Introduce el capital en euros: ";
	cin >> capital;
	
	cout << "Introduce el tanto por ciento de interes: ";
	cin >> interes;
	
	cout << "Introduce el numero de anios que pasaran: ";
	cin >> anios;
	
	for(c=1;c<=anios;c++){
		
		capital=capital+capital*interes/100;
		cout << "\nTotal en el anio numero " << c << " = " << capital;
		
	}
	
}
