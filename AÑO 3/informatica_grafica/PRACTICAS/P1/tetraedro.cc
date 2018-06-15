/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "tetraedro.h"

Tetraedro::Tetraedro(float altura, float lado, const Color &nuevoColor){
  this->numVertices = 4;
  this->numLados = 4;

  this->vertices = {
    Vertice(altura/2, -(altura/2), lado/2),
    Vertice(altura/2, -(altura/2), -(lado/2)),
    Vertice(-(altura/2), -(altura/2), 0.0),
    Vertice(0.0, altura/2, 0.0)
  };

  this->lados = {
    Triangulo(0,1,3),
    Triangulo(1,2,3),
    Triangulo(2,0,3),
    Triangulo(0,1,2)
  };

  this->color = {
    Color(nuevoColor.r, nuevoColor.g, nuevoColor.b),
    Color(nuevoColor.r, nuevoColor.g, nuevoColor.b),
    Color(nuevoColor.r, nuevoColor.g, nuevoColor.b),
    Color(nuevoColor.r, nuevoColor.g, nuevoColor.b)
  };

}
