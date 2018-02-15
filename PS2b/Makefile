all: Encrypt

Encrypt: Encrypt.o LFSR.o
		g++ -g Encrypt.o LFSR.o -o Encrypt -lsfml-system -lsfml-graphics -lsfml-window

Encrypt.o: Encrypt.cpp
		g++ -g -c Encrypt.cpp
		
LFSR.o: LFSR.cpp LFSR.hpp
		g++ -g -c LFSR.cpp
		
clean:
		rm -rf *.o *.gch *~ Encrypt
