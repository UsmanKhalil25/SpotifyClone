#pragma once

#include<SFML/Graphics.hpp>
#include "../../appstate.h"
#include"../../playingstate.h"
#include "../../utility/music.h"
class SongCard {
private:
	int index;
	sf::RectangleShape background;
	sf::Font font;
	sf::Text titleText;
	sf::Text durationText;
	std::string title;
	bool isSelected;
	int duration;

public:
	SongCard(float resolutionX, float yPosition, std::string title,int duration,int index);
	~SongCard();
	void setTitle(std::string title);
	std::string getTitle();
	void setDuration(int duration);
	int getDuration();
	int getIndex();
	bool getIsSelected();
	void setIsSelected(bool isSelected);
	void handleEvent(sf::Event event, AppState& currentState, PlayingState& playingState, Music& music);
	void update(AppState& currentState, PlayingState& playingState, Music& music);
	void draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playingState, Music& music);
	bool contains(sf::Vector2f point);
	void updateColorOnHover(sf::Vector2f mousePosition);

};