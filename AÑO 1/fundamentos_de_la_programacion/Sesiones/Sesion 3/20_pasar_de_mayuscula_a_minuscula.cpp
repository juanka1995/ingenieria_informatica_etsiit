/*

Diseñar un programa que lea un carácter (supondremos que el usuario introduce una
mayúscula), lo pase a minúscula y lo imprima en pantalla. Hacedlo sin usar las funciones
toupper ni tolower de la biblioteca cctype. Para ello, debe considerarse
la equivalencia en C++ entre los tipos enteros y caracteres.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	const int NUM_ASCII=32;		//Diferencia entre mayusculas y minusculas segun la tabla ASCII.
	char letra_may,letra_min;
	
	cout << "Introduce una letra mayuscula: ";
	cin >> letra_may;
	
	letra_min=letra_may+NUM_ASCII;
	
	cout << "La letra " << letra_may << " en minuscula es: " << letra_min;
	
}
