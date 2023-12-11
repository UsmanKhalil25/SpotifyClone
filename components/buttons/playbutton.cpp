#include "playbutton.h"

PlayButton::PlayButton(float resolutionX, float resolutionY) : isPlaying(false) {
    float radius = 25.0f;
    circle.setRadius(radius);


    circle.setPointCount(100);

    circle.setOrigin(radius, radius);
    circle.setFillColor(sf::Color(29, 185, 84));

    float screenWidth = resolutionX; 
    float screenHeight = resolutionY; 
    float circleYPosition = screenHeight - radius - 55.0f; 
    circle.setPosition(screenWidth / 2.0f, circleYPosition);

    playTexture.loadFromFile("assets/playButton.png");
    pauseTexture.loadFromFile("assets/pauseButton.png");
    pauseSprite.setTexture(pauseTexture);
    playingSprite.setTexture(playTexture);

    // Set the origin to the center of the sprite
    pauseSprite.setOrigin(playTexture.getSize().x / 2.0f , playTexture.getSize().y / 2.0f);
    playingSprite.setOrigin(playTexture.getSize().x / 2.0f, playTexture.getSize().y / 2.0f);


    float scaleFactor =1.5f *  radius / std::max(playTexture.getSize().x, playTexture.getSize().y);
    pauseSprite.setScale(scaleFactor, scaleFactor);
    playingSprite.setScale(scaleFactor, scaleFactor);  


    // Center the button on the circle
    float spriteXPosition = circle.getPosition().x;
    float spriteYPosition = circle.getPosition().y;
    pauseSprite.setPosition(spriteXPosition , spriteYPosition);
    playingSprite.setPosition(spriteXPosition + 2.0f, spriteYPosition);

    playingSprite.setColor(sf::Color(40,40,40));
    pauseSprite.setColor(sf::Color(40,40,40));
    updateColorOnHover(sf::Vector2f(0.f, 0.f));
}


PlayButton::~PlayButton(){}

void PlayButton::setIsPlaying(bool isPlaying){
	this->isPlaying = isPlaying;
}

bool PlayButton::getIsPlaying()
{
	return isPlaying;
}

void PlayButton::handleEvent(sf::Event event, AppState& currentState,PlayingState& playingState,Music& music){
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        if (contains(mousePosition)) {
            if (playingState == PlayingState::AllSongs) {
                isPlaying =!isPlaying;
                if (isPlaying) {
                    music.playAllSongs();
                }
                else {
                    music.pauseAllSong();
                }
            }
        }
    }
}

void PlayButton::update(AppState& currentState,PlayingState&  playingState,Music& music){
    isPlaying = music.getIsPlaying();

}

void PlayButton::updateColorOnHover(sf::Vector2f mousePosition) {
    if (contains(mousePosition)) {
        circle.setFillColor(sf::Color(29-20, 185-20, 84-20)); 
    }
    else {
        circle.setFillColor(sf::Color(29, 185, 84));
    }
}


void PlayButton::draw(sf::RenderWindow& window,AppState& currentState,PlayingState& playingState,Music& music) {
    updateColorOnHover(sf::Vector2f(sf::Mouse::getPosition(window))); // Update color based on mouse position
    window.draw(circle);
    isPlaying ? window.draw(pauseSprite) : window.draw(playingSprite);
}

bool PlayButton::contains(sf::Vector2f point){
	return circle.getGlobalBounds().contains(point);
}

