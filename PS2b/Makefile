all: PhotoMagic

PhotoMagic: PhotoMagic.o LFSR.o
		g++ -g PhotoMagic.o LFSR.o -o PhotoMagic -lsfml-system -lsfml-graphics -lsfml-window

PhotoMagic.o: PhotoMagic.cpp
		g++ -g -c PhotoMagic.cpp
		
LFSR.o: LFSR.cpp LFSR.hpp
		g++ -g -c LFSR.cpp
		
clean:
		rm -rf *.o *.gch *~ PhotoMagic
