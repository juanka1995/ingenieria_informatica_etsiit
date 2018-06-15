BIN = bin
SRC = src
OBJ = obj
INC = include

all: $(BIN)/main

bin/main: $(OBJ)/bloqueLed.o $(OBJ)/main.o
	g++ -o $(BIN)/main $(OBJ)/bloqueLed.o $(OBJ)/main.o

obj/bloqueLed.o: $(SRC)/bloqueLed.cpp $(INC)/bloqueLed.h
	g++ -c $(SRC)/bloqueLed.cpp -o $(OBJ)/bloqueLed.o -I$(INC)

obj/main.o: $(SRC)/main.cpp $(INC)/bloqueLed.h
	g++ -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)

clean:
	@echo "Limpiando..."
	rm $(OBJ)/*.o

mrproper: clean
	rm $(BIN)/main
