#include "volumebuttons.h"

VolumeButtons::VolumeButtons(float resolutionX, float resolutionY) : volume(100.0f) {
    volumeIncreaseTexture.loadFromFile("assets/volumeIncreaseButton.png");
    volumeDecreaseTexture.loadFromFile("assets/volumeDecreaseButton.png");
    volumeMuteTexture.loadFromFile("assets/volumeMuteButton.png");

    volumeIncreaseSprite.setTexture(volumeIncreaseTexture);
    volumeDecreaseSprite.setTexture(volumeDecreaseTexture);
    volumeMuteSprite.setTexture(volumeMuteTexture);

    // Set scale for the sprites
    float scale = 0.15f;
    volumeIncreaseSprite.setScale(scale, scale);
    volumeDecreaseSprite.setScale(scale, scale);
    volumeMuteSprite.setScale(scale, scale);

    sf::Vector2u textureSize = volumeIncreaseTexture.getSize();
    float buttonYPosition = resolutionY - textureSize.y * scale - 40.0f;

    volumeIncreaseSprite.setPosition(resolutionX - textureSize.x * scale - 30.0f, buttonYPosition);
    volumeDecreaseSprite.setPosition(volumeIncreaseSprite.getPosition().x - textureSize.x * scale - 40.0f, buttonYPosition);
    volumeMuteSprite.setPosition(volumeDecreaseSprite.getPosition().x - textureSize.x * scale - 40.0f, buttonYPosition);

    // Set the initial button color
    sf::Color buttonColor(40, 40, 40);
    volumeIncreaseSprite.setColor(buttonColor);
    volumeDecreaseSprite.setColor(buttonColor);
    volumeMuteSprite.setColor(buttonColor);

    // Set up the volume bar
    float volumeBarHeight = 5.0f;
    backgroundBar.setSize(sf::Vector2f(resolutionX / 5 - 20.0f, volumeBarHeight));
    backgroundBar.setPosition(resolutionX - backgroundBar.getSize().x - 30.0f, buttonYPosition - volumeBarHeight - 10.0f);
    backgroundBar.setFillColor(sf::Color(18, 18, 18));
    \
    progressBar.setSize(sf::Vector2f(resolutionX / 5 -20.0f, volumeBarHeight));
    progressBar.setPosition(resolutionX - progressBar.getSize().x -30.0f, buttonYPosition - volumeBarHeight - 10.0f);
    progressBar.setFillColor(sf::Color(29, 185, 84));

    // Other initialization code...
}

void VolumeButtons::draw(sf::RenderWindow& window,AppState & currentState,PlayingState& playingState) {
    // Check for button hover effect
    updateColorOnHover(sf::Vector2f(sf::Mouse::getPosition(window)));

    window.draw(volumeIncreaseSprite);
    window.draw(volumeDecreaseSprite);
    window.draw(volumeMuteSprite);
    window.draw(backgroundBar);
    window.draw(progressBar);

}

void VolumeButtons::setVolume(const float targetVolume) {

    volume = targetVolume;
}

float VolumeButtons::getVolume() {
    return volume;
}

void VolumeButtons::increaseVolume(){
    float volume = getVolume();
    if(volume <=90){
        setVolume(volume + 10);
    }
}

void VolumeButtons::decreaseVolume(){
    float volume = getVolume();
    if (volume >=10) {
        setVolume(volume - 10);
    }
}


bool VolumeButtons::increaseButtonContains(sf::Vector2f point) {
    return volumeIncreaseSprite.getGlobalBounds().contains(point);
}

bool VolumeButtons::decreaseButtonContains(sf::Vector2f point) {
    return volumeDecreaseSprite.getGlobalBounds().contains(point);
}
bool VolumeButtons::muteButtonContains(sf::Vector2f point) {
    return volumeMuteSprite.getGlobalBounds().contains(point);
}
void VolumeButtons::updateColorOnHover(sf::Vector2f mousePosition){
    if (increaseButtonContains(mousePosition)) {
        volumeIncreaseSprite.setColor(sf::Color(40-30,40-30,40-30));
    }
    else {
        volumeIncreaseSprite.setColor(sf::Color(40, 40, 40));
    }
    if (decreaseButtonContains(mousePosition)) {
        volumeDecreaseSprite.setColor(sf::Color(40 - 30, 40 - 30, 40 - 30));
    }
    else {
        volumeDecreaseSprite.setColor(sf::Color(40, 40, 40));
    }
    if (muteButtonContains(mousePosition)) {
        volumeMuteSprite.setColor(sf::Color(40 - 30, 40 - 30, 40 - 30));
    }
    else {
        volumeMuteSprite.setColor(sf::Color(40, 40, 40));
    }
}


void VolumeButtons::handleEvent(sf::Event event, AppState& currentState, PlayingState& playingState, Music& music)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

        if (increaseButtonContains(mousePosition)) {
            increaseVolume();
        }
        else if (decreaseButtonContains(mousePosition)) {
            decreaseVolume();
        }
        else if (muteButtonContains(mousePosition)) {
            setVolume(0.0f);
        }

        if (playingState == PlayingState::AllSongs) {
           
            music.setAllSongsVolume(getVolume());
        }
        else if (playingState == PlayingState::LikedSongs) {
            music.setLikedMusicVolume(getVolume());
        }
        else if (playingState == PlayingState::PlaylistSongs) {

        }
    }
}

void VolumeButtons::update(AppState& currentState, PlayingState& playingState) {
    float xSize = backgroundBar.getSize().x;
    float fillSize = (xSize * getVolume()) / 100;
    progressBar.setSize(sf::Vector2f(fillSize, 5.0f));
}

VolumeButtons::~VolumeButtons() {}
