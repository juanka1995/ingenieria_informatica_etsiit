/*

Implemente un programa que sea capaz de “dibujar” pinos utilizando asteriscos “*”. El
usuario ingresara el ancho de la base del pino (podemos asumir que es un número
impar). Supongamos que se ingresa 7, entonces el dibujo tendrá la siguiente forma:

*/

#include <iostream>

using namespace std;


int main(){
	
	int ancho,alto,negro,blanco,c,c1,c2;
	
	do{
		
		cout << "Introduce el ancho IMPAR del pino a dibujar (min. 3): ";
		cin >> ancho;
		
	}while(ancho<3 || ancho%2==0);
	
	alto=(ancho+1)/2;		//Calculo el alto del pino
	
	cout << "\nAQUI TIENES EL PINO DE " << ancho << " * DE ANCHO\n\n";
	
	
	negro=1;				//Inicializo el numero de blancos y de negros en lo alto del pino	
	blanco=alto-negro;						
	
	for(c=1;c<=alto;c++){
		
		for(c1=1;c1<=blanco;c1++)		//Muestro los blancos
			cout << " ";
		
		for(c2=1;c2<=negro;c2++)
			cout << "*";
		
		cout << "\n";
		negro+=2;					//Calculo el numero de * a mostrar en cada punto
		blanco-=1;					//Calculo el numero de blancos a mostrar en cada punto
		
	}
	
	negro=(ancho/2)+1;
	
	if(negro%2==0)
		negro-=1;

	blanco=(ancho-negro)/2;
	
	for(c=0;c<2;c++){			//Muestro el ancho de la base 2 veces
		
		for(c1=1;c1<=blanco;c1++)
			cout << " ";
		
		for(c2=1;c2<=negro;c2++)
			cout << "*";	
			
		cout << "\n";
	}
	
}
