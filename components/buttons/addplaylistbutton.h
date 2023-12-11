#pragma once

#include<SFML/Graphics.hpp>
#include"../../appstate.h"
class AddPlaylistButton {
private:
	sf::Sprite buttonSprite;
	sf::Texture buttonTexture;
public:
	AddPlaylistButton(float resolutionX, float resolutionY);
	~AddPlaylistButton();
	void handleEvent(sf::Event event, AppState& currentState);
	void update(AppState& currentState);
	void draw(sf::RenderWindow& window, AppState& currentState);
	bool contains(sf::Vector2f point);
};