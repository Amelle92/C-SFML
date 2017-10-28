#include <SFML/Graphics.hpp>

class Original : public sf::Drawable
{
	public:
	
		//top left right points and depth
		Original(sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f, int);
		
		//side length and depth
		Original(int, int);
		
		//destructor
		~Original();
		
	private:
		
		void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
		
		sf::Vector2f _top, _left, _bottom, _right;
		int _depth;
		
		Original* _child1;
};
