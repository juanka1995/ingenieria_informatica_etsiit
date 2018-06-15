/*

Implemente un programa que sea capaz de “dibujar” pinos utilizando asteriscos “*”. El
usuario ingresara el ancho de la base del pino (podemos asumir que es un número
impar). Supongamos que se ingresa 7, entonces el dibujo tendrá la siguiente forma:

*/

#include <iostream>

using namespace std;

// Funcion para mostrar la base del pino

void Base_pino(int ancho,char simbolo){
	
	/*	Esta funcion se encarga de mostrar la base de nuestro pino la cual calcularemos en base a 
		su anchura de manera proporcionada.
	*/
	
	int negro,blanco,c,c1,c2;
	
	negro=(ancho/2)+1;
	
	if(negro%2==0)
		negro-=1;

	blanco=(ancho-negro)/2;
	
	for(c=0;c<2;c++){			//Muestro el ancho de la base 2 veces
		
		for(c1=1;c1<=blanco;c1++)
			cout << " ";
		
		for(c2=1;c2<=negro;c2++)
			cout << simbolo;	
			
		cout << "\n";
	}
	
	
}


//Funcion para calcular el ancho de nuestro pino

void Copa_pino(int alto,int ancho,char simbolo){
	
	/*	Esta funcion recibe la altura y el ancho del pino. Se encarga de mostrar por pantalla el numero
		de blancos y el numero de * en cada altura de la de la copa de nuestro pino mediante una serie de
		bucles anidados.
		El ancho solo lo necesitaremos para sacar la base de nuestro pino con la llamada a otra funcion.	
	*/
	
	int negro,blanco,c,c1,c2;
	
	cout << "\nAQUI TIENES EL PINO DE " << ancho << " " << simbolo << " DE ANCHO\n\n";
	
	negro=1;				//Inicializo el numero de blancos y de negros en lo alto del pino	
	blanco=alto-negro;						
	
	for(c=1;c<=alto;c++){
		
		for(c1=1;c1<=blanco;c1++)		//Muestro los blancos
			cout << " ";
		
		for(c2=1;c2<=negro;c2++)		//Muestro los *
			cout << simbolo;
		
		cout << "\n";
		negro+=2;					//Calculo el numero de * a mostrar en cada punto
		blanco-=1;					//Calculo el numero de blancos a mostrar en cada punto
		
	}
	
	Base_pino(ancho,simbolo);
	
}

void Altura_pino(){
	
	/*	Esta funcion primero valida que el usuario meta una anchura del pino > 3 e impar y
		posteriormente calcula la altura de nuestro pino gracias a su anchura.	
	*/
	
	int alto,ancho;
	char simbolo;
	
	do{
		
		cout << "Introduce el ancho IMPAR del pino a dibujar (min. 3): ";
		cin >> ancho;
		
	}while(ancho<3 || ancho%2==0);
	
	cout << "Introduce un simbolo: ";
	cin >> simbolo;
	
	alto=(ancho+1)/2;		//Calculo el alto del pino
	
	Copa_pino(alto,ancho,simbolo);
	
}

int main(){
	
	Altura_pino();
	
}
