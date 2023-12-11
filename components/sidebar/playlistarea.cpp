#include"playlistarea.h"
#include<iostream>



PlaylistArea::PlaylistArea(float resolutionX, float resolutionY):startingPlaylistIndex(0),positioner(0), xSize(resolutionX / 4), ySize(resolutionY - (resolutionY / 3) - 75.0f), pageshifter(250.0f, 175.0f,sf::Color(200,200,200)) {
    this->resolutionX = resolutionX;
    background.setPosition(0.0f, 175.0f);
    background.setSize(sf::Vector2f(xSize,ySize));
    background.setFillColor(sf::Color::Transparent);

    font.loadFromFile("assets/fonts/GothamMedium.ttf");
    playlistText.setFont(font);
    playlistText.setCharacterSize(25);
    playlistText.setFillColor(sf::Color(200, 200, 200));
    playlistText.setString("Playlists");

    playlistText.setPosition(30.0f, 175.0f);
    addNewPlaylist("Liked songs");



}

std::string PlaylistArea::getPlaylistName(){
    for (std::size_t i = startingPlaylistIndex; i < playlists.size() && i < startingPlaylistIndex + 5; i++) {
        if (playlists[i]->getIsSelected()) {
            return playlists[i]->getName();
        }
    }
    return "";
    
}

void PlaylistArea::draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playlistState, Music& music) {
    window.draw(background);
    window.draw(playlistText);
    for (std::size_t i = startingPlaylistIndex; i < playlists.size() && i < startingPlaylistIndex + 5; i++) {
        playlists[i]->draw(window,currentState,playlistState,music);
    }
    pageshifter.draw(window, currentState, playlistState, music);
}


void PlaylistArea::addNewPlaylist(std::string playlistname) {
    auto temp = std::make_unique<PlaylistItem>(resolutionX, (positioner * 75.0f) + (positioner * 2.0f) + 210.0f, playlistname);
    playlists.push_back(std::move(temp));
    positioner++;
    if (positioner >= 5)
        positioner = 0;
}

void PlaylistArea::deletePlaylist(std::string playlistname) {
    for (auto it = playlists.begin(); it != playlists.end(); ++it) {
        if ((*it)->getName() == playlistname) {
            it = playlists.erase(it);
            // Adjust positioner and startingPlaylistIndex
            positioner--;
            if (positioner < 0)
                positioner = 4;
            if (startingPlaylistIndex >= playlists.size() && startingPlaylistIndex > 0)
                startingPlaylistIndex -= 5;
            return;
        }
    }
}
bool PlaylistArea::contains(sf::Vector2f point){
    return background.getGlobalBounds().contains(point);
}


void PlaylistArea::handleEvent(sf::Event event, AppState& currentState, PlayingState& playlistState, Music& music,std::string&centerName) {

    for (std::size_t i = startingPlaylistIndex; i < playlists.size() && i < startingPlaylistIndex + 5; i++) {
        playlists[i]->handleEvent(event, currentState, playlistState, music);
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        if (pageshifter.containsNext(mousePosition)) {
            if(startingPlaylistIndex +5 < playlists.size())
                startingPlaylistIndex += 5;

        }
        else if (pageshifter.containsPrevious(mousePosition)) {
            if(startingPlaylistIndex > 0)
                startingPlaylistIndex -= 5;

        }
       
        for (std::size_t i = startingPlaylistIndex; i < playlists.size() && i < startingPlaylistIndex + 5; i++) {
            if (playlists[i]->contains(mousePosition)) {
                centerName = playlists[i]->getName();
                currentState = AppState::Playlist;
            }
        }


        
    }
    
    
}


void PlaylistArea::update(AppState& currentState, PlayingState& playlistState, Music& music){
    pageshifter.update(currentState,playlistState,music);
}

PlaylistArea::~PlaylistArea() {}

void PlaylistArea::setSelectedIndex(int index){
    this->selectedIndex = index;
}

int PlaylistArea::getSelectedIndex(){
    return selectedIndex;
   
}