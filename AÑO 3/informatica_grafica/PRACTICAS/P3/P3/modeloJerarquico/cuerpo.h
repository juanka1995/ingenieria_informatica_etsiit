/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _CUERPO_H
#define _CUERPO_H

#include "../objetoPLY.h"

class Cuerpo{
private:
    ObjetoPLY pecho;
    ObjetoPLY barriga;
    ObjetoPLY cadera;
    ObjetoPLY clavicula;

public:
    Cuerpo();
    void dibujarSolido();
    void dibujarAjedrez();
    void dibujarAlambre();
    void dibujarPuntos();
};

#endif