#include <iostream>
#include <cmath> 
#include "punto.h"
using namespace std;

void EscribirPunto(const Punto &p)
{
	cout << "(" << p.x << "," << p.y << ")";
}

Punto LeerPunto()
{
	Punto punto_aux;
	char basura;
	cin >> basura >> punto_aux.x >> basura >> punto_aux.y >> basura;
	return punto_aux;
}

double DistanciaPuntos(const Punto &p1, const Punto &p2)
{
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

Punto PuntoMedio(const Punto &p1, const Punto &p2)
{
	Punto punto_aux;
	punto_aux.x=(p1.x+p2.x)/2;
	punto_aux.y=(p1.y+p2.y)/2;
	return punto_aux;
}
