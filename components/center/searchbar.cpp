#include "searchbar.h"

SearchBar::SearchBar(float resolutionX, float resolutionY):size(sf::Vector2f(resolutionX/3,40.0f)),showBlinker(true),doSearch(false){
    inputField.setSize(size);
    inputField.setOutlineColor(sf::Color(100,100,100));
    inputField.setOutlineThickness(2.0f);
    inputField.setPosition(sf::Vector2f((resolutionX / 4) + 25.0f, 120.0f));
    inputField.setFillColor(sf::Color(33, 33, 33));
    font.loadFromFile("assets/fonts/GothamLight.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color(200,200,200));
    text.setPosition((resolutionX / 4) + 25.0f + 10.0f, 120.0f + 5.0f);
}

void SearchBar::handleEvent(sf::Event event){
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Return) {
            setDoSearch(true);
        }
    }
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128 && event.text.unicode != 8) {  
            if (event.text.unicode != '\r') {
                if (inputText.length() < 25) {
                    inputText += static_cast<char>(event.text.unicode);
                    originalText = inputText;
                }
            }
            
           
        }
        else if (event.text.unicode == 8 && !inputText.empty()) { 
            inputText.pop_back();
            originalText = inputText;
        }
    }
}

void SearchBar::update(){
    if (blinkClock.getElapsedTime().asSeconds() > 0.5f) {
        showBlinker = !showBlinker;
        blinkClock.restart();
    }

    const std::size_t maxLength = 25; // Assuming character size 24
    if (inputText.length() > maxLength) {
        return;
    }

    text.setString(inputText + (showBlinker ? "|" : ""));
}

void SearchBar::draw(sf::RenderWindow& window) {
    window.draw(inputField);
    window.draw(text);
}

std::string SearchBar::getEnteredText(){
    return originalText;
}

void SearchBar::setDoSearch(bool doSearch){
    this->doSearch = doSearch;
}

bool SearchBar::getDoSearch() {
    return doSearch;
}