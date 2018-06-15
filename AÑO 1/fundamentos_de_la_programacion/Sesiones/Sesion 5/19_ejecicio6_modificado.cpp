/*

Modifiquemos el ejercicio 6 del capital y los intereses de la primera relaci�n. Supongamos
ahora que se quiere reinvertir todo el dinero obtenido (el original C m�s los
intereses producidos) en otro plazo fijo a un a�o y as�, sucesivamente. Construid un
programa para que lea el capital, el inter�s y un n�mero de a�os N, y calcule e imprima
todo el dinero obtenido durante cada uno de los N a�os, suponiendo que todo
lo ganado (incluido el capital original C) se reinvierte a plazo fijo durante el siguiente
a�o. El programa debe mostrar una salida del tipo:

	Total en el a�o n�mero 1 = 240
	Total en el a�o n�mero 2 = 288
	Total en el a�o n�mero 3 = 345.6

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
