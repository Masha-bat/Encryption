#pragma once
#include "Header.h"
#include <iostream>
#include <chrono>
#include <string>
template <typename temp> temp GetCorrectNumber(temp min, temp max);
int search1(char a, const std::string& alphabet);
int LOT(int a, int b);
int Evklid(int a, int b, int c);
std::string Zashifr(const std::string& alphabet, const std::string& word_to_shifr, const int& alfa, const int& beta);
std::string Rashif(const std::string& shifr, const std::string& alphabet);
std::string Affin_method(const std::string& word_to_shifr, Encryption p); //вызывать эту функцию


