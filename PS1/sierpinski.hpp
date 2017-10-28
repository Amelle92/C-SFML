#include <SFML/Graphics.hpp>

class Sierpinski : public sf::Drawable
{
	public:
	
		//top left right points and depth
		Sierpinski(sf::Vector2f, sf::Vector2f, sf::Vector2f, int);
		
		//side length and depth
		Sierpinski(int, int);
		
		//destructor
		~Sierpinski();
		
	private:
		
		void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
		
		sf::Vector2f _top, _left, _right;
		int _depth;
		
		Sierpinski* _child1;
		Sierpinski* _child2;
		Sierpinski* _child3;
};
