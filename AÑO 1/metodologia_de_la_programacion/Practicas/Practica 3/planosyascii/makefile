
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)


all: $(BIN)/arteASCII $(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen

$(BIN)/testimagen: $(OBJ)/testimagen.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/testimagen.o -L$(LIB) -limagen -o $(BIN)/testimagen

$(BIN)/testplano: $(OBJ)/testplano.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/testplano.o -L$(LIB) -limagen -o $(BIN)/testplano

$(BIN)/testarteASCII: $(OBJ)/testarteASCII.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/testarteASCII.o -L$(LIB) -limagen -o $(BIN)/testarteASCII

$(BIN)/arteASCII: $(OBJ)/arteASCII.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/arteASCII.o -L$(LIB) -limagen -o $(BIN)/arteASCII

$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o

$(OBJ)/testplano.o: $(SRC)/testplano.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/testplano.cpp -o $(OBJ)/testplano.o

$(OBJ)/testarteASCII.o: $(SRC)/testarteASCII.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o

$(OBJ)/arteASCII.o: $(SRC)/arteASCII.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
	$(CXX) $(CPPFLAGS) $(SRC)/pgm.cpp -o $(OBJ)/pgm.o

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	$(CXX) $(CPPFLAGS) $(SRC)/byte.cpp -o $(OBJ)/byte.o

$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/testarteASCII.o $(OBJ)/arteASCII.o
	ar -rvs $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/testarteASCII.o $(OBJ)/arteASCII.o

# ************ documentación *******

clean:
	rm -f $(OBJ)/*.o $(LIB)/*.a

mrproper:clean
	rm -f *.pgm $(BIN)/* *.txt

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
