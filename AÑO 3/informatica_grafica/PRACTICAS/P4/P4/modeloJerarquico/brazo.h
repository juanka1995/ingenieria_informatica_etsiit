/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _BRAZO_H
#define _BRAZO_H

#include "../objetoPLY.h"

class Brazo{
private:
    ObjetoPLY antebrazo_mano;
    ObjetoPLY codo;
    ObjetoPLY hombro;

    GLfloat velocidadGlobal;
    GLfloat velocidadHombro;

    GLfloat grHombro, grCodo;
    GLfloat maxMovAbajoCodo, maxMovArribaCodo;
    GLfloat maxMovAbajoHombro, maxMovArribaHombro;
public:
    Brazo();
    void dibujarSolido();
    void dibujarPuntos();
    void dibujarAlambre();
    void dibujarAjedrez();
    void dibujarSinSuavizado();
    void dibujarConSuavizado();
    void moverHombroArriba();
    void moverHombroAbajo();
    void moverCodoArriba();
    void moverCodoAbajo();
    void setGradosHombro(GLfloat gradosHombro);
    void incrementarVelocidadGlobal(GLfloat velocidadGlobalSup);
    void decrementarVelocidadGlobal(GLfloat velocidadGlobalSup);
    bool incrementarVelocidadHombro();
    bool decrementarVelocidadHombro(); 
    void reset();
};

#endif