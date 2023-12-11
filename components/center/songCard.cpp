#include "songCard.h"

#include <sstream> 


SongCard::SongCard(float resolutionX, float yPosition, std::string title, int duration, int index): title(title), duration(duration), index(index),isSelected(false) {

    background.setSize(sf::Vector2f(resolutionX - resolutionX / 4 - 15.0f, 75.0f));
    background.setPosition((resolutionX / 4) + 10.0f, yPosition);
    background.setFillColor(sf::Color(33, 33, 33));
    background.setOutlineThickness(0);
    background.setOutlineColor(sf::Color(75, 75, 75));

    font.loadFromFile("assets/fonts/GothamMedium.ttf");
    titleText.setFont(font);
    titleText.setCharacterSize(19);
    titleText.setFillColor(sf::Color(200, 200, 200));
    titleText.setPosition((resolutionX / 4) + 20.0f, yPosition + 17.0f);
    titleText.setString(title);

    // Convert duration to minute:second format
    int minutes = duration / 60;
    int seconds = duration % 60;

    std::stringstream durationStream;
    durationStream << minutes << ":" << std::setw(2) << std::setfill('0') << seconds; // Ensures that seconds are always displayed with two digits
    std::string durationString = durationStream.str();

    durationText.setFont(font);
    durationText.setCharacterSize(14);
    durationText.setFillColor(sf::Color(200, 200, 200));
    durationText.setPosition(1200.0f, yPosition + 25.0f);
    durationText.setString(durationString);

 
}



void SongCard::setTitle(std::string title){
	this->title = title;
}

std::string SongCard::getTitle(){
	return title;
}

void SongCard::setDuration( int duration){
	this->duration = duration;
}

int SongCard::getDuration(){
	return duration;
}
int SongCard::getIndex() {
    return index;
}

bool SongCard::getIsSelected(){
    return isSelected;
}
void SongCard::setIsSelected(bool isSelected){
    this->isSelected = isSelected;
}
void SongCard::handleEvent(sf::Event event, AppState& currentState, PlayingState& playingState, Music& music){
    if (currentState == AppState::CreatePlaylist) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

            if (contains(mousePosition)) {
                setIsSelected(!isSelected);
            }
        }
    }
}

void SongCard::update(AppState& currentState, PlayingState& playingState, Music& music){
    if (currentState == AppState::CreatePlaylist) {
        if (isSelected) {
            background.setFillColor(sf::Color(33 - 10, 33 - 10, 33 - 10));
            background.setOutlineThickness(2);
        }
        else if (!isSelected) {
            background.setFillColor(sf::Color(33, 33 , 33 ));
        }
    }
    if (currentState != AppState::CreatePlaylist)
        isSelected = false;
	titleText.setString(title);
    int minutes = duration / 60;
    int seconds = duration % 60;
    std::stringstream durationStream;
    durationStream << minutes << ":" << std::setw(2) << std::setfill('0') << seconds; // Ensures that seconds are always displayed with two digits
    std::string durationString = durationStream.str();
    durationText.setString(durationString);
}

void SongCard::draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playingState, Music& music){
    if(currentState !=AppState::CreatePlaylist)
         updateColorOnHover(sf::Vector2f(sf::Mouse::getPosition(window)));
	window.draw(background);
	window.draw(titleText);
	window.draw(durationText);

}

bool SongCard::contains(sf::Vector2f point){
	return background.getGlobalBounds().contains(point);
}


void SongCard::updateColorOnHover(sf::Vector2f mousePosition) {
    if (contains(mousePosition)) {
        background.setFillColor(sf::Color(33 - 10, 33 - 10, 33 - 10));
        background.setOutlineThickness(2);
    }
    else {
        background.setFillColor(sf::Color(33, 33, 33));
        background.setOutlineThickness(0);
    }
}


SongCard::~SongCard(){}
