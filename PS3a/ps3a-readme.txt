/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name: Adam Melle
OS: Ubuntu
Machine (e.g., Dell Latitude, MacBook Pro): MSI Ghost
Text editor: Geany
Hours to complete assignment (optional):

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
So basically I implemented a class named Body with all the member variables
needed to hold the position, mass, texture, sprite, and file information. The is also derived from
Drawable and I implemented a draw function. My main starts by declaring the window size, which I 
made the same size as the background texture provided. I then declare N and univ_size and read them
in from cin which is directly from the planets.txt file. N lets the program know how many planets
to create and read in from the file. I created a vector of pointers to Body objects using N, like so.

std::vector <Body*> planets;
for(int x=0;x<N;x++){
	planets.push_back(new Body(univ_size, window_size));
}

I pass univ_size and window_size to the constructor for later when I convert the x and y positions.

Each time a new Body object constructor is called it reads in each variable within the object
from planets.txt using my operator >> overloaded function. This is what it looks like.

input>>B._xpos>>B._ypos>>B._xvel>>B._yvel>>B._mass>>B._fname;

Then once all the variables are populated, I call my conversions() function to scale the positions
so that they fit on the screen but are still proportionally spaced. Note that I am adding 256 to the number because the origin of the window should be placed in the center and my window size is 512.

_xpos = (_xpos/((_univ_size*2)/_window_size)) + 256;
_ypos = (_ypos/((_univ_size*2)/_window_size)) + 256;

Then I load in my textures. My constructor has also placed the origin of the sprite directly in the center of itself by utilizing the getSize and setOrigin functions.

_texture.loadFromFile("images/"+_fname);
_sprite.setTexture(_texture);

sf::Vector2u scale = _texture.getSize();
_sprite.setOrigin((scale.x/2),(scale.y/2));

Now that my planet bodies are all set to be printed to the screen, I start my draw loop and work
my way through the vector of bodies printing each one. But before I do that I make sure to print
my background, which wasn't a requirement yet but I decided to do it anyway.

sf::Texture bgtexture;
if (!bgtexture.loadFromFile("images/starfield.jpg"))
	return EXIT_FAILURE;
sf::Sprite background(bgtexture);

Now the Draw loop

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

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
None

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
My eyes started to get really dry from staring at the screen.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
