
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)


all: $(BIN)/arteASCII $(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen $(BIN)/arteASCII2 $(BIN)/suma $(BIN)/testFinal

$(BIN)/testimagen: $(OBJ)/testimagen.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/testimagen.o -L$(LIB) -limagen -o $(BIN)/testimagen

$(BIN)/testplano: $(OBJ)/testplano.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/testplano.o -L$(LIB) -limagen -o $(BIN)/testplano

$(BIN)/testarteASCII: $(OBJ)/testarteASCII.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/testarteASCII.o -L$(LIB) -limagen -o $(BIN)/testarteASCII

$(BIN)/arteASCII: $(OBJ)/arteASCII.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/arteASCII.o -L$(LIB) -limagen -o $(BIN)/arteASCII

$(BIN)/arteASCII2: $(OBJ)/arteASCII2.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/arteASCII2.o -L$(LIB) -limagen -o $(BIN)/arteASCII2

$(BIN)/suma: $(OBJ)/suma.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/suma.o -L$(LIB) -limagen -o $(BIN)/suma

$(BIN)/testFinal: $(OBJ)/testFinal.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/testFinal.o -L$(LIB) -limagen -o $(BIN)/testFinal

$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o

$(OBJ)/testplano.o: $(SRC)/testplano.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/testplano.cpp -o $(OBJ)/testplano.o

$(OBJ)/testarteASCII.o: $(SRC)/testarteASCII.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o

$(OBJ)/arteASCII.o: $(SRC)/arteASCII.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o

$(OBJ)/arteASCII2.o: $(SRC)/arteASCII2.cpp $(INC)/imagen.h $(INC)/lista.h
	$(CXX) $(CPPFLAGS) $(SRC)/arteASCII2.cpp -o $(OBJ)/arteASCII2.o

$(OBJ)/suma.o: $(SRC)/suma.cpp $(INC)/imagen.h $(INC)/lista.h
	$(CXX) $(CPPFLAGS) $(SRC)/suma.cpp -o $(OBJ)/suma.o

$(OBJ)/testFinal.o: $(SRC)/testFinal.cpp $(INC)/imagen.h $(INC)/lista.h
	$(CXX) $(CPPFLAGS) $(SRC)/testFinal.cpp -o $(OBJ)/testFinal.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h $(INC)/lista.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
	$(CXX) $(CPPFLAGS) $(SRC)/pgm.cpp -o $(OBJ)/pgm.o

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	$(CXX) $(CPPFLAGS) $(SRC)/byte.cpp -o $(OBJ)/byte.o

$(OBJ)/lista.o: $(SRC)/lista.cpp $(INC)/lista.h
	$(CXX) $(CPPFLAGS) $(SRC)/lista.cpp -o $(OBJ)/lista.o

$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o
	ar -rvs $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o

# ************ documentación *******

clean:
	rm -f $(OBJ)/*.o $(LIB)/*.a

mrproper:clean
	rm -f *.pgm $(BIN)/*
	find . ! -name "grises.txt" -name "*.txt" -delete

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
