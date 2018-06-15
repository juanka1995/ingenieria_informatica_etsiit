/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "rombo.h"

Rombo::Rombo(float altura, float lado){

  this->numVertices = 6;
  this->numCaras = 8;

  this->vertices = {
    Vertice(0.0, -(altura/2), 0.0),
    Vertice(lado/2, 0.0, lado/2),
    Vertice(lado/2, 0.0, -(lado/2)),
    Vertice(-(lado/2), 0.0, -(lado/2)),
    Vertice(-(lado/2), 0.0, lado/2),
    Vertice(0.0, altura/2, 0.0)
  };

  this->caras = {
    Triangulo(0,1,2),
    Triangulo(0,2,3),
    Triangulo(0,3,4),
    Triangulo(0,4,1),
    Triangulo(5,2,3),
    Triangulo(5,1,2),
    Triangulo(5,4,1),
    Triangulo(5,3,4)
  };

  for(unsigned int i = 0 ; i < numVertices ; i++){
    this->color.push_back(Color(defaultColor.r, defaultColor.g, defaultColor.b));
  }

  calcularNormalesCaras();
  calcularNormalesVertices();

}
