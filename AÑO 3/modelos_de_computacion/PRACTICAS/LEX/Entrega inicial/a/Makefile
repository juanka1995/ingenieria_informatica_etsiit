CC = gcc
CFLAGS = -ll
EJECUTABLE = ejercicioA
PLANTILLA = plantillaA.l

all: $(EJECUTABLE)

$(EJECUTABLE): clean lex.yy.c
	gcc lex.yy.c -o $(EJECUTABLE) -ll

lex.yy.c: $(PLANTILLA)
	lex $(PLANTILLA)

clean:
	rm -f $(EJECUTABLE)
	rm -f lex.yy.c
