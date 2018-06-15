/*

Este programa leera desde teclado tres variables correspondientes a un n�mero de horas, minutos
y segundos. Calculara las horas, minutos y segundos dentro de su rango correspondiente. Por ejemplo, 
dadas 10 horas, 119 minutos y 280 segundos, deber�a dar como resultado 12 horas, 3 minutos y 40 segundos.
El programa no calcular� meses, a�os, etc sino que se quedar� en los d�as.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int horas,minutos,segundos,dias,resultado_h,resultado_m,resultado_s;
	
	cout << "Introduce el numero de horas: ";
	cin >> horas;
	
	cout << "Introduce el numero de minutos: ";
	cin >> minutos;
	
	cout << "Introduce el numero de segundos: ";
	cin >> segundos;
	
	resultado_s=segundos%60;		// Calcula los segundos totales
	
	resultado_m=(segundos/60)+(minutos%60);		// Calcula los minutos totales
	
	resultado_h=(minutos/60)+(horas%24);		// Calcula las horas totales
	
	dias=horas/24;		//Calcula los dias totales
	
	cout << horas << " horas, " << minutos << " minutos y " << segundos << " segundos equivalen a: " << dias << " dias, " << resultado_h << " horas, " << resultado_m << " minutos y " << resultado_s << " segundos.";
	
}
