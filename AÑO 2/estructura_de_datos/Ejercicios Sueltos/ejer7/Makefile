SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -std=c++11 -I$(INC) -c
all: $(BIN)/main

$(BIN)/main: $(OBJ)/main.o
	$(CXX) -o $(BIN)/main $(OBJ)/main.o
$(OBJ)/main.o:  $(SRC)/main.cpp  $(INC)/lista.h
	$(CXX)  $(CPPFLAGS)  $(SRC)/main.cpp -o $(OBJ)/main.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/*
