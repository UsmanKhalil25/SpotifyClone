#pragma  once

#include <SFML/Graphics.hpp>
#include"../buttons/playbutton.h"
#include"../buttons/songshifter.h"
#include"../buttons/volumebuttons.h"
#include "../../appstate.h"
#include"progressbar.h"
#include<string>
#include "../../utility/music.h"
#include "../../playingstate.h"
#include<filesystem>


class Footer {
private:
	sf::RectangleShape mBackground;
	sf::Font font;
	sf::Text songNameText;
	std::string songName;
	PlayButton playbutton;
	SongShifter songshifter;
	ProgressBar progressbar;
	VolumeButtons volumebuttons;
public:

	Footer(float resolutionX,float resolutionY);
	~Footer();
	void setSongName(std::string songName);
	std::string getSongName();
	void handleEvent(sf::Event event, AppState& currentState,PlayingState& playingState,Music& music);
	void update(AppState& currentState,PlayingState& playingState,Music& music);
	void draw(sf::RenderWindow& window, AppState& currentState,PlayingState& playingState, Music& music);


};