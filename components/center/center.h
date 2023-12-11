#pragma once

#include<SFML/Graphics.hpp>
#include "searchbar.h"
#include"inputbar.h"
#include "../buttons/pageshifter.h"
#include "../buttons/deleteplaylistbutton.h"
#include"../../appstate.h"
#include"../../playingstate.h"
#include"../../utility/music.h"
#include "../../components/sidebar/sidebar.h"
#include<vector>
#include"songCard.h"
#include <memory>
#include<cctype>
#include<algorithm>

class Center {
private:
	sf::RectangleShape background;
	sf::Font font;
	sf::Text homeText;
	sf::Text searchText;
	sf::Text createNewPlaylistText;
	sf::Text playlistNameText;
	sf::Text totalSongsText;
	SearchBar searchbar;
	InputBar inputbar;
	PageShifter pageshifter;
	DeletePlaylistButton deleteplaylistbutton;
	std::vector<std::unique_ptr<SongCard>> songcards;
	std::vector<std::unique_ptr<SongCard>> filteredCards;

	int positioner;
	int filteredPositioner;
	std::size_t startingPlaylistIndex;
	AppState currentState;
	std::string currentPlaylistName;
	std::string newPlaylistName;

public:
	Center(float resolutionX, float resolutionY);
	~Center();
	void handleEvent(sf::Event event,AppState& currentState,PlayingState& playingState,Music& music,std::string& centerName,Sidebar& sidebar);
	void update(AppState& currentState,PlayingState& playingState,Music& music,Sidebar&sidebar);
	void addNewSongFilteredSongs(std::string title, int duration, int index);
	void addNewSong(std::string title, int duration, int index);
	void draw(sf::RenderWindow& window,AppState& currentState,PlayingState& playingState,Music& music,Sidebar& sidebar);
};