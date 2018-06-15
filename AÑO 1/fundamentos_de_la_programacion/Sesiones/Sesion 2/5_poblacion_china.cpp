/*
	Programa para que mostrar� la poblacion de China dentro de x a�os,
	partiendo de que la poblaci�n actual ser� lo que el usuario introduzca.
	
	Datos estimados:
		- nace una persona cada 1.87 segundos
		- muere una persona cada 3.27 segundos
		- emigra una personada cada 71.9 segundos
*/

#include <iostream>		// Inclusion de los recursos de E/S
#include <cmath>		// Inclusi�n de los recursos matem�ticos

using namespace std;

int main(){
	
	const double NACE=1.87,MUERE=3.27,EMIGRA=71.9;		// Declara cada cuantos segundos nace, muere o emigra una persona en China
	int poblacion_china,futura_poblacion;					
	int anios, seg_anios;																		
	int n_nacidos,n_muertos,n_emigrados;
	
	cout << "Introduce la poblacion actual de China: ";
	cin >> poblacion_china;
	
	cout << "Introduce los anios que quieres que pasen: ";
	cin >> anios;
	
	seg_anios=anios*365*24*60*60; 	//Calcula el numero de segundos que son X a�os.
	
	n_nacidos=seg_anios/NACE;			//Calcula el numero de gente que nace
	n_muertos=seg_anios/MUERE;			//Calcula el numero de gente que muere
	n_emigrados=seg_anios/EMIGRA;		//Calcula el numero de gente que emigra
	
	futura_poblacion=poblacion_china+n_nacidos-n_muertos-n_emigrados;		//Calcula la futura poblacion despues de X a�os
	

	cout << "La poblacion de China dentro de " << anios << " anios sera de: " << futura_poblacion;																								
}
