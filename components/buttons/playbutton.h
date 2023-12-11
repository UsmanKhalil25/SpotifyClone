#pragma once

#include <SFML/Graphics.hpp>
#include"../../appstate.h"
#include"../../playingstate.h"
#include "../../utility/music.h"
class PlayButton {
private:
	sf::CircleShape circle;
	sf::Sprite playingSprite;
	sf::Sprite pauseSprite;
	sf::Texture playTexture;
	sf::Texture pauseTexture;
	bool isPlaying;

public:
	PlayButton(float resolutionX,float resolutionY);
	~PlayButton();
	void setIsPlaying(bool isPlaying);
	bool getIsPlaying();
	void handleEvent(sf::Event event, AppState& currentState,PlayingState & playingState,Music & music);
	void update(AppState& currentState,PlayingState& playingState,Music& music);
	void draw(sf::RenderWindow& window, AppState& currentState,PlayingState& playingState,Music& music);
	bool contains(sf::Vector2f point);
	void updateColorOnHover(sf::Vector2f mousePosition);
};