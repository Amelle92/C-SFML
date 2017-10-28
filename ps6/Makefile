all: TextGenerator mmtest

TextGenerator: MarkovModel.o TextGenerator.o
		g++ -Wall MarkovModel.o TextGenerator.o -o TextGenerator

mmtest: mmtest.o MarkovModel.o
		g++ mmtest.o MarkovModel.o -o mmtest -lboost_unit_test_framework

mmtest.o: mmtest.cpp
		g++ -c mmtest.cpp -lboost_unit_test_framework

TextGenerator.o: TextGenerator.cpp
		g++ -g -c TextGenerator.cpp

MarkovModel.o: MarkovModel.cpp MarkovModel.hpp
		g++ -g -c MarkovModel.cpp

clean:
		rm -rf *.o *.gch *~ TextGenerator mmtest
