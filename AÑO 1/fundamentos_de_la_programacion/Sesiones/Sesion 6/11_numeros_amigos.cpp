/*

Dos números amigos son dos números naturales a y b,
tales que la suma de los divisores propios de a más uno es igual a b, y viceversa. Un
ejemplo de números amigos es el par de naturales (220; 284), ya que:
Los divisores propios de 220 son 2, 4, 5, 10, 11, 20, 22, 44, 55 y 110, que suman
283, y 283 + 1 = 284.
Los divisores propios de 284 son 2, 4, 71 y 142, que suman 219, y 219 + 1 = 220.

Realice un programa que implemente estas dos tareas:
a) En primer lugar debe leer dos números naturales e indicar si son o no amigos.

*/

#include <iostream>
#include <cmath>

using namespace std;

//Funcion que calcula la suma de los divisores de un numero

int Suma_divisores(int numero){				
	
	/*  Esta funcion recibe un numero y mediante un bucle calcula sus divisores,
		los cuales suma y devuelve dicho valor para posteriormente comprobar si un
		numero es amigo de otro.
	*/
	
	int suma=0,c;
	
	for(c=2;c<=(numero/2);c++){
		
		if(numero%c==0)
			suma=suma+c;
		
	}
	
	return suma;
	
}

int main(){
	
	const int UNO=1;
	int num1,num2,sum_div1,sum_div2;
	
	cout << "NUMEROS AMIGOS\n\n";
	cout << "Introduce dos numeros (Ej. 14 128): ";
	cin >> num1;
	cin >> num2;
	
	sum_div1=Suma_divisores(num1);
	sum_div2=Suma_divisores(num2);
	
	if(sum_div1+UNO==num2 && sum_div2+UNO==num1)
		cout << "BIEN. Los numeros " << num1 << " y " << num2 << " SI son amigos";
	else
		cout << "LO SIENTO. Los numeros " << num1 << " y " << num2 << " NO son amigos";
	
}
