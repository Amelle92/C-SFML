all: GuitarHero GStest

GuitarHero: GuitarHero.o RingBuffer.o GuitarString.o
		g++ -Wall GuitarHero.o RingBuffer.o GuitarString.o -o GuitarHero -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window

GStest: GStest.o GuitarString.o RingBuffer.o
		g++ GStest.o GuitarString.o RingBuffer.o -o GStest -lboost_unit_test_framework

GStest.o: GStest.cpp
		g++ -c GStest.cpp -lboost_unit_test_framework

GuitarHero.o: GuitarHero.cpp
		g++ -Wall -c GuitarHero.cpp -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window

GuitarString.o: GuitarString.cpp GuitarString.hpp
		g++ -g -c GuitarString.cpp
		
RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
		g++ -g -c RingBuffer.cpp

clean:
		rm -rf *.o *.gch *~ GuitarHero GStest
