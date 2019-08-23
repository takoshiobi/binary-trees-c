CC=gcc
OPT=-Wall -ansi -pedantic 

all:Test_arbre.exec

%_arbre.exec: %_arbre.c Affichage.o ArbreBinaire.o
	$(CC) $(OPT) -o $@  $^

%.pdf: %.gv
	dot -Tpdf -o $@ $^

Affichage.o : Affichage.c
	$(CC) $(OPT) -c $<

ArbreBinaire.o: ArbreBinaire.c ArbreBinaire.h
	$(CC) $(OPT) -c $<

clean:
	rm -f *.gv *.pdf *.o *.exec
