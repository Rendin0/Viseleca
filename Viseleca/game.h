#pragma once
#include "crypt.h"
#include <string>
#include <conio.h>
#include <ctime>

class Game
{
	size_t score;
	std::string word;
	std::vector<std::string> all_words;
	std::string key;
	std::vector<std::string> stages;
public:
	Game();

	Game& play();
	size_t getScore();
	Game& importFile(std::string path, std::string key);
};

size_t menu(std::vector<std::string> strs);
std::string toLowerCase(std::string str);