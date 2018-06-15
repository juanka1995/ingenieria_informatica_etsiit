/*

Programa que declare las variables x, y y z, les asigne los valores 10, 20
y 30 e intercambien entre sí sus valores de forma que el valor de x pasa a y, el de y
pasa a z y el valor de z pasa a x (se pueden declarar variables auxiliares aunque se
pide que se use el menor número posible).

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int x=10,y=20,z=30,aux;
	
	cout << "La variable x=" << x << ", y=" << y << " y z=" << z;
	
	aux=y; 	//aux=20
	y=x;		//y=10;
	x=z;		//x=30
	z=aux;	//z=20
	
	cout << "\n\nAhora la variable x=" << x << ", y=" << y << " y z=" << z;	
	
}
