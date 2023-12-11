// Center.cpp
#include "Center.h"
#include<iostream>

// Custom case-insensitive finder
bool customFind(const std::string& str, const std::string& substr) {
    // Transform the main string and substring to lowercase
    std::string strLower = str;
    std::transform(strLower.begin(), strLower.end(), strLower.begin(), ::tolower);

    std::string substrLower = substr;
    std::transform(substrLower.begin(), substrLower.end(), substrLower.begin(), ::tolower);


    // Iterate over the main string
    for (std::size_t i = 0; i <= strLower.length() - substrLower.length(); i++) {
        // Check if substr is found starting at position i
        bool found = true;
        for (std::size_t j = 0; j < substrLower.length(); j++) {
            if (strLower[i + j] != substrLower[j]) {
                found = false;
                break;  // No need to continue checking if a mismatch is found
            }
        }
        // If found, return true
        if (found) {
            return true;
        }
    }

    // If no match is found, return false
    return false;
}

Center::Center(float resolutionX, float resolutionY):positioner(0),filteredPositioner(0), startingPlaylistIndex(0), searchbar(resolutionX, resolutionY), inputbar(resolutionX, resolutionY), pageshifter(1150.0f, 75.0f, sf::Color(18, 18, 18)),deleteplaylistbutton(resolutionX,resolutionY), currentState(AppState::None), newPlaylistName(""), currentPlaylistName("") {

    background.setFillColor(sf::Color(111, 111,111));
    background.setPosition((resolutionX / 4) +5.0f, 20.0f);
    background.setSize(sf::Vector2f((resolutionX - resolutionX / 4), resolutionY - (20.0f + 125.0f)));

    font.loadFromFile("assets/fonts/GothamMedium.ttf");
    homeText.setFont(font);
    homeText.setCharacterSize(35);
    homeText.setFillColor(sf::Color(18, 18,18));
    homeText.setString("Home");

    searchText.setFont(font);
    searchText.setCharacterSize(35);
    searchText.setFillColor(sf::Color(18, 18, 18));
    searchText.setString("Search");

    createNewPlaylistText.setFont(font);
    createNewPlaylistText.setCharacterSize(35);
    createNewPlaylistText.setFillColor(sf::Color(18, 18, 18));
    createNewPlaylistText.setString("Create new playlist");

    playlistNameText.setFont(font);
    playlistNameText.setCharacterSize(35);
    playlistNameText.setFillColor(sf::Color(18, 18, 18));
    playlistNameText.setString("Search");
   
    totalSongsText.setFont(font);
    totalSongsText.setCharacterSize(20);
    totalSongsText.setFillColor(sf::Color(18, 18, 18));
    
    homeText.setPosition(sf::Vector2f((resolutionX / 4) + 25.0f, 60.0f));
    searchText.setPosition(sf::Vector2f((resolutionX / 4) + 25.0f, 60.0f));
    createNewPlaylistText.setPosition(sf::Vector2f((resolutionX / 4) + 25.0f, 60.0f));
    playlistNameText.setPosition(sf::Vector2f((resolutionX / 4) + 25.0f, 60.0f));

    totalSongsText.setPosition(sf::Vector2f((resolutionX / 4) + 25.0f, 120.0f));

}


Center::~Center() {}

void Center::handleEvent(sf::Event event,AppState & currentState,PlayingState& playingState,Music & music,std::string& centerName,Sidebar&sidebar){

    
    int index = { 0 };
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Return) {
            if (currentState == AppState::CreatePlaylist) {
                newPlaylistName = inputbar.getEnteredText();
            }
        }
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        if (pageshifter.containsNext(mousePosition)) {
            if (currentState == AppState::Home || currentState == AppState::CreatePlaylist) {
                if (startingPlaylistIndex + 5 < songcards.size())
                    startingPlaylistIndex += 5;
            }
            else if (currentState == AppState::Search) {
                if (startingPlaylistIndex + 5 < filteredCards.size())
                    startingPlaylistIndex += 5;
            }
          
        }
        else if (pageshifter.containsPrevious(mousePosition)) {
            if (startingPlaylistIndex > 0)
                startingPlaylistIndex -= 5;

        }
        if (currentState == AppState::Home) {
            for (std::size_t i = startingPlaylistIndex; i < songcards.size() && i < startingPlaylistIndex + 5; i++) {
                if (songcards[i]->contains(mousePosition)) {
                    index = songcards[i]->getIndex();
                    music.playAllSongsByIndex(index);
                }
            }
        }
        else if (currentState == AppState::Search) {
            for (std::size_t i = startingPlaylistIndex; i < filteredCards.size() && i < startingPlaylistIndex + 5; i++) {
                if (filteredCards[i]->contains(mousePosition)) {
                    index = filteredCards[i]->getIndex();
                    music.playAllSongsByIndex(index);
                }
            }
        }
        else if (currentState == AppState::Playlist) {
            for (std::size_t i = startingPlaylistIndex; i < songcards.size() && i < startingPlaylistIndex + 5; i++) {
                if (songcards[i]->contains(mousePosition)) {
                    index = songcards[i]->getIndex();
                    music.playAllSongsByIndex(index);
                }
            }
        }
       
    }
    if (currentState == AppState::Home) {
        
    }
    else if(currentState == AppState::Search){
        searchbar.handleEvent(event);
        
    }
    else if (currentState == AppState::CreatePlaylist) {
        inputbar.handleEvent(event,currentState,playingState,music);
        for (std::size_t i = 0; i < songcards.size(); i++) {
            songcards[i]->handleEvent(event, currentState, playingState, music);
        }
    }
    else if (currentState == AppState::Playlist) {
        currentPlaylistName = centerName;
        playlistNameText.setString(centerName);
        deleteplaylistbutton.handleEvent(event, currentState, playingState, music, sidebar, currentPlaylistName);
    }

}


void Center::update(AppState& currentState, PlayingState& playingState, Music& music,Sidebar&sidebar) {
    pageshifter.update(currentState, playingState, music);
    deleteplaylistbutton.update(currentState, playingState);
    if (currentState == AppState::Search) {
        searchbar.update();
        
        if (searchbar.getDoSearch()) {
            filteredPositioner = 0;
            std::string enteredString = searchbar.getEnteredText();
            std::cout << enteredString.length() << std::endl;
            if (enteredString.length() ==0){
                filteredCards.clear();
                searchbar.setDoSearch(false);
                return;
            }
            std::transform(enteredString.begin(), enteredString.end(), enteredString.begin(), ::tolower);

            for (std::size_t i = 0; i < songcards.size(); i++) {
                std::string songTitle = songcards[i]->getTitle();
                bool found = customFind(songTitle, enteredString);
                
                if (found) {
                    std::string title = songcards[i]->getTitle();
                    int duration = songcards[i]->getDuration();
                    addNewSongFilteredSongs(title, duration, i);
                }
            }
            searchbar.setDoSearch(false);
        }
    }
    else if (this->currentState != currentState || currentState == AppState::Playlist) {
        positioner = 0;
        songcards.clear();
        filteredCards.clear();
        this->currentState = currentState;
        std::vector<sf::Music*> songs;
        std::vector<std::string> titles;
        bool isLiked = false;

        try {
            if (currentState == AppState::Home || currentState == AppState::CreatePlaylist) {
                songs = music.getAllSongsVector();
                titles = music.getAllSongsNamesVector();
                
            }
            else if (currentState == AppState::LikedMusic) {
                songs = music.getLikedSongsVector();
                titles = music.getLikedSongsNamesVector();
                isLiked = true;
            }
            else if (currentState == AppState::Playlist) {
                std::string playlistName = currentPlaylistName;
                songs = music.getPlaylistVector(playlistName);
                titles = music.getPlaylistSongsNamesVector(playlistName);


            }
            totalSongsText.setString("Total Songs: " + std::to_string(songs.size()));

            for (std::size_t i = 0; i < songs.size(); i++) {
                if (songs[i] != nullptr) {
                    sf::Time duration = songs[i]->getDuration();

                    std::string title;
                    std::string currentSongPath = titles[i];
                    fs::path songPath(currentSongPath);
                    std::string updatedSongName = songPath.filename().string();

                    if (updatedSongName.length() > 30) {
                        updatedSongName = updatedSongName.substr(0, 29) + "...";
                    }

                    title = updatedSongName;
                    addNewSong(title, duration.asSeconds(), i);
                }
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
            // Handle the exception as needed
        }
    }
    if (currentState == AppState::CreatePlaylist) {
        inputbar.update(currentState,playingState,music);
        for (std::size_t i = 0; i < songcards.size(); i++)
            songcards[i]->update(currentState, playingState, music);
        
        if (newPlaylistName != "") {
            sidebar.getPlaylistArea().addNewPlaylist(newPlaylistName);
            std::cout << "While creating the newplaylist: " << newPlaylistName << std::endl;
            for (std::size_t i = startingPlaylistIndex; i < songcards.size() && i < startingPlaylistIndex + 5; i++) {
                if (songcards[i]->getIsSelected()) {
                    sf::Music* temp = music.getAllSongsPointerSpecific(i);
                    music.addToplaylist(temp, newPlaylistName);
                    music.addToplaylistNamesVector(i, newPlaylistName);
                    songcards[i]->setIsSelected(false);
                    temp = NULL;
                }
            }

            newPlaylistName = "";
            currentState = AppState::Home;
        }
    }
    
}
void Center::addNewSongFilteredSongs(std::string title, int duration, int index) {
    auto temp = std::make_unique<SongCard>(1280.0f, (filteredPositioner * 75.0f) + (filteredPositioner * 2.0f) + 180.0f, title, duration, index);
    filteredCards.push_back(std::move(temp));
    filteredPositioner++;
    if (filteredPositioner == 5)
        filteredPositioner = 0;
}

void Center::addNewSong(std::string title,int duration,int index) {
    auto temp = std::make_unique<SongCard>(1280.0f, (positioner * 75.0f) + (positioner * 2.0f) + 180.0f, title, duration, index);
    songcards.push_back(std::move(temp));
    positioner++;
    if (positioner == 5)
        positioner = 0;
}


void Center::draw(sf::RenderWindow& window, AppState& currentState, PlayingState& playingState, Music& music, Sidebar& sidebar) {
    // Draw the background rectangle
    window.draw(background);
    pageshifter.draw(window, currentState, playingState, music);
    deleteplaylistbutton.draw(window, currentState, playingState);

    window.draw(totalSongsText);
    if (currentState == AppState::Home) {
        window.draw(homeText);
        for (std::size_t i = startingPlaylistIndex; i < songcards.size() && i < startingPlaylistIndex + 5; i++) {
            songcards[i]->draw(window, currentState, playingState, music);
        }
    }
    else if (currentState == AppState::Search) {
        window.draw(searchText);
        searchbar.draw(window);
        for (std::size_t i = startingPlaylistIndex; i < filteredCards.size() && i < startingPlaylistIndex + 5; i++) {
            filteredCards[i]->draw(window, currentState, playingState, music);
        }
    }
    else if (currentState == AppState::CreatePlaylist) {
        window.draw(createNewPlaylistText);
        inputbar.draw(window,currentState,playingState,music);
        for (std::size_t i = startingPlaylistIndex; i < songcards.size() && i < startingPlaylistIndex + 5; i++) {
            songcards[i]->draw(window, currentState, playingState, music);
        }
    }
    else if (currentState == AppState::Playlist) {
        window.draw(playlistNameText);
        for (std::size_t i = startingPlaylistIndex; i < songcards.size() && i < startingPlaylistIndex + 5; i++) {
            songcards[i]->draw(window, currentState, playingState, music);
        }

    }
    else if (currentState == AppState::LikedMusic) {
        window.draw(playlistNameText);
    }


}


