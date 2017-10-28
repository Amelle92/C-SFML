all: RingBuffer ps5a

RingBuffer: main.o RingBuffer.o
		g++ -g main.o RingBuffer.o -o RingBuffer

main.o: main.cpp
		g++ -g -c main.cpp
		
ps5a: test.o RingBuffer.o
		g++ -g test.o RingBuffer.o -o ps5a -lboost_unit_test_framework
		
test.o: test.cpp
		g++ -g -c test.cpp -lboost_unit_test_framework
		
RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
		g++ -g -c RingBuffer.cpp
		
clean:
		rm -rf *.o *.gch *~ RingBuffer ps5a
