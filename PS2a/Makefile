all: main ps2a

main: main.o LFSR.o
		g++ -g main.o LFSR.o -o main

main.o: main.cpp
		g++ -g -c main.cpp

ps2a: test.o LFSR.o
		g++ -g test.o LFSR.o -o ps2a -lboost_unit_test_framework

test.o: test.cpp
		g++ -g -c test.cpp -lboost_unit_test_framework
		
LFSR.o: LFSR.cpp LFSR.hpp
		g++ -g -c LFSR.cpp
		
clean:
		rm -rf *.o *.gch *~ main ps2a
