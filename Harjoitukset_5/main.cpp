/*
+---------------------------------------------------------------------+
|  SMV -  - Superman Meets Viikatemies - Version 40                     |
+---------------------------------------------------------------------+
| Copyright (c) 2002-2014 The SMV Group (http://aaaseeemviii.com/)      |
+---------------------------------------------------------------------+
| This source file is subject to version 40.00 of the SMV license,      |
| that is bundled with this package in the file LICENSE, and is         |
| available through the world-wide-web at the following url:            |
| http://aaaseeemviii.com/license/40_00.txt.                            |
| If you did not receive a copy of the SMV license and are unable to    |
| obtain it through the world-wide-web, please send a note to           |
| license@aaaseeemviii.com so we can mail you a copy immediately.       |
+---------------------------------------------------------------------+
| Authors: Ari Rantala <ara@aaaseeemviii.com>                           |
+---------------------------------------------------------------------+
*/


/* ************************************************************************
Luotu:    29.9.2014 Ari Rantala

Toiminta: SMV - Superman Meets Viikatemies. SMV on pieni SFML-kirjaston
perusominaisuuksia demonstroiva "peli", jonka dokumentaatio
toimitetaan toistaiseksi vain puhuttuna.
************************************************************************ */

#include <iostream>
#include <random>
#include "globals.h"
#include "event.h"
#include "gamestatus.h"
#include "character.h"
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Teksti.h"
#include "Rectangle.h"

int main() {
	int frames = 0;
	int s = 0, v = 0;
	//G7902 Ohjelmistoprojekti
	// Satunnaislukujen alustus
	std::random_device rd;
	std::srand(rd());

	// dClock FPS:stä riippumaton peliaika
	sf::Clock dClock;

	//TAUSTAN MUODOSTAMINEN
	sf::Image background_image;
	background_image.loadFromFile("background.jpg");
	sf::Texture background_tex;
	background_tex.loadFromImage(background_image);

	sf::Font font1;

	Teksti vmantext(&font1, 0, 0, 0, 16, "Viikatemies");
	vmantext.setPosition(50, ag::ZONE_HEIGHT - 60);

	Teksti smantext(&font1, 0, 0, 0, 16, "Supermies");
	smantext.setPosition(350, ag::ZONE_HEIGHT - 60);

	Teksti ss(&font1, 0, 0, 0, 20, "0");
	ss.setPosition(250, ag::ZONE_HEIGHT - 60);

	Teksti sv(&font1, 0, 0, 0, 20, "0");
	sv.setPosition(210, ag::ZONE_HEIGHT - 60);

	Teksti fps(&font1, 0, 0, 0, 20, "0");
	fps.setPosition(200, 40);

	sf::RectangleShape background;
	background.setSize(sf::Vector2f((float)ag::ZONE_WIDTH, (float)ag::ZONE_WIDTH - 30));
	background.setPosition(0, 0);
	background.setTexture(&background_tex);

	// Pelin tilan ja tapahtumien kasittely
	Event      tapahtumat;
	Gamestatus pelitila;

	// Hahmot
	sf::Texture vmantex, smantex;

	/*Background b("viikatemies.png", -ag::CHARACTER_DISTANCE, &vmantex);*/

	Character vman("viikatemies.png", -ag::CHARACTER_DISTANCE, &vmantex);
	Character sman("superman.png", ag::CHARACTER_DISTANCE, &smantex);

	Rectangle v1(30, 30, 50, 100, sf::Color::Black);
	Rectangle s2(430, 30, 50, 100, sf::Color::Red);

	sf::RenderWindow window(sf::VideoMode(ag::ZONE_WIDTH, ag::ZONE_HEIGHT), "Superman vs. Viikatemies");

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// - - - - - - - - - - - Varsinanen peli kayntiin  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	pelitila.setgamestatus(1);

	while (window.isOpen()) {
		tapahtumat.kasittele(window);

		// Pelinopeus FPS:stä riippumaton vakio
		float d = dClock.restart().asSeconds();
		float siirtyma = d * ag::GAME_SPEED;

		// Peli kaynnissa
		if (pelitila.getgamestatus() == 1){
			// Viikatemiehen siirtyma
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
				vman.setPosition(vman.getPosition() + sf::Vector2f(0, -siirtyma));
				vman.setRotation(0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
				vman.setPosition(vman.getPosition() + sf::Vector2f(0, siirtyma));
				vman.setRotation(180);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
				vman.setPosition(vman.getPosition() + sf::Vector2f(-siirtyma, 0));
				vman.setRotation(270);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				vman.setPosition(vman.getPosition() + sf::Vector2f(siirtyma, 0));
				vman.setRotation(90);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
				// Jos hahmot tormaavat
				if (vman.getPosition().x < sman.getPosition().x + ag::COLLISION_LIMIT &&
					vman.getPosition().x > sman.getPosition().x - ag::COLLISION_LIMIT &&
					vman.getPosition().y < sman.getPosition().y + ag::COLLISION_LIMIT &&
					vman.getPosition().y > sman.getPosition().y - ag::COLLISION_LIMIT){

					v1.setHeight();		v++;

					// Viikatemiehelle arvotaan uusi sijainti
					float xsijainti = (float)(std::rand() % ag::ZONE_WIDTH + 1);
					float ysijainti = (float)(std::rand() % ag::ZONE_HEIGHT + 1);
					sman.setPosition(xsijainti, ysijainti);

					// Kummankin pisteitä lisätään demotarkoituksessa
					vman.setpoints(vman.getpoints() + 20);
				}
			}

			// Hahmo ilmestyy alueen toiselta puolelta ylittaessaan rajat
			if (vman.getPosition().x > ag::ZONE_WIDTH + ag::BORDER_LIMIT) vman.setPosition(-ag::BORDER_LIMIT, vman.getPosition().y);
			if (vman.getPosition().x < -ag::BORDER_LIMIT) vman.setPosition(ag::ZONE_WIDTH + ag::BORDER_LIMIT, vman.getPosition().y);
			if (vman.getPosition().y > ag::ZONE_HEIGHT + ag::BORDER_LIMIT) vman.setPosition(vman.getPosition().x, -ag::BORDER_LIMIT);
			if (vman.getPosition().y < -ag::BORDER_LIMIT) vman.setPosition(vman.getPosition().x, ag::ZONE_HEIGHT + ag::BORDER_LIMIT);

			// Supermanin siirtyma
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				sman.setPosition(sman.getPosition() + sf::Vector2f(0, -siirtyma));
				sman.setRotation(0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				sman.setPosition(sman.getPosition() + sf::Vector2f(0, siirtyma));
				sman.setRotation(180);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				sman.setPosition(sman.getPosition() + sf::Vector2f(-siirtyma, 0));
				sman.setRotation(270);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				sman.setPosition(sman.getPosition() + sf::Vector2f(siirtyma, 0));
				sman.setRotation(90);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
			// Jos hahmot tormaavat
				if (vman.getPosition().x < sman.getPosition().x + ag::COLLISION_LIMIT &&
					vman.getPosition().x > sman.getPosition().x - ag::COLLISION_LIMIT &&
					vman.getPosition().y < sman.getPosition().y + ag::COLLISION_LIMIT &&
					vman.getPosition().y > sman.getPosition().y - ag::COLLISION_LIMIT){

					s2.setHeight();		s++;

					// Viikatemiehelle arvotaan uusi sijainti
					float xsijainti = (float)(std::rand() % ag::ZONE_WIDTH + 1);
					float ysijainti = (float)(std::rand() % ag::ZONE_HEIGHT + 1);
					vman.setPosition(xsijainti, ysijainti);

					// Kummankin pisteitä lisätään demotarkoituksessa
					sman.setpoints(sman.getpoints() + 50);
				}
			}

			// Hahmo ilmestyy alueen toiselta puolelta ylittaessaan rajat
			if (sman.getPosition().x > ag::ZONE_WIDTH + ag::BORDER_LIMIT) sman.setPosition(-ag::BORDER_LIMIT, sman.getPosition().y);
			if (sman.getPosition().x < -ag::BORDER_LIMIT) sman.setPosition(ag::ZONE_WIDTH + ag::BORDER_LIMIT, sman.getPosition().y);
			if (sman.getPosition().y > ag::ZONE_HEIGHT + ag::BORDER_LIMIT) sman.setPosition(sman.getPosition().x, -ag::BORDER_LIMIT);
			if (sman.getPosition().y < -ag::BORDER_LIMIT) sman.setPosition(sman.getPosition().x, ag::ZONE_HEIGHT + ag::BORDER_LIMIT);
		} // Peli kaynnissa

		  // Tyhjataan naytto
		window.clear();

		// Piirrellaan oliot naytolle
		window.draw(background, sf::RenderStates::Default); // Tää pitää luoda ensin.

		vman.draw(window);
		sman.draw(window);

		vmantext.draw(window);
		smantext.draw(window);

		v1.draw(window);
		s2.draw(window);

		fps.draw2(window, std::to_string(frames++));

		ss.draw2(window, std::to_string(s));
		sv.draw2(window, std::to_string(v));


		// Jos jommallakummalla pelaajalla pisteet yli 200, kerrotaan voittaja
		if (vman.getpoints() >= 200){
			if (pelitila.getgamestatus()) vman.setwins(vman.getwins() + 1);
			pelitila.setgamestatus(0);
		}
		else if (sman.getpoints() >= 200){
			if (pelitila.getgamestatus()) sman.setwins(sman.getwins() + 1);

			Teksti svoitti(&font1, 0, 0, 0, 16, "Supermies voitti");
			svoitti.setPosition(200, ag::ZONE_HEIGHT - 200);

			Teksti info(&font1, 0, 0, 0, 16, "R = RETRY | ESC = EXIT");
			info.setPosition(200, ag::ZONE_HEIGHT - 240);

			svoitti.draw(window);

			info.draw(window);

			pelitila.setgamestatus(0);


		}

		// Pelin uudelleenkaynnistys R:lla
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
			vman.setPosition(-ag::CHARACTER_DISTANCE + ag::ZONE_WIDTH / 2, ag::ZONE_HEIGHT / 2);
			sman.setPosition(ag::CHARACTER_DISTANCE + ag::ZONE_WIDTH / 2, ag::ZONE_HEIGHT / 2);
			vman.setpoints(0);
			sman.setpoints(0);
			pelitila.setgamestatus(1);
		}
		window.display();
	}
	return 0;
}