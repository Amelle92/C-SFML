//  Copyright 2015 Adam Melle
#include <time.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include "MarkovModel.hpp"

MarkovModel::MarkovModel(std::string text, int k) {
    std::string gram;
    std::size_t found;
    int index;

    // Set the order
    _order = k;

    // Construct the alphabet and map
    for (int x = 0; x < text.size(); x++) {
        for (int y = 0; y < _order; y++) {
            index = x + y;
            while (index >= text.size()) {  // wrap around
                index -= text.size();
            }

            //  append the kgram until order is reached
            gram.append(1, text[index]);

            //  add letter to alphabet if not already there
            found = _alphabet.find(text[index]);
            if (found == std::string::npos)
                _alphabet.append(1, text[index]);
        }

        //  Check if kgram is already in the map
        std::map<std::string, int>::iterator it = _kgrams.find(gram);

        if (it != _kgrams.end())  // Incrememnt it in the map
            _kgrams[gram]++;
        else                    //  add it to map and alphabet
            _kgrams[gram] = 1;

        gram.clear();
    }

    // add kgram+1
    for (int x = 0; x < text.size(); x++) {
        for (int y = 0; y < _order+1; y++) {
            index = x + y;
            while (index >= text.size()) {  // wrap around
                index -= text.size();
            }
            gram.append(1, text[index]);
        }

        std::map<std::string, int>::iterator it = _kgrams.find(gram);

        if (it != _kgrams.end())   // Incrememnt it in the map
            _kgrams[gram]++;
        else                       //  add it to map and alphabet
            _kgrams[gram] = 1;

        gram.clear();
    }
}
MarkovModel::~MarkovModel() {
}
int MarkovModel::order() {
    return _order;
}
int MarkovModel::freq(std::string kgram) {
    if (kgram.size() != _order)
        throw std::runtime_error("Wrong size kgram");

    std::map<std::string, int>::iterator it = _kgrams.find(kgram);

    if (it != _kgrams.end())
        return it->second;
    else
        return 0;
}
int MarkovModel::freq(std::string kgram, char c) {
    if (kgram.size() != _order)
        throw std::runtime_error("Wrong size kgram");

    kgram.append(1, c);
    std::map<std::string, int>::iterator it = _kgrams.find(kgram);

    if (it != _kgrams.end())
        return it->second;
    else
        return 0;
}
char MarkovModel::randk(std::string kgram) {
    if (kgram.size() != _order)
        throw std::runtime_error("Wrong size kgram");

    std::map<std::string, int>::iterator it = _kgrams.find(kgram);
    if (it == _kgrams.end())
        throw std::runtime_error("No such kgram");

    int probability = 0;

    srand(time(NULL));
    int num = rand() % it->second + 1;  //NOLINT

    for (int x = 0; x < _alphabet.size(); x++) {
        probability += freq(kgram, _alphabet[x]);

        if (num <= probability)
            return _alphabet[x];
    }
}
std::string MarkovModel::gen(std::string kgram, int T) {
    if (kgram.size() != _order)
        throw std::runtime_error("Wrong size kgram");

    std::string newgram;
    for (int x = kgram.size(); x < T; x++) {  //  while size < T
        for (int y = (kgram.size() - _order); y < kgram.size(); y++) {
            newgram.append(1, kgram[y]);  //  create the new kgram
         }
         kgram.append(1, randk(newgram));  // add the new character
         newgram.clear();
    }

    return kgram;
}
std::ostream& operator<< (std::ostream &out, MarkovModel &mm) {
    for (std::map < std::string, int>::iterator it = mm._kgrams.begin();
         it != mm._kgrams.end(); ++it)
         out << it->first << " => " << it->second << '\n';
    return out;
}
