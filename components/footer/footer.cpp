#include"footer.h"
#include<iostream>

Footer::Footer(float resolutionX,float resolutionY):playbutton(resolutionX, resolutionY), songshifter(resolutionX, resolutionY), progressbar(resolutionX, resolutionY), volumebuttons(resolutionX, resolutionY) {
	float positionY = (resolutionY / 2) + (resolutionY / 3);
	mBackground.setPosition(0.f, positionY); 
	mBackground.setFillColor(sf::Color(33, 33, 33));
	mBackground.setSize(sf::Vector2f(resolutionX, resolutionY/3)); 

	font.loadFromFile("assets/fonts/GothamMedium.ttf");
	songNameText.setFont(font);
	songNameText.setCharacterSize(22);
	songName = "Nothing to play";
	songNameText.setFillColor(sf::Color(200, 200, 200));
	songNameText.setString(songName);
	songNameText.setPosition(50.0f, resolutionY - 90.0f);
	
}


void Footer::draw(sf::RenderWindow& window,AppState& currentState,PlayingState & playingState,Music & music) {
	window.draw(mBackground);
	window.draw(songNameText);
	playbutton.draw(window,currentState, playingState,music);
	songshifter.draw(window,currentState, playingState);
	progressbar.draw(window, currentState,playingState,music);
	volumebuttons.draw(window,currentState, playingState);

}

Footer::~Footer(){}

void Footer::setSongName(std::string songName){
	this->songName = songName;
}

std::string Footer::getSongName(){
	return songName;	
}

void Footer::handleEvent(sf::Event event, AppState& currentState,PlayingState& playingState,Music& music){
	playbutton.handleEvent(event, currentState,playingState,music);
	songshifter.handleEvent(event, currentState, playingState,music);
	volumebuttons.handleEvent(event, currentState, playingState, music);
	progressbar.handleEvent(event, currentState, playingState, music);
}

void Footer::update(AppState& currentState,PlayingState& playingState,Music& music) {
	playbutton.update(currentState, playingState,music);
	progressbar.update(currentState, playingState, music);
	volumebuttons.update(currentState, playingState);
	std::string currentSongPath;

	if (playingState == PlayingState::AllSongs) {
		currentSongPath = music.getCurrentAllSongs();
	}
	else if (playingState == PlayingState::LikedSongs) {
		currentSongPath = music.getCurrentLikedSongs();
	}
	else if (playingState == PlayingState::PlaylistSongs) {
		currentSongPath = music.getCurrentPlaylistSongs();
	}

	fs::path songPath(currentSongPath);
	std::string updatedSongName = songPath.filename().string();

	if (updatedSongName.length() > 30) {
		updatedSongName = updatedSongName.substr(0, 29) + "...";
	}

	songName = updatedSongName;
	songNameText.setString(songName);
	
}