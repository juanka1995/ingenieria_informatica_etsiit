/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _PIERNA_H
#define _PIERNA_H

#include "../objetoPLY.h"
#include "zapatilla.h"

class Pierna{
private:
    Zapatilla zapatilla;
    ObjetoPLY tobillo;
    ObjetoPLY gemelo;
    ObjetoPLY rodilla;
    ObjetoPLY pantalon;

    GLfloat velocidadGlobal;
    // Marca la velocidad de movimiento de los grados de libertad de la pierna
    GLfloat velocidadPierna;

    GLfloat grCadera, grRodilla, grTobillo;
    GLfloat maxMovDelanteCadera, maxMovDelanteRodilla, maxMovArribaTobillo;
    GLfloat maxMovDetrasCadera, maxMovDetrasRodilla, maxMovAbajoTobillo;
public:
    Pierna();
    void dibujarSolido();
    void dibujarAlambre();
    void dibujarPuntos();
    void dibujarAjedrez();
    void moverTobilloAbajo();
    void moverTobilloArriba();
    void moverRodillaDetras();
    void moverRodillaDelante();
    void moverCaderaDelante();
    void moverCaderaDetras();
    void setGrCadera(GLfloat nuevosGRCadera);
    bool getTopeDetrasCaderaAlcanzado() const;
    bool getTopeDelanteCaderaAlcanzado() const;
    void incrementarVelocidadGlobal(GLfloat velocidadGlobalSup);
    void decrementarVelocidadGlobal(GLfloat velocidadGlobalSup);
    bool incrementarVelocidadPierna();
    bool decrementarVelocidadPierna(); 
    void reset();
};

#endif
