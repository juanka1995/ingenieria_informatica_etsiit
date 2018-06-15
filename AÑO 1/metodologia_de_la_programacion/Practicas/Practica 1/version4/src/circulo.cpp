#include <iostream>
#include <cmath> 
#include "punto.h"
#include "circulo.h"
using namespace std;

void EscribirCirculo(const Circulo &p)
{
	cout << p.radio << "-";
	EscribirPunto(p.centro);
}

Circulo LeerCirculo()
{
	Circulo c_aux;
	char basura;
	
	cin >> c_aux.radio >> basura;
	Punto punto_aux=LeerPunto();
	c_aux.centro.x=punto_aux.x;
	c_aux.centro.y=punto_aux.y;

	return c_aux;

}

double AreaCirculo(const Circulo &c)
{
	double area=M_PI*pow(c.radio,2);
	return area;
}
