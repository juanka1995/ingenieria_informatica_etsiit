/*


Escribid un programa en C++ para que lea tres enteros desde teclado y nos diga si
están ordenados (da igual si es de forma ascendente o descendente) o no lo están.


*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int num1,num2,num3,mayor,menor;
	
	cout << "Introduce los 3 numeros enteros separados por espacio: ";
	cin >> num1;
	cin >> num2;
	cin >> num3;
	
	if(num1>num2 && num2>num3)
		cout << "Los numeros estan ordenados de forma descendente.";

	else if(num3>num2 && num2>num1)
		cout << "Los numeros estan ordenados de forma ascendente";
		
	else
		cout << "Los numeros no estan ordenados";
	
	
}
