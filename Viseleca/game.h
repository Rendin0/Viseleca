#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <ctime>

class Game
{
	size_t score;
	std::string word;
	std::vector<std::string> all_words;
	std::string key;
	std::vector<std::string> stages;
	std::string wrong_answers;
public:
	Game();

	Game& play();
	size_t getScore();
	Game& importFile(std::string path, std::string key);
};

std::string crypt(std::string str, std::string key);
void crypt_file(std::string path, std::string key);
size_t menu(std::vector<std::string> strs);
std::string toLowerCase(std::string str);