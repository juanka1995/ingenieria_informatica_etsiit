# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= practica4

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -g -I/usr/include -I. -std=c++11
CXXFLAGS=  -g -I/usr/include -I. -std=c++11

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut -lX11 -lpthread

# definicion del compilador
#
CC = g++

# definicion de objetos
#
OBJECTS= practica4.o escena.o ejes.o objeto3d.o cubo.o tetraedro.o rombo.o piramide.o file_ply_stl.o objetoPLY.o objetoPerfilRevolucion.o objetoPerfilBarrido.o modeloJerarquico/bartSimpson.o modeloJerarquico/pierna.o modeloJerarquico/zapatilla.o modeloJerarquico/cabeza.o modeloJerarquico/ojo.o modeloJerarquico/brazo.o modeloJerarquico/cuerpo.o escenaP4.o luz.o
# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) : ./$(OBJECTS)
	$(CC) -o $@ $(CXXFLAGS) $(OBJECTS) $(LDFLAGS)

#
#
clean:
	rm -f *.o modeloJerarquico/*.o
	rm -f $(TARGETS)
	rm -f *.gch modeloJerarquico/*.gch

#
#
redo:
	touch *.cc
	make

#
#
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f *.o
	rm -f *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *
