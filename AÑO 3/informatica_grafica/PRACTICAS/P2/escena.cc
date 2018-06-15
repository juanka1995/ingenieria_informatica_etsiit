/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifdef _WIN32
#include <windows.h>
#endif

#include "escena.h"


Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);

    // Inicializo los objetos3D
    miTetraedro = Tetraedro(85.0,65.0);
    miCubo = Cubo(40.0);
    miRombo = Rombo (100.0, 80.0);
    miPiramide = Piramide(90.0, 75.0);
    miObjetoPerfilRevolucion = ObjetoPerfilRevolucion(3);
    miObjetoPerfilBarrido = ObjetoPerfilBarrido(4,5.0);

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
    if(pintaAlambre)
      objetos[objetoActivo]->dibujarAlambre();
    else if(pintaPuntos)
      objetos[objetoActivo]->dibujarPuntos();
    else if(pintaSolido)
      objetos[objetoActivo]->dibujarSolido();
    else
      objetos[objetoActivo]->dibujarAjedrez();
  }
}

void Escena::dibujar() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla,int x,int y) {
  std::cout << "Tecla " << Tecla<< std::endl;
	if (toupper(Tecla)=='Q')
    return 1;
  else if(toupper(Tecla)=='P') // Puntos
    return 2;
  else if(toupper(Tecla)=='L') // Lineas/Aristas
    return 3;
  else if(toupper(Tecla)=='F') // Relleno
    return 4;
  else if(toupper(Tecla)=='C') // Ajedrez
    return 5;
  else if(toupper(Tecla)=='1'){ // Activar tetraedro
    redimensionar(600.0,600.0);
    return 6;
  } 
  else if(toupper(Tecla)=='2'){ // Activar cubo
    redimensionar(600.0,600.0);
    return 7;
  }
  else if(toupper(Tecla)=='3'){ // Activar rombo
    redimensionar(600.0,600.0);
    return 8;
  }
  else if(toupper(Tecla)=='4'){ // Activar piramide
    redimensionar(600.0,600.0);
    return 9;
  }
  else if(toupper(Tecla)=='5' && (objetoPlyBienCargado || perfilPlyRevolucionBienCargado || perfilPlyBarridoBienCargado)){ // Activar objeto PLY 
    redimensionar(600.0,600.0,140);
    return 10;
  }
  else if(toupper(Tecla)=='6'){ // Activar objeto perfil por revolucion estático
    redimensionar(600.0,600.0,250);
    return 11;
  }
  else if(toupper(Tecla)=='7'){
    redimensionar(600.0,600.0,250);
    return 12;
  }
  else if(toupper(Tecla)=='0') // Activar modo no pintar
    return 13;
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
  else if(toupper(Tecla)=='H')
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


void Escena::redimensionar(int newWidth,int newHeight, int denominador) {
Width=newWidth / denominador;
Height=newHeight / denominador;
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

	cout << "Tecla 1 --> Activa tetraedro" << endl;
	cout << "Tecla 2 --> Activa cubo" << endl;
	cout << "Tecla 3 --> Activa rombo" << endl;
	cout << "Tecla 4 --> Activa piramide" << endl;
	cout << "Tecla 5 --> Activa objetos PLY (PLY, Revolución o Barrido)" << endl;
	cout << "Tecla 6 --> Activa perfil por revolución" << endl;
	cout << "Tecla 7 --> Activa perfil por barrido" << endl;
	cout << "Tecla 0 --> No pinta nada" << endl;

	cout << endl << "Tecla p/P --> Dibuja la figura actual en modo puntos" << endl;
	cout << "Tecla l/L --> Dibuja la figura actual en modo lineas" << endl;
	cout << "Tecla c/C --> Dibuja la figura actual en modo ajedrez" << endl;
	cout << "Tecla f/F --> Dibuja la figura actual en modo solido" << endl;
	cout << "Tecla h/H --> Muestra las instrucciones de uso por pantalla" << endl;

	cout << endl << "####################################################" << endl << endl;
}