#include <SFML/Graphics.hpp>
#include <string>

class Body : public sf::Drawable
{
	public:
		
		//constructor
		Body(double univ_size, int window_size);
		
		//destructor
		~Body();
		
		//accessors
		double xpos();
		double ypos();
		double mass();
		
		//mutators
		void conversions();				//converts xpos and ypos
		void add_to_xvel(double xvel);  //update x velocity
		void add_to_yvel(double yvel);  //update y velocity
		void step(double t);		    //based on existing v's update positions
									    //calls update_pixel_pos after updating
									   
		void update_pixel_pos(void);	//update sprite coords based on x,y, position
		
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
