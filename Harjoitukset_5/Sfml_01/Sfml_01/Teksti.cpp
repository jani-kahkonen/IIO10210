#include "Teksti.h"
#include "globals.h"
#include <string>
#include "SFML\Graphics.hpp"
#include "character.h"

Teksti::Teksti(sf::Font *font, int r = 255, int g = 255, int b = 255, int size = 14, std::string str = "") {
	//_str = str;
	font->loadFromFile("tahoma.ttf");
	this->setFont(*font);
	this->setCharacterSize(size);
	this->setColor(sf::Color(r, g, b));
	this->setString(str);

}


void Teksti::draw(sf::RenderWindow &window) {
	//this->setString(_str);
	window.draw(*this);

}

void Teksti::draw2(sf::RenderWindow &window, std::string s) {
	this->setString(s);
	window.draw(*this);

}