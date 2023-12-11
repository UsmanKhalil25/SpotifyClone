// VolumeButtons.h
#pragma once
#include <SFML/Graphics.hpp>
#include "../../appstate.h"
#include "../../playingstate.h"
#include "../../utility/music.h"

class VolumeButtons {
private:
    sf::Texture volumeIncreaseTexture;
    sf::Texture volumeDecreaseTexture;
    sf::Texture volumeMuteTexture;

    sf::Sprite volumeIncreaseSprite;
    sf::Sprite volumeDecreaseSprite;
    sf::Sprite volumeMuteSprite;

    float volume;
    sf::RectangleShape backgroundBar;
    sf::RectangleShape progressBar;

public:
    VolumeButtons(float resolutionX, float resolutionY);
    ~VolumeButtons();
    void setVolume(const float volume);
    float getVolume();
    void increaseVolume();
    void decreaseVolume();
    bool increaseButtonContains(sf::Vector2f point);
    bool decreaseButtonContains(sf::Vector2f point);
    bool muteButtonContains(sf::Vector2f point);
    void updateColorOnHover(sf::Vector2f mousePosition);
    void handleEvent(sf::Event event, AppState& currentState, PlayingState& playingState, Music& music);
    void update(AppState& currentState,PlayingState& playingState);
    void draw(sf::RenderWindow& window, AppState& currentState,PlayingState& playingState);

};
