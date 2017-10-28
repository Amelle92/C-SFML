#include "sierpinski.hpp"
#include <cmath>
#include <iostream>

Sierpinski::Sierpinski(sf::Vector2f top, sf::Vector2f left, sf::Vector2f right, int depth) : 
									  _top(top), _left(left), _right(right), _depth(depth)
{
	int newdepth = _depth - 1;
	
	if(newdepth > 0) 
	{
		
		//Finding the midpoints
		sf::Vector2f p1 = sf::Vector2f( (_top.x + _left.x) / 2,
										(_top.y + _left.y) / 2);
		sf::Vector2f p2 = sf::Vector2f( (_top.x + _right.x) / 2,
										(_top.y + _right.y) / 2);
		sf::Vector2f p3 = sf::Vector2f( (_left.x + _right.x) / 2,
										(_left.y + _right.y) / 2);
		
		//Recursively creating the new child nodes
		_child1 = new Sierpinski(_top, p1, p2, newdepth);
		_child2 = new Sierpinski(p1, _left, p3, newdepth);
		_child3 = new Sierpinski(p3, p2, _right, newdepth);
	} 
	else //if depth is less than 1 then there will not be any child nodes
	{
		_child1 = NULL;
		_child2 = NULL;
		_child3 = NULL;
	}
}

Sierpinski::Sierpinski(int side, int depth) : _depth(depth)
{
	_top = sf::Vector2f(side / 2, 0);
	
	float height = 0.5 * sqrt(3.) * (float)side;
	
	_left = sf::Vector2f(0, height);
	_right = sf::Vector2f(side-1, height);
	
	int newdepth = _depth - 1;
	if(newdepth > 0) {
		
		
		//find midpoints
		sf::Vector2f p1 = sf::Vector2f( (_top.x + _left.x) / 2,
										(_top.y + _left.y) / 2);
					   
		sf::Vector2f p2 = sf::Vector2f( (_top.x + _right.x) / 2,
										(_top.y + _right.y) / 2);
									
		sf::Vector2f p3 = sf::Vector2f( (_left.x + _right.x) / 2,
										(_left.y + _right.y) / 2);
		
		//recursively add child nodes
		_child1 = new Sierpinski(_top, p1, p2, newdepth);
		_child2 = new Sierpinski(p1, _left, p3, newdepth);
		_child3 = new Sierpinski(p2, p3, _right, newdepth);
	} 
	else //depth is not > 0 so there are no child nodes
	{
		_child1 = NULL;
		_child2 = NULL;
		_child3 = NULL;
	}			
}

Sierpinski::~Sierpinski()
{
	//free the children
	if(_child1 != NULL) 
	{
		delete (_child1);
		delete (_child2);
		delete (_child3);
	}
}

void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	std::cout << "_depth is " << _depth << std::endl;
	std::cout << "_top is (" << _top.x << ", " << _top.y << ")" << std::endl;
	std::cout << "_left is (" << _left.x << ", " << _left.y << ")" << std::endl;
	std::cout << "_right is (" << _right.x << ", " << _right.y << ")" << std::endl;
	
	
	//find midpoints
	sf::Vector2f p1 = sf::Vector2f( (_top.x + _left.x) / 2,
									(_top.y + _left.y) / 2);
					   
	sf::Vector2f p2 = sf::Vector2f( (_top.x + _right.x) / 2,
									(_top.y + _right.y) / 2);
									
	sf::Vector2f p3 = sf::Vector2f( (_left.x + _right.x) / 2,
									(_left.y + _right.y) / 2);
									
	
	//draw traingle using p1 p2 p3			   
	sf::ConvexShape polygon;
	polygon.setPointCount(3);
	polygon.setPoint(0, p1); //draw first point  p1
	polygon.setPoint(1, p2); //draw second point p2
	polygon.setPoint(2, p3); //draw third point  p3
	polygon.setFillColor(sf::Color::Red);
	
	target.draw(polygon, states);
	
	if (_child1 != NULL) {
		_child1->draw(target, states);
		_child2->draw(target, states);
		_child3->draw(target, states);
	}
		
}
