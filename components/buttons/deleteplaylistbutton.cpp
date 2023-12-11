#include "deleteplaylistbutton.h"

DeletePlaylistButton::DeletePlaylistButton(float xResolution, float yResolution){
	
	xPos = 850.f;
	yPos = 75.0f;
	background.setPosition(xPos,yPos);
	background.setSize(sf::Vector2f(100.0f,30.0f));
	background.setFillColor(sf::Color(206, 32, 41));
	
	font.loadFromFile("assets/fonts/GothamMedium.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setString("Delete");
	text.setPosition(xPos + 15.0f, yPos+2.0f);
	text.setFillColor(sf::Color(200, 200, 200));

}

DeletePlaylistButton::~DeletePlaylistButton(){}

bool DeletePlaylistButton::contains(sf::Vector2f point){
	return background.getGlobalBounds().contains(point);
}

void DeletePlaylistButton::updateColorOnHover(sf::Vector2f mousePosition){
	if (contains(mousePosition)) {
		background.setFillColor(sf::Color(206 - 20, 32 - 20, 41 - 20));
	}
	else {
		background.setFillColor(sf::Color(206, 32, 41));
	}
}

void DeletePlaylistButton::handleEvent(sf::Event event, AppState& currentState, PlayingState& playingState, Music& music, Sidebar& sidebar,std::string currentPlaylistName){
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
		if (contains(mousePosition) && currentState == AppState::Playlist) {
			std::string playlistname = currentPlaylistName;
			music.deletePlaylist(playlistname);
			sidebar.getPlaylistArea().deletePlaylist(playlistname);
			currentState = AppState::Home;
		}
		
	}


}
	
void DeletePlaylistButton::update(AppState& currentState, PlayingState& playingState){
	if (currentState == AppState::Playlist) {
		xPos = 1000.0f;
		yPos = 100.0f;
		background.setPosition(sf::Vector2f(xPos, yPos));
		text.setPosition(xPos + 15.0f, yPos + 2.0f);
	}
	else {
		xPos = 0.0f;
		yPos = 0.0f;
		background.setPosition(sf::Vector2f(xPos, yPos));
		text.setPosition(xPos, yPos );
	}
}

void DeletePlaylistButton::draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playingState){
	if (currentState == AppState::Playlist) {
		updateColorOnHover(sf::Vector2f(sf::Mouse::getPosition(window)));
		window.draw(background);
		window.draw(text);
	}
}
