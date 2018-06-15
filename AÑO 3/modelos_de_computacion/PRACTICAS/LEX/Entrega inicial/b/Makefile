CC = gcc
CFLAGS = -ll
EJECUTABLE = ejercicioB
PLANTILLA = plantillaB.l

all: $(EJECUTABLE)

$(EJECUTABLE): clean lex.yy.c
	gcc lex.yy.c -o $(EJECUTABLE) -ll

lex.yy.c: $(PLANTILLA)
	lex $(PLANTILLA)

clean:
	rm -f $(EJECUTABLE)
	rm -f lex.yy.c
