#include <SFML/Graphics.hpp>
#include <string>

class Body : public sf::Drawable
{
	public:
		
		//constructor
		Body(double univ_size, int window_size);
		
		//destructor
		~Body();
		
		//mutators
		void conversions();				//converts xpos and ypos
		void step(double seconds);		//based on existing v's update positions
		
		//overload >> operator to read in xpos, ypos, xvel, yvel, mass, and
		//filename for image sprite
		friend std::istream& operator >> (std::istream &input, Body &B);
		
	private:
		
		//implement draw method to display self
		void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
		double _xpos, _ypos, _xvel, _yvel, _mass, _univ_size;
		int _window_size;
		sf::Texture _texture;
		sf::Sprite _sprite;
		std::string _fname;
};
