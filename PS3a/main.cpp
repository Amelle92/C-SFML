#include <SFML/Graphics.hpp>
#include <cmath>
#include "NBody.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	int window_size = 512, N; //Size of background so I thought it would be appropriate; Number of planets
	double univ_size;
	std::cin>>N; //Read in num planets
	std::cin>>univ_size; //Read universe size
	
	//Setup Window
	sf::RenderWindow window(sf::VideoMode(window_size, window_size), "The Solar System");
	window.setFramerateLimit(1);
	
	//Create vector of pointers and populate it
	std::vector <Body*> planets;
	for(int x=0;x<N;x++){
		planets.push_back(new Body(univ_size, window_size));
	}
	
	//Background
	sf::Texture bgtexture;
	if (!bgtexture.loadFromFile("images/starfield.jpg"))
		return EXIT_FAILURE;
	sf::Sprite background(bgtexture);
	
	//Draw Loop
	while(window.isOpen())	
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(background);
		for(int x=0;x<N;x++){
			window.draw(*planets[x]);
		}
		window.display();
	}
	return 0;
}
