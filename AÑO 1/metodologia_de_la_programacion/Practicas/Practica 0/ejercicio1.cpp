#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
	Estructura encargada de almacenar un instante de tiempo
*/
struct Ins_Tiempo{

	int horas,minutos,segundos;

};

/*
	Esta funcion se encarga de recibir dos instantes de tiempo y calcular si 
	el segundo instante introducido es posterior al primero.
*/
bool esPosterior(const Ins_Tiempo a, const Ins_Tiempo b){

	bool es_posterior=false;

	if(b.horas>a.horas)
		es_posterior=true;
	else if(b.minutos>a.minutos)
		es_posterior=true;
	else if(b.segundos>a.segundos)
		es_posterior=true;

	return es_posterior;

}

/*
	Esta funcion se encarga de recibir un instante de tiempo y convertirlo a segundos,
	devolviendo dichos segundos como resultado.
*/
int convertirASegundos(const Ins_Tiempo a){

	int total_sec=a.horas*3600 + a.minutos*60 + a.segundos;
	return total_sec;

}

/*
	Esta funcion se encarga de recibir un instante de tiempo y un numero de segundos.
	Su finalidad es generar un nuevo instante de tiempo el cual devolvera como resultado, 
	tras haberle sumado al instante pasado como parametro el numero de segundos.
*/
Ins_Tiempo obtenerNuevoTiempo(const Ins_Tiempo inst_1, int sec){

	Ins_Tiempo inst_sol;
	inst_sol.segundos=(inst_1.segundos+sec)%60;
	inst_sol.minutos=(inst_1.minutos+(inst_1.segundos+sec)/60)%60;
	inst_sol.horas=(inst_1.horas+(inst_1.minutos+(inst_1.segundos+sec)/60)/60)%24;

	return inst_sol;	
	
}


int main(){

	const int SUMA_SEC=6751;
	int hora,min,sec;

	Ins_Tiempo inst1={14,41,7}, inst2={16,21,17}, inst3;

	// Ejemplo de uso de la funcion esPosterior
	if(esPosterior(inst1,inst2))
		cout << "\nEl segundo instante de tiempo ES MAYOR que el primero\n";
	else
		cout << "\nEl segundo instante de tiempo NO ES MAYOR que el primero\n";

	//Ejemplo de uso del a funcion convertirASegundos
	cout << "El numero total de segundos del instante 1 es de: " << convertirASegundos(inst1) << " segundos\n";

	//Ejemplo de uso de la funcion obtenerNuevoTiempo
	inst3=obtenerNuevoTiempo(inst1,SUMA_SEC);
	cout << "La hora tras sumar " << SUMA_SEC << " segundos es: " << inst3.horas << ":" << inst3.minutos << ":" << inst3.segundos << ".\n";

}
