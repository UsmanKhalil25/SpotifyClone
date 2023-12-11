#pragma once

#include<SFML/Graphics.hpp>
#include"../../appstate.h"
#include"../../playingstate.h"
#include"../../utility/music.h"
class PageShifter {
private:
	sf::Font font;
	sf::Text next;
	sf::Text previous;
	sf::Color color;
public:
	PageShifter(float resolutionX, float resolutionY,sf::Color color);
	~PageShifter();
	void handleEvent(sf::Event event, AppState& currentState,PlayingState& playingState,Music& music);
	void update(AppState& currentState, PlayingState& playingState, Music& music);
	void draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playingState, Music& music);
	bool containsNext(sf::Vector2f point);
	bool containsPrevious(sf::Vector2f point);

};