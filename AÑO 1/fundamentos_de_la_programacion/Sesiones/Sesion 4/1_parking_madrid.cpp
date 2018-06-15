/*

La tabla para el cálculo del precio a pagar en los parkings de Madrid para el 2015 es
la siguiente:
	Desde el minuto 0 al 30: 0.0412 euros cada minuto
	Desde el minuto 31 al 90: 0.0370 euros cada minuto
	Desde el minuto 91 al 660: 0.0493 euros cada minuto
	Desde el minuto 661 hasta máximo 24 horas: 31.55 euros
Dado un tiempo de entrada y un tiempo de salida, construya un programa que calcule
la tarifa final en euros a cobrar. Ejemplo: si el tiempo de permanencia es de 32 minutos,
los primeros 30 minutos se facturan a 0.0412 el minuto y los 2 restantes a 0.0370.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	const double TAR_0_30=30*0.0412,TAR_31_90=60*0.370,TAR_91_660=570*0.0493; //Valores totales de cada tramo horario dependiendo de su precio.
	int hora_inicial,min_inicial,hora_final,min_final,minutos,calculo;
	double tarifa_f,tarifa31,tarifa91,tarifa661;
	
	cout << "Introduce la hora de entrada al parking (HH MM): ";
	cin >> hora_inicial;
	cin >> min_inicial;
	
	cout << "Introduce la hora de salida del parking (HH MM): ";
	cin >> hora_final;
	cin >> min_final;
	
	minutos=((hora_final*60)+min_final)-((hora_inicial*60)+min_inicial);		//Calcula los minutos entre dos tramos horarios.
	
	if(minutos == 0){
		
		tarifa_f=0.0412;
		
	}
	else if(minutos<=30){
		
		tarifa_f=minutos*0.0412;
		
	}
	else if(minutos<=90){
	
		calculo=minutos-30;
		tarifa31=calculo*0.0370;
		tarifa_f=tarifa31+TAR_0_30;
	
	}
	else if(minutos<=660){
	
		calculo=minutos-90;
		tarifa91=calculo*0.0493;
		tarifa_f=tarifa91+TAR_31_90+TAR_0_30;
	
	}
	else if(minutos<=1440){		//1440 minutos == 24 horas
	
		calculo=minutos-660;
		tarifa661=calculo*31.55;
		tarifa_f=tarifa661+TAR_31_90+TAR_0_30+TAR_91_660;
	
	}
	
		cout << "\nTu coche ha pasado " << minutos << " minutos en el parking.\n\nEl precio final de la tarifa es de : " << tarifa_f << "€";
	
}
