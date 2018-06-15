/*

Un banco presenta la siguiente oferta. Si se deposita una cantidad de euros capital
durante un año a plazo fijo, se dará un interés dado por la variable interes. Realizad
un programa que lea una cantidad capital y un interés interes desde teclado y
calcule en una variable total el dinero que se tendrá al cabo de un año, aplicando la
fórmula:

		total = capital + capital * (interes/100)

Tanto el capital como el interés serán valores reales. Supondremos que el usuario
introduce el interés como un valor real entre 0 y 100, es decir, un interés del 5;4%
se introducirá como 5.4. También supondremos que lo introduce correctamente, es
decir, que sólo introducirá valores entre 0 y 100.
Supongamos que queremos modificar la variable original capital con el nuevo valor
de total. ¿Es posible hacerlo directamente en la expresión de arriba?

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
