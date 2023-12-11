#pragma once

#include<SFML/Audio.hpp>
#include<vector>
#include<map>
#include"filereader.h"

class Music {
private:
	std::vector<sf::Music*> allsongs;
	std::vector<std::string> allsongsnames;
	int allSongsIndex;
	std::map<std::string, std::vector<sf::Music*>> playlists;
	std::map<std::string, std::vector<std::string>> playlistsnames;
	std::map<std::string, int> playlistsIndex;
	std::vector<sf::Music*> likedSongs;
	std::vector<std::string> likedSongsNames;
	int likedSongsIndex;
	Filereader filereader;
	bool isPlaying;
public:
	Music();
	~Music();

	std::vector<sf::Music*> getAllSongsVector();
	std::vector<sf::Music*> getLikedSongsVector();
	std::vector<sf::Music*> getPlaylistVector(std::string name);
	std::vector<std::string> getAllSongsNamesVector();
	std::vector < std::string> getLikedSongsNamesVector();
	std::vector < std::string> getPlaylistSongsNamesVector(std::string name);
	void deletePlaylist(const std::string name);
	void playAllSongsByIndex(const std::size_t index);
	void playLikedSongsByIndex(const std::size_t index);
	void playPlaylistSongsByIndex(std::string name,const std::size_t index);
	void setIsPlaying(bool isPlaying);
	bool getIsPlaying();
	void addToAllSongs(sf::Music* song);
	void addToplaylist(sf::Music* song,std::string name);
	void addToplaylistNamesVector(std::size_t index, std::string name);
	void addToLikedSongs(sf::Music* song);
	void playAllSongs();
	void playPlaylist(std::string name);
	void playLikedMusic();
	void nextAllSong();
	void nextPlaylistSong(std::string name);
	void nextLikedSong();
	void previousAllSong();
	void previousPlaylistSong(std::string name);
	void previousLikedSong();
	void pauseAllSong();
	void pausePlaylistSong(std::string name);
	void pauseLikedSong();
	void stopAllSong();
	void stopPlaylistSong(std::string name);
	void stopLikedSong();
	void setAllSongsVolume(float volume);
	void setLikedMusicVolume(float volume);
	void setPlaylistVolume(std::string name, float volume);
	void shuffleAllSongs();
	void shuffleLikedSongs();
	void shufflePlaylistSongs(std::string name);
	sf::Music* getCurrentAllSongsPointer();
	sf::Music* getCurrentLikedSongsPointer();
	sf::Music* getCurrentPlaylistSongsPointer();
	sf::Music* getAllSongsPointerSpecific(std::size_t index);
	std::string getCurrentAllSongs();
	std::string getCurrentLikedSongs();
	std::string getCurrentPlaylistSongs();

};