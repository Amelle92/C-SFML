// Copyright 2015 Adam Melle
#include <SFML/Audio.hpp>
#include <math.h>
#include <stdint.h>
#include <vector>
#include "GuitarString.hpp"

GuitarString::GuitarString(double frequency) {
    _time = 0;
    int size = ceil(44100/frequency);
    rb = new RingBuffer(size);
}
GuitarString::GuitarString(std::vector<sf::Int16> init) {
    rb = new RingBuffer(init.size());
    for (int x = 0; x < init.size(); x++) {
        rb->enqueue(init[x]);
    }
}
GuitarString::~GuitarString() {
    delete rb;
}
void GuitarString::pluck() {
    int random, cap = rb->capacity();
    rb = new RingBuffer(cap);
    for (int x = 0; x < cap; x++) {
        rb->enqueue( (sf::Int16)(rand() & 0xffff));  //NOLINT
    }
}
void GuitarString::tic() {
    int16_t popped = rb->dequeue();
    int16_t peek = rb->peek();
    popped = .996*((popped + peek)/2);
    rb->enqueue(popped);
    _time++;
}
sf::Int16 GuitarString::sample() {
    return rb->peek();
}
int GuitarString::time() {
    return _time;
}
