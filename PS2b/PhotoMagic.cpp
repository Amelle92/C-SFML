// Adam Melle

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "LFSR.hpp"
#include <string>

sf::Image transform(sf::Image output, LFSR lfsr);

int main(int argc, char* argv[])
{
	if(argc < 5)
	{
		std::cout << "PhotoMagic [input-file.png] [output-file.png] [bit string] [tap bit]" << std::endl;
		return -1;
	}
	
	LFSR lfsr(argv[3], atoi(argv[4]));
  
	std::cout<<lfsr;
	  
	sf::Image inputfile;
	sf::Image outputfile;
	  
	if (!inputfile.loadFromFile(argv[1]))
		return -1;
		
	outputfile = transform(inputfile, lfsr);

	sf::Vector2u size =inputfile.getSize();
	  
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Source File");
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Encrypted File");

	sf::Texture input;
	input.loadFromImage(inputfile);
	sf::Texture output;
	output.loadFromImage(outputfile);

	sf::Sprite in;
	in.setTexture(input);
	sf::Sprite out;
	out.setTexture(output);

    while (window1.isOpen() && window2.isOpen()) {
    sf::Event event;
    
    while (window1.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window1.close();
    }
    while (window2.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window2.close();
    }
		window1.clear();
		window1.draw(in);
		window1.display();
		window2.clear();
		window2.draw(out);
		window2.display();
  }

  //   write the file
  if (!outputfile.saveToFile(argv[2]))
    return -1;

  return 0;
}

sf::Image transform(sf::Image output, LFSR lfsr)
{
	// p is a pixel
	sf::Color p;

	// create photographic negative image of upper-left 200 px square
	for (int x=0; x<600; x++) 
	{
		for (int y=0; y< 428; y++)
		{
			p = output.getPixel(x, y);
			p.r = (p.r ^ lfsr.generate(8));
			p.g = (p.g ^ lfsr.generate(8));
			p.b = (p.b ^ lfsr.generate(8));
			output.setPixel(x, y, p);
		}
	}
	return output;
}
