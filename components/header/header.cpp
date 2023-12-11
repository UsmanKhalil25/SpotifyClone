#include"header.h"

Header::Header(float resolutionX, float resolutionY): dropdown1(950.0f, 0.0f, "File", std::vector<std::string>{"Create new playlist", "Exit"}), dropdown2(1100.0f, 0.0f, "Playback", std::vector<std::string>{"Play next song", "Play previous song", "Shuffle"}) {
    header.setPosition(0.f, 0.f);
    header.setFillColor(sf::Color(33, 33, 33));
    header.setSize(sf::Vector2f(resolutionX, 20.0f));
}

void Header::handleEvent(sf::Event event, AppState& currentState,PlayingState& playingState,Music & music){
	dropdown1.handleEvent(event, currentState, playingState, music);
	dropdown2.handleEvent(event, currentState, playingState, music);

}

void Header::update(AppState& currentState,PlayingState& playingState,Music & music){
	dropdown1.update(currentState, playingState,music);
	dropdown2.update(currentState, playingState, music);

}

void Header::draw(sf::RenderWindow& window, AppState& currentState,PlayingState& playingState,Music & music){
	window.draw(header);
	dropdown1.draw(window, currentState, playingState);
	dropdown2.draw(window, currentState, playingState);

}

bool Header::contains(sf::Vector2f point){
	return header.getGlobalBounds().contains(point);
}

Header::~Header(){}