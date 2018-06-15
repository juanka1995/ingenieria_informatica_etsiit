/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "piramide.h"

Piramide::Piramide(float altura, float lado, const Color &nuevoColor){

  this->numVertices = 5;
  this->numLados = 6;

  this->vertices = {
    Vertice(lado/2, -(altura/2), lado/2),
    Vertice(lado/2, -(altura/2), -(lado/2)),
    Vertice(-(lado/2), -(altura/2), -(lado/2)),
    Vertice(-(lado/2), -(altura/2), lado/2),
    Vertice(0.0, altura/2, 0.0)
  };

  this->lados = {
    Triangulo(0,1,2),
    Triangulo(0,1,4),
    Triangulo(1,2,4),
    Triangulo(2,3,4),
    Triangulo(3,0,4),
    Triangulo(0,2,3)
  };

  this->color = {
    Color(nuevoColor.r, nuevoColor.g, nuevoColor.b),
    Color(nuevoColor.r, nuevoColor.g, nuevoColor.b),
    Color(nuevoColor.r, nuevoColor.g, nuevoColor.b),
    Color(nuevoColor.r, nuevoColor.g, nuevoColor.b),
    Color(nuevoColor.r, nuevoColor.g, nuevoColor.b)
  };

}
