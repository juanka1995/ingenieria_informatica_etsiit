/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "objeto3d.h"

unsigned int Object3D::getNumCaras(){
  return numCaras;
}

unsigned int Object3D::getNumVertices(){
  return numVertices;
}

void Object3D::dibujarPuntos(){
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  glPointSize(4);
  glColorPointer(3, GL_FLOAT, 0, &color[0]);
  glDrawElements(GL_TRIANGLES, 3*numCaras, GL_UNSIGNED_INT, &caras[0]);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Object3D::dibujarAlambre(){
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  glColorPointer(3, GL_FLOAT, 0, &color[0]);
  glDrawElements(GL_TRIANGLES, 3*numCaras, GL_UNSIGNED_INT, &caras[0]);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Object3D::dibujarAjedrez(){

  // Tenemos los 2 arrays de colores
  std::vector<Color> color2 = color;
  modifyToDifferentColor(color2,Color(0.0,1.0,0.0));

  // Tenemos los arrays con las caras pares e impares
  std::vector<Triangulo> cPares, cImpares;

  for(unsigned int i = 0; i < caras.size(); i++){
    if(i%2 == 0)
      cPares.push_back(caras[i]);
    else
      cImpares.push_back(caras[i]);
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);

  // Pintamos las caras pares
  glColorPointer(3, GL_FLOAT, 0, &color[0]);
  glDrawElements(GL_TRIANGLES, 3*cPares.size(), GL_UNSIGNED_INT, &cPares[0]);

  // Pintamos las caras impares
  glColorPointer(3, GL_FLOAT, 0, &color2[0]);
  glDrawElements(GL_TRIANGLES, 3*cImpares.size(), GL_UNSIGNED_INT, &cImpares[0]);

  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Object3D::dibujarSolido(){
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  glColorPointer(3, GL_FLOAT, 0, &color[0]);
  glDrawElements(GL_TRIANGLES, 3*numCaras, GL_UNSIGNED_INT, &caras[0]);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Object3D::modifyToDifferentColor(std::vector<Color> &arrayColores, const Color &nuevoColor){
  for (unsigned int i = 0; i < arrayColores.size(); i++) {
    arrayColores[i].r = nuevoColor.r; arrayColores[i].g = nuevoColor.g; arrayColores[i].b = nuevoColor.b;
  }
}

void Object3D::modifyActualColor(const Color &nuevoColor){
  for (unsigned int i = 0; i < color.size(); i++) {
    color[i].r = nuevoColor.r; color[i].g = nuevoColor.g; color[i].b = nuevoColor.b;
  }
}
