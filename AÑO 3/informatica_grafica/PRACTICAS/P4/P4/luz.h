/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _LUZ_H
#define _LUZ_H

#include "vertex.h"
#include <GL/gl.h>
#include <GL/glut.h>

class Luz{
    private:
        _vertex4f cAmbiental, cDifuso, cEspecular, dirPos;
        GLfloat rotarZ, rotarY;
    public:
        Luz(){};
        Luz(_vertex4f ambiente, _vertex4f difuso, _vertex4f especular, _vertex4f direcPosi);
        void posicionarLuz(int numLuz);
        void activarLuz(int numLuz);
        void desactivarLuz(int numLuz);
        void incrementarRotacionLuz1();
        void incrementarRotacionLuz2();
};

#endif