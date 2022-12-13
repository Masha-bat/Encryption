#include <fstream>
#include <algorithm>
#include <chrono>
#pragma once

std::string vigenereCode(std::string message, std::string key);
std::string vigenereDecode(std::string message, std::string key);

void code(std::string message);
void decode(std::string message);

std::string vigenereCode(std::string message, std::string key);
std::string vigenereDecode(std::string message, std::string key);
