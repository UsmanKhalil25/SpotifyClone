#pragma once

#include<SFML/Graphics.hpp>
#include "../../appstate.h"

class SearchButton {

private:
	sf::RectangleShape button;
	sf::Texture searchTexture;
	sf::Sprite searchSprite;
	sf::Text searchText;
	sf::Font font;
public:
	SearchButton(float resolutionX, float resolutionY);
	~SearchButton();
	void handleEvent(sf::Event event, AppState& currentState);
	void update(AppState& currentState);
	void draw(sf::RenderWindow& window, AppState& currentState);
	bool contains(sf::Vector2f point);
	void updateColorOnHover(sf::Vector2f mousePosition);

};