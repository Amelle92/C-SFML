// Copyright 2015 Adam Melle
#include <stdint.h>

class RingBuffer {
 public:
    explicit RingBuffer(int capacity);  // create buffer with capacity
    ~RingBuffer();                      // destructor
    int size();                 // return number of items in the buffer
    int capacity();             // return capacity
    bool isEmpty();             // is buffer empty (size equals zero)?
    bool isFull();              // is buffer full (size == capacity)
    void enqueue(int16_t x);    // add item x to the end
    int16_t dequeue();          // delete and return item from the front
    int16_t peek();             // return (not delete) item from front

 private:
    int16_t *buffer;               // ring buffer
    int _first, _last, _capacity, _size;  // first, last element
};
