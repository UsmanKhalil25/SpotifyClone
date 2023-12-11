#pragma once

#include <SFML/Graphics.hpp>
#include "../../appstate.h"
#include "../../playingstate.h"
#include "../../utility/music.h"

class SongShifter {
private:
	sf::Sprite nextButtonSprite;
	sf::Sprite previousButtonSprite;
	sf::Texture nextButtonTexture;
	sf::Texture previousButtonTexture;
	sf::Texture shuffleButtonTexture;
	sf::Sprite shuffleButtonSprite;
public:
	SongShifter(float resolutionX,float resolutionY);
	~SongShifter();
	void handleEvent(sf::Event event, AppState& currentState,PlayingState& playingState,Music & music);
	void update(AppState& currentState,PlayingState& playingState);
	void draw(sf::RenderWindow& window, AppState& currentState,PlayingState& playingState);
	bool containsNext(sf::Vector2f point);
	bool containsPrevious(sf::Vector2f point);
	bool containsShuffle(sf::Vector2f point);

};