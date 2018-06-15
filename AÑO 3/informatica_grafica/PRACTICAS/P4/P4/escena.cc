/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifdef _WIN32
#include <windows.h>
#endif

#include "escena.h"


Escena::Escena(){
    Front_plane=40;
    Back_plane=2000;
    Observer_distance = 2*Front_plane;
    Observer_angle_x = Observer_angle_y = 0;
    ejes.changeAxisSize(10000);

    // Inicializo los objetos3D
    miTetraedro = Tetraedro(5.0,3.25);
    miCubo = Cubo(1.5);
    miRombo = Rombo (5.0, 3.8);
    miPiramide = Piramide(5.0, 4.0);
    miObjetoPerfilRevolucion = ObjetoPerfilRevolucion(3);
    miObjetoPerfilBarrido = ObjetoPerfilBarrido(4,5.0);
    miBartSimpson = BartSimpson();

    miEscenaP4 = EscenaP4();

    iluminacionActiva = false;
    suavizadoActivo = false;
    Object3D::setMaterialActivo(0);
    orientacionTextura = 0;
    offset = 0.0;

    //POSICION/COLOR INICIAL LUZ DIRECCIONAL Y POSICIONAL
    _vertex4f ambiente(0.1,0.1,0.1,1.0);
    _vertex4f difuso(1.0,1.0,1.0,1.0);
    _vertex4f especular(1.0,1.0,1.0,1.0);
    _vertex4f posicion(0.0,0.0,1.0,0.0);
    luzDireccional = Luz(ambiente,difuso,especular,posicion);
    ambiente = _vertex4f(0.1,0.1,0.1,1.0);
    posicion = _vertex4f(0.0,150.0,0.0,1.0);
    luzPosicional = Luz(ambiente, difuso, especular, posicion);

    objetos.push_back(&miTetraedro);
    objetos.push_back(&miCubo);
    objetos.push_back(&miRombo);
    objetos.push_back(&miPiramide);
    objetos.push_back(&miObjetoPerfilRevolucion);
    objetos.push_back(&miObjetoPerfilBarrido);

    //Ponemos el modo de pintar en solido por defecto
    pintaAlambre = pintaPuntos = pintaAjedrez = false;
    pintaSolido = true;

    // No se ha pasado un objeto ply por parametros, por lo que no se ha cargado
    objetoPlyBienCargado = perfilPlyRevolucionBienCargado = perfilPlyBarridoBienCargado = false;

    // No pintar nada por defecto
    objetoActivo = -1;

    // Parte Bart a mover y grado de libertad seleccionado inicialmente ninguno
    parteBartAMover = gradoLibertadSeleccionado = -1;

    // Animacion desactivada por defecto
    animacionActiva = false;
}

Escena::Escena(const std::string &ply_file) : Escena(){
    miObjetoPLY = ObjetoPLY(ply_file);
    if(miObjetoPLY.getIsFileReaded()){
      objetos.push_back(&miObjetoPLY);
      objetoPlyBienCargado = true;
      cout << "Objeto CARGADO correctamente del fichero " << ply_file << endl;
    }
    else{
      objetoPlyBienCargado = false;
      cout << "ERROR: Objeto NO CARGADO correctamente, revise el fichero " << ply_file << endl;
    }
}

Escena::Escena(const std::string &ply_file, const int &nSegmentos, string eje) : Escena(){
  miObjetoPerfilRevolucionPLY = ObjetoPerfilRevolucion(ply_file,nSegmentos,eje);
  if(miObjetoPerfilRevolucionPLY.getIsFileReaded()){
    objetos.push_back(&miObjetoPerfilRevolucionPLY);
    perfilPlyRevolucionBienCargado = true;
    cout << "Perfil para revolucion CARGADO correctamente del fichero " << ply_file << endl;
  }
  else{
    perfilPlyRevolucionBienCargado = false;
    cout << "ERROR: Perfil para revolucion NO CARGADO correctamente, revise el fichero" << ply_file << endl;
  }
}

Escena::Escena(const std::string &ply_file, const int &nSegmentos, const float &longitud) : Escena(){
  miObjetoPerfilBarridoPLY = ObjetoPerfilBarrido(ply_file,nSegmentos,longitud);
  if(miObjetoPerfilBarridoPLY.getIsFileReaded()){
    objetos.push_back(&miObjetoPerfilBarridoPLY);
    perfilPlyBarridoBienCargado = true;
    cout << "Perfil para barrido CARGADO correctamente del fichero " << ply_file << endl;
  }
  else{
    perfilPlyBarridoBienCargado = false;
    cout << "ERROR: Perfil para barrido NO CARGADO correctamente, revise el fichero" << ply_file << endl;
  }
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {
  // Miramos el modo de dibujar activo y llamamos a la funcion determinada
  if(objetoActivo != -1){
    if(objetoActivo == 7){
      if(pintaAlambre)
        miBartSimpson.dibujarAlambre();
      else if(pintaPuntos)
        miBartSimpson.dibujarPuntos();
      else if(pintaSolido){
        if(!iluminacionActiva)
          miBartSimpson.dibujarSolido();
        else
          if(suavizadoActivo)
            miBartSimpson.dibujarConSuavizado();
          else
            miBartSimpson.dibujarSinSuavizado();
      }
      else
        miBartSimpson.dibujarAjedrez();
    }
    else if(objetoActivo == 8){
      if(pintaAlambre)
        miEscenaP4.dibujarAlambre();
      else if(pintaPuntos)
        miEscenaP4.dibujarPuntos();
      else if(pintaSolido){
        if(!iluminacionActiva)
          miEscenaP4.dibujarSolido();
        else
          if(suavizadoActivo)
            miEscenaP4.dibujarConSuavizado();
          else
            miEscenaP4.dibujarSinSuavizado();
      }
      else
        miEscenaP4.dibujarAjedrez();
    }
    else if(objetoActivo == 9){
      dibujarTextura();
    }  
    else{
      parteBartAMover = gradoLibertadSeleccionado = -1;
      if(pintaAlambre)
        objetos[objetoActivo]->dibujarAlambre();
      else if(pintaPuntos)
        objetos[objetoActivo]->dibujarPuntos();
      else if(pintaSolido){
        if(!iluminacionActiva)
          objetos[objetoActivo]->dibujarSolido();
        else
          if(suavizadoActivo)
            objetos[objetoActivo]->dibujarConSuavizado();
          else
            objetos[objetoActivo]->dibujarSinSuavizado();
      }
      else
        objetos[objetoActivo]->dibujarAjedrez();
    }
  }
}

void Escena::dibujar() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
  if(iluminacionActiva){
    luzDireccional.posicionarLuz(0);
    luzPosicional.posicionarLuz(1);
    glEnable(GL_LIGHTING);
    luzDireccional.activarLuz(0);
    luzPosicional.activarLuz(1);
  }
  else{
    glDisable(GL_LIGHTING);
    luzDireccional.desactivarLuz(0);
    luzPosicional.desactivarLuz(1);
  }
	draw_axis();
	draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla,int x,int y) {
  if(objetoActivo != 7)
    std::cout << "Tecla " << Tecla<< std::endl;
  
  if (toupper(Tecla)=='Q'){
    cout << "Hasta luego! :)" << endl;
    return 1;
  }
  else if(toupper(Tecla)=='P') // Puntos
    return 2;
  else if(toupper(Tecla)=='L') // Lineas/Aristas
    return 3;
  else if(toupper(Tecla)=='F') // Relleno
    return 4;
  else if(toupper(Tecla)=='C') // Ajedrez
    return 5;
  else if(toupper(Tecla)=='1'){ // Activar tetraedro
    mostrarInstruccionesUso();
    return 6;
  }
  else if(toupper(Tecla)=='2'){ // Activar cubo
    mostrarInstruccionesUso();
    return 7;
  }
  else if(toupper(Tecla)=='3'){ // Activar rombo
    mostrarInstruccionesUso();
    return 8;
  }
  else if(toupper(Tecla)=='4'){ // Activar piramide
    mostrarInstruccionesUso();
    return 9;
  }
  else if(toupper(Tecla)=='5' && (objetoPlyBienCargado || perfilPlyRevolucionBienCargado || perfilPlyBarridoBienCargado)){ // Activar objeto PLY
    mostrarInstruccionesUso();
    return 10;
  }
  else if(toupper(Tecla)=='6'){ // Activar objeto perfil por revolucion estático
    mostrarInstruccionesUso();
    return 11;
  }
  else if(toupper(Tecla)=='7'){ // Activar perfil por barrido
    mostrarInstruccionesUso();
    return 12;
  }
  else if(toupper(Tecla) == '8'){ // Activar modelo jerarquico
    miBartSimpson.mostrarAyudaBart();
    return 13;
  }
  else if(toupper(Tecla) == '9'){ // Activar escena P4
    mostrarInstruccionesUso();
    return 14;
  }
  else if(toupper(Tecla) == '0'){ // Activar textura
    mostrarInstruccionesUso();
    iluminacionActiva = true;
    return 16;
  }
  else if(toupper(Tecla) == 'I'){ // Activar/desactivar iluminacion
    activarDesactivarIluminacion();
  }
  else if(toupper(Tecla) == 'G'){ // Activar/desactivar suavizado
    activarDesactivarSuavizado();
  }
  else if(objetoActivo == 7 && toupper(Tecla) == 'H'){
    miBartSimpson.mostrarAyudaBart();
  }
  else if(objetoActivo == 7 && toupper(Tecla) == 'R' && !animacionActiva){
    miBartSimpson.reset();
    parteBartAMover = gradoLibertadSeleccionado = -1;
    draw_objects();
  }
  else if(objetoActivo == 7 && Tecla == '*' && !miBartSimpson.getRotarBartDerecha() && !miBartSimpson.getRotarBartIzquierda()){ // Incrementar velocidad global de movimiento
    if(miBartSimpson.incrementarVelocidadGlobal())
      cout << "Velocidad GLOBAL incrementada" << endl;
    else
      cout << "ERROR! No se puede incrementar mas la velocidad GLOBAL" << endl;
  }
  else if(objetoActivo == 7 && Tecla == '/' && !miBartSimpson.getRotarBartDerecha() && !miBartSimpson.getRotarBartIzquierda()){ // Decrementar velocidad global de movimiento
    if(miBartSimpson.decrementarVelocidadGlobal())
        cout << "Velocidad GLOBAL decrementada" << endl;
      else
        cout << "ERROR! No se puede decrementar mas la velocidad GLOBAL" << endl;
  }
  else if(objetoActivo == 7 && Tecla == 'u' && !miBartSimpson.getRotarBartDerecha() && !miBartSimpson.getRotarBartIzquierda()){
    if(miBartSimpson.incrementarVelocidadCadera())
      cout << "Velocidad de la CADERA incrementada" << endl;
    else
      cout << "ERROR! No se puede incrementar mas la velocidad de la CADERA" << endl;
  }
  else if(objetoActivo == 7 && Tecla == 'U' && !miBartSimpson.getRotarBartDerecha() && !miBartSimpson.getRotarBartIzquierda()){
    if(miBartSimpson.decrementarVelocidadCadera())
      cout << "Velocidad de la CADERA decrementada" << endl;
    else
      cout << "ERROR! No se puede decrementar mas la velocidad de la CADERA" << endl;
  }
  else if(objetoActivo == 7 && Tecla == 'i' && !miBartSimpson.getRotarBartDerecha() && !miBartSimpson.getRotarBartIzquierda()){
    if(miBartSimpson.brazoDrc.incrementarVelocidadHombro() && miBartSimpson.brazoIzq.incrementarVelocidadHombro())
      cout << "Velocidad de los BRAZOS incrementada" << endl;
    else
      cout << "ERROR! No se puede incrementar mas la velocidad de los BRAZOS" << endl;
  }
  else if(objetoActivo == 7 && Tecla == 'I' && !miBartSimpson.getRotarBartDerecha() && !miBartSimpson.getRotarBartIzquierda()){
    if(miBartSimpson.brazoDrc.decrementarVelocidadHombro() && miBartSimpson.brazoIzq.decrementarVelocidadHombro())
      cout << "Velocidad de los BRAZOS decrementada" << endl;
    else
      cout << "ERROR! No se puede decrementar mas la velocidad de los BRAZOS" << endl;
  }
  else if(objetoActivo == 7 && Tecla == 'o' && !miBartSimpson.getRotarBartDerecha() && !miBartSimpson.getRotarBartIzquierda()){
    if(miBartSimpson.piernaDrc.incrementarVelocidadPierna() && miBartSimpson.piernaIzq.incrementarVelocidadPierna())
      cout << "Velocidad de las PIERNAS incrementada" << endl;
    else
      cout << "ERROR! No se puede incrementar mas la velocidad de las PIERNAS" << endl;
  }
  else if(objetoActivo == 7 && Tecla == 'O' && !miBartSimpson.getRotarBartDerecha() && !miBartSimpson.getRotarBartIzquierda()){
    if(miBartSimpson.piernaDrc.decrementarVelocidadPierna() && miBartSimpson.piernaIzq.decrementarVelocidadPierna())
      cout << "Velocidad de las PIERNAS decrementada" << endl;
    else
      cout << "ERROR! No se puede decrementar mas la velocidad de las PIERNAS" << endl;
  }
  else if(objetoActivo == 7 && Tecla == ' '){   // Animar bart simpson
    animacionActiva = !animacionActiva;
    if(animacionActiva){
      miBartSimpson.brazoDrc.setGradosHombro(180.0);
      miBartSimpson.setRotacionBart(90.0);
      miBartSimpson.piernaDrc.setGrCadera(-60.0);
      miBartSimpson.piernaIzq.setGrCadera(60.0);
    }
    else{
      miBartSimpson.reset();
      miBartSimpson.setRotacionBart(0.0);
      miBartSimpson.piernaDrc.setGrCadera(0.0);
      miBartSimpson.piernaIzq.setGrCadera(0.0);
    }
  }
  else if(objetoActivo == 7 && !animacionActiva){
    controlDeTeclasBart(Tecla);
    draw_objects();
  }
  else if(toupper(Tecla)=='\'') // Activar modo no pintar
    return 15;
  else if(toupper(Tecla)=='+' && (objetoActivo == 4 || objetoActivo == 5 || (objetoActivo == 6 && perfilPlyRevolucionBienCargado) || (objetoActivo == 6 && perfilPlyBarridoBienCargado))){ // Incrementar nSegmentos de objeto perfilRevolucion/perfilBarrido
    if(objetoActivo == 4 || (objetoActivo == 6 && perfilPlyRevolucionBienCargado))
      static_cast<ObjetoPerfilRevolucion*>(objetos[objetoActivo])->incrementarNSegmentos();
    else
      static_cast<ObjetoPerfilBarrido*>(objetos[objetoActivo])->incrementarNSegmentos();
    return 0;
  }
  else if(toupper(Tecla)=='-' && (objetoActivo == 4 || objetoActivo == 5 || (objetoActivo == 6 && perfilPlyRevolucionBienCargado) || (objetoActivo == 6 && perfilPlyBarridoBienCargado))){ // Decrementar nSegmentos de objeto perfilRevolucion/perfilBarrido
    if(objetoActivo == 4 || (objetoActivo == 6 && perfilPlyRevolucionBienCargado))
      static_cast<ObjetoPerfilRevolucion*>(objetos[objetoActivo])->decrementarNSegmentos();
    else
      static_cast<ObjetoPerfilBarrido*>(objetos[objetoActivo])->decrementarNSegmentos();
    return 0;
  }
  else if(toupper(Tecla)=='T' && (objetoActivo == 4 || objetoActivo == 5 || (objetoActivo == 6 && perfilPlyRevolucionBienCargado))){ // Pintar despintar tapas perfilRevolucion
    bool estanTapasPintadas = static_cast<ObjetoPerfilRevolucion*>(objetos[objetoActivo])->getEstanTapasPintadas();
    int queTapaPuedoPintarODespintar = static_cast<ObjetoPerfilRevolucion*>(objetos[objetoActivo])->getQueTapaPuedoPintarODespintar();

    if(!estanTapasPintadas)
      static_cast<ObjetoPerfilRevolucion*>(objetos[objetoActivo])->addTapasCorrespondientes(queTapaPuedoPintarODespintar);
    else
      static_cast<ObjetoPerfilRevolucion*>(objetos[objetoActivo])->deleteTapasCorrespondientes(queTapaPuedoPintarODespintar);

    static_cast<ObjetoPerfilRevolucion*>(objetos[objetoActivo])->setEstanTapasPintadas();
    return 0;
  }
  else if(toupper(Tecla)=='H' && !animacionActiva)
    mostrarInstruccionesUso();
	else return 0;
}

void Escena::setPintaAjedrez(){
  if(objetoActivo != -1){
    pintaAlambre = pintaPuntos = pintaSolido = false;
    pintaAjedrez = true;
  }
}

void Escena::setPintaAlambre(){
  if(objetoActivo != -1){
    pintaAjedrez = pintaPuntos = pintaSolido = false;
    pintaAlambre = true;
  }
}

void Escena::setPintaPuntos(){
  if(objetoActivo != -1){
    pintaAlambre = pintaAjedrez = pintaSolido = false;
    pintaPuntos = true;
  }
}

void Escena::setPintaSolido(){
  if(objetoActivo != -1){
    pintaAlambre = pintaPuntos = pintaAjedrez = false;
    pintaSolido = true;
  }
}

void Escena::setObjetoActivo(int numObjeto){
  objetoActivo = numObjeto;
}

void Escena::teclaEspecial(int Tecla,int x,int y) {
switch (Tecla){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
  case GLUT_KEY_F3: Object3D::setMaterialActivo(1); cout << "Activado material RUBI" << endl; break;
  case GLUT_KEY_F4: Object3D::setMaterialActivo(2); cout << "Activado material ORO" << endl; break;
  case GLUT_KEY_F5: Object3D::setMaterialActivo(3); cout << "Activado material TURQUESA" << endl;break;
  case GLUT_KEY_F6: Object3D::setMaterialActivo(0); cout << "Material desactivado" << endl;break;
  case GLUT_KEY_F1: luzDireccional.incrementarRotacionLuz1(); cout << "Moviendo luz direccional" << endl;break;
  case GLUT_KEY_F2: luzPosicional.incrementarRotacionLuz2(); cout << "Moviendo luz posicional" << endl;break;
  case GLUT_KEY_F7: // Girar textura
    orientacionTextura += 90; 
    orientacionTextura %= 360; 
    cout << "Textura en "  << orientacionTextura << " grados" << endl;
  break;
  case GLUT_KEY_F8: //Offset textura
    offset -= 0.05;
    if(offset == -1.0)
      offset = 0.0; 
  break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformaci�n de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
// Width=newWidth / denominador;
// Height=newHeight / denominador;
Width = Height = 5;
change_projection();
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformaci�n de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}


//**************************************************************************
// Funcion que muestras las instrucciones de uso
//***************************************************************************
void Escena::mostrarInstruccionesUso(){
  system("clear");
	cout << endl << "#############  INSTRUCCIONES DE USO ################" << endl << endl; 

  cout << "Pulsa la tecla H/h para mostrar esta ayuda en cualquier momento" << endl;

	cout << "Tecla 1 --> Activa tetraedro" << endl;
	cout << "Tecla 2 --> Activa cubo" << endl;
	cout << "Tecla 3 --> Activa rombo" << endl;
	cout << "Tecla 4 --> Activa piramide" << endl;
	cout << "Tecla 5 --> Activa objetos PLY (PLY, Revolución o Barrido)" << endl;
	cout << "Tecla 6 --> Activa perfil por revolución" << endl;
  cout << "Tecla 7 --> Activa perfil por barrido" << endl;
  cout << "Tecla 8 --> Activa modelo jerarquico (Bart Simpson)" << endl;
  cout << "Tecla 9 --> Activa la escena de la Practica 4" << endl;
  cout << "Tecla 0 --> Activa la textura" << endl;
	cout << "Tecla ' --> No pinta nada" << endl;

	cout << endl << "Tecla p/P --> Dibuja la figura actual en modo puntos" << endl;
	cout << "Tecla l/L --> Dibuja la figura actual en modo lineas" << endl;
	cout << "Tecla c/C --> Dibuja la figura actual en modo ajedrez" << endl;
	cout << "Tecla f/F --> Dibuja la figura actual en modo solido" << endl;
	cout << "Tecla h/H --> Muestra las instrucciones de uso por pantalla" << endl << endl;

  cout << "-- ILUMINACION --" << endl << endl;
  cout << "Tecla i/I --> Activa/desactiva la iluminación" << endl;
  cout << "Tecla g/G --> Alterna entre el suavizado plano y el suavizado de Gouraud" << endl;
  cout << "Tecla F1 --> Cambia la posicion de la luz direccional" << endl;
  cout << "Tecla F2 --> Cambia la posicion de la luz posicional" << endl;
  cout << "Tecla F3 --> Activa el material RUBI" << endl;
  cout << "Tecla F4 --> Activa el material ORO" << endl;
  cout << "Tecla F5 --> Activa el material TURQUESA" << endl;
  cout << "Tecla F6 --> Desactiva cualquier material activo" << endl << endl;

  cout << "-- TEXTURA --" << endl;
  cout << "Tecla F7 --> Gira la textura +90º" << endl;
  cout << "Tecla F8 --> Realiza el offset de la textura" << endl;

	cout << endl << "####################################################" << endl << endl;
}

//**************************************************************************
// Control de teclas de Bart
//***************************************************************************
void Escena::controlDeTeclasBart(unsigned char Tecla){
  // Seleccionar parte del cuerpo
  if(Tecla == 'W'){
    parteBartAMover = 0;
    cout << "Has seleccionado la CABEZA de Bart" << endl;
    cout << "No hace falta seleccionar un grado de libertad para esta parte del cuerpo" << endl;
    cout << "AHORA PUEDES REALIZAR MOVIMIENTOS" << endl << endl;
    gradoLibertadSeleccionado = -1;
  }
  else if(Tecla == 'A'){
    parteBartAMover = 1;
    cout << "Has seleccionado el BRAZO DERECHO de Bart" << endl;
    gradoLibertadSeleccionado = -1;
  }
  else if(Tecla == 'S'){
    parteBartAMover = 2;
    cout << "Has seleccionado el CUERPO de Bart" << endl;
    cout << "No hace falta seleccionar un grado de libertad para esta parte del cuerpo" << endl;
    cout << "AHORA PUEDES REALIZAR MOVIMIENTOS" << endl << endl;
    gradoLibertadSeleccionado = -1;
  }
  else if(Tecla == 'D'){
    parteBartAMover = 3;
    cout << "Has seleccionado el BRAZO IZQUIERDO de Bart" << endl;
    gradoLibertadSeleccionado = -1;
  }
  else if(Tecla == 'Z'){
    parteBartAMover = 4;
    cout << "Has seleccionado la PIERNA DERECHA de Bart" << endl;
    gradoLibertadSeleccionado = -1;
  }
  else if(Tecla == 'X'){
    parteBartAMover = 5;
    cout << "Has seleccionado la PIERNA IZQUIERDA de Bart" << endl;
    gradoLibertadSeleccionado = -1;
  }

  // Si se ha seleccionado una parte del cuerpo se puede pasar a seleccionar un grado de libertad
  if(parteBartAMover != -1){
    // Seleccionar grado de libertad de la parte del cuerpo seleccionada
    if(parteBartAMover == 0 || parteBartAMover == 2){   // Cabeza o Cuerpo
      gradoLibertadSeleccionado = 0;
    }
    else if(parteBartAMover == 1 || parteBartAMover == 3){ // Brazos
      if(Tecla == ','){
        gradoLibertadSeleccionado = 0;
        cout << "Has seleccionado el 1er grado de libertad" << endl;
        cout << "AHORA PUEDES REALIZAR MOVIMIENTOS" << endl << endl;
      }
      else if(Tecla == '.'){
        gradoLibertadSeleccionado = 1;
        cout << "Has seleccionado el 2o grado de libertad" << endl;
        cout << "AHORA PUEDES REALIZAR MOVIMIENTOS" << endl << endl;
      }
    }
    else if(parteBartAMover == 4 || parteBartAMover == 5){ // Piernas
      if(Tecla == ','){
        gradoLibertadSeleccionado = 0;
        cout << "Has seleccionado el 1er grado de libertad" << endl;
        cout << "AHORA PUEDES REALIZAR MOVIMIENTOS" << endl << endl;
      }
      else if(Tecla == '.'){
        gradoLibertadSeleccionado = 1;
        cout << "Has seleccionado el 2o grado de libertad" << endl;
        cout << "AHORA PUEDES REALIZAR MOVIMIENTOS" << endl << endl;
      }
      else if(Tecla == '-'){
        gradoLibertadSeleccionado = 2;
        cout << "Has seleccionado el 3er grado de libertad" << endl;
        cout << "AHORA PUEDES REALIZAR MOVIMIENTOS" << endl << endl;
      }
    }

    // Si se han seleccionado tanto la parte del cuerpo como el grado de libertad se puede realizar el movimiento
    if(gradoLibertadSeleccionado != -1){  
      if(parteBartAMover == 0){   // Cabeza
        if(Tecla == 'a'){ // Mover hacia izquierda
          // Rotacion en y hacia <--
          miBartSimpson.cabeza.moverCabezaDerecha(); // Derecha de BART
        }
        else if(Tecla == 'd'){ // Mover hacia derecha
          // Rotacion en y hacia -->
          miBartSimpson.cabeza.moverCabezaIzquierda(); // Izquierda de BART
        }
        else if(Tecla == 'w' || Tecla == 's'){
          cout << "Movimiento no permitido en la CABEZA" << endl;
        }
      }
      else if(parteBartAMover == 1){  // Brazo derecho
        if(Tecla == 'w'){ // Mover hacia delante
          // Rotacion en x hacia arriba
          if(gradoLibertadSeleccionado == 0)
            miBartSimpson.brazoDrc.moverHombroArriba();
          else if(gradoLibertadSeleccionado == 1)
            miBartSimpson.brazoDrc.moverCodoArriba();
        }
        else if(Tecla == 's'){ // Mover hacia atras
          // Rotacion en x hacia abajo
          if(gradoLibertadSeleccionado == 0)
            miBartSimpson.brazoDrc.moverHombroAbajo();
          else if(gradoLibertadSeleccionado == 1)
            miBartSimpson.brazoDrc.moverCodoAbajo();
        }
        else if(Tecla == 'a' || Tecla == 'd'){
          cout << "Movimiento no permitido en el BRAZO DERECHO" << endl;
        }
      }
      else if(parteBartAMover == 2){  // Cuerpo
        if(Tecla == 'w'){ // Mover hacia arriba
          // Rotacion en x hacia arriba
          miBartSimpson.moverCaderaArriba();
        }
        else if(Tecla == 's'){ // Mover hacia abajo
          // Rotacion en x hacia abajo
          miBartSimpson.moverCaderaAbajo();
        }
        else if(Tecla == 'a' || Tecla == 'd'){
          cout << "Movimiento no permitido en el CUERPO" << endl;
        }
      }
      else if(parteBartAMover == 3){  // Brazo izquierdo
        if(Tecla == 'w'){ // Mover hacia delante
          // Rotacion en x hacia arriba
          if(gradoLibertadSeleccionado == 0)
            miBartSimpson.brazoIzq.moverHombroArriba();
          else if(gradoLibertadSeleccionado == 1)
            miBartSimpson.brazoIzq.moverCodoArriba();
        }
        else if(Tecla == 's'){ // Mover hacia atras
          // Rotacion en x hacia abajo
          if(gradoLibertadSeleccionado == 0)
            miBartSimpson.brazoIzq.moverHombroAbajo();
          else if(gradoLibertadSeleccionado == 1)
            miBartSimpson.brazoIzq.moverCodoAbajo();
        }
        else if(Tecla == 'a' || Tecla == 'd'){
          cout << "Movimiento no permitido en el BRAZO IZQUIERDO" << endl;
        }
      }
      else if(parteBartAMover == 4){  // Pierna derecha
        if(Tecla == 'w'){ // Mover hacia delante
          if(gradoLibertadSeleccionado == 0) // Cadera
            miBartSimpson.piernaDrc.moverCaderaDelante();
          else if(gradoLibertadSeleccionado == 1) // Rodilla
            miBartSimpson.piernaDrc.moverRodillaDelante();
          else if(gradoLibertadSeleccionado == 2) // Tobillo
            miBartSimpson.piernaDrc.moverTobilloArriba();
        }
        else if(Tecla == 's'){ // Mover hacia atras
          if(gradoLibertadSeleccionado == 0) // Cadera
            miBartSimpson.piernaDrc.moverCaderaDetras();
          else if(gradoLibertadSeleccionado == 1) // Rodilla
            miBartSimpson.piernaDrc.moverRodillaDetras();
          else if(gradoLibertadSeleccionado == 2) // Tobillo
            miBartSimpson.piernaDrc.moverTobilloAbajo();
        }
        else if(Tecla == 'a' || Tecla == 'd'){
          cout << "Movimiento no permitido en la PIERNA DERECHA" << endl;
        }
      }
      else if(parteBartAMover == 5){  // Pierna izquierda
        if(Tecla == 'w'){ // Mover hacia delante
          if(gradoLibertadSeleccionado == 0) // Cadera
            miBartSimpson.piernaIzq.moverCaderaDelante();
          else if(gradoLibertadSeleccionado == 1) // Rodilla
            miBartSimpson.piernaIzq.moverRodillaDelante();
          else if(gradoLibertadSeleccionado == 2) // Tobillo
            miBartSimpson.piernaIzq.moverTobilloArriba();
        }
        else if(Tecla == 's'){ // Mover hacia atras
          if(gradoLibertadSeleccionado == 0) // Cadera
            miBartSimpson.piernaIzq.moverCaderaDetras();
          else if(gradoLibertadSeleccionado == 1) // Rodilla
            miBartSimpson.piernaIzq.moverRodillaDetras();
          else if(gradoLibertadSeleccionado == 2) // Tobillo
            miBartSimpson.piernaIzq.moverTobilloAbajo();
        }
        else if(Tecla == 'a' || Tecla == 'd'){
          cout << "Movimiento no permitido en la PIERNA IZQUIERDA" << endl;
        }
      }
    }
    else
      cout << "Aun no has seleccionado ningun grado de libertad" << endl << endl;
  }
  else
    cout << "Aun no has seleccionado que parte de Bart deseas mover" << endl << endl;  
}

bool Escena::getAnimacionActiva(){
  return animacionActiva;
}

void Escena::animarBart(){
    // Movimiento brazos
      miBartSimpson.brazoDrc.moverHombroAbajo();
      miBartSimpson.brazoIzq.moverHombroAbajo();
    
    // Movimiento pierna derecha
      if(miBartSimpson.getMovPiernaDerDelante())
        miBartSimpson.piernaDrc.moverCaderaDelante();
      else
        miBartSimpson.piernaDrc.moverCaderaDetras();
      
      if(miBartSimpson.piernaDrc.getTopeDelanteCaderaAlcanzado())
        miBartSimpson.setMovPiernaDerDelante();
      if(miBartSimpson.piernaDrc.getTopeDetrasCaderaAlcanzado())
        miBartSimpson.setMovPiernaDerDelante();

    // Movimiento pierna izquierda
      if(miBartSimpson.getMovPiernaIzqDelante())
        miBartSimpson.piernaIzq.moverCaderaDelante();
      else
        miBartSimpson.piernaIzq.moverCaderaDetras();
      
      if(miBartSimpson.piernaIzq.getTopeDelanteCaderaAlcanzado())
        miBartSimpson.setMovPiernaIzqDelante();
      if(miBartSimpson.piernaIzq.getTopeDetrasCaderaAlcanzado())
        miBartSimpson.setMovPiernaIzqDelante();

    // Traslacion BartSimpson
      miBartSimpson.traslacionBart();
    draw_objects();
}

void Escena::activarDesactivarIluminacion(){
  iluminacionActiva = !iluminacionActiva;
  if(iluminacionActiva)
    cout << "Iluminacion activada" << endl;
  else
    cout << "Iluminacion desactivada" << endl;
}

void Escena::activarDesactivarSuavizado(){
  suavizadoActivo = !suavizadoActivo;
  if(suavizadoActivo)
    cout << "Suavizado activado" << endl;
  else
    cout << "Suavizado desactivado" << endl;
}

void Escena::dibujarTextura(){
  GLfloat vertices[] = {-6, -5,
		      				6, -5,
		      				6, 5,
		      				-6, 5};

  texVertices.clear();

  if(orientacionTextura == 0){
    // Original
    texVertices = {0.0,1.0,
			 				1.0,1.0,
			 				1.0,0.0,
			 				0.0,0.0};  
 }
  else if(orientacionTextura == 90){
    // 90º
    texVertices = {1.0,1.0,
              1.0,0.0,
              0.0,0.0,
              0.0,1.0}; 
  }
  else if(orientacionTextura == 180){
    // 180º
    texVertices = {1.0,0.0,
              0.0,0.0,
              0.0,1.0,
              1.0,1.0}; 
  }
  else if(orientacionTextura == 270){
    // 270º
    texVertices = {0.0,0.0,
              0.0,1.0,
              1.0,1.0,
              1.0,0.0
              }; 
  }
                            
  std::vector<unsigned char> data;

  cimg_library::CImg<unsigned char> imagen;
  imagen.load("./homer.jpg");

  // empaquetamos bien los datos
  for (long y = 0; y < imagen.height(); y ++)
    for (long x = 0; x < imagen.width(); x ++)
    {
    unsigned char *r = imagen.data(x, y, 0, 0);
    unsigned char *g = imagen.data(x, y, 0, 1);
    unsigned char *b = imagen.data(x, y, 0, 2);
    data.push_back(*r);
    data.push_back(*g);
    data.push_back(*b);
    }

  glGenTextures(1, &textura_id);
  glBindTexture(GL_TEXTURE_2D, textura_id);

  glActiveTexture(GL_TEXTURE_2D);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  // TRASFIERE LOS DATOS A GPU
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imagen.width(), imagen.height(),
  0, GL_RGB, GL_UNSIGNED_BYTE, &data[0]);

  // Offset
  glMatrixMode(GL_TEXTURE);
  glLoadIdentity();
  glTranslatef(offset,0.0,0.0);
  glMatrixMode(GL_MODELVIEW);

  //glTranslatef(-2,0,0);
  glEnable(GL_TEXTURE_2D);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState (GL_TEXTURE_COORD_ARRAY_EXT);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, textura_id);

  glVertexPointer(2, GL_FLOAT, 0, vertices);
  glTexCoordPointer(2, GL_FLOAT, 0, &texVertices[0]);

  glDrawArrays(GL_QUADS, 0, 4);

  glDisableClientState(GL_VERTEX_ARRAY);
  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_TEXTURE_2D);
}

void Escena::liberarTextura(){
  glDeleteTextures(1, &textura_id);
}