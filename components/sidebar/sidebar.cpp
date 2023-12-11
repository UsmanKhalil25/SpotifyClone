#include "sidebar.h"

Sidebar::Sidebar(float resolutionX, float resolutionY):homebutton(resolutionX,resolutionY),searchbutton(resolutionX,resolutionY),playlistarea(resolutionX,resolutionY){}

void Sidebar::draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playlistState, Music& music) {
	homebutton.draw(window,currentState);
	searchbutton.draw(window,currentState);
	playlistarea.draw(window,currentState,playlistState,music);
}

void Sidebar::handleEvent(sf::Event event, AppState& currentState, PlayingState& playlistState, Music& music,std::string &centerName){
	
	homebutton.handleEvent(event, currentState);	
	searchbutton.handleEvent(event,currentState);
	playlistarea.handleEvent(event, currentState,playlistState,music,centerName);
}

void Sidebar::update(AppState& currentState, PlayingState& playlistState, Music& music){
	homebutton.update(currentState);
	searchbutton.update(currentState);
	playlistarea.update(currentState,playlistState,music);
}

Sidebar::~Sidebar() {}

PlaylistArea& Sidebar::getPlaylistArea()
{
	return playlistarea;
}
