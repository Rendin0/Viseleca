#include "game.h"

Game::Game()
{
	score = 0;
	word = key = "0";
	all_words = {};
	wrong_answers = {};
	stages.push_back(R"STAGE(
 ------    
|         
|         
|      
|       
/\        
)STAGE");
	stages.push_back(R"STAGE(
 ------    
|         
|         
|      
|       
/\    TT  
)STAGE");
	stages.push_back(R"STAGE(
 ------    
|         
|         
|      
|     /\  
/\    TT  
)STAGE");
	stages.push_back(R"STAGE(
 ------    
|         
|         
|      0 
|     /\  
/\    TT  
)STAGE");
	stages.push_back(R"STAGE(
 ------    
|         
|         
|     /0\ 
|     /\  
/\    TT  
)STAGE");
	stages.push_back(R"STAGE(
 ------    
|         
|      o   
|     /0\ 
|     /\  
/\    TT  
)STAGE");
	stages.push_back(R"STAGE(
 ------    
|      |   
|      o   
|     /0\ 
|     /\  
/\    TT  
)STAGE");
	stages.push_back(R"STAGE(
 ------    
|      |   
|      o   
|     /0\ 
|     /\  
/\      
)STAGE");
}

Game& Game::play()
{
	std::string wrong_answers;

	if (all_words.empty())
		throw std::exception("No words found");

	srand(static_cast<int>(time(0)));

	std::string seeking, word = crypt(all_words.at(rand() % all_words.size()), key);

	word = toLowerCase(word);

	for (auto i : word)
		seeking.push_back('_');

	for (size_t i = 0; i < stages.size() - 1;)
	{
		system("cls");
		std::cout << stages.at(i);

		std::cout << seeking << std::endl;
		std::cout << "Неправильные: ";
		for (auto& i : wrong_answers)
			std::cout << i << " ";
		std::cout << std::endl;

		if (seeking.find('_') == std::string::npos)
		{
			std::cout << "Вы победили!\n";
			score++;
			system("pause");
			return *this;
		}

		std::cout << ">_ ";
		std::string answer;
		std::getline(std::cin, answer);

		if (word.find(answer.at(0)) == std::string::npos) // Not found
		{
			if (wrong_answers.find(answer.at(0)) != std::string::npos)
				continue;

			wrong_answers.push_back(answer.at(0));
			i++;
		}
		else // Found
		{
			size_t found = word.find(answer.at(0));



			while (found != std::string::npos) // Looking for all chars
			{
				seeking.at(found) = word.at(found);
				found = word.find(answer.at(0), found + 1);
			}
		}
	}

	system("cls");
	std::cout << stages.at(7);

	std::cout << "Искомое слово: " << word << std::endl;
	std::cout << seeking << std::endl;
	std::cout << "Неправильные: ";
	for (auto& i : wrong_answers)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "Вы проиграли\n";
	system("pause");

	return *this;
}

size_t Game::getScore()
{
	return score;
}

Game& Game::importFile(std::string path, std::string key)
{
	this->key = key;
	all_words.clear();
	std::ifstream file(path);
	if (!file.is_open())
		throw std::exception("File not found");

	for (std::string tmp; !file.eof(); file >> tmp)
	{
		if (tmp.empty())
			continue;
		all_words.push_back(tmp);
	}

	return *this;
}



size_t menu(std::vector<std::string> strs)
{
	size_t choice = 0;

	system("cls");

	for (size_t i = 0; i < strs.size(); i++)
	{
		if (choice == i)
			std::cout << "\033[31m" << strs.at(i) << "\033[0m" << std::endl;
		else
			std::cout << strs.at(i) << std::endl;
	}

	while (true)
	{
		int key = _getch();

		switch (key)
		{
		case 72:
			if (choice <= 0)
				choice = strs.size() - 1;
			else
				choice--;
			break;
		case 80:
			if (choice >= strs.size() - 1)
				choice = 0;
			else
				choice++;
			break;
		case 13:
			return choice;
		default:
			break;
		}

		std::cout << "\033[H";

		for (size_t i = 0; i < strs.size(); i++)
		{
			if (choice == i)
				std::cout << "\033[31m" << strs.at(i) << "\033[0m" << std::endl;
			else
				std::cout << strs.at(i) << std::endl;
		}
	}


}

std::string toLowerCase(std::string str)
{
	for (auto& i : str)
	{
		if (i >= 'А' && i <= 'Я')
			i = i + ('а' - 'А');
		if (i >= 'A' && i <= 'Z')
			i = i + ('a' - 'A');
	}
	return str;
}
