/*


Cread un programa que lea el valor de la edad (dato de tipo entero) y salario (dato de
tipo real) de una persona. Subid el salario un 5% si éste es menor de 300 euros y la
persona es mayor de 65 años.
¿Es mejor incluir otra variable nueva salario_final o es mejor modificar la variable
que teníamos?
Imprimid el resultado por pantalla. En caso contrario imprimid el mensaje
"No es aplicable la subida". En ambos casos imprimid el salario resultante.


*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int edad;
	double salario,salario_final;	
	
	cout << "Introduce la edad de la persona: ";
	cin >> edad;
	
	cout << "Introduce el salario de dicha persona: ";
	cin >> salario;
	
	if(edad > 65 && salario < 300){
	
		salario_final=salario+(salario*5/100);
		cout << "Se te aumenta un 5% el salario. Ahora es de: " << salario_final;
	
	}	
		
	else
		cout << "No es aplicable la subida.";
	
}
