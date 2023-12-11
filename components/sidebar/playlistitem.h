#pragma once

#include<SFML/Graphics.hpp>
#include"../../appstate.h"
#include"../../playingstate.h"
#include "../../utility/music.h"

class PlaylistItem {

private:
	sf::RectangleShape button;
	sf::Text nameText;
	std::string name;
	sf::Font font;
	bool isSelected;
public:
	PlaylistItem(float resolutionX, float yPosition,std::string name);
	~PlaylistItem();
	void setName(std::string name);
	std::string getName();
	void handleEvent(sf::Event event, AppState& currentState, PlayingState& playingState, Music& music);
	void update(AppState& currentState, PlayingState& playingState, Music& music);
	void draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playingState, Music& music);
	bool contains(sf::Vector2f point);
	void updateColorOnHover(sf::Vector2f mousePosition);
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;
	bool getIsSelected();
	void setIsSelected(bool isSelected);

};