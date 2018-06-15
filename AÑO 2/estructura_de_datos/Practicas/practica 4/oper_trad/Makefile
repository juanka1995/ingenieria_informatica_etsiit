SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebatraductor $(BIN)/traductor_inverso $(BIN)/concatenar $(BIN)/sumar
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************

$(BIN)/pruebatraductor: $(OBJ)/pruebatraductor.o
	$(CXX) $(OBJ)/pruebatraductor.o -o $(BIN)/pruebatraductor

$(OBJ)/pruebatraductor.o: $(INC)/traductor.h $(SRC)/pruebatraductor.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/pruebatraductor.cpp  -o $(OBJ)/pruebatraductor.o -I$(INC)

$(BIN)/concatenar: $(OBJ)/concatenar.o
	$(CXX) $(OBJ)/concatenar.o -o $(BIN)/concatenar

$(OBJ)/concatenar.o: $(INC)/traductor.h $(SRC)/concatenar.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/concatenar.cpp  -o $(OBJ)/concatenar.o -I$(INC)

$(BIN)/sumar: $(OBJ)/sumar.o
	$(CXX) $(OBJ)/sumar.o -o $(BIN)/sumar

$(OBJ)/sumar.o: $(INC)/traductor.h $(SRC)/sumar.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/sumar.cpp  -o $(OBJ)/sumar.o -I$(INC)

$(BIN)/traductor_inverso: $(OBJ)/traductor_inverso.o
	$(CXX) $(OBJ)/traductor_inverso.o -o $(BIN)/traductor_inverso

$(OBJ)/traductor_inverso.o: $(INC)/traductor.h $(SRC)/traductor_inverso.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/traductor_inverso.cpp  -o $(OBJ)/traductor_inverso.o -I$(INC)

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
