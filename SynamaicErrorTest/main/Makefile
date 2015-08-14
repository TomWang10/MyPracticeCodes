main: main.o libLibA.so
	g++ -I. main.o -o main -L. -lLibA 

main.o: LibA.h
	g++ -c -I. main.cc
