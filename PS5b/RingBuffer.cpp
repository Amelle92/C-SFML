// Copyright 2015 Adam Melle
#include <stdint.h>
#include <iostream>
#include <exception>
#include <stdexcept>
#include "RingBuffer.hpp"

RingBuffer::RingBuffer(int capacity) {
    if (capacity < 1) {
        throw std::invalid_argument("RB constructor: capacity must"
                                    " be greater than zero");
    }
    _size = 0;
    _capacity = capacity;
    _last = capacity - 1;
    _first = _last;
    buffer = new int16_t[_capacity];

    // initialize the buffer to all 0's
    for (int x = 0; x < _capacity; x++) {
        buffer[x] = 0;
    }
}

RingBuffer::~RingBuffer() {
    delete [] buffer;
}

int RingBuffer::size() {
    return _size;
}

int RingBuffer::capacity() {
    return _capacity;
}

bool RingBuffer::isEmpty() {
    if (size() == 0)
        return true;
    else
        return false;
}

bool RingBuffer::isFull() {
    if (size() == _capacity)
        return true;
    else
        return false;
}

void RingBuffer::enqueue(int16_t x) {
    // check if buffer is full before enqueuing
    if (isFull() == true) {
        throw std::runtime_error("enqueue: can't enqueue to a full"
                                " ring");
    }

    // if buffer is empty
    if (size() == 0) {
        buffer[_last] = x;
    } else if (_last + 1 == _capacity) {  // if true loop to index 0
        _last = 0;
        buffer[_last] = x;
    } else {  // we can just incrememnt last normally
        _last += 1;
        buffer[_last] = x;
    }
    _size++;
    return;
}

int16_t RingBuffer::dequeue() {
    int16_t popped;

    //  check if buffer is empty before dequeuing
    if (isEmpty() == true) {
        throw std::runtime_error("dequeue: can't dequeue an empty"
                                " ring");
    }

    popped = buffer[_first];           // record the dequeued value
    buffer[_first] = ' ';             // cell is now empty

    // determine how to increment first
    if (_first == _last)  {              // last element do nothing
        _size--;
        return popped;
    } else if (_first + 1 == _capacity) {  // loop to index 0
        _first = 0;
    } else {
        _first += 1;                   // incrememnt normally
    }
    _size--;
    return popped;
}

int16_t RingBuffer::peek() {
    //  check if buffer is empty before dequeuing
    if (isEmpty() == true) {
        throw std::runtime_error("peek: can't peek an empty"
                                " ring");
    }

    return buffer[_first];
}
