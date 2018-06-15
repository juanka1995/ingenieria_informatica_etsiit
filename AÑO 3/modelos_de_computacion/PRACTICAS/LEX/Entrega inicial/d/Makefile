CC = gcc
CFLAGS = -ll
EJECUTABLE = ejercicioD
PLANTILLA = plantillaD.l

all: $(EJECUTABLE)

$(EJECUTABLE): clean lex.yy.c
	gcc lex.yy.c -o $(EJECUTABLE) -ll

lex.yy.c: $(PLANTILLA)
	lex $(PLANTILLA)

clean:
	rm -f $(EJECUTABLE)
	rm -f lex.yy.c
	rm -f inverseFile.out
