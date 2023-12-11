#pragma once

#include<SFML/Graphics.hpp>
#include"../../appstate.h"
#include"../../playingstate.h"
#include"../../utility/music.h"

class DropDown {
private:
	sf::Font font;
	sf::Text titleText;
	std::string title;
	sf::RectangleShape background;
	std::vector<sf::Text> optionsText;	
	std::vector<sf::RectangleShape> optionsRectangle;
	std::vector<std::string> optionsNames;
	int numberOfOptions;
	float xPos;
	float yPos;
	bool display;
public:
	DropDown(float xPos, float yPos, std::string title, std::vector<std::string> options);
	~DropDown();
	void handleEvent(sf::Event event, AppState& currentState, PlayingState& playingState, Music& music);
	void update(AppState& currentState, PlayingState& playingState,Music & music);
	void draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playingState);
	bool containsTitle(sf::Vector2f point);
	bool containsOption(sf::Vector2f point, std::size_t optionIndex);
	void updateColorOnHover(sf::Vector2f mousePosition);
	bool getIsDisplaying();
	void setIsDisplaying(bool display);
};