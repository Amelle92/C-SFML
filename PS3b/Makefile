all: NBody

NBody: main.o NBody.o
		g++ -g main.o NBody.o -o NBody -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

main.o: main.cpp
		g++ -g -c main.cpp
		
NBody.o: NBody.cpp NBody.hpp
		g++ -g -c NBody.cpp
		
clean:
		rm -rf *.o *.gch *~ NBody
