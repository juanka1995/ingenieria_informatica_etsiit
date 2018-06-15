/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "escenaP4.h"

EscenaP4::EscenaP4(){
    esfera = ObjetoPLY("ply/p4/esfera.ply");
    media_esfera = ObjetoPLY("ply/p4/media_esfera.ply");
    mono = ObjetoPLY("ply/p4/mono.ply");
    
    esfera.calcularNormalesCaras();
    esfera.calcularNormalesVertices();

    mono.calcularNormalesCaras();
    mono.calcularNormalesVertices();

    media_esfera.calcularNormalesCaras();
    media_esfera.calcularNormalesVertices();
}

void EscenaP4::dibujarSolido(){
    glPushMatrix();
        // Esfera
        glPushMatrix();
            glScalef(5.0,5.0,5.0);
            glTranslatef(1.0,0.5,-0.8);
            esfera.dibujarSolido();
        glPopMatrix();

        // mono
        glPushMatrix();
            glScalef(3.0,3.0,3.0);
            glTranslatef(-1.8,1.0,-0.8);
            mono.dibujarSolido();
        glPopMatrix();

        // media_esfera
        glPushMatrix();
            glScalef(5.0,5.0,5.0);
            media_esfera.dibujarSolido();
        glPopMatrix();
    glPopMatrix();
}

void EscenaP4::dibujarAjedrez(){
glPushMatrix();
        // Esfera
        glPushMatrix();
            glScalef(5.0,5.0,5.0);
            glTranslatef(1.0,0.5,-0.8);
            esfera.dibujarAjedrez();
        glPopMatrix();

        // mono
        glPushMatrix();
            glScalef(3.0,3.0,3.0);
            glTranslatef(-1.8,1.0,-0.8);
            mono.dibujarAjedrez();
        glPopMatrix();

        // media_esfera
        glPushMatrix();
            glScalef(5.0,5.0,5.0);
            media_esfera.dibujarAjedrez();
        glPopMatrix();
    glPopMatrix();
}

void EscenaP4::dibujarAlambre(){
glPushMatrix();
        // Esfera
        glPushMatrix();
            glScalef(5.0,5.0,5.0);
            glTranslatef(1.0,0.5,-0.8);
            esfera.dibujarAlambre();
        glPopMatrix();

        // mono
        glPushMatrix();
            glScalef(3.0,3.0,3.0);
            glTranslatef(-1.8,1.0,-0.8);
            mono.dibujarAlambre();
        glPopMatrix();

        // media_esfera
        glPushMatrix();
            glScalef(5.0,5.0,5.0);
            media_esfera.dibujarAlambre();
        glPopMatrix();
    glPopMatrix();
}

void EscenaP4::dibujarPuntos(){
glPushMatrix();
        // Esfera
        glPushMatrix();
            glScalef(5.0,5.0,5.0);
            glTranslatef(1.0,0.5,-0.8);
            esfera.dibujarPuntos();
        glPopMatrix();

        // mono
        glPushMatrix();
            glScalef(3.0,3.0,3.0);
            glTranslatef(-1.8,1.0,-0.8);
            mono.dibujarPuntos();
        glPopMatrix();

        // media_esfera
        glPushMatrix();
            glScalef(5.0,5.0,5.0);
            media_esfera.dibujarPuntos();
        glPopMatrix();
    glPopMatrix();
}

void EscenaP4::dibujarSinSuavizado(){
    glPushMatrix();
        // Esfera
        glPushMatrix();
            glScalef(5.0,5.0,5.0);
            glTranslatef(1.0,0.5,-0.8);
            esfera.dibujarSinSuavizado();
        glPopMatrix();

        // mono
        glPushMatrix();
            glScalef(3.0,3.0,3.0);
            glTranslatef(-1.8,1.0,-0.8);
            mono.dibujarSinSuavizado();
        glPopMatrix();

        // media_esfera
        glPushMatrix();
            glScalef(5.0,5.0,5.0);
            media_esfera.dibujarSinSuavizado();
        glPopMatrix();
    glPopMatrix();
}

void EscenaP4::dibujarConSuavizado(){
    glPushMatrix();
        // Esfera
        glPushMatrix();
            glScalef(5.0,5.0,5.0);
            glTranslatef(1.0,0.5,-0.8);
            esfera.dibujarConSuavizado();
        glPopMatrix();

        // mono
        glPushMatrix();
            glScalef(3.0,3.0,3.0);
            glTranslatef(-1.8,1.0,-0.8);
            mono.dibujarConSuavizado();
        glPopMatrix();

        // media_esfera
        glPushMatrix();
            glScalef(5.0,5.0,5.0);
            media_esfera.dibujarConSuavizado();
        glPopMatrix();
    glPopMatrix();
}