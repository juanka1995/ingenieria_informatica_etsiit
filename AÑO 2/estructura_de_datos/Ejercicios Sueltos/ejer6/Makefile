BIN = bin
SRC = src
OBJ = obj
INC = include

all: $(BIN)/main

bin/main: $(OBJ)/conjunto_enteros.o $(OBJ)/main.o
	g++ -o $(BIN)/main $(OBJ)/conjunto_enteros.o $(OBJ)/main.o

obj/conjunto_enteros.o: $(SRC)/conjunto_enteros.cpp $(INC)/conjunto_enteros.h
	g++ -c $(SRC)/conjunto_enteros.cpp -o $(OBJ)/conjunto_enteros.o -I$(INC)

obj/main.o: $(SRC)/main.cpp $(INC)/conjunto_enteros.h
	g++ -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)

clean:
	@echo "Limpiando..."
	rm $(OBJ)/*.o

mrproper: clean
	rm $(BIN)/main
