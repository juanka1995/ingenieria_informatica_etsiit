/*

A un trabajador le pagan según sus horas trabajadas y la tarifa está a un valor por
hora. Si la cantidad de horas trabajadas es mayor de 40 horas, la tarifa por hora se
incrementa en un 50% para las horas extras (las que haya por encima de 40). Construir
una función que dado el número total de horas trabajadas y el precio por hora,
devuelva el salario del trabajador.

*/

#include <iostream>
#include <cmath>

using namespace std;

// Funcion para calcular el salario de un trabajador

int Calcular_Salario(int horas, int tarifa){

	/* Esta funcion recibe n horas y x tarifa y calcula un salario dependiendo del numero
	   de horas. Solo en el caso de que las horas sean mas de 40, la tarifa se incrementara 
	   un 50%.
	*/

	const int TOPE_H=40;	
	int salario,aux;
	
	if(horas>TOPE_H){
		
		salario=TOPE_H*tarifa;
		aux=horas-TOPE_H;
		tarifa=tarifa*1.5;
		salario=salario+(aux*tarifa);
		
	}
	else
		salario=horas*tarifa;
	
	return salario;
	
}

int main(){
	
	int horas;
	double tarifa,salario_final;
	
	cout << "Introduce el numero de horas trabajadas: ";
	cin >> horas;
	
	cout << "Introduce el precio de la tarifa por hora: ";
	cin >> tarifa;
	
	salario_final=Calcular_Salario(horas,tarifa);
		
	cout << "\nEl salario del trabajador tras " << horas << " horas de trabajo es de: " << salario_final;
	
	
	
	
}
