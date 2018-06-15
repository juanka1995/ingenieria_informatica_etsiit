/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "cubo.h"

Cubo::Cubo(float ancho){
  this->numVertices = 8;
  this->numCaras = 12;

  // Vertices
  this->vertices = {
    Vertice(-ancho,-ancho,ancho),
    Vertice(ancho,-ancho,ancho),
    Vertice(-ancho,ancho,ancho),
    Vertice(ancho,ancho,ancho),
    Vertice(-ancho,-ancho,-ancho),
    Vertice(ancho,-ancho,-ancho),
    Vertice(-ancho,ancho,-ancho),
    Vertice(ancho,ancho,-ancho)
  };

  // Triangulos
  this->caras = {
    Triangulo(0,1,2),
    Triangulo(1,3,2),
    Triangulo(2,3,7),
    Triangulo(2,7,6),
    Triangulo(1,7,3),
    Triangulo(1,5,7),
    Triangulo(6,7,4),
    Triangulo(7,5,4),
    Triangulo(0,4,1),
    Triangulo(1,4,5),
    Triangulo(2,6,4),
    Triangulo(0,2,4)
  };

  // color
  for(unsigned int i = 0 ; i < numVertices ; i++){
    this->color.push_back(Color(defaultColor.r, defaultColor.g, defaultColor.b));
  }

}
