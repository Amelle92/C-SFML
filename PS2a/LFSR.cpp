#include <iostream>
#include <string>

#include "LFSR.hpp"

LFSR::LFSR(const std::string seed, const int tap):_seed(seed), _tap(tap)
{
}

LFSR::~LFSR()
{
}

int LFSR::step()
{
	int length = _seed.size();
	length=length-1;
	
	if(_seed[0]=='1' && _seed[length-_tap]=='1'){
		for(int x=0; x<length; x++){
			_seed[x]=_seed[x+1];
		}
			_seed[length] = '0';
		return 0;
	}
	if(_seed[0]=='1' && _seed[(length-_tap)]=='0'){
		for(int x=0; x<length; x++){
			_seed[x]=_seed[x+1];
		}
			_seed[length] = '1';
		return 1;
	}
	if(_seed[0]=='0' && _seed[length-_tap]=='1'){
		for(int x=0; x<length; x++){
			_seed[x]=_seed[x+1];
		}
			_seed[length] = '1';
		return 1;
	}
	if(_seed[0]=='0' && _seed[(length-_tap)]=='0'){
		for(int x=0; x<length; x++){
			_seed[x]=_seed[x+1];
		}
			_seed[length] = '0';
		return 0;
	}
}

int LFSR::generate(int k)
{
	int var=0;
	for(int x=0;x<k;x++)
		var=(var*2)+step();
	
	return var;
}

std::ostream& operator<< (std::ostream &out, LFSR &lfsr)
{
	out<<lfsr._seed;
	return out;
}
