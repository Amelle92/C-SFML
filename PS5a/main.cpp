// Copyright 2015 Adam Melle
#include <stdint.h>
#include <iostream>
#include "RingBuffer.hpp"

int main() {
    int16_t returned;

    RingBuffer rb(100);

    rb.enqueue(32);
    rb.enqueue(32);
    rb.enqueue(32);

    returned = rb.dequeue();
    std::cout << returned << std::endl;
    returned = rb.dequeue();
    std::cout << returned << std::endl;
    returned = rb.dequeue();
    std::cout << returned << std::endl;

    std::cout << rb.size() << std::endl;

    returned = rb.dequeue();
    std::cout << returned << std::endl;

    return 0;
}
