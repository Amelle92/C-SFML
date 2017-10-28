all: ED

ED: main.o ED.o
		g++ -g main.o ED.o -o ED -lsfml-system

main.o: main.cpp
		g++ -g -c main.cpp -lsfml-system
		
ED.o: ED.cpp ED.hpp
		g++ -g -c ED.cpp
		
clean:
		rm -rf *.o *.gch *~ ED
