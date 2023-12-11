#pragma once 

#include<SFML/Graphics.hpp>
#include<string>
#include"../../appstate.h"
#include"../../playingstate.h"
#include"../../utility/music.h"
#include"../../components/sidebar/sidebar.h"

class DeletePlaylistButton {
private:
	sf::RectangleShape background;
	sf::Text text;
	sf::Font font;
	float xPos;
	float yPos;

public:
	DeletePlaylistButton(float xResolution,float yResolution);
	~DeletePlaylistButton();
	bool contains(sf::Vector2f point);
	void updateColorOnHover(sf::Vector2f mousePosition);
	void handleEvent(sf::Event event, AppState& currentState, PlayingState& playingState, Music& music,Sidebar& sidebar,std::string currentPlaylistName);
	void update(AppState& currentState, PlayingState& playingState);
	void draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playingState);

};