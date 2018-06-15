/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _PIRAMIDE_H
#define _PIRAMIDE_H

#include "objeto3d.h"

class Piramide : public Object3D{
  public:
    Piramide(){};
    Piramide(float altura, float lado);
};

#endif