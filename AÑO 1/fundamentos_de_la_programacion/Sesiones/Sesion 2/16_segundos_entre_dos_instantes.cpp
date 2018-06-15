/*

	Este programa calcular� el n�mero de segundos que hay entre dos instantes del mismo d�a.
	
	Cada instante se caracteriza por la hora (entre 0 y 23), minuto (entre 0 y 59) y segundo
	(entre 0 y 59).

	El programa leer� la hora, minuto y segundo del instante inicial, y la hora, minuto y
	segundo del instante final (supondremos que los valores introducidos son correctos) y
	mostrar� el n�mero de segundos entre ambos instantes.

*/

#include <iostream>		// Inclusion de los recursos de E/S
#include <cmath>		// Inclusi�n de los recursos matem�ticos

using namespace std;

int main(){
	
	int hora_1,min_1,seg_1,hora_2,min_2,seg_2;		//Declara las variables necesarias para definir dos tramos horarios (Horas, minutos, segundos)
	int seg_inicial, seg_final;							//Declara las variables que guardaran los segundos de cada tramo horario
	int intervalo_seg;
	
	cout << "Introduce el primer tramo horario (HH MM SS): ";
	cin >> hora_1;
	cin >> min_1;
	cin >> seg_1;
	
	cout << "Introduce el ultimo tramo horario (HH MM SS): ";
	cin >> hora_2;
	cin >> min_2;
	cin >> seg_2;
	
	seg_inicial=(hora_1*60*60)+(min_1*60)+seg_1;		//Calcula los segundos totales del primer tramo horario introducido
	
	seg_final=(hora_2*60*60)+(min_2*60)+seg_2;		//Calcula los segundos totales del ultimo tramo horario introducido
	
	intervalo_seg=seg_final-seg_inicial;			//Calcula el intervalo de segundos entre la 1� hora y la 2�
	
	cout << "Los segundos transcurridos entre las " << hora_1 << ":" << min_1 << ":" << seg_1 << " y las " << hora_2 << ":" << min_2 << ":" << seg_2 << " es de: " << intervalo_seg << " segundos.";
}
