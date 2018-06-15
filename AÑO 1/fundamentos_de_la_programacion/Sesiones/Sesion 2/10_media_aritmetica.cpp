/*

	Este programa recogera la altura de 3 personas y
	calculará la media y la desviacion tipica de dichas
	personas.

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
	
	cout << "La media de " << altura_1 << " + " << altura_2 << " + " << altura_3 << " es de: " << media << " metros, y su desviacion tipica es de : " << desv_tipica;
	
}
