#ifndef _CIRCULO_H_
#define _CIRCULO_H_

#include "punto.h"

struct Circulo {
    Punto centro; 
    double radio; 
};

void EscribirCirculo(const Circulo &c); 
Circulo LeerCirculo(); 
double AreaCirculo(const Circulo &c);

#endif
