/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _TETRAEDRO_H
#define _TETRAEDRO_H

#include "objeto3d.h"

class Tetraedro : public Object3D{
  public:
    Tetraedro(){};
    Tetraedro(float altura, float lado);
};

#endif