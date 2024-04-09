#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Game
{
	std::string word;
	std::vector<std::string> all_words;
	std::vector<char> wrong_answers;
public:
	Game();

	Game& importFile(std::string path, std::string key);
};

std::string crypt(std::string str, std::string key);
void crypt_file(std::string path, std::string key);