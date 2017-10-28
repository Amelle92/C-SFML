#include "NBody.hpp"
#include <iostream>
#include <string>
#include <math.h>

Body::Body(double univ_size, int window_size):_univ_size(univ_size), 
											_window_size(window_size)
{
	std::cin>>*this; //populate the variables from planets.txt
	
	conversions(); //convert the x and y positions
	
	_texture.loadFromFile("images/"+_fname);
	_sprite.setTexture(_texture);
	
	//get the size of the texture and set the sprites origin to the center
	sf::Vector2u scale = _texture.getSize();
	_sprite.setOrigin((scale.x/2),(scale.y/2));
}
Body::~Body()
{
}
void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}
void Body::step(double seconds)
{
	if(_mass==1.9890e+30) //Don't do for the sun
		return;
	
	double x, y, G=6.67e-11, F, r, x_accel, y_accel, D_x, D_y;
	
	//calculate the pairwise forces
	D_x = _xpos;
	D_y = _ypos;
	r = sqrt((pow(D_x,2))+(pow(D_y,2)));
	F = (((_mass*1.9890e+30)*G)/pow(r,2));
	x = F*(D_x/r);
	y = F*(D_y/r);
	
	//acceleration
	x_accel = x/_mass;
	y_accel = y/_mass;
	
	//new velocity
	_xvel = (_xvel + (seconds * x_accel));
	_yvel = (_yvel + (seconds * y_accel));
	
	//new position
	_xpos -= (seconds*_xvel);
	_ypos -= (seconds*_yvel);
	
	conversions(); //convert the new positions
}
void Body::conversions()
{
	//coordinate conversions
	double xpos = (_xpos/((_univ_size*2)/_window_size)) + 256;
	double ypos = (_ypos/((_univ_size*2)/_window_size)) + 256;
	_sprite.setPosition(xpos, ypos); //set new position
}
std::istream& operator >> (std::istream &input, Body &B)
{
	input>>B._xpos>>B._ypos>>B._xvel>>B._yvel>>B._mass>>B._fname;
	return input;
}
