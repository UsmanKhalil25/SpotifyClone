#pragma once
#include "searchbutton.h"

SearchButton::SearchButton(float resolutionX, float resolutionY) {
    searchTexture.loadFromFile("assets/searchIcon.png");

    button.setSize(sf::Vector2f(resolutionX / 4, 75.0f)); // Adjust the size as needed
    button.setPosition(1.0f, 97.0f); // Adjust the position as needed
    button.setFillColor(sf::Color(33, 33, 33));
    button.setOutlineThickness(0);
    button.setOutlineColor(sf::Color(75, 75, 75));

    // Set up the sprite for the button
    searchSprite.setTexture(searchTexture);

    // Scale the sprite (adjust the scale factor as needed)
    float scale_factor = 0.1f;
    searchSprite.setScale(scale_factor, scale_factor);

    searchSprite.setPosition(15.f,110.f);
    searchSprite.setColor(sf::Color(40, 40, 40));


    // Set up the text (optional)
    font.loadFromFile("assets/fonts/GothamMedium.ttf");
    searchText.setFont(font);
    searchText.setCharacterSize(25);
    searchText.setFillColor(sf::Color(200, 200, 200));
    searchText.setString("Search");

    searchText.setPosition(100.0f, 115.0f);
}


SearchButton::~SearchButton() {}

void SearchButton::handleEvent(sf::Event event,AppState& currentState) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

        if (contains(mousePosition)) {
            currentState = AppState::Search;
        }
    }
}

void SearchButton::update(AppState& currentState){

}

void SearchButton::draw(sf::RenderWindow& window,AppState& currentState) {
    updateColorOnHover(sf::Vector2f(sf::Mouse::getPosition(window)));
    window.draw(button);
    window.draw(searchText);
    window.draw(searchSprite);
}

bool SearchButton::contains(sf::Vector2f point) {
    return button.getGlobalBounds().contains(point);
}

void SearchButton::updateColorOnHover(sf::Vector2f mousePosition) {
    if (contains(mousePosition)) {
        button.setFillColor(sf::Color(33 - 10, 33 -10, 33 - 10));
        button.setOutlineThickness(2);
    }
    else {
        button.setFillColor(sf::Color(33, 33, 33));
        button.setOutlineThickness(0);
    }
}
