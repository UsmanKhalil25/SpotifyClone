#pragma once

#include <SFML/Graphics.hpp>
#include "../../appstate.h"
#include "../../playingstate.h"
#include "../../utility/music.h"

class InputBar {
private:
    sf::RectangleShape inputField;
    sf::Vector2f size;
    sf::Text text;
    sf::Font font;
    std::string inputText;
    std::string originalText;
    sf::Clock blinkClock;
    bool showBlinker;
    bool enterPressed;
public:
    InputBar(float resolutionX, float resolutionY);
    void handleEvent(sf::Event event,AppState& currentState,PlayingState& playingState,Music & music);
    void update(AppState& currentState, PlayingState& playingState, Music& music);
    void draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playingState, Music& music);
    std::string getEnteredText();
    void clearText();
    bool getEnterPressed();
    void setEnterPressed(bool enterPressed);
};
