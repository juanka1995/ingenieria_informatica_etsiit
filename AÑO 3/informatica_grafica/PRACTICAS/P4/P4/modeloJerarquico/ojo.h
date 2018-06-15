/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _OJO_H
#define _OJO_H

#include "../objetoPLY.h"

class Ojo{
private:
    ObjetoPLY esclera;
    ObjetoPLY pupila;
public:
    Ojo();
    void dibujarSolido();
    void dibujarAjedrez();
    void dibujarAlambre();
    void dibujarPuntos();
    void dibujarSinSuavizado();
    void dibujarConSuavizado();
};

#endif
