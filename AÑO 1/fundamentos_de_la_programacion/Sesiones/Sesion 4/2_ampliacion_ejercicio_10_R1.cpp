/*

	Ampliad el ejercicio 10 de la relación de problemas I, para que, una vez calculada la
	media y la desviación, el programa imprima por cada uno de los valores introducidos
	previamente, si está por encima o por debajo de la media.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	const double N=3;
	double altura_1,altura_2,altura_3,media,desviacion_1,desviacion_2,desviacion_3,desv_tipica;

	cout << "Introduce la altura de la primera persona: ";
	cin >> altura_1;
	
	cout << "Introduce la altura de la segunda persona: ";
	cin >> altura_2;
	
	cout << "Introduce la altura de la tercera persona: ";
	cin >> altura_3;
	
	media=(altura_1+altura_2+altura_3)/N;		//Formula de la media
	
	desviacion_1=pow(altura_1 - media,2);
	desviacion_2=pow(altura_2 - media,2);
	desviacion_3=pow(altura_3 - media,2);
	
	desv_tipica=sqrt(1/N * (desviacion_1+desviacion_2+desviacion_3));		//Formula de la desviación tipica.
			
	cout << "\nLa media de " << altura_1 << " + " << altura_2 << " + " << altura_3 << " es de: " << media << " metros.\nY su desviacion tipica es de : " << desv_tipica;
	
	if(altura_1>=media)
		cout << "\n\nLa primera altura es de: "<< altura_1 << ", y es mayor o igual que la media";
	else
		cout << "\nLa primera altura es de: "<< altura_1 << ", y es menor que la media";
		
	if(altura_2>=media)
		cout << "\nLa segunda altura es de: "<< altura_2 << ", y es mayor o igual que la media";
	else
		cout << "\nLa segunda altura es de: "<< altura_2 << ", y es menor que la media";
		
	if(altura_3>=media)
		cout << "\nLa tercera altura es de: "<< altura_3 << ", y es mayor o igual que la media";
	else
		cout << "\nLa tercera altura es de: "<< altura_3 << ", y es menor que la media";	
	
}
