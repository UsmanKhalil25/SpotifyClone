#pragma once

#include <SFML/Graphics.hpp>
#include"components\footer\footer.h"
#include"components/sidebar/sidebar.h"
#include "components/center/center.h"
#include"components/header/header.h"
#include"components/sidebar/playlistitem.h"
#include"utility/music.h"
#include"appstate.h"
#include"playingstate.h"


class Engine {
private:
	sf::RenderWindow mWindow;
	float mResolutionX = 1280.0f;
	float mResolutionY = 720.0f;

	Header header;
	Footer footer;
	Sidebar sidebar;
	Center center;
	Music music;

	AppState currentState;
	PlayingState playingState;
	std::vector<std::unique_ptr<PlaylistItem>> playlists;

	std::string centerName;
	const uint32_t FPS = 60;
	const sf::Time FRAME_TIME = sf::seconds(1.0f / FPS);

private:
	void mainLoop();
	void pollEvents();
	void render();
	void update();

public:
	Engine();
	~Engine();
	void run();

};