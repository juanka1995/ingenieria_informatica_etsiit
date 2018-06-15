/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "bartSimpson.h"

BartSimpson::BartSimpson(){
    piernaDrc = Pierna();
    piernaIzq = Pierna();
    cabeza = Cabeza();
    brazoDrc = Brazo();
    brazoIzq = Brazo();
    cuerpo = Cuerpo();

    grCadera = 0.0;
    
    maxMovAbajoCadera = 45.0;
    maxMovArribaCadera = 0.0;

    rotarBartEnY = 0.0;

    movPiernaDerDelante = false;
    movPiernaIzqDelante = true;

    trasladarBart = 0.0;
    topeTraslacionDerecha = 6.0;
    topeTraslacionIzquierda = -6.0;

    movBartDerecha = true;
    movBartIzquierda = false;

    rotarBartDerecha = rotarBartIzquierda = false;

    velocidadGlobal = velocidadCadera = 5.0;
}

void BartSimpson::dibujarSolido(){
    // Bart completo
    glPushMatrix();
        glTranslatef(trasladarBart,0.0,0.0);
        glRotatef(rotarBartEnY,0.0,1.0,0.0);
        glScalef(4.5,4.5,4.5);
        //Pierna Derecha
            glPushMatrix();
            glTranslatef(-0.2,-0.1,0.0);
            glScalef(0.3,0.35,0.3);
            piernaDrc.dibujarSolido();
        glPopMatrix();
        
        // Pierna Izquierda    
        glPushMatrix();
            glTranslatef(0.2,-0.1,0.0);
            glScalef(0.3,0.35,0.3);
            piernaIzq.dibujarSolido();
        glPopMatrix();

        // Cuerpo + Brazos + Cabeza
        glPushMatrix();
            glRotatef(grCadera,1.0,0.0,0.0);
            cuerpo.dibujarSolido();
            // Brazos + cabeza
            glPushMatrix();
                // Brazo derecho
                glPushMatrix();
                    glTranslatef(-0.15,0.7,0.0);
                    glScalef(0.15,0.15,0.15);
                    brazoDrc.dibujarSolido();
                glPopMatrix();

                // Brazo izquierdo
                glPushMatrix();
                    glTranslatef(0.15,0.7,0.0);
                    glScalef(-1.0,1.0,1.0);
                    glScalef(0.15,0.15,0.15);
                    brazoIzq.dibujarSolido();
                glPopMatrix();

                // Cabeza
                glPushMatrix();
                    glTranslatef(0.0,0.8,0.0);
                    glScalef(0.12,0.12,0.12);
                    cabeza.dibujarSolido();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void BartSimpson::dibujarSinSuavizado(){
    // Bart completo
    glPushMatrix();
        glTranslatef(trasladarBart,0.0,0.0);
        glRotatef(rotarBartEnY,0.0,1.0,0.0);
        glScalef(4.5,4.5,4.5);
        //Pierna Derecha
            glPushMatrix();
            glTranslatef(-0.2,-0.1,0.0);
            glScalef(0.3,0.35,0.3);
            piernaDrc.dibujarSinSuavizado();
        glPopMatrix();
        
        // Pierna Izquierda    
        glPushMatrix();
            glTranslatef(0.2,-0.1,0.0);
            glScalef(0.3,0.35,0.3);
            piernaIzq.dibujarSinSuavizado();
        glPopMatrix();

        // Cuerpo + Brazos + Cabeza
        glPushMatrix();
            glRotatef(grCadera,1.0,0.0,0.0);
            cuerpo.dibujarSinSuavizado();
            // Brazos + cabeza
            glPushMatrix();
                // Brazo derecho
                glPushMatrix();
                    glTranslatef(-0.15,0.7,0.0);
                    glScalef(0.15,0.15,0.15);
                    brazoDrc.dibujarSinSuavizado();
                glPopMatrix();

                // Brazo izquierdo
                glPushMatrix();
                    glTranslatef(0.15,0.7,0.0);
                    glScalef(-1.0,1.0,1.0);
                    glScalef(0.15,0.15,0.15);
                    brazoIzq.dibujarSinSuavizado();
                glPopMatrix();

                // Cabeza
                glPushMatrix();
                    glTranslatef(0.0,0.8,0.0);
                    glScalef(0.12,0.12,0.12);
                    cabeza.dibujarSinSuavizado();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void BartSimpson::dibujarConSuavizado(){
    // Bart completo
    glPushMatrix();
        glTranslatef(trasladarBart,0.0,0.0);
        glRotatef(rotarBartEnY,0.0,1.0,0.0);
        glScalef(4.5,4.5,4.5);
        //Pierna Derecha
            glPushMatrix();
            glTranslatef(-0.2,-0.1,0.0);
            glScalef(0.3,0.35,0.3);
            piernaDrc.dibujarConSuavizado();
        glPopMatrix();
        
        // Pierna Izquierda    
        glPushMatrix();
            glTranslatef(0.2,-0.1,0.0);
            glScalef(0.3,0.35,0.3);
            piernaIzq.dibujarConSuavizado();
        glPopMatrix();

        // Cuerpo + Brazos + Cabeza
        glPushMatrix();
            glRotatef(grCadera,1.0,0.0,0.0);
            cuerpo.dibujarConSuavizado();
            // Brazos + cabeza
            glPushMatrix();
                // Brazo derecho
                glPushMatrix();
                    glTranslatef(-0.15,0.7,0.0);
                    glScalef(0.15,0.15,0.15);
                    brazoDrc.dibujarConSuavizado();
                glPopMatrix();

                // Brazo izquierdo
                glPushMatrix();
                    glTranslatef(0.15,0.7,0.0);
                    glScalef(-1.0,1.0,1.0);
                    glScalef(0.15,0.15,0.15);
                    brazoIzq.dibujarConSuavizado();
                glPopMatrix();

                // Cabeza
                glPushMatrix();
                    glTranslatef(0.0,0.8,0.0);
                    glScalef(0.12,0.12,0.12);
                    cabeza.dibujarConSuavizado();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void BartSimpson::dibujarPuntos(){
    // Bart completo
    glPushMatrix();
        glTranslatef(trasladarBart,0.0,0.0);
        glRotatef(rotarBartEnY,0.0,1.0,0.0);
        glScalef(4.5,4.5,4.5);
        //Pierna Derecha
            glPushMatrix();
            glTranslatef(-0.2,-0.1,0.0);
            glScalef(0.3,0.35,0.3);
            piernaDrc.dibujarPuntos();
        glPopMatrix();
        
        // Pierna Izquierda    
        glPushMatrix();
            glTranslatef(0.2,-0.1,0.0);
            glScalef(0.3,0.35,0.3);
            piernaIzq.dibujarPuntos();
        glPopMatrix();

        // Cuerpo + Brazos + Cabeza
        glPushMatrix();
            glRotatef(grCadera,1.0,0.0,0.0);
            cuerpo.dibujarPuntos();
            // Brazos + cabeza
            glPushMatrix();
                // Brazo derecho
                glPushMatrix();
                    glTranslatef(-0.15,0.7,0.0);
                    glScalef(0.15,0.15,0.15);
                    brazoDrc.dibujarPuntos();
                glPopMatrix();

                // Brazo izquierdo
                glPushMatrix();
                    glTranslatef(0.15,0.7,0.0);
                    glScalef(-1.0,1.0,1.0);
                    glScalef(0.15,0.15,0.15);
                    brazoIzq.dibujarPuntos();
                glPopMatrix();

                // Cabeza
                glPushMatrix();
                    glTranslatef(0.0,0.8,0.0);
                    glScalef(0.12,0.12,0.12);
                    cabeza.dibujarPuntos();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void BartSimpson::dibujarAlambre(){
    // Bart completo
    glPushMatrix();
        glTranslatef(trasladarBart,0.0,0.0);
        glRotatef(rotarBartEnY,0.0,1.0,0.0);
        glScalef(4.5,4.5,4.5);
        //Pierna Derecha
            glPushMatrix();
            glTranslatef(-0.2,-0.1,0.0);
            glScalef(0.3,0.35,0.3);
            piernaDrc.dibujarAlambre();
        glPopMatrix();
        
        // Pierna Izquierda    
        glPushMatrix();
            glTranslatef(0.2,-0.1,0.0);
            glScalef(0.3,0.35,0.3);
            piernaIzq.dibujarAlambre();
        glPopMatrix();

        // Cuerpo + Brazos + Cabeza
        glPushMatrix();
            glRotatef(grCadera,1.0,0.0,0.0);
            cuerpo.dibujarAlambre();
            // Brazos + cabeza
            glPushMatrix();
                // Brazo derecho
                glPushMatrix();
                    glTranslatef(-0.15,0.7,0.0);
                    glScalef(0.15,0.15,0.15);
                    brazoDrc.dibujarAlambre();
                glPopMatrix();

                // Brazo izquierdo
                glPushMatrix();
                    glTranslatef(0.15,0.7,0.0);
                    glScalef(-1.0,1.0,1.0);
                    glScalef(0.15,0.15,0.15);
                    brazoIzq.dibujarAlambre();
                glPopMatrix();

                // Cabeza
                glPushMatrix();
                    glTranslatef(0.0,0.8,0.0);
                    glScalef(0.12,0.12,0.12);
                    cabeza.dibujarAlambre();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void BartSimpson::dibujarAjedrez(){
    // Bart completo
    glPushMatrix();
        glTranslatef(trasladarBart,0.0,0.0);
        glRotatef(rotarBartEnY,0.0,1.0,0.0);
        glScalef(4.5,4.5,4.5);
        //Pierna Derecha
            glPushMatrix();
            glTranslatef(-0.2,-0.1,0.0);
            glScalef(0.3,0.35,0.3);
            piernaDrc.dibujarAjedrez();
        glPopMatrix();
        
        // Pierna Izquierda    
        glPushMatrix();
            glTranslatef(0.2,-0.1,0.0);
            glScalef(0.3,0.35,0.3);
            piernaIzq.dibujarAjedrez();
        glPopMatrix();

        // Cuerpo + Brazos + Cabeza
        glPushMatrix();
            glRotatef(grCadera,1.0,0.0,0.0);
            cuerpo.dibujarAjedrez();
            // Brazos + cabeza
            glPushMatrix();
                // Brazo derecho
                glPushMatrix();
                    glTranslatef(-0.15,0.7,0.0);
                    glScalef(0.15,0.15,0.15);
                    brazoDrc.dibujarAjedrez();
                glPopMatrix();

                // Brazo izquierdo
                glPushMatrix();
                    glTranslatef(0.15,0.7,0.0);
                    glScalef(-1.0,1.0,1.0);
                    glScalef(0.15,0.15,0.15);
                    brazoIzq.dibujarAjedrez();
                glPopMatrix();

                // Cabeza
                glPushMatrix();
                    glTranslatef(0.0,0.8,0.0);
                    glScalef(0.12,0.12,0.12);
                    cabeza.dibujarAjedrez();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void BartSimpson::moverCaderaArriba(){
    if(grCadera > maxMovArribaCadera)
        grCadera -= velocidadCadera;
}

void BartSimpson::moverCaderaAbajo(){
    if(grCadera < maxMovAbajoCadera)
        grCadera += velocidadCadera;
}

void BartSimpson::reset(){
    grCadera = 0.0;
    trasladarBart = 0.0;
    rotarBartDerecha = rotarBartIzquierda = false;
    movBartDerecha = true;
    movBartIzquierda = false;
    rotarBartEnY = 0.0;
    piernaDrc.reset();
    piernaIzq.reset();
    brazoDrc.reset();
    brazoIzq.reset();
    cabeza.reset();
}

void BartSimpson::setRotacionBart(GLfloat nuevaRotacionBart){
    rotarBartEnY = nuevaRotacionBart;
}

bool BartSimpson::getMovPiernaDerDelante() const{
    return movPiernaDerDelante;
}

bool BartSimpson::getMovPiernaIzqDelante() const{
    return movPiernaIzqDelante;
}

void BartSimpson::setMovPiernaDerDelante(){
    movPiernaDerDelante = !movPiernaDerDelante;
}

void BartSimpson::setMovPiernaIzqDelante(){
    movPiernaIzqDelante = !movPiernaIzqDelante;
}

void BartSimpson::traslacionBart(){
    if(rotarBartDerecha || rotarBartIzquierda){
        if(rotarBartDerecha){
            if(rotarBartEnY != -90.0)
                rotarBartEnY -= velocidadGlobal;
            else
                rotarBartDerecha = false;
        }
        else{
            if(rotarBartEnY != 90.0)
                rotarBartEnY += velocidadGlobal;
            else
                rotarBartIzquierda = false;
        }
    }
    else{
        if(movBartDerecha)
            trasladarBart += (velocidadGlobal+5.0)/100.0;
    
        if(movBartIzquierda)
            trasladarBart -= (velocidadGlobal+5.0)/100.0;

        if(trasladarBart >= topeTraslacionDerecha){
            movBartDerecha = false;
            movBartIzquierda = true;
            rotarBartDerecha = true;
        }

        if(trasladarBart <= topeTraslacionIzquierda){
            movBartIzquierda = false;
            movBartDerecha = true;
            rotarBartIzquierda = true;
        }
    }
}

bool BartSimpson::getRotarBartIzquierda() const{
    return rotarBartIzquierda;
}
bool BartSimpson::getRotarBartDerecha() const{
    return rotarBartDerecha;
}

bool BartSimpson::incrementarVelocidadGlobal(){
    bool incrementado = false;
    if(velocidadGlobal < 15.0){
        velocidadGlobal += 5.0;
        velocidadCadera = velocidadGlobal;
        
        brazoDrc.incrementarVelocidadGlobal(velocidadGlobal);
        brazoIzq.incrementarVelocidadGlobal(velocidadGlobal);
        piernaDrc.incrementarVelocidadGlobal(velocidadGlobal);
        piernaIzq.incrementarVelocidadGlobal(velocidadGlobal);
        cabeza.incrementarVelocidadGlobal(velocidadGlobal);

        incrementado = true;
    }
    return incrementado;
}

bool BartSimpson::decrementarVelocidadGlobal(){
    bool decrementado = false;
    if(velocidadGlobal > 5.0){
        velocidadGlobal -= 5.0;
        velocidadCadera = velocidadGlobal;
        
        brazoDrc.decrementarVelocidadGlobal(velocidadGlobal);
        brazoIzq.decrementarVelocidadGlobal(velocidadGlobal);
        piernaDrc.decrementarVelocidadGlobal(velocidadGlobal);
        piernaIzq.decrementarVelocidadGlobal(velocidadGlobal);
        cabeza.decrementarVelocidadGlobal(velocidadGlobal);

        decrementado = true;
    }   
    return decrementado;
}

bool BartSimpson::incrementarVelocidadCadera(){
    bool incrementado = false;
    if(velocidadCadera < 15.0){
        velocidadCadera += 5.0;
        incrementado = true;
    }
    return incrementado;
}

bool BartSimpson::decrementarVelocidadCadera(){
    bool decrementado = false;
    if(velocidadCadera > 5.0){
        velocidadCadera -= 5.0;
        decrementado = true;
    }
    return decrementado;
}

//**************************************************************************
// Funcion que muestras las instrucciones de como mover a Bart
//***************************************************************************
void BartSimpson::mostrarAyudaBart(){
  system("clear");
  
  cout << endl << "\tINSTRUCCIONES DE COMO MOVER A BART" << endl << endl;

  cout << "Pulsa la tecla H/h para volver a mostrar esta ayuda en cualquier momento" << endl;
  cout << "Pulsa la tecla R/r para volver a poner a Bart en su posicion inicial" << endl;
  cout << "Pulsa la tecla ESPACIO para iniciar/detener la animación automatica de Bart" << endl << endl;
  
  cout << "Pulsa la tecla * para INCREMENTAR la VELOCIDAD GLOBAL" << endl;
  cout << "Pulsa la tecla / para DECREMENTAR la VELOCIDAD GLOBAL" << endl << endl;

  cout << "Pulsa la tecla ['u' para INCREMENTAR / 'U' para DECREMENTAR] la VELOCIDAD DE LA CADERA" << endl;
  cout << "Pulsa la tecla ['i' para INCREMENTAR / 'I' para DECREMENTAR] la VELOCIDAD DE LOS BRAZOS" << endl;
  cout << "Pulsa la tecla ['o' para INCREMENTAR / 'O' para DECREMENTAR] la VELOCIDAD DE LAS PIERNAS" << endl;

	cout << endl << "########  PASO 1: SELECCIONAR PARTE CUERPO ########" << endl << endl;

	cout << "\tW --> Selecciona cabeza" << endl;
	cout << "\tA --> Selecciona brazo derecho" << endl;
	cout << "\tS --> Selecciona Cuerpo" << endl;
	cout << "\tD --> Selecciona brazo izquierdo" << endl;
	cout << "\tZ --> Selecciona pierna derecha" << endl;
	cout << "\tX --> Selecciona pierna izquierda" << endl;

	cout << endl << "########  PASO 2: SELECCIONAR GRADO DE LIBERTAD ########" << endl << endl;
  
  cout << "\t, --> Selecciona 1er grado de libertad." << endl;
  cout << "\t. --> Selecciona 2o grado de libertad." << endl;
  cout << "\t- --> Selecciona 3er grado de libertad." << endl;

  cout << endl << "NOTA: no todas las partes seleccionables cuentan con 3 grados de libertad" << endl;

  cout << endl << "######## PASO 3: REALIZAR MOVIMIENTO ########" << endl << endl;
  
    cout << "\tw --> Rotacion en X hacia ARRIBA" << endl;
    cout << "\ts --> Rotacion en X hacia ABAJO" << endl;
    cout << "\ta --> Rotacion en Y hacia IZQUIERDA" << endl;
    cout << "\td --> Rotacion en Y hacia DERECHA" << endl;

    cout << endl << "NOTA: no todos los grados de libertad pueden realizar los 4 tipos de rotaciones" << endl;

    cout << "----------------------------------------------------------------------------------" << endl << endl;

}