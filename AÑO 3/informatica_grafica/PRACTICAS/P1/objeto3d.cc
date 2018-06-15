/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "objeto3d.h"

unsigned int Object3D::getNumLados(){
  return numLados;
}

unsigned int Object3D::getNumVertices(){
  return numVertices;
}

void Object3D::dibujarPuntos(){
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  glPointSize(5);
  glColorPointer(3, GL_FLOAT, 0, &color[0]);
  glDrawElements(GL_TRIANGLES, 3*numLados, GL_UNSIGNED_INT, &lados[0]);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Object3D::dibujarAlambre(){
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  glColorPointer(3, GL_FLOAT, 0, &color[0]);
  glDrawElements(GL_TRIANGLES, 3*numLados, GL_UNSIGNED_INT, &lados[0]);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Object3D::dibujarAjedrez(){
  std::vector<Color> color2 = color;
  modifyColor(color2,Color(0.0,255.0,0.0));

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);

  for (unsigned int i = 0; i < numLados; i++) {
    if(i%2 == 0)
      glColorPointer(3, GL_FLOAT, 0, &color[0]);
    else
      glColorPointer(3, GL_FLOAT, 0, &color2[0]);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &lados[i]);
  }

  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Object3D::dibujarSolido(){
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  glColorPointer(3, GL_FLOAT, 0, &color[0]);
  glDrawElements(GL_TRIANGLES, 3*numLados, GL_UNSIGNED_INT, &lados[0]);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Object3D::modifyColor(std::vector<Color> &arrayColores, const Color &nuevoColor){
  for (unsigned int i = 0; i < arrayColores.size(); i++) {
    arrayColores[i].r = nuevoColor.r; arrayColores[i].g = nuevoColor.g; arrayColores[i].b = nuevoColor.b;
  }
}
