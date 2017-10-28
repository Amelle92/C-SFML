#include "original.hpp"
#include <cmath>
#include <iostream>

Original::Original(sf::Vector2f top, sf::Vector2f left, sf::Vector2f bottom, sf::Vector2f right, int depth) : 
									  _top(top), _left(left), _bottom(bottom), _right(right), _depth(depth)
									  //p1          //p2           //p3             //p4
{
	int newdepth = _depth - 1;
	
	if(newdepth > 0) 
	{
		
		//Finding the midpoints
		sf::Vector2f p1 = sf::Vector2f( (_top.x + _left.x) / 2,
										(_top.y + _left.y) / 2);
					   
		sf::Vector2f p2 = sf::Vector2f( (_left.x + _bottom.x) / 2,
										(_left.y + _bottom.y) / 2);
										
		sf::Vector2f p3 = sf::Vector2f( (_right.x + _bottom.x) / 2,
										(_right.y + _bottom.y) / 2);
									
		sf::Vector2f p4 = sf::Vector2f( (_right.x + _top.x) / 2,
										(_right.y + _top.y) / 2);
										
		
		//Recursively creating the new child nodes
		_child1 = new Original(p1, p2, p3, p4, newdepth);
	} 
	else //if depth is less than 1 then there will not be any child nodes
	{
		_child1 = NULL;
	}
}

Original::Original(int side, int depth) : _depth(depth)
{
	_top = sf::Vector2f(0, 0);
	
	float height = .5 * sqrt(4.) * (float)side;
	
	_left = sf::Vector2f(0, height-1);
	_right = sf::Vector2f(height-1, 0);
	_bottom = sf::Vector2f(height-1, height-1);
	
	int newdepth = _depth - 1;
	if(newdepth > 0) {
		
		
		//find midpoints
		sf::Vector2f p1 = sf::Vector2f( (_top.x + _right.x) / 2,
										(_top.y + _right.y) / 2);
					   
		sf::Vector2f p2 = sf::Vector2f( (_top.x + _left.x) / 2,
										(_top.y + _left.y) / 2);
										
		sf::Vector2f p3 = sf::Vector2f( (_left.x + _bottom.x) / 2,
										(_left.y + _bottom.y) / 2);
		
		sf::Vector2f p4 = sf::Vector2f( (_right.x + _bottom.x) / 2,
										(_right.y + _bottom.y) / 2);
		
		//recursively add child nodes
		_child1 = new Original(p1, p2, p3, p4, newdepth);
	} 
	else //depth is not > 0 so there are no child nodes
	{
		_child1 = NULL;
	}			
}

Original::~Original()
{
	//free the children
	if(_child1 != NULL) 
	{
		delete (_child1);
	}
}

void Original::draw(sf::RenderTarget& target, sf::RenderStates states) const
{		
	//find midpoints
	sf::Vector2f p1 = sf::Vector2f( (_top.x + _right.x) / 2,
									(_top.y + _right.y) / 2);
					   
	sf::Vector2f p2 = sf::Vector2f( (_top.x + _left.x) / 2,
									(_top.y + _left.y) / 2);
										
	sf::Vector2f p3 = sf::Vector2f( (_left.x + _bottom.x) / 2,
									(_left.y + _bottom.y) / 2);
	
	sf::Vector2f p4 = sf::Vector2f( (_right.x + _bottom.x) / 2,
									(_right.y + _bottom.y) / 2);
									
	//draw traingle using p1 p2 p3		
	sf::ConvexShape polygon;
	polygon.setPointCount(4);
	polygon.setPoint(0, p1); //draw first point  p1
	polygon.setPoint(1, p2); //draw second point p2
	polygon.setPoint(2, p3); //draw third point  p3
	polygon.setPoint(3, p4); //draw third point  p4
	polygon.setFillColor(sf::Color::Transparent);
	polygon.setOutlineThickness(2.);
	sf::Color custom(std::rand() % 255, std::rand() % 255, std::rand() % 255);
	polygon.setOutlineColor(custom);
	sf::Color custom2(std::rand() % 255, std::rand() % 255, std::rand() % 255);
	polygon.setFillColor(custom2);
	
	target.draw(polygon, states);
	
	if (_child1 != NULL) {
		_child1->draw(target, states);
	}
		
}
