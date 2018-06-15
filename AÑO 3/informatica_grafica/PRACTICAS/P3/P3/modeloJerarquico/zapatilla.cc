/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "zapatilla.h"

Zapatilla::Zapatilla(){
    base_zapatilla = ObjetoPLY("modeloJerarquico/ply_modJer/base_zapatilla.ply");
    empeine = ObjetoPLY("modeloJerarquico/ply_modJer/empeine.ply");
}

void Zapatilla::dibujarSolido(){
    // Base del zapato
    glPushMatrix();
        base_zapatilla.modifyActualColor(Color(0.85,0.85,0.85)); // Color gris calcetines y base zapato
        glScalef(0.9,1,1.5);
        base_zapatilla.dibujarSolido();
    glPopMatrix();
    
    // Empeine del zapato
    glPushMatrix();
        empeine.modifyActualColor(Color(0.11,0.60,0.85)); // Color azul zapatillas y pantalon
        glTranslatef(0.0,0.2,0.0);
        glScalef(0.9,0.6,1.4);
        empeine.dibujarSolido();
    glPopMatrix();
}

void Zapatilla::dibujarAlambre(){
    // Base del zapato
    glPushMatrix();
        base_zapatilla.modifyActualColor(Color(0.85,0.85,0.85)); // Color gris calcetines y base zapato
        glScalef(0.9,1,1.5);
        base_zapatilla.dibujarAlambre();
    glPopMatrix();
    
    // Empeine del zapato
    glPushMatrix();
        empeine.modifyActualColor(Color(0.11,0.60,0.85)); // Color azul zapatillas y pantalon
        glTranslatef(0.0,0.2,0.0);
        glScalef(0.9,0.6,1.4);
        empeine.dibujarAlambre();
    glPopMatrix();
}

void Zapatilla::dibujarPuntos(){
    // Base del zapato
    glPushMatrix();
        base_zapatilla.modifyActualColor(Color(0.85,0.85,0.85)); // Color gris calcetines y base zapato
        glScalef(0.9,1,1.5);
        base_zapatilla.dibujarPuntos();
    glPopMatrix();
    
    // Empeine del zapato
    glPushMatrix();
        empeine.modifyActualColor(Color(0.11,0.60,0.85)); // Color azul zapatillas y pantalon
        glTranslatef(0.0,0.2,0.0);
        glScalef(0.9,0.6,1.4);
        empeine.dibujarPuntos();
    glPopMatrix();
}

void Zapatilla::dibujarAjedrez(){
    // Base del zapato
    glPushMatrix();
        base_zapatilla.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
        glScalef(0.9,1,1.5);
        base_zapatilla.dibujarAjedrez();
    glPopMatrix();
    
    // Empeine del zapato
    glPushMatrix();
        empeine.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
        glTranslatef(0.0,0.2,0.0);
        glScalef(0.9,0.6,1.4);
        empeine.dibujarAjedrez();
    glPopMatrix();
}