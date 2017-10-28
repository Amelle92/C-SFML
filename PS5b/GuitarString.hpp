// Copyright 2015 Adam Melle
#include <vector>
#include "RingBuffer.hpp"

class GuitarString {
 public:
    explicit GuitarString(double frequency);  // create string
                                     // using a sampling rate of 44,100
    explicit GuitarString(std::vector<sf::Int16> init);
    ~GuitarString();
    void pluck();  // pluck string by replacing buffer with rnd values
    void tic();  // advance the simulation one time step
    sf::Int16 sample();  // return the current sample
    int time();  // return number of times tic was called so far

 private:
    RingBuffer* rb;
    int _time;
};
