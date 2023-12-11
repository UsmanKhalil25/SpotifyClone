#include "pageshifter.h"
#include<iostream>

PageShifter::PageShifter(float xPos, float yPos, sf::Color color) {
	this->color = color;
	font.loadFromFile("assets/fonts/GothamBold.ttf");
	next.setFont(font);
	next.setString(">");
	next.setCharacterSize(24);
	next.setFillColor(color);
	next.setPosition(xPos +30.0f, yPos);

	previous.setFont(font);
	previous.setString("<");
	previous.setCharacterSize(24);
	previous.setFillColor(color);
	previous.setPosition(xPos, yPos);
	
}

void PageShifter::handleEvent(sf::Event event, AppState& currentState, PlayingState& playingState, Music& music){
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
	}
}

void PageShifter::update(AppState& currentState, PlayingState& playingState, Music& music){}

void PageShifter::draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playingState, Music& music){
	window.draw(next);
	window.draw(previous);
}

bool PageShifter::containsNext(sf::Vector2f point){
	return next.getGlobalBounds().contains(point);
}
bool PageShifter::containsPrevious(sf::Vector2f point) {
	return previous.getGlobalBounds().contains(point);
}

PageShifter::~PageShifter() {}