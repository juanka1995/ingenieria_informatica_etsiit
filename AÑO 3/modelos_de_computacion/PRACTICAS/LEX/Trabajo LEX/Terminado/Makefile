CC = g++
CFLAGS = -ll
EJECUTABLE = calculadora
PLANTILLA = calculadora.l

all: $(EJECUTABLE)

$(EJECUTABLE): clean lex.yy.c
	$(CC) -std=c++11 lex.yy.c -o $(EJECUTABLE) -ll

lex.yy.c: $(PLANTILLA)
	lex $(PLANTILLA)

clean:
	rm -f $(EJECUTABLE)
	rm -f lex.yy.c
