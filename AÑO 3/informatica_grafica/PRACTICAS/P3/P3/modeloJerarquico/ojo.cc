/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "ojo.h"

Ojo::Ojo(){
    esclera = ObjetoPLY("modeloJerarquico/ply_modJer/esfera.ply");
    pupila = ObjetoPLY("modeloJerarquico/ply_modJer/esfera.ply");
}

void Ojo::dibujarSolido(){
    // Esclera
    glPushMatrix();
        esclera.modifyActualColor(Color(0.90,0.90,0.90)); // Color blanco ojo
        glScalef(0.5,0.5,0.5);
        esclera.dibujarSolido();
    glPopMatrix();
    // Pupila
    glPushMatrix();
        pupila.modifyActualColor(Color(0.0,0.0,0.0)); // Color negro pupila
        glTranslatef(0.0,0.0,0.2);
        glScalef(0.15,0.15,0.15);
        pupila.dibujarSolido();
    glPopMatrix();
}

void Ojo::dibujarAlambre(){
    // Esclera
    glPushMatrix();
        esclera.modifyActualColor(Color(0.90,0.90,0.90)); // Color blanco ojo
        glScalef(0.5,0.5,0.5);
        esclera.dibujarAlambre();
    glPopMatrix();
    // Pupila
    glPushMatrix();
        pupila.modifyActualColor(Color(0.0,0.0,0.0)); // Color negro pupila
        glTranslatef(0.0,0.0,0.2);
        glScalef(0.15,0.15,0.15);
        pupila.dibujarAlambre();
    glPopMatrix();
}

void Ojo::dibujarPuntos(){
    // Esclera
    glPushMatrix();
        esclera.modifyActualColor(Color(0.90,0.90,0.90)); // Color blanco ojo
        glScalef(0.5,0.5,0.5);
        esclera.dibujarPuntos();
    glPopMatrix();
    // Pupila
    glPushMatrix();
        pupila.modifyActualColor(Color(0.0,0.0,0.0)); // Color negro pupila
        glTranslatef(0.0,0.0,0.2);
        glScalef(0.15,0.15,0.15);
        pupila.dibujarPuntos();
    glPopMatrix();
}

void Ojo::dibujarAjedrez(){
    // Esclera
    glPushMatrix();
        esclera.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
        glScalef(0.5,0.5,0.5);
        esclera.dibujarAjedrez();
    glPopMatrix();
    // Pupila
    glPushMatrix();
        pupila.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
        glTranslatef(0.0,0.0,0.2);
        glScalef(0.15,0.15,0.15);
        pupila.dibujarAjedrez();
    glPopMatrix();
}