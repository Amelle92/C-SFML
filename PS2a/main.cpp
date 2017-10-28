 #include <iostream>
 #include "LFSR.hpp"
 
int main()
{	
	LFSR l("01101000010", 8);
	LFSR l2("01101000010", 8);
	
	for (int i = 0; i < 10; i++) {
		int bit = l.step();
		std::cout<<l<<" "<<bit<<std::endl;
	}
	
	std::cout<<std::endl; //spacing
	
	for (int i = 0; i < 10; i++) {
		int r = l2.generate(5);
		std::cout<<l2<<" "<<r<<std::endl;
	}
	
	return 0;
}
