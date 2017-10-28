//  Copyright 2015 Adam Melle
#include <stdlib.h>
#include <iostream>
#include <string>
#include "MarkovModel.hpp"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "TextGenerator [k] [T] < [input.txt]" << std::endl;
        return -1;
    }
    std::string input;
    std::getline(std::cin, input);
    int k = atoi(argv[1]);
    int T = atoi(argv[2]);

    std::string kgram;
    for (int x = 0; x < k; x++)
        kgram.append(1, input[x]);

    MarkovModel mm(input, k);
    std::string generate = mm.gen(kgram, T);

    std::cout << generate << std::endl;

    return 0;
}
