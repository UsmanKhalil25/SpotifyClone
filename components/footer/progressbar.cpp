#include "progressbar.h"
#include <iomanip>
#include <sstream>

ProgressBar::ProgressBar(float resolutionX, float resolutionY) {
    font.loadFromFile("assets/fonts/GothamLight.ttf");
    backgroundBar.setSize(sf::Vector2f(400, 5));
    backgroundBar.setPosition((resolutionX - backgroundBar.getSize().x) / 2, resolutionY - backgroundBar.getSize().y - 30);
    backgroundBar.setFillColor(sf::Color(18, 18, 18));

    progressBar.setSize(sf::Vector2f(0, 0));
    progressBar.setPosition((resolutionX - backgroundBar.getSize().x) / 2, resolutionY - backgroundBar.getSize().y - 30);
    progressBar.setFillColor(sf::Color(29, 185, 84));

    totalTime = 0;   // total time in seconds
    timeElapsed = 0;  // elapsed time in seconds

    totalTimeText.setFont(font);
    totalTimeText.setCharacterSize(15);
    totalTimeText.setFillColor(sf::Color(200,200,200));

    timeElapsedText.setFont(font);
    timeElapsedText.setCharacterSize(15);
    timeElapsedText.setFillColor(sf::Color(200,200,200));

    

    // Update text positions based on bar position, size, and padding
    updateTextPositions();
}

void ProgressBar::draw(sf::RenderWindow& window,AppState& currentState,PlayingState & playingState,Music& music) {
    // Draw your bar and text here
    window.draw(backgroundBar);
    window.draw(progressBar);
    window.draw(totalTimeText);
    window.draw(timeElapsedText);
}

bool ProgressBar::contains(sf::Vector2f point)
{
    return false;
}

void ProgressBar::setTotalTime(const int totalTime) {
    this->totalTime = totalTime;
    updateTextPositions();
}

void ProgressBar::setElapsedTime(const int timeElapsed) {
    this->timeElapsed = timeElapsed;
    updateTextPositions();
}

void ProgressBar::updateTextPositions() {
    // Convert total time to minutes and seconds
    int totalMinutes = totalTime / 60;
    int totalSeconds = totalTime % 60;

    // Convert elapsed time to minutes and seconds
    int elapsedMinutes = timeElapsed / 60;
    int elapsedSeconds = timeElapsed % 60;

    // Format the time strings using std::ostringstream
    std::ostringstream totalTimeString;
    totalTimeString << std::setw(2) << std::setfill('0') << totalMinutes << ":" << std::setw(2) << std::setfill('0') << totalSeconds;

    std::ostringstream elapsedTimeString;
    elapsedTimeString << std::setw(2) << std::setfill('0') << elapsedMinutes << ":" << std::setw(2) << std::setfill('0') << elapsedSeconds;

    // Update text positions based on bar position, size, and padding
    totalTimeText.setString(totalTimeString.str());
    totalTimeText.setPosition(backgroundBar.getPosition().x + backgroundBar.getSize().x + 12, backgroundBar.getPosition().y - 10);

    timeElapsedText.setString(elapsedTimeString.str());
    timeElapsedText.setPosition(backgroundBar.getPosition().x - timeElapsedText.getLocalBounds().width - 12, backgroundBar.getPosition().y -10);
}


void ProgressBar::handleEvent(sf::Event event, AppState& currentState, PlayingState& playingState,Music& music){}

void ProgressBar::update(AppState& currentState, PlayingState& playingState, Music& music) {
    if (playingState == PlayingState::AllSongs || playingState == PlayingState::LikedSongs || playingState == PlayingState::PlaylistSongs) {
        sf::Music* currentSong = nullptr;

        if (playingState == PlayingState::AllSongs) {
            currentSong = music.getCurrentAllSongsPointer();
        }
        else if (playingState == PlayingState::LikedSongs) {
            currentSong = music.getCurrentLikedSongsPointer();
        }
        else if (playingState == PlayingState::PlaylistSongs) {
            // Add logic to get the current song for the playlist
        }

        if (currentSong == nullptr) {
            totalTime = 0;
            timeElapsed = 0;
        }
        else {
            sf::Time duration = currentSong->getDuration();
            totalTime = duration.asSeconds();

            // Get the elapsed time for the current song
            timeElapsed = static_cast<int>(currentSong->getPlayingOffset().asSeconds());

            // Update the progress bar size based on the song progress
            float progress = (timeElapsed / static_cast<float>(totalTime)) * backgroundBar.getSize().x;
            progressBar.setSize(sf::Vector2f(progress, backgroundBar.getSize().y));

            // Update the text positions
            updateTextPositions();
        }
    }
}

ProgressBar::~ProgressBar() {}