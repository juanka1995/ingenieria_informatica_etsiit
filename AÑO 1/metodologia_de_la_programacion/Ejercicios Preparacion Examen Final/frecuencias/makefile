SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

all: $(BIN)/prueba $(BIN)/contar

$(BIN)/contar: $(SRC)/contar.cpp $(LIB)/libfrecuencia.a
	g++ $(SRC)/contar.cpp -o $(BIN)/contar -lfrecuencia -I$(INC) -L$(LIB)

$(BIN)/prueba: $(SRC)/prueba.cpp $(LIB)/libfrecuencia.a
	g++ $(SRC)/prueba.cpp -o $(BIN)/prueba -lfrecuencia -I$(INC) -L$(LIB)

$(OBJ)/frecuencias.o: $(SRC)/frecuencias.cpp $(INC)/frecuencias.h
	g++ -c $(SRC)/frecuencias.cpp -o $(OBJ)/frecuencias.o -I$(INC)

$(LIB)/libfrecuencia.a: $(OBJ)/frecuencias.o
	ar rsv $(LIB)/libfrecuencia.a $(OBJ)/frecuencias.o

mrproper:
	rm $(OBJ)/* $(BIN)/*
