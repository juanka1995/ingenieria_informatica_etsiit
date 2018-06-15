/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "cuerpo.h"

Cuerpo::Cuerpo(){
    pecho = ObjetoPLY("modeloJerarquico/ply_modJer/pecho.ply");
    barriga = ObjetoPLY("modeloJerarquico/ply_modJer/media_esfera.ply");
    clavicula = ObjetoPLY("modeloJerarquico/ply_modJer/media_esfera.ply");
    cadera = ObjetoPLY("modeloJerarquico/ply_modJer/esfera.ply");

    pecho.calcularNormalesCaras();
    pecho.calcularNormalesVertices();

    barriga.calcularNormalesCaras();
    barriga.calcularNormalesVertices();

    clavicula.calcularNormalesCaras();
    clavicula.calcularNormalesVertices();

    cadera.calcularNormalesCaras();
    cadera.calcularNormalesVertices();
}

void Cuerpo::dibujarSolido(){
    // Cuerpo
    glPushMatrix();
        // Cadera
        glPushMatrix();
            cadera.modifyActualColor(Color(0.11,0.60,0.85)); // Color azul zapatillas y pantalon
            glScalef(0.75,0.6,0.75);
            cadera.dibujarSolido();
        glPopMatrix();
        // Clavicula + Pecho + Barriga
        glTranslatef(0.0,0.15,0.0);
        glPushMatrix();
            // Barriga
            glPushMatrix();
                barriga.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                glScalef(0.75,0.6,0.75);
                barriga.dibujarSolido();
            glPopMatrix();
            // Clavicula + Pecho
            glTranslatef(0.0,0.15,0.0);
            glPushMatrix();
                // Clavicula
                glPushMatrix();
                    clavicula.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                    glTranslatef(0.0,0.4,0.0);
                    glScalef(0.5,0.5,0.5);
                    clavicula.dibujarSolido();
                glPopMatrix();
                // Pecho
                glPushMatrix();
                    pecho.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                    glScalef(0.75,0.6,0.75);
                    pecho.dibujarSolido();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Cuerpo::dibujarSinSuavizado(){
    // Cuerpo
    glPushMatrix();
        // Cadera
        glPushMatrix();
            cadera.modifyActualColor(Color(0.11,0.60,0.85)); // Color azul zapatillas y pantalon
            glScalef(0.75,0.6,0.75);
            cadera.dibujarSinSuavizado();
        glPopMatrix();
        // Clavicula + Pecho + Barriga
        glTranslatef(0.0,0.15,0.0);
        glPushMatrix();
            // Barriga
            glPushMatrix();
                barriga.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                glScalef(0.75,0.6,0.75);
                barriga.dibujarSinSuavizado();
            glPopMatrix();
            // Clavicula + Pecho
            glTranslatef(0.0,0.15,0.0);
            glPushMatrix();
                // Clavicula
                glPushMatrix();
                    clavicula.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                    glTranslatef(0.0,0.4,0.0);
                    glScalef(0.5,0.5,0.5);
                    clavicula.dibujarSinSuavizado();
                glPopMatrix();
                // Pecho
                glPushMatrix();
                    pecho.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                    glScalef(0.75,0.6,0.75);
                    pecho.dibujarSinSuavizado();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Cuerpo::dibujarConSuavizado(){
    // Cuerpo
    glPushMatrix();
        // Cadera
        glPushMatrix();
            cadera.modifyActualColor(Color(0.11,0.60,0.85)); // Color azul zapatillas y pantalon
            glScalef(0.75,0.6,0.75);
            cadera.dibujarConSuavizado();
        glPopMatrix();
        // Clavicula + Pecho + Barriga
        glTranslatef(0.0,0.15,0.0);
        glPushMatrix();
            // Barriga
            glPushMatrix();
                barriga.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                glScalef(0.75,0.6,0.75);
                barriga.dibujarConSuavizado();
            glPopMatrix();
            // Clavicula + Pecho
            glTranslatef(0.0,0.15,0.0);
            glPushMatrix();
                // Clavicula
                glPushMatrix();
                    clavicula.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                    glTranslatef(0.0,0.4,0.0);
                    glScalef(0.5,0.5,0.5);
                    clavicula.dibujarConSuavizado();
                glPopMatrix();
                // Pecho
                glPushMatrix();
                    pecho.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                    glScalef(0.75,0.6,0.75);
                    pecho.dibujarConSuavizado();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Cuerpo::dibujarAlambre(){
    // Cuerpo
    glPushMatrix();
        // Cadera
        glPushMatrix();
            cadera.modifyActualColor(Color(0.11,0.60,0.85)); // Color azul zapatillas y pantalon
            glScalef(0.75,0.6,0.75);
            cadera.dibujarAlambre();
        glPopMatrix();
        // Clavicula + Pecho + Barriga
        glTranslatef(0.0,0.15,0.0);
        glPushMatrix();
            // Barriga
            glPushMatrix();
                barriga.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                glScalef(0.75,0.6,0.75);
                barriga.dibujarAlambre();
            glPopMatrix();
            // Clavicula + Pecho
            glTranslatef(0.0,0.15,0.0);
            glPushMatrix();
                // Clavicula
                glPushMatrix();
                    clavicula.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                    glTranslatef(0.0,0.4,0.0);
                    glScalef(0.5,0.5,0.5);
                    clavicula.dibujarAlambre();
                glPopMatrix();
                // Pecho
                glPushMatrix();
                    pecho.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                    glScalef(0.75,0.6,0.75);
                    pecho.dibujarAlambre();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Cuerpo::dibujarPuntos(){
    // Cuerpo
    glPushMatrix();
        // Cadera
        glPushMatrix();
            cadera.modifyActualColor(Color(0.11,0.60,0.85)); // Color azul zapatillas y pantalon
            glScalef(0.75,0.6,0.75);
            cadera.dibujarPuntos();
        glPopMatrix();
        // Clavicula + Pecho + Barriga
        glTranslatef(0.0,0.15,0.0);
        glPushMatrix();
            // Barriga
            glPushMatrix();
                barriga.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                glScalef(0.75,0.6,0.75);
                barriga.dibujarPuntos();
            glPopMatrix();
            // Clavicula + Pecho
            glTranslatef(0.0,0.15,0.0);
            glPushMatrix();
                // Clavicula
                glPushMatrix();
                    clavicula.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                    glTranslatef(0.0,0.4,0.0);
                    glScalef(0.5,0.5,0.5);
                    clavicula.dibujarPuntos();
                glPopMatrix();
                // Pecho
                glPushMatrix();
                    pecho.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                    glScalef(0.75,0.6,0.75);
                    pecho.dibujarPuntos();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Cuerpo::dibujarAjedrez(){
    // Cuerpo
    glPushMatrix();
        // Cadera
        glPushMatrix();
            cadera.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
            glScalef(0.75,0.6,0.75);
            cadera.dibujarAjedrez();
        glPopMatrix();
        // Clavicula + Pecho + Barriga
        glTranslatef(0.0,0.15,0.0);
        glPushMatrix();
            // Barriga
            glPushMatrix();
                barriga.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                glScalef(0.75,0.6,0.75);
                barriga.dibujarAjedrez();
            glPopMatrix();
            // Clavicula + Pecho
            glTranslatef(0.0,0.15,0.0);
            glPushMatrix();
                // Clavicula
                glPushMatrix();
                    clavicula.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                    glTranslatef(0.0,0.4,0.0);
                    glScalef(0.5,0.5,0.5);
                    clavicula.dibujarAjedrez();
                glPopMatrix();
                // Pecho
                glPushMatrix();
                    pecho.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                    glScalef(0.75,0.6,0.75);
                    pecho.dibujarAjedrez();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}
