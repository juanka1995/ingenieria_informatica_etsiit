SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

#Rellenad el makefile para compilar el proyecto
all: $(BIN)/pruebatrad_test
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************

$(BIN)/pruebatrad_test: $(OBJ)/pruebatrad_test.o
	$(CXX) $(OBJ)/pruebatrad_test.o -o $(BIN)/pruebatrad_test

$(OBJ)/pruebatrad_test.o: $(INC)/conjuntofrases.h $(SRC)/pruebatrad_test.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/pruebatrad_test.cpp  -o $(OBJ)/pruebatrad_test.o -I$(INC)

# ************ Limpieza ************
clean :
	-rm -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm -f $(BIN)/* doc/html/search/* doc/latex/*
	-rm -f $(BIN)/* doc/html/*
