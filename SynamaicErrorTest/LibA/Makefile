libLibA: LibA.o
	g++ -shared LibA.o -L. -lLibB -o libLibA.so

LibA.o: LibA.cc CommonC1.hpp LibA.h
	g++ -c -I. -fPIC LibA.cc
