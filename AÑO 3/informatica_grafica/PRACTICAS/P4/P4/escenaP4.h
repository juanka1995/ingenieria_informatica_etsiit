/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _ESCENAP4_H
#define _ESCENAP4_H

#include "objetoPLY.h"

class EscenaP4{
    private:
        ObjetoPLY esfera, media_esfera, mono;
    public:
        EscenaP4();
        void dibujarSolido();
        void dibujarAjedrez();
        void dibujarAlambre();
        void dibujarPuntos();

        void dibujarSinSuavizado();
        void dibujarConSuavizado();
};

#endif