#include "filereader.h"

Filereader::Filereader(){
    std::string path = "C:/Users/Muhammad Usman/Visual Studio 2017 Projects/SpotifyClone/SpotifyClone/songs"; // replace with your directory path
    for (const auto& entry : fs::directory_iterator(path)) {
        filenames.push_back(entry.path().string());
    }
}

std::vector<std::string> Filereader::getFilenames(){
	return filenames;
}

Filereader::~Filereader(){}
