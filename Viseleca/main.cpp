#include "main.h"

int main()
{
	system("chcp 1251");
	system("cls");

	Game game1;
	//game1.importFile("file.txt", "UltraDrive");

	while (true)
	{
		size_t key = menu({ "New game", "Import file", "Crypt file", "Score", "Exit" });

		system("cls");
		try
		{
			switch (key)
			{
			case 0:
				game1.play();
				break;
			case 1:
			{
				std::cout << "Path: ";
				std::string path, key;
				std::getline(std::cin, path);
				std::cout << "Key: ";
				std::getline(std::cin, key);
				game1.importFile(path, key);

				break;
			}
			case 2:
			{
				std::cout << "Path: ";
				std::string path, key;
				std::getline(std::cin, path);
				std::cout << "Key: ";
				std::getline(std::cin, key);
				crypt_file(path, key);
				break;
			}
			case 3:
				std::cout << "Score: " << game1.getScore() << std::endl;
				system("pause");
				break;
			case 4:
				return 0;
			}
		}
		catch (std::exception e) { std::cout << e.what() << std::endl; system("pause"); }
	}

	return 0;
}