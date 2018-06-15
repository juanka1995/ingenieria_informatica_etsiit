INC = include
SRC = src
OBJ = obj
BIN = bin

all: $(BIN)/ejer4 $(BIN)/ejer5_feb_15_16

$(BIN)/ejer4: $(OBJ)/ejer4.o
	${CXX} -o $(BIN)/ejer4 $(OBJ)/ejer4.o

$(OBJ)/ejer4.o: $(SRC)/ejer4.cpp $(INC)/bintree.h
	${CXX} -c $(SRC)/ejer4.cpp -o $(OBJ)/ejer4.o -I$(INC)


$(BIN)/ejer5_feb_15_16: $(OBJ)/ejer5_feb_15_16.o
	${CXX} -o $(BIN)/ejer5_feb_15_16 $(OBJ)/ejer5_feb_15_16.o

$(OBJ)/ejer5_feb_15_16.o: $(SRC)/ejer5_feb_15_16.cpp $(INC)/bintree.h
	${CXX} -c $(SRC)/ejer5_feb_15_16.cpp -o $(OBJ)/ejer5_feb_15_16.o -I$(INC)

clean:
	rm $(OBJ)/*.o $(BIN)/*
