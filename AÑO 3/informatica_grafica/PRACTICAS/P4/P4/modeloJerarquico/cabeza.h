/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _CABEZA_H
#define _CABEZA_H

#include "../objetoPLY.h"
#include "ojo.h"

class Cabeza{
private:
    ObjetoPLY cuello;
    ObjetoPLY boca;
    ObjetoPLY cara;
    ObjetoPLY oreja;
    Ojo ojo;
    ObjetoPLY nariz;
    ObjetoPLY pelo;

    GLfloat velocidadGlobal;
    
    GLfloat grCabeza;
    GLfloat maxMovDerechaCabeza,maxMovIzquierdaCabeza;
public:
public:
    Cabeza();
    void dibujarSolido();
    void dibujarAjedrez();
    void dibujarPuntos();
    void dibujarAlambre();
    void dibujarSinSuavizado();
    void dibujarConSuavizado();
    void moverCabezaDerecha();
    void moverCabezaIzquierda();
    void incrementarVelocidadGlobal(GLfloat velocidadGlobalSup);
    void decrementarVelocidadGlobal(GLfloat velocidadGlobalSup);
    void reset();
};

#endif
