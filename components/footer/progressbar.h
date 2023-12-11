#pragma once

#include<SFML/Graphics.hpp>
#include "../../playingstate.h"
#include "../../appstate.h"
#include "../../utility/music.h"

class ProgressBar {
private:
	sf::RectangleShape backgroundBar;
	sf::RectangleShape progressBar;
	sf::Text totalTimeText;
	sf::Text timeElapsedText;
	sf::Font font;
	int totalTime;
	int timeElapsed;
	void updateTextPositions();

public:
	ProgressBar(float resolutionX,float resolutionY);
	~ProgressBar();
	void handleEvent(sf::Event event, AppState& currentState, PlayingState& playingState,Music& music);
	void update(AppState& currentState, PlayingState& playingState,Music& music);
	void draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playingState,Music& music);
	bool contains(sf::Vector2f point);
	void setTotalTime(const int totalTime);
	void setElapsedTime(const int timeElapsed);

};