#include "songshifter.h"

SongShifter::SongShifter(float resolutionX, float resolutionY){

    float radius = 25.0f; // the radius of the circle of play button

    // only using the circle for reference (to be precise)
    sf::CircleShape circle;
    circle.setRadius(radius);
    circle.setPointCount(100);
    circle.setOrigin(radius, radius);
    circle.setFillColor(sf::Color(29, 185, 84));

    float screenWidth = resolutionX;
    float screenHeight = resolutionY;
    float circleYPosition = screenHeight - radius - 55.0f;
    circle.setPosition(screenWidth / 2.0f, circleYPosition);


    nextButtonTexture.loadFromFile("assets/nextButton.png");
    previousButtonTexture.loadFromFile("assets/previousButton.png");
    shuffleButtonTexture.loadFromFile("assets/shuffleButton.png");
    nextButtonSprite.setTexture(nextButtonTexture);
    previousButtonSprite.setTexture(previousButtonTexture);
    shuffleButtonSprite.setTexture(shuffleButtonTexture);

   
    nextButtonSprite.setOrigin(nextButtonTexture.getSize().x / 2.0f, nextButtonTexture.getSize().y / 2.0f);
    previousButtonSprite.setOrigin(previousButtonTexture.getSize().x / 2.0f, previousButtonTexture.getSize().y / 2.0f);
    shuffleButtonSprite.setOrigin(previousButtonTexture.getSize().x / 2.0f, previousButtonTexture.getSize().y / 2.0f);


    float scaleFactor = 1.5f * radius / std::max(nextButtonTexture.getSize().x, nextButtonTexture.getSize().y);
    nextButtonSprite.setScale(scaleFactor, scaleFactor);
    previousButtonSprite.setScale(scaleFactor, scaleFactor);
    shuffleButtonSprite.setScale(scaleFactor* 1.5f, scaleFactor * 1.5f);


    // Center the button on the circle
    float spriteXPosition = circle.getPosition().x;
    float spriteYPosition = circle.getPosition().y;
    float distanceFromCenter = 100.0f;

    sf::Color buttonColor(40, 40, 40);
    nextButtonSprite.setColor(buttonColor);
    previousButtonSprite.setColor(buttonColor);
    nextButtonSprite.setPosition(spriteXPosition + distanceFromCenter, spriteYPosition);
    previousButtonSprite.setPosition(spriteXPosition - distanceFromCenter, spriteYPosition);
    
    shuffleButtonSprite.setPosition(spriteXPosition + 2* distanceFromCenter, spriteYPosition + 15.0f);

    

}


void SongShifter::draw(sf::RenderWindow& window,AppState & currentState,PlayingState& playingState){
    window.draw(nextButtonSprite);
    window.draw(previousButtonSprite);
    window.draw(shuffleButtonSprite);
}

SongShifter::~SongShifter(){}

void SongShifter::handleEvent(sf::Event event, AppState& currentState,PlayingState& playingState,Music& music){

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

        if (containsNext(mousePosition)) {
            if(playingState == PlayingState::AllSongs){
                music.nextAllSong();
            }
        }
        else if (containsPrevious(mousePosition)) {
            if (playingState == PlayingState::AllSongs) {
                music.previousAllSong();
            }
        }
        else if (containsShuffle(mousePosition)) {
            if (playingState == PlayingState::AllSongs) {
                music.shuffleAllSongs();
            }
        }
        
    }
}

void SongShifter::update(AppState& currentState,PlayingState& playingState){

}

bool SongShifter::containsNext(sf::Vector2f point){
    return nextButtonSprite.getGlobalBounds().contains(point);
}

bool SongShifter::containsPrevious(sf::Vector2f point) {
    return previousButtonSprite.getGlobalBounds().contains(point);
}
bool SongShifter::containsShuffle(sf::Vector2f point) {
    return shuffleButtonSprite.getGlobalBounds().contains(point);
}
