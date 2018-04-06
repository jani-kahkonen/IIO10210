#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h, sf::Color c): _h(h), color(c) {
	this->setSize(sf::Vector2f(w, _h));
	this->setPosition(x, y);
	this->setFillColor(c);
}

void Rectangle::draw(sf::RenderWindow &window) {
	this->setFillColor(color);
	this->setSize(sf::Vector2f(50, _h));
	window.draw(*this);

}