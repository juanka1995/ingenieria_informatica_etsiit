SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

all: $(BIN)/prueba

$(BIN)/prueba: $(SRC)/prueba.cpp $(LIB)/liblista.a
	g++ $(SRC)/prueba.cpp -o $(BIN)/prueba -llista -I$(INC) -L$(LIB)

$(OBJ)/lista.o: $(SRC)/lista.cpp $(INC)/lista.h
	g++ -c $(SRC)/lista.cpp -o $(OBJ)/lista.o -I$(INC)

$(LIB)/liblista.a: $(OBJ)/lista.o
	ar rsv $(LIB)/liblista.a $(OBJ)/lista.o

mrproper:
	rm $(OBJ)/* $(BIN)/*
