#include "game.h"

Game::Game()
{
	word = "0";
	all_words = {};
	wrong_answers = {};
}

Game& Game::importFile(std::string path, std::string key)
{
	all_words.clear();
	std::ifstream file(path);
	if (!file.is_open())
		throw std::exception("File not found");

	for (std::string tmp; !file.eof(); file >> tmp)
	{
		if (tmp.empty())
			continue;
		all_words.push_back(crypt(tmp, key));
	}

	return *this;
}

std::string crypt(std::string str, std::string key)
{
	size_t original_size = str.size();

	if (key.empty() || str.empty())
		throw std::exception("Wrong key or string size");

	if (str.size() > key.size())
		return crypt(str, key + key.at(key.size() - 1));

	if (str.size() < key.size())
	{
		str = crypt(str + str.at(str.size() - 1), key);

		if (str.size() > original_size)
			str.erase(str.begin() + original_size, str.end());

		return str;
	}

	for (size_t i = 0; i < key.size(); i++)
		str.at(i) = str.at(i) ^ key.at(i);


	return str;
}

void crypt_file(std::string path, std::string key)
{
	std::ofstream file_out(path, std::ios::app);
	file_out << "\n";
	file_out.close();
	std::ifstream file_in(path);

	std::vector<std::string> words;

	if (!file_in.is_open())
		throw std::exception("File not found");

	for (std::string tmp; !file_in.eof(); file_in >> tmp)
	{
		if (tmp.empty())
			continue;
		words.push_back(crypt(tmp, key));
	}
	file_in.close();

	file_out.open(path);
	for (auto& i : words)
		file_out << i + "\n";
	file_out.close();

}
