#include "dropdown.h"

DropDown::DropDown(float xPos, float yPos, std::string title, std::vector<std::string> options):title(title),xPos(xPos),yPos(yPos),numberOfOptions(options.size()),display(false),optionsNames(options) {


	background.setPosition(xPos, yPos);
	background.setFillColor(sf::Color(111,111, 111));
	background.setSize(sf::Vector2f(180.0f, 20.0f));
	
	font.loadFromFile("assets/fonts/GothamMedium.ttf");
	titleText.setFont(font);
	titleText.setCharacterSize(16);
	titleText.setString(title);
	titleText.setPosition(sf::Vector2f(xPos + 20.0f, yPos));
	titleText.setFillColor(sf::Color(12, 12, 12));


	for (std::size_t i = 0; i < numberOfOptions; i++) {
		sf::RectangleShape tempShape;
		tempShape.setPosition(xPos, yPos + (i + 1) * 20.0f);
		tempShape.setFillColor(sf::Color(100, 100, 100));
		tempShape.setSize(sf::Vector2f(180.f, 20.0f));
		optionsRectangle.push_back(tempShape);
		sf::Text tempText;
		tempText.setFont(font);
		tempText.setCharacterSize(16);
		tempText.setString(optionsNames[i]);
		tempText.setPosition(sf::Vector2f(xPos + 20.0f, yPos + (i + 1) * 20.0f));
		tempText.setFillColor(sf::Color(12, 12, 12));
		optionsText.push_back(tempText);
	}
}



void DropDown::handleEvent(sf::Event event, AppState& currentState, PlayingState& playingState, Music& music) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

		if (containsTitle(mousePosition)) {
			setIsDisplaying(!display);
		}
		if (display) {
			for (std::size_t i = 0; i < numberOfOptions; i++) {
				if (containsOption(mousePosition, i)) {
					if (title == "File") {
						if (optionsNames[i] == "Create new playlist") {
							currentState = AppState::CreatePlaylist;
							setIsDisplaying(false);
						}
						else if (optionsNames[i] == "Exit") {
							currentState = AppState::Exit;
							setIsDisplaying(false);

						}
					}
					else if (title == "Playback") {
						if (optionsNames[i] == "Play next song") {
							music.nextAllSong();
							setIsDisplaying(false);

						}
						else if (optionsNames[i] == "Play previous song") {
							music.previousAllSong();
							setIsDisplaying(false);

						}
						else if (optionsNames[i] == "Shuffle") {
							music.shuffleAllSongs();
							setIsDisplaying(false);

						}
					}
				}
				else {
					
				}
			}


		}
	}
}

void DropDown::update(AppState& currentState, PlayingState& playingState,Music & music){
	
}

void DropDown::draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playingState){
	updateColorOnHover(sf::Vector2f(sf::Mouse::getPosition(window)));
	window.draw(background);
	window.draw(titleText);
	if (display) {
		for (std::size_t i = 0; i < numberOfOptions; i++) {
			window.draw(optionsRectangle[i]);
			window.draw(optionsText[i]);
		}

	}
}

bool DropDown::containsTitle(sf::Vector2f point) {
    return background.getGlobalBounds().contains(point);
}
bool DropDown::containsOption(sf::Vector2f point, std::size_t optionIndex) {
	return optionsRectangle[optionIndex].getGlobalBounds().contains(point);
}

void DropDown::updateColorOnHover(sf::Vector2f mousePosition) {
	if (containsTitle(mousePosition)) {
		background.setFillColor(sf::Color(100 - 20, 100 - 20, 100 - 20));
	}
	else {
		background.setFillColor(sf::Color(100, 100, 100));
	}

	for (std::size_t i = 0; i < numberOfOptions; i++) {
		if (containsOption(mousePosition, i)) {
			optionsRectangle[i].setFillColor(sf::Color(80, 80, 80));
		}
		else {
			optionsRectangle[i].setFillColor(sf::Color(100, 100, 100));
		}
	}
}

bool DropDown::getIsDisplaying(){
	return display;
}

void DropDown::setIsDisplaying(bool display){

	this->display = display;
}


DropDown::~DropDown() {}