#pragma once
#include <iostream>
#include <fstream>
#include <vector>

std::string crypt(std::string str, std::string key);
void crypt_file(std::string path, std::string key);