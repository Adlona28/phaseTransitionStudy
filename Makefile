TARGETS  = main
TestFase.exe: Union_Find.o percolacio.o properties.o graphgen.o main.o 
	g++ -o TestFase.exe main.o Union_Find.o
	rm *.o *.gch
main.o: main.c
	g++ -c main.c
percolacio.o: percolacio.h
	g++ -c percolacio.h
properties.o: properties.c 
	g++ -c properties.c
graphgen.o: graphgen.h
	g++ -c graphgen.h
Union_Find.o: Union_Find.c Union_Find.h
	g++ -c Union_Find.c

clean:
	rm *.o
	rm *.exe
	rm *.gch
