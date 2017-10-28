#include <iostream>
#include <string>

#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(fiveBitsTapTwo){
	
	LFSR l("00111", 2);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 0);

	LFSR l2("00111", 2);
	BOOST_REQUIRE(l2.generate(8) == 198);
}
BOOST_AUTO_TEST_CASE(testLongAndShort){
	
	/*First I'm going to test a long string of 30 bits
	  and tap the bit at position 17 to make sure my algorithm
	  can handle long strings without breaking*/
	
	LFSR l3("011001111100100010001111001010", 17);
	BOOST_REQUIRE(l3.step() == 1);
	BOOST_REQUIRE(l3.step() == 1);
	BOOST_REQUIRE(l3.step() == 1);
	BOOST_REQUIRE(l3.step() == 0);
	BOOST_REQUIRE(l3.step() == 1);
	BOOST_REQUIRE(l3.step() == 1);
	BOOST_REQUIRE(l3.step() == 1);
	BOOST_REQUIRE(l3.step() == 1);
	
	/*I've noticed in my years of programming that the shortest
	  and simplest cases tend to fail because I don't think
	  of the situation when I'm creating the algorithm. Let's see
	  if the algorithm I created is able to have the tap bit be the
	  same bit it's xoring against. In this case every returned bit
	  should be 0 since it's always xoring against the same bit.*/
	
	LFSR l4("01", 1);
	BOOST_REQUIRE(l4.step() == 0);
	BOOST_REQUIRE(l4.step() == 0);
	BOOST_REQUIRE(l4.step() == 0);
	BOOST_REQUIRE(l4.step() == 0);
	BOOST_REQUIRE(l4.step() == 0);
	BOOST_REQUIRE(l4.step() == 0);
	BOOST_REQUIRE(l4.step() == 0);
	BOOST_REQUIRE(l4.step() == 0);
}

BOOST_AUTO_TEST_CASE(testGenerate){
	
	/*Now that I know the step method is working correctly I can
	  test the generate method that utilizes the step method. Let's 
	  try a couple random length bits and generate with two different
	  number of iterations.*/
	
	LFSR l5("100110101000", 6);
	BOOST_REQUIRE(l5.generate(19) == 415956);
	
	LFSR l6("001", 1);
	BOOST_REQUIRE(l6.generate(7) == 57);
}
