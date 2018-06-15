/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "objeto3d.h"

int materialActivo;

Object3D::Object3D(){

  // Material Rubi
  materialRubi.emision[0] = 0.0; materialRubi.emision[1] = 0.0; materialRubi.emision[2] = 0.0; materialRubi.emision[3] = 1.0;
  materialRubi.ambiente[0] = 0.1745; materialRubi.ambiente[1] = 0.01175; materialRubi.ambiente[2] = 0.01175; materialRubi.ambiente[3] = 1.0;
  materialRubi.difuso[0] = 0.61424; materialRubi.difuso[1] = 0.04136; materialRubi.difuso[2] = 0.04136; materialRubi.difuso[3] = 1.0;
  materialRubi.especular[0] = 0.727811; materialRubi.especular[1] = 0.626959; materialRubi.especular[2] = 0.626959; materialRubi.especular[3] = 1.0;
  materialRubi.brillo = 65.3;

// Material Dorado
  materialDorado.emision[0] = 0.0; materialDorado.emision[1] = 0.0; materialDorado.emision[2] = 0.0; materialDorado.emision[3] = 1.0;
  materialDorado.ambiente[0] = 0.24725; materialDorado.ambiente[1] = 0.1995; materialDorado.ambiente[2] = 0.0745; materialDorado.ambiente[3] = 1.0;
  materialDorado.difuso[0] = 0.75164; materialDorado.difuso[1] = 0.60648; materialDorado.difuso[2] = 0.22648; materialDorado.difuso[3] = 1.0;
  materialDorado.especular[0] = 0.628281; materialDorado.especular[1] = 0.555802; materialDorado.especular[2] = 0.366065; materialDorado.especular[3] = 1.0;
  materialDorado.brillo = 51.2;

  // Material Turquesa
  materialTurquesa.emision[0] = 0.0; materialTurquesa.emision[1] = 0.0; materialTurquesa.emision[2] = 0.0; materialTurquesa.emision[3] = 1.0;
  materialTurquesa.ambiente[0] = 0.1; materialTurquesa.ambiente[1] = 0.18725; materialTurquesa.ambiente[2] = 0.1745; materialTurquesa.ambiente[3] = 0.8;
  materialTurquesa.difuso[0] = 0.396; materialTurquesa.difuso[1] = 0.74151; materialTurquesa.difuso[2] = 0.69102; materialTurquesa.difuso[3] = 0.8;
  materialTurquesa.especular[0] = 0.297254; materialTurquesa.especular[1] = 0.30829; materialTurquesa.especular[2] = 0.306678; materialTurquesa.especular[3] = 0.8;
  materialTurquesa.brillo = 12.8;

  // Material por defecto
  materialPorDefecto.emision[0] = 0.0; materialPorDefecto.emision[1] = 0.0; materialPorDefecto.emision[2] = 0.0; materialPorDefecto.emision[3] = 1.0;
  materialPorDefecto.ambiente[0] = 0.2; materialPorDefecto.ambiente[1] = 0.2; materialPorDefecto.ambiente[2] = 0.2; materialPorDefecto.ambiente[3] = 1.0;
  materialPorDefecto.difuso[0] = 0.8; materialPorDefecto.difuso[1] = 0.8; materialPorDefecto.difuso[2] = 0.8; materialPorDefecto.difuso[3] = 1.0;
  materialPorDefecto.especular[0] = 0.0; materialPorDefecto.especular[1] = 0.0; materialPorDefecto.especular[2] = 0.0; materialPorDefecto.especular[3] = 1.0;
  materialPorDefecto.brillo = 0.0;

}

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

  // PINTAR NORMALES CARAS
      // vector<_vertex3f> colorNormalesCaras, colorNormalesVertices, copiaNormalesCaras, copiaNormalesVertices;
      // vector<_vertex2<unsigned int> > lineasNormalesCaras, lineasNormalesVertices;
      // _vertex3f a;   

      // // Caras
      // for(unsigned int i = 0; i < caras.size(); i++){
      //   a._0 = (vertices[caras[i].l1].x + vertices[caras[i].l2].x + vertices[caras[i].l3].x) / 3.0;
      //   a._1 = (vertices[caras[i].l1].y + vertices[caras[i].l2].y + vertices[caras[i].l3].y) / 3.0;
      //   a._2 = (vertices[caras[i].l1].z + vertices[caras[i].l2].z + vertices[caras[i].l3].z) / 3.0;

      //   copiaNormalesCaras.push_back(a);
      //   copiaNormalesCaras.push_back(a+normalesCaras[i]);
      // }

      // // Vertices
      // for(unsigned int i = 0; i < vertices.size(); i++){
      //   a._0 = vertices[i].x;
      //   a._1 = vertices[i].y;
      //   a._2 = vertices[i].z;
      //   copiaNormalesVertices.push_back(a);
      //   copiaNormalesVertices.push_back(a+normalesVertices[i]);
      // }

      // // Color normales caras
      // a._0=0.0;
      // a._1=0.0;
      // a._2=0.0;
      // for(unsigned int i = 0; i < copiaNormalesCaras.size(); i++)
      //   colorNormalesCaras.push_back(a); 

      // // Color normales vertices
      // a._2=1.0;
      // for(unsigned int i = 0; i < copiaNormalesVertices.size(); i++)
      //   colorNormalesVertices.push_back(a);

      // // Lineas Normales caras
      // _vertex2<unsigned int> b;
      // for(unsigned int i = 0; i < copiaNormalesCaras.size(); i=i+2){
      //     b._0 = i;
      //     b._1 = i+1;
      //     lineasNormalesCaras.push_back(b);
      // }

      // // Lineas Normales vertices
      // for(unsigned int i = 0; i < copiaNormalesVertices.size(); i=i+2){
      //     b._0 = i;
      //     b._1 = i+1;
      //     lineasNormalesVertices.push_back(b);
      // }

      // glEnableClientState(GL_VERTEX_ARRAY);
      // glEnableClientState(GL_COLOR_ARRAY);
      // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      
      // // Caras
      // glVertexPointer(3,GL_FLOAT,0,&copiaNormalesCaras[0]);
      // glColorPointer(3, GL_FLOAT, 0, &colorNormalesCaras[0]);
      // glDrawElements(GL_LINES, 2*lineasNormalesCaras.size(), GL_UNSIGNED_INT, &lineasNormalesCaras[0]);
      // // Vertices
      // glVertexPointer(3,GL_FLOAT,0,&copiaNormalesVertices[0]);
      // glColorPointer(3, GL_FLOAT, 0, &colorNormalesVertices[0]);
      // glDrawElements(GL_LINES, 2*lineasNormalesVertices.size(), GL_UNSIGNED_INT, &lineasNormalesVertices[0]);
      
      // glDisableClientState(GL_COLOR_ARRAY);
      // glDisableClientState(GL_VERTEX_ARRAY);

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

void Object3D::dibujarSinSuavizado(){
  glShadeModel(GL_FLAT);
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
  glEnable(GL_NORMALIZE);

  if(materialActivo == 0){
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, materialPorDefecto.emision);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialPorDefecto.ambiente);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialPorDefecto.difuso);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialPorDefecto.especular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialPorDefecto.brillo);
  }
  else if(materialActivo == 1){
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, materialRubi.emision);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialRubi.ambiente);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialRubi.difuso);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialRubi.especular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialRubi.brillo);
  }
  else if(materialActivo == 2){
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, materialDorado.emision);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialDorado.ambiente);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialDorado.difuso);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialDorado.especular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialDorado.brillo);
  }
  else if(materialActivo == 3){
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, materialTurquesa.emision);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialTurquesa.ambiente);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialTurquesa.difuso);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialTurquesa.especular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialTurquesa.brillo);
  }

  glBegin(GL_TRIANGLES);
  for(unsigned int i = 0; i < caras.size(); i++){
    glNormal3fv((GLfloat *) &normalesCaras[i]);
      glVertex3fv((GLfloat *) &vertices[caras[i].l1]);
      glVertex3fv((GLfloat *) &vertices[caras[i].l2]);
      glVertex3fv((GLfloat *) &vertices[caras[i].l3]);
  }
  glEnd();

  glDisable(GL_NORMALIZE);
}

void Object3D::dibujarConSuavizado(){
  glShadeModel(GL_SMOOTH);
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
  glEnable(GL_NORMALIZE);

  if(materialActivo == 0){
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, materialPorDefecto.emision);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialPorDefecto.ambiente);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialPorDefecto.difuso);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialPorDefecto.especular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialPorDefecto.brillo);
  }
  else if(materialActivo == 1){
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, materialRubi.emision);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialRubi.ambiente);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialRubi.difuso);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialRubi.especular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialRubi.brillo);
  }
  else if(materialActivo == 2){
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, materialDorado.emision);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialDorado.ambiente);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialDorado.difuso);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialDorado.especular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialDorado.brillo);
  }
  else if(materialActivo == 3){
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, materialTurquesa.emision);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialTurquesa.ambiente);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialTurquesa.difuso);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialTurquesa.especular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialTurquesa.brillo);
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  glNormalPointer(GL_FLOAT, 0, &normalesVertices[0]);
  glDrawElements(GL_TRIANGLES, 3*numCaras, GL_UNSIGNED_INT, &caras[0]);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);

  glDisable(GL_NORMALIZE);
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

void Object3D::calcularNormalesCaras(){
  _vertex3f a, b, c;
  // Calculo
  for(unsigned int i = 0; i < caras.size(); i++){
    a._0 = vertices[caras[i].l2].x - vertices[caras[i].l1].x;
    a._1 = vertices[caras[i].l2].y - vertices[caras[i].l1].y;
    a._2 = vertices[caras[i].l2].z - vertices[caras[i].l1].z;

    b._0 = vertices[caras[i].l3].x - vertices[caras[i].l1].x;
    b._1 = vertices[caras[i].l3].y - vertices[caras[i].l1].y;
    b._2 = vertices[caras[i].l3].z - vertices[caras[i].l1].z;

    c = a.cross_product(b);
    c.normalize();
    normalesCaras.push_back(c);
  }
}

void Object3D::calcularNormalesVertices(){
  // Inicializo a 0 todas las normales de los vertices
  _vertex3f a;
  a._0=0.0;
  a._1=0.0;
  a._2=0.0;;
  for(unsigned int i = 0; i < vertices.size(); i++){
    normalesVertices.push_back(a);
  }

  // Sumo las normales de las caras adyacentes a los vertices
  for(unsigned int i = 0; i < caras.size(); i++){
    normalesVertices[caras[i].l1] += normalesCaras[i];
    normalesVertices[caras[i].l2] += normalesCaras[i];
    normalesVertices[caras[i].l3] += normalesCaras[i];
  }

  // Normalizo las normales de los vertices
  for(unsigned int i = 0; i < normalesVertices.size(); i++){
    normalesVertices[i].normalize();
  }
}

void Object3D::setMaterialActivo(int material){
  materialActivo = material;
}