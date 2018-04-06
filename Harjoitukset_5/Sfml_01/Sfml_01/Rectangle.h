#pragma once

#include "SFML\Graphics.hpp"

class Rectangle : public sf::RectangleShape {
public:
	void setHeight() {
		_h += 75;
	}
	void draw(sf::RenderWindow&);
	Rectangle(int, int, int, int, sf::Color);
public:
	sf::Color color;
	int _h = 150;
};