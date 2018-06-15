/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "tetraedro.h"

Tetraedro::Tetraedro(float altura, float lado){
  this->numVertices = 4;
  this->numCaras = 4;

  this->vertices = {
    Vertice(altura/2, -(altura/2), lado/2),
    Vertice(altura/2, -(altura/2), -(lado/2)),
    Vertice(-(altura/2), -(altura/2), 0.0),
    Vertice(0.0, altura/2, 0.0)
  };

  this->caras = {
    Triangulo(0,1,3),
    Triangulo(1,2,3),
    Triangulo(2,0,3),
    Triangulo(0,1,2)
  };

  for(unsigned int i = 0 ; i < numVertices ; i++){
    this->color.push_back(Color(defaultColor.r, defaultColor.g, defaultColor.b));
  }

  calcularNormalesCaras();
  calcularNormalesVertices();

}
