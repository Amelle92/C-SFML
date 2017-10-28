#include "NBody.hpp"
#include <iostream>
#include <string>

Body::Body(double univ_size, int window_size):_univ_size(univ_size), 
											_window_size(window_size)
{
	std::cin>>*this; //populate the variables from planets.txt
	
	this->conversions(); //convert the x and y positions
	
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
double Body::xpos()
{
	return _xpos;
}
double Body::ypos()
{
	return _ypos;
}
double Body::mass()
{
	return _mass;
}
void Body::add_to_xvel(double xvel)
{
	_xvel += xvel;
}
void Body::add_to_yvel(double yvel)
{
	_yvel += yvel;
}
void Body::step(double t)
{
	//for physics portion
}
void Body::update_pixel_pos(void)
{
	//for physics portion
}
void Body::conversions()
{
	//coordinate conversions
	_xpos = (_xpos/((_univ_size*2)/_window_size)) + 256;
	_ypos = (_ypos/((_univ_size*2)/_window_size)) + 256;
	_sprite.setPosition(_xpos, _ypos); //set new position
}
std::istream& operator >> (std::istream &input, Body &B)
{
	input>>B._xpos>>B._ypos>>B._xvel>>B._yvel>>B._mass>>B._fname;
	return input;
}
