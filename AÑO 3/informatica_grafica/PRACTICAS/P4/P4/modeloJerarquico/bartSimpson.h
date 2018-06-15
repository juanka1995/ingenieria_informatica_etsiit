/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _BARTSIMPSON_H
#define _BARTSIMPSON_H

#include "pierna.h"
#include "cabeza.h"
#include "brazo.h"
#include "cuerpo.h"

class BartSimpson{
    private:
        GLfloat grCadera;
        
        GLfloat maxMovArribaCadera, maxMovAbajoCadera;

        GLfloat rotarBartEnY;

        GLfloat trasladarBart, topeTraslacionDerecha, topeTraslacionIzquierda;

        // Marca la velocidad de movimiento de todos los grados de libertad
        GLfloat velocidadGlobal;

        // Marca la velocidad de movimiento de los grados de libertad de la cadera
        GLfloat velocidadCadera;

        // True indica que el movimiento a realizar es hacia delante y false hacia atras
        bool movPiernaDerDelante, movPiernaIzqDelante;

        // True indica que bart se movera hacia la derecha o hacia la izquierda
        bool movBartDerecha, movBartIzquierda;

        // True indica que bart debe rotar 180 grados hacia la derecha o la izquierda
        bool rotarBartIzquierda, rotarBartDerecha;

    public:
        Pierna piernaDrc, piernaIzq;
        Cabeza cabeza;
        Brazo brazoDrc, brazoIzq;
        Cuerpo cuerpo;

        BartSimpson();
        void dibujarSolido();
        void dibujarPuntos();
        void dibujarAlambre();
        void dibujarAjedrez();
        void dibujarSinSuavizado();
        void dibujarConSuavizado();
        void moverCaderaArriba();
        void moverCaderaAbajo();
        void setRotacionBart(GLfloat nuevaRotacionBart);
        bool getMovPiernaDerDelante() const;
        bool getMovPiernaIzqDelante() const;
        void setMovPiernaDerDelante();
        void setMovPiernaIzqDelante();
        void traslacionBart();
	    void mostrarAyudaBart();
        bool incrementarVelocidadGlobal(); // Devuelve true si se ha podido incrementar o false en caso contrario
        bool decrementarVelocidadGlobal(); // Devuelve true si se ha podido decrementar o false en caso contrario
        bool incrementarVelocidadCadera();
        bool decrementarVelocidadCadera(); 
        bool getRotarBartIzquierda() const;
        bool getRotarBartDerecha() const;
        void reset();
};

#endif