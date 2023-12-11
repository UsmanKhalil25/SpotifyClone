#include "addplaylistbutton.h"

AddPlaylistButton::AddPlaylistButton(float resolutionX, float resolutionY){

	buttonTexture.loadFromFile("assets/addplaylistbutton.png");
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setScale(0.09f, 0.09f);
	buttonSprite.setPosition(250.0f, 175.0f);
}


void AddPlaylistButton::draw(sf::RenderWindow& window,AppState& currentState){
	window.draw(buttonSprite);
}


AddPlaylistButton::~AddPlaylistButton(){}

void AddPlaylistButton::handleEvent(sf::Event event, AppState& currentState){
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

		if (contains(mousePosition)) {
			currentState = AppState::CreatePlaylist;
		}
	}

}

bool AddPlaylistButton::contains(sf::Vector2f point) {
	return buttonSprite.getGlobalBounds().contains(point);
}


void AddPlaylistButton::update(AppState& currentState){}
