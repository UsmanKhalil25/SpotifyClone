#include "music.h"
#include<iostream>


Music::Music() : allSongsIndex(0), likedSongsIndex(0),isPlaying(false) {
	allsongsnames = filereader.getFilenames();
	for (std::size_t i = 0; i < allsongsnames.size(); i++) {
		sf::Music* temp = new sf::Music;
		(*temp).openFromFile(allsongsnames[i]);
		addToAllSongs(temp);
	}
}
void Music::setIsPlaying(bool isPlaying) {
	this->isPlaying = isPlaying;
}

bool Music::getIsPlaying() {
	return isPlaying;
}

void Music::addToAllSongs(sf::Music* song) {
	allsongs.push_back(song);
}

void Music::addToplaylist(sf::Music* song, std::string name) {
	
	playlists[name].push_back(song);
}

void Music::addToplaylistNamesVector(std::size_t index, std::string name) {

	playlistsnames[name].push_back(allsongsnames[index]);
}


void Music::addToLikedSongs(sf::Music* song) {
	likedSongs.push_back(song);
}
void Music::playAllSongs() {
	if (allSongsIndex >= 0 && allSongsIndex < allsongs.size()) {
		allsongs[allSongsIndex]->play();
		setIsPlaying(true);
	}
}

void Music::playPlaylist(std::string name) {
	if (playlistsIndex[name] >= 0 && playlistsIndex[name] < playlists[name].size()) {
		playlists[name][playlistsIndex[name]]->play();
		setIsPlaying(true);
	}
}

void Music::playLikedMusic() {
	if (likedSongsIndex >= 0 && likedSongsIndex < likedSongs.size()) {
		likedSongs[likedSongsIndex]->play();
		setIsPlaying(true);
	}
}

void Music::nextAllSong() {

	stopAllSong();
	if (allSongsIndex < allsongs.size() - 1) {
		allSongsIndex++;
	}
	else {
		allSongsIndex = 0;
	}
	playAllSongs();
}

void Music::nextPlaylistSong(std::string name) {
	stopPlaylistSong(name);
	if (playlistsIndex[name] < playlists[name].size() - 1) {
		playlistsIndex[name]++;
	}
	else {
		playlistsIndex[name] = 0;
	}
	playPlaylist(name);
}

void Music::nextLikedSong() {
	stopLikedSong();
	if (likedSongsIndex < likedSongs.size() - 1) {
		likedSongsIndex++;
	}
	else {
		likedSongsIndex = 0;
	}
	playLikedMusic();
}

void Music::previousAllSong() {
	stopAllSong();
	if (allSongsIndex > 0) {
		allSongsIndex--;
	}
	else {
		// Wrap around to the last song if at the beginning
		allSongsIndex = allsongs.size() - 1;
	}
	playAllSongs();
}

void Music::previousPlaylistSong(std::string name) {
	stopPlaylistSong(name);
	if (playlistsIndex[name] < playlists[name].size() - 1) {
		playlistsIndex[name]--;
	}
	else {
		playlistsIndex[name] = playlists[name].size() - 1;
	}
	playPlaylist(name);
}

void Music::previousLikedSong() {
	stopLikedSong();
	if (likedSongsIndex < likedSongs.size() - 1) {
		likedSongsIndex--;
	}
	else {
		likedSongsIndex = likedSongs.size() - 1;
	}
	playLikedMusic();
}

void Music::pauseAllSong() {
	if (allSongsIndex >= 0 && allSongsIndex < allsongs.size()) {
		allsongs[allSongsIndex]->pause();
		setIsPlaying(false);
	}
}

void Music::pausePlaylistSong(std::string name) {
	if (playlistsIndex[name] >= 0 && playlistsIndex[name] < playlists[name].size()) {
		playlists[name][playlistsIndex[name]]->pause();
		setIsPlaying(false);

	}
}

void Music::pauseLikedSong() {
	if (likedSongsIndex >= 0 && likedSongsIndex < likedSongs.size()) {
		likedSongs[likedSongsIndex]->pause();
		setIsPlaying(false);

	}
}

void Music::stopAllSong() {
	if (allSongsIndex >= 0 && allSongsIndex < allsongs.size()) {
		allsongs[allSongsIndex]->stop();
		setIsPlaying(false);

	}
}

void Music::stopPlaylistSong(std::string name) {
	if (playlistsIndex[name] >= 0 && playlistsIndex[name] < playlists[name].size()) {
		playlists[name][playlistsIndex[name]]->stop();
		setIsPlaying(false);

	}
		

}

void Music::stopLikedSong() {
	if (likedSongsIndex >= 0 && likedSongsIndex < likedSongs.size()) {
		likedSongs[likedSongsIndex]->stop();
		setIsPlaying(false);
	}
}

void Music::setAllSongsVolume(float volume) {
	for (sf::Music* song : allsongs) {
		song->setVolume(volume);
	}
}

// Function to set the volume of liked songs
void Music::setLikedMusicVolume(float volume) {
	for (sf::Music* song : likedSongs) {
		song->setVolume(volume);
	}
}

// Function to set the volume of songs in a playlist
void Music::setPlaylistVolume(std::string name, float volume) {
	// Check if the playlist exists
	if (playlists.find(name) != playlists.end()) {
		// Iterate through the songs in the playlist and set their volume
		for (sf::Music* song : playlists[name]) {
			song->setVolume(volume);
		}
	}
}

void Music::shuffleAllSongs(){
	stopAllSong();
	srand(static_cast<unsigned int>(time(nullptr)));
	int newIndex = rand() % allsongs.size();
	while (newIndex == allSongsIndex) {
		newIndex = rand() % allsongs.size();
	}
	allSongsIndex = newIndex;
	playAllSongs();
}

void Music::shuffleLikedSongs(){
	stopLikedSong();
	srand(static_cast<unsigned int>(time(nullptr)));
	int newIndex = rand() % likedSongs.size();
	while (newIndex == likedSongsIndex) {
		newIndex = rand() % likedSongs.size();
	}
	likedSongsIndex = newIndex;
	playLikedMusic();
}

void Music::shufflePlaylistSongs(std::string name){
	stopPlaylistSong(name);
	srand(static_cast<unsigned int>(time(nullptr)));
	int newIndex = rand() % playlists[name].size();
	while (newIndex == playlistsIndex[name]) {
		newIndex = rand() % playlists[name].size();
	}
	playlistsIndex[name] = newIndex;
	playPlaylist(name);
}

sf::Music* Music::getCurrentAllSongsPointer(){
	if (!allsongs.empty() && allSongsIndex >= 0 && allSongsIndex < allsongsnames.size()) {
		return allsongs[allSongsIndex];
	}
	return nullptr;
}

sf::Music* Music::getCurrentLikedSongsPointer(){
	if (!likedSongs.empty() && likedSongsIndex >= 0 && likedSongsIndex < likedSongsNames.size()) {
		return likedSongs[likedSongsIndex];
	}
	return nullptr;
}

sf::Music* Music::getCurrentPlaylistSongsPointer()
{
	return nullptr;
}

sf::Music* Music::getAllSongsPointerSpecific(std::size_t index){
	return allsongs[index];
}

std::string Music::getCurrentAllSongs(){
	if (!allsongs.empty() && allSongsIndex >= 0 && allSongsIndex < allsongsnames.size()) {
		return allsongsnames[allSongsIndex];
	}
	return "Nothing to play";
}

std::string Music::getCurrentLikedSongs(){

	if (!likedSongs.empty() && likedSongsIndex >= 0 && likedSongsIndex < likedSongsNames .size()) {
		return likedSongsNames[likedSongsIndex];
	}
	return "Nothing to play";
}

std::string Music::getCurrentPlaylistSongs(){
	return  "";
	
}
std::vector<sf::Music*> Music::getAllSongsVector(){
	return allsongs;
}

std::vector<sf::Music*> Music::getLikedSongsVector() {
	return likedSongs;
}

std::vector<sf::Music*> Music::getPlaylistVector(std::string name) {
	return playlists[name];
}

std::vector<std::string> Music::getAllSongsNamesVector(){
	return allsongsnames;
}

std::vector<std::string> Music::getLikedSongsNamesVector(){
	return likedSongsNames;
}

std::vector<std::string> Music::getPlaylistSongsNamesVector(std::string name){
	return playlistsnames[name];
}

void Music::deletePlaylist(const std::string name) {
	auto playlistsIt = playlists.find(name);
	auto playlistNamesIt = playlistsnames.find(name);

	if (playlistsIt != playlists.end() && playlistNamesIt != playlistsnames.end()) {
		playlists[name].clear();
		playlistsnames[name].clear();

		// Remove the empty playlists
		playlists.erase(playlistsIt);
		playlistsnames.erase(playlistNamesIt);
	}
}

void Music::playAllSongsByIndex(const std::size_t index){
	stopAllSong();

	this->allSongsIndex = index;
	playAllSongs();
}

void Music::playLikedSongsByIndex(const std::size_t index){
	stopLikedSong();
	this->likedSongsIndex = index;
	playLikedMusic();
}

void Music::playPlaylistSongsByIndex(std::string name, const std::size_t index){
	stopPlaylistSong(name);
	this->playlistsIndex[name] = index;
	playPlaylist(name);
}

Music::~Music() {}





