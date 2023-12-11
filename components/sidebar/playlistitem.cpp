#pragma once
#include "playlistitem.h"
#include<iostream>

PlaylistItem::PlaylistItem(float resolutionX, float yPosition, std::string name):isSelected(false) {
    button.setSize(sf::Vector2f(resolutionX / 4, 75.0f)); // Adjust the size as needed
    button.setPosition(1.0f, yPosition); // Adjust the position as needed
    button.setFillColor(sf::Color(33, 33, 33));
    button.setOutlineThickness(0);
    button.setOutlineColor(sf::Color(75, 75, 75));



    font.loadFromFile("assets/fonts/GothamMedium.ttf");
    nameText.setFont(font);
    nameText.setCharacterSize(25);
    nameText.setFillColor(sf::Color(200, 200, 200));
    this->name = name;
    nameText.setString(name);

    nameText.setPosition(30.0f, yPosition+17.0f);
}


PlaylistItem::~PlaylistItem() {}

void PlaylistItem::setName(std::string name){
    this->name = name;
}

std::string PlaylistItem::getName(){
    return name;
}

void PlaylistItem::handleEvent(sf::Event event, AppState& currentState, PlayingState& playingState, Music& music){

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        if (contains(mousePosition)) {
            setIsSelected(true);
        }
    
    }
}

void PlaylistItem::update(AppState& currentState, PlayingState& playingState, Music& music){}

void PlaylistItem::draw(sf::RenderWindow& window,AppState& currentState,PlayingState& playingState,Music&music) {
    updateColorOnHover(sf::Vector2f(sf::Mouse::getPosition(window)));
    window.draw(button);
    window.draw(nameText);
}

bool PlaylistItem::contains(sf::Vector2f point) {
    return button.getGlobalBounds().contains(point);
}

void PlaylistItem::updateColorOnHover(sf::Vector2f mousePosition) {
    if (contains(mousePosition)) {
        button.setFillColor(sf::Color(33 - 10, 33 - 10, 33 - 10));
        button.setOutlineThickness(2);
    }
    else {
        button.setFillColor(sf::Color(33, 33, 33));
        button.setOutlineThickness(0);
    }
}

sf::Vector2f PlaylistItem::getPosition() const{
    return button.getPosition();
}

sf::Vector2f PlaylistItem::getSize() const{
    return button.getSize();
}

bool PlaylistItem::getIsSelected()
{
    return isSelected;
}

void PlaylistItem::setIsSelected(bool isSelected){
    this->isSelected = isSelected;
}
