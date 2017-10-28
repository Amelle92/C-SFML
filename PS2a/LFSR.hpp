#include <iostream>
#include <string>

class LFSR {

public:
	LFSR(std::string seed, int tap);
	~LFSR();
	int step();
	int generate(int k);
	
	friend std::ostream& operator<< (std::ostream &out, LFSR &lfsr);
	
private:
	std::string _seed;
	int _tap;
};
