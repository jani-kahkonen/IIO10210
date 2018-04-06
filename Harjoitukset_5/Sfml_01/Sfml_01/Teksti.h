#ifndef TEKSTIH
#define TEKSTIH

#include "globals.h"
#include <string>
#include <sstream>
#include "SFML\Graphics.hpp"

class Teksti : public sf::Text{
public:
	void draw(sf::RenderWindow&);
	void draw2(sf::RenderWindow&, std::string);
	Teksti(sf::Font*, int, int, int, int, std::string);
private:
	std::string _str;
};

#endif
