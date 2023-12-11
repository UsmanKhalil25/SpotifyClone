#pragma once

#include<SFML/Graphics.hpp>
#include"playlistitem.h"
#include "../buttons/addplaylistbutton.h"
#include"../../appstate.h"
#include"../../playingstate.h"
#include "../../utility/music.h"
#include"../buttons/pageshifter.h"
#include<vector>
#include <memory>

class PlaylistArea {		
private:
	PageShifter pageshifter;
	sf::Text playlistText;
	sf::Font font;
	sf::RectangleShape background;
	std::vector<std::unique_ptr<PlaylistItem>> playlists;
	float resolutionX;
	float xSize;
	float ySize;
	int positioner;
	std::size_t startingPlaylistIndex;
	int selectedIndex;
public:
	PlaylistArea(float resolutionX,float resolutionY);
	~PlaylistArea();
	void setSelectedIndex(int index);
	int getSelectedIndex();
	void handleEvent(sf::Event event, AppState& currentState,PlayingState& playlistState,Music& music,std::string& centerName);
	void update(AppState& currentState, PlayingState& playlistState, Music& music);
	void draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playlistState, Music& music);
	void addNewPlaylist(std::string playlistname);
	void deletePlaylist(std::string playlistname);
	bool contains(sf::Vector2f point);
	std::string getPlaylistName();

};