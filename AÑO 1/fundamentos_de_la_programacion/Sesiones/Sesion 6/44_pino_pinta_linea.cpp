/*

Implemente un programa que sea capaz de “dibujar” pinos utilizando asteriscos “*”. El
usuario ingresara el ancho de la base del pino (podemos asumir que es un número
impar). Supongamos que se ingresa 7, entonces el dibujo tendrá la siguiente forma:

*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const char BLANCO=' '; 		//Constante global que contiene el caracter espacio.

//Funcion que se encarga de pintar lineas

void Pinta_linea(int n,char simbolo){
	
	/*	Esta funcion recibe un n y un simbolo. Se encargara de mostrar el simbolo n
		veces por pantalla.
	*/
	
	int c;
	
	for(c=1;c<=n;c++)
		cout << simbolo;
	
}


// Funcion para mostrar la base del pino

void Base_pino(int ancho,char simbolo){
	
	/*	Esta funcion se encarga de mostrar la base de nuestro pino a traves de la funcion Pinta_linea
		la cual calcularemos en base a su anchura de manera proporcionada.
	*/
	
	int n_negro,n_blanco,c,c1,c2;
	
	n_negro=(ancho/2)+1;
	
	if(n_negro%2==0)
		n_negro-=1;

	n_blanco=(ancho-n_negro)/2;
	
	for(c=0;c<2;c++){			//Muestro el ancho de la base 2 veces
		
		Pinta_linea(n_blanco,BLANCO);

		Pinta_linea(n_negro,simbolo);	
			
		cout << "\n";
	}
	
	
}


//Funcion para calcular el ancho de nuestro pino

void Copa_pino(int alto,int ancho,char simbolo){
	
	/*	Esta funcion recibe la altura y el ancho del pino. Se encarga de mostrar por pantalla el numero
		de blancos y el numero de simbolos mediante el uso de la funcion Pinta_linea.
		El ancho solo lo necesitaremos para sacar la base de nuestro pino con la llamada a otra funcion.	
	*/
	
	int n_negro,n_blanco,c,c1,c2;
		
	n_negro=1;				//Inicializo el numero de blancos y de negros en lo alto del pino	
	n_blanco=alto-n_negro;						
	
	for(c=1;c<=alto;c++){
		
		Pinta_linea(n_blanco,BLANCO);
		
		Pinta_linea(n_negro,simbolo);
		
		cout << "\n";
		n_negro+=2;					//Calculo el numero de * a mostrar en cada punto
		n_blanco-=1;					//Calculo el numero de blancos a mostrar en cada punto
		
	}
	
	Base_pino(ancho,simbolo);
	
}

//Funcion que calcula la altura del pino

int Altura_pino(int ancho){
	
	/*	Esta funcion recibe el ancho del pino y seguidamente calcula la altura de la copa
		de nuestro pino para devolverla.	
	*/
	
	int alto;
	
	alto=(ancho+1)/2;		//Calculo del alto del pino
	
	return alto;
	
}

// Funcion que pide los datos al usuario

int Leer_datos(string mensaje){
	
	/*	Esta funcion recibe un mensaje que es el que muestra al usuario para que 
		introduzca los datos necesarios para la resolucion del ejercicio. Devuelve
		el dato introducido por el usuario.
	*/
	
	int ancho;
	
	do{
		
		cout << mensaje;
		cin >> ancho;
			
	}while(ancho<3 || ancho%2==0);
	
	return ancho;
	
}

int main(){
	
	const string MENSAJE="Introduce el ancho IMPAR del pino a dibujar (min. 3): ";
	int alto,ancho;
	char simbolo;
	
	ancho=Leer_datos(MENSAJE);
	
	cout << "Introduce un simbolo: ";
	cin >> simbolo;
	
	alto=Altura_pino(ancho);
	
	cout << "\nAQUI TIENES EL PINO DE " << ancho << " " << simbolo << " DE ANCHO\n\n";
	Copa_pino(alto,ancho,simbolo);
	
}
