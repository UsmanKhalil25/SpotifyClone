#pragma once
#include<SFML/Graphics.hpp>
#include"../buttons/homebutton.h"
#include"../buttons/searchbutton.h"
#include "playlistarea.h"
#include"../../appstate.h"
#include"../../playingstate.h"
#include"../../utility/music.h"
class Sidebar {
private:

	HomeButton homebutton;
	SearchButton searchbutton;
	PlaylistArea playlistarea;
public:
	Sidebar(float resolutionX, float resolutionY);
	~Sidebar();
	PlaylistArea& getPlaylistArea();
	void handleEvent(sf::Event event, AppState& currentState, PlayingState& playlistState, Music& music,std::string& centerName);
	void update(AppState& currentState, PlayingState& playlistState, Music& music);
	void draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playlistState, Music& music);

};