/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _ZAPATILLA_H
#define _ZAPATILLA_H

#include "../objetoPLY.h"

class Zapatilla{
private:
    ObjetoPLY base_zapatilla;
    ObjetoPLY empeine;
public:
    Zapatilla();
    void dibujarSolido();
    void dibujarPuntos();
    void dibujarAjedrez();
    void dibujarAlambre();
    void dibujarSinSuavizado();
    void dibujarConSuavizado();
};

#endif