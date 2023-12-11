#pragma once

#include<SFML/Graphics.hpp>
#include "../../appstate.h"
#include"../../playingstate.h"
#include"../../utility/music.h"
#include"dropdown.h"
class Header {
private:
	sf::RectangleShape header;
	DropDown dropdown1;
	DropDown dropdown2;
public:
	Header(float resolutionX, float resolutionY);
	~Header();
	void handleEvent(sf::Event event, AppState& currentState,PlayingState& playingState,Music & music);
	void update(AppState& currentState,PlayingState& playingState,Music & music);
	void draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playingState, Music& music);
	bool contains(sf::Vector2f point);




};