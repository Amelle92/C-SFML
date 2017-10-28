#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "NBody.hpp"
#include <iostream>
#include <vector>
#include <sstream>

int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		std::cout << "NBody [T] [Dt]" << std::endl;
		return -1;
	}
	int window_size = 512, N; //Size of background so I thought it would 
							  //be appropriate; Number of planets
	double univ_size, T=atoi(argv[1]), Dt=atoi(argv[2]), seconds=0.0;
	
	std::cin>>N; //Read in num planets
	std::cin>>univ_size; //Read universe size
	
	//Set Window
	sf::RenderWindow window(sf::VideoMode(window_size, window_size), "The Solar System");
	window.setFramerateLimit(40);
	
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
	
	//Text
	sf::Font font;
	font.loadFromFile("times.ttf");
	
	//Convert seconds to a string
	std::ostringstream ss;
	ss << (int)seconds;
	
	//Set up text settings
	sf::Text atext;
	atext.setFont(font);
	atext.setCharacterSize(18);
	atext.setStyle(sf::Text::Bold);
	atext.setColor(sf::Color::Red);
	atext.setPosition(10,10);
	atext.setString(ss.str());
	
	//Sound
	//load sound file
	sf::SoundBuffer buffer;
    buffer.loadFromFile("2001.ogg");
    
    //play sound file
    sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

	//Draw Loop
	while(window.isOpen() && seconds<T)	
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(background);
		window.draw(atext);
		for(int x=0;x<N;x++){
			window.draw(*planets[x]);
			planets[x]->step(Dt);
		}
		window.display();
		
		//Update Text and Seconds
		seconds += Dt;
		ss.clear();
		ss.str(std::string());
		ss << (int)seconds;
		atext.setString(ss.str());
	}
	return 0;
}
