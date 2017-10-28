// Copyright 2015 Adam Melle
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "RingBuffer.hpp"

BOOST_AUTO_TEST_CASE(RBcontructor) {
  // normal constructor
  BOOST_REQUIRE_NO_THROW(RingBuffer(100));

  // this should fail
  BOOST_REQUIRE_THROW(RingBuffer(0), std::exception);
  BOOST_REQUIRE_THROW(RingBuffer(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RBenque_dequeue) {
  RingBuffer rb(100);

  BOOST_REQUIRE(rb.isEmpty() == true);

  rb.enqueue(2);
  rb.enqueue(1);
  rb.enqueue(0);

  BOOST_REQUIRE(rb.size() == 3);
  BOOST_REQUIRE(rb.isFull() == false);
  BOOST_REQUIRE(rb.isEmpty() == false);

  BOOST_REQUIRE(rb.dequeue() == 2);
  BOOST_REQUIRE(rb.dequeue() == 1);
  BOOST_REQUIRE(rb.dequeue() == 0);

  // these 2 should fail
  BOOST_REQUIRE_THROW(rb.peek(), std::runtime_error);
  BOOST_REQUIRE_THROW(rb.dequeue(), std::runtime_error);

  BOOST_REQUIRE(rb.size() == 0);

  BOOST_REQUIRE(rb.isFull() == false);
  BOOST_REQUIRE(rb.isEmpty() == true);
}

BOOST_AUTO_TEST_CASE(RBfunctions) {
  RingBuffer rb2(3);

  rb2.enqueue(2);
  rb2.enqueue(1);
  rb2.enqueue(0);

  // buffer should be full now
  BOOST_REQUIRE(rb2.size() == 3);
  BOOST_REQUIRE(rb2.isFull() == true);
  BOOST_REQUIRE(rb2.isEmpty() == false);

  // this should fail
  BOOST_REQUIRE_THROW(rb2.enqueue(3), std::runtime_error);
}
