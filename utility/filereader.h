#pragma once

#include<vector>
#include<string>
#include<filesystem>

namespace fs = std::filesystem;

class Filereader {
private:
	std::vector<std::string> filenames;
public:
	Filereader();
	~Filereader();
	std::vector<std::string> getFilenames();
};