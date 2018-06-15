/*

Cread un programa que lea los datos fiscales de una persona, reajuste su renta bruta seg�n el criterio que se indica posteriormente 
e imprima su renta neta final.
	- La renta bruta es la cantidad de dinero �ntegra que el trabajador gana.
	- La retenci�n fiscal es el tanto por ciento que el gobierno se queda.
	- La renta neta es la cantidad que le queda al trabajador despu�s de quitarle el porcentaje de retenci�n fiscal, es decir:
		Renta_neta = Renta_bruta - Renta_bruta * Retenci�n final / 100

Los datos a leer son:
	- Si la persona es un trabajador aut�nomo o no
	- Si es pensionista o no
	- Estado civil
	- Renta bruta (total de ingresos obtenidos)
	- Retenci�n inicial a aplicar.

La retenci�n inicial se va a modificar ahora atendiendo al siguiente criterio:
	-Se baja 3 puntos la retenci�n fiscal a los aut�nomos, es decir, si la retenci�n inicial era de un 15 %, por ejemplo, la retenci�n
	 final a aplicar ser� de un 12% (por lo que la renta neta final ser� mayor)
	 
Para los no aut�nomos:
	� Se sube un punto la retenci�n fiscal a todos los pensionistas, es decir, si la retenci�n inicial era de un 13 %, por ejemplo, la 
	retenci�n final a aplicar ser� de un 14% (por lo que la renta neta final ser� menor)
	� Al resto de trabajadores (no aut�nomo y no pensionista) se le aplica a todos una primera subida lineal de dos puntos en la retenci�n inicial.

Una vez hecha esta subida, se le aplica (sobre el resultado anterior) las siguientes subidas adicionales, dependiendo de su estado 
civil y niveles de ingresos:
	- Se sube otros dos puntos la retenci�n fiscal si la renta bruta es menor de 20.000 euros
	- Se sube otros 2.5 puntos la retenci�n fiscal a los casados con renta bruta superior a 20.000 euros
	- Se sube otros tres puntos la retenci�n fiscal a los solteros con renta bruta superior a 20.000 euros

Una vez calculada la retenci�n final, habr� que aplicarla sobre la renta bruta para as� obtener la renta final del trabajador.


*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	char autonomo,pensionista,estado_civil;
	double renta_bruta,renta_neta,retencion;
	
	cout << "CALCULAR TU RENTA: \n\n";
	
	cout << "Actualmente eres autonomo? (S/N): ";
	cin >> autonomo;
	
	if(autonomo=='N' || autonomo=='n'){
		cout << "\nActualmente eres pensionista? (S/N): ";
		cin >> pensionista;
	}
	
	cout << "\nEstado civil: \n   a)Casado/a\n   b)Soltero/a\n";
	cout << "Cual es su estado civil? (a/b): ";
	cin >> estado_civil;
	
	cout << "\nIntroduzca la renta bruta obtenida: ";
	cin >> renta_bruta;
	
	cout << "\nIntroduzca el porcentaje su retencion inicial: ";
	cin >> retencion;
	
	if(autonomo=='S' || autonomo=='s')
		retencion=retencion-3;
	
	else if(pensionista=='S' || pensionista=='s')
		retencion++;
		
	else{
		
		retencion=retencion+2;
		
		if(renta_bruta<20000)
			retencion=retencion+2;
			
		else if(estado_civil=='a' || estado_civil=='A')
			retencion=retencion+2.5;
			
		else
			retencion=retencion+3;
			
	}
	
	renta_neta=renta_bruta-(renta_bruta*retencion/100);
	
	cout << "\nSu renta neta es de: " << renta_neta << " euros.";
	
} 
