#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <numeric>
#include <algorithm>
#include "Header.h"



void Encryption_vigenere(string& text, Encryption& p);
string Encode(string text, string key);
int keycode(char s);
//void Encode(vector <char> alphabet, string text, string keyword);