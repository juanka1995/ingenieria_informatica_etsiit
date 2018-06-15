/*

Un banco presenta la siguiente oferta. Si se deposita una cantidad de euros capital
durante un a�o a plazo fijo, se dar� un inter�s dado por la variable interes. Realizad
un programa que lea una cantidad capital y un inter�s interes desde teclado y
calcule en una variable total el dinero que se tendr� al cabo de un a�o, aplicando la
f�rmula:

		total = capital + capital * (interes/100)

Tanto el capital como el inter�s ser�n valores reales. Supondremos que el usuario
introduce el inter�s como un valor real entre 0 y 100, es decir, un inter�s del 5;4%
se introducir� como 5.4. Tambi�n supondremos que lo introduce correctamente, es
decir, que s�lo introducir� valores entre 0 y 100.
Supongamos que queremos modificar la variable original capital con el nuevo valor
de total. �Es posible hacerlo directamente en la expresi�n de arriba?

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	double total,capital,interes;
	
	cout << "Introduce el capital en euros: ";
	cin >> capital;
	
	cout << "Introduce el tanto por ciento de interes: ";
	cin >> interes;
	
	total=capital+capital*(interes/100);
	
	cout << "Al cabo de un anio el dinero total seria de: " << total << " euros.";
	
}
