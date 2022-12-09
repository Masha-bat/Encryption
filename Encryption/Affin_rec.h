#pragma once
#include <locale>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include "Header.h"

using namespace std;

void zapoln_alphavit(vector <char>& alphavit);

void zapoln_keys(Encryption& p, vector <int>& alpha, vector <int>& beta, vector <char> alphavit);

void Galimov(string&word,Encryption& p);