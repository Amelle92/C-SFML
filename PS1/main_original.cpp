#include <SFML/Graphics.hpp>
#include <cmath>
#include "original.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		cout << "Original [recursion-depth] [side-length]" << endl;
		return -1;
	}
	int depth = atoi(argv[1]);
	int side =  atoi(argv[2]);
	Original s(side, depth);
	sf::RenderWindow
		window(sf::VideoMode(side,(int)(0.5*sqrt(4.)*(float)side)), "Original");
	window.setFramerateLimit(1);
	
	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(s);
		window.display();
	}
	return 0;
}
