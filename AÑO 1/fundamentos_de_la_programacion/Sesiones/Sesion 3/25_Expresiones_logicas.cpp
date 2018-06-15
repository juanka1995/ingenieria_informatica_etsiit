/*

- Escribid una expresi�n l�gica que sea verdadera si una variable de tipo car�cter llamada
letra es una letra min�scula y falso en otro caso.

		letra >='a' && letra <='z'

- Escribid una expresi�n l�gica que sea verdadera si una variable de tipo entero llamada
edad es menor de 18 o mayor de 65.
	
		edad < 18 || edad > 65
	
- Escribid una expresi�n l�gica que nos informe cuando un a�o es bisiesto. Los a�os
bisiestos son aquellos que o bien son divisibles por 4 pero no por 100, o bien son
divisibles por 400.

		(anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0

- Escribid un programa que lea las variables letra, edad y anio, calcule el valor de
las expresiones l�gicas anteriores e imprima el resultado. Tened en cuenta que cuando
se imprime por pantalla (con cout) una expresi�n l�gica que es true, se imprime 1. Si
es false, se imprime un 0. En el tema 2 veremos la raz�n.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	char letra;
	int edad,anio,r_edad,r_anio,r_letra;
	
	cout << "Introduce la letra: ";
	cin >> letra;
	r_letra=letra >='a' && letra <='z' ; //Si la letra es minuscula mostrara 1 (TRUE), en caso contrario 0 (FALSE).

	cout << "Introduce la edad: ";
	cin >> edad;
	r_edad=edad < 18 || edad > 65;	//Si es < 18 o > 65 mostrara 1 (TRUE), en caso contrario 0(FALSE).
	
	cout << "Introduce el anio bisiesto: ";
	cin >> anio;
	r_anio=(anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0; //Si es bisiesto mostrara 1(TRUE), en caso contrario 0(FALSE).
	
	cout << "El resultado de la expresion logica de la letra es: " << r_letra;
	
	cout << "\nEl resultado de la expresion logica de la edad es: " << r_edad;
	
	cout << "\nEl resultado de la expresion logica del anio es: " << r_anio;
	
	
}
