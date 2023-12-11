#pragma once
#include "homebutton.h"

HomeButton::HomeButton(float resolutionX, float resolutionY) {
    homeTexture.loadFromFile("assets/homeIcon.png");

    // Set up the button's properties
    button.setSize(sf::Vector2f(resolutionX / 4, 75.0f)); // Adjust the size as needed
    button.setPosition(1.0f, 20.0f); // Adjust the position as needed
    button.setFillColor(sf::Color(33, 33, 33));
    button.setOutlineThickness(0);
    button.setOutlineColor(sf::Color(75, 75, 75));

    // Set up the sprite for the button
    homeSprite.setTexture(homeTexture);

    // Scale the sprite (adjust the scale factor as needed)
    float scale_factor = 0.1f;
    homeSprite.setScale(scale_factor, scale_factor);

    homeSprite.setPosition(20.f,30.f);
    homeSprite.setColor(sf::Color(40, 40, 40));
  
    font.loadFromFile("assets/fonts/GothamMedium.ttf");
    homeText.setFont(font);
    homeText.setCharacterSize(25);
    homeText.setFillColor(sf::Color(200, 200, 200));
    homeText.setString("Home");

    homeText.setPosition(100.0f, 40.0f);
}


HomeButton::~HomeButton() {}

void HomeButton::handleEvent(sf::Event event,AppState& currentState){
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

        if (contains(mousePosition)) {
            currentState = AppState::Home;
        }
    }
}

void HomeButton::update(AppState& currentState){}

void HomeButton::draw(sf::RenderWindow& window,AppState& currentState) {
  
    updateColorOnHover(sf::Vector2f(sf::Mouse::getPosition(window)));
    window.draw(button);
    window.draw(homeText); 
    window.draw(homeSprite);
}

bool HomeButton::contains(sf::Vector2f point) {
    return button.getGlobalBounds().contains(point);
}

void HomeButton::updateColorOnHover(sf::Vector2f mousePosition) {
    if (contains(mousePosition)) {
        button.setFillColor(sf::Color(33-10, 33-10, 33-10));
        button.setOutlineThickness(2);
    }
    else {
        button.setFillColor(sf::Color(33, 33, 33));
        button.setOutlineThickness(0);
    }
}