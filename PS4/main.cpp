// Copyright 2015 Adam Melle
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include "ED.hpp"

int main(int argc, char* argv[]) {
    if (argc < 1) {
        std::cout << "ED < [exmample.txt]" << std::endl;
        return -1;
    }
    sf::Clock clock;
    sf::Time t;

    int distance;
    // Start by reading the two strings from the file
    std::string s1, s2;
    std::cin >> s1 >> s2;

    // Construct a new EditDistance object
    EditDistance ED(s1, s2);
    distance = ED.OptDistance();
    std::cout << "Edit distance = " << distance << std::endl;
    std::string aligned = ED.Alignment();
    std::cout << aligned;

    // display computation time
    t = clock.getElapsedTime();
    std::cout << "Execution time is " << t.asSeconds() << " seconds \n";
    return 0;
}
