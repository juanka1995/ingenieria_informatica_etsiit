/*

Implemente un programa que sea capaz de “dibujar” rectángulos utilizando un símbolo
(un carácter) dado. El usuario ingresará el símbolo simb, la altura M y el ancho N
del rectángulo. Por ejemplo, siendo simb =*, M = 3 y N = 5, el dibujo tendría la
siguiente forma:

		*****
		*****
		*****

*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Funcion que pinta lineas

void Pinta_linea(int n,char simbolo){
	
	/*	Esta funcion recibe dos variables, n y simbolo y muestra n veces el caracter simbolo
		por pantalla.	
	*/
	
	int c;
	
	for(c=1;c<=n;c++)
		cout << simbolo;
		
}

// Funcion que pinta el cuadrado

void Pintar_cuadrado(int ancho,int altura,char simbolo){
	
	/*	Esta funcion recibe el ancho, la altura y el simbolo introducidos previamente por
		el usuario y muestra el cuadrado en relacion a dichos datos.	
	*/
	
	int c1,c2;
	
	cout << "\n";
	
	for(c1=1;c1<=altura;c1++){		//Bucle para las columnas
				
		cout << "\t";		
				
		Pinta_linea(ancho,simbolo);
		
		cout << "\n";
		
	}
	
}

// Funcion que devuelve el simbolo introducido

char Leer_simbolo(string SIMBOLO){
	
	/*	Le pasamos la constante SIMBOLO con el mensaje a mostrar para que el
		usuario lo introduzca. Seguidamente devuelve el simbolo introducido.	
	*/
	
	char simbolo;
	cout << SIMBOLO;
	cin >> simbolo;
	
	return simbolo;
	
}

// Funcion que devuelve el ANCHO y la ALTURA del cuadrado.

int Leer_dimensiones(string MENSAJE){
	
	/*	Le pasamos la constante MENSAJE con el mensaje a mostrar para que el
		usuario introduzca el ANCHO y la ALTURA del cuadrado. Seguidamente 
		devuelve el simbolo introducido.
	*/
	
	int opcion;
	cout << MENSAJE;
	cin >> opcion;
	
	return opcion;
	
}

int main(){
	
	const string ALTO="Introduce la altura del cuadrado: ",ANCHO="Introduce el ancho del cuadrado: ",SIMBOLO="Introduce un simbolo: ";
	int ancho,alto;
	char simbolo;
	
	ancho=Leer_dimensiones(ANCHO);		
	alto=Leer_dimensiones(ALTO);
	simbolo=Leer_simbolo(SIMBOLO);
	
	Pintar_cuadrado(ancho,alto,simbolo);
	
}
