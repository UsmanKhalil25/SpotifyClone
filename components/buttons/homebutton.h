#pragma once

#include<SFML/Graphics.hpp>
#include"../../appstate.h"

class HomeButton {

private:
	sf::RectangleShape button;
	sf::Texture homeTexture;
	sf::Sprite homeSprite;
	sf::Text homeText;
	sf::Font font;
public:
	HomeButton(float resolutionX,float resolutionY);
	~HomeButton();
	void handleEvent(sf::Event event, AppState& currentState);
	void update(AppState& currentState);
	void draw(sf::RenderWindow& window, AppState& currentState);
	bool contains(sf::Vector2f point);
	void updateColorOnHover(sf::Vector2f mousePosition);

};