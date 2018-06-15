/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _ROMBO_H
#define _ROMBO_H

#include "objeto3d.h"

class Rombo : public Object3D{
  public:
    Rombo(){};
    Rombo(float altura, float lado);
};

#endif