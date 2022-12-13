#pragma once
#include <locale>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include "Header.h"

using namespace std;

void input_check_keys(Encryption& p, vector <long>& alpha, vector <long>& beta, string alphabet);

void input_alphabet(string& alphabet);

void Affin_rec_Galimov(const string& text, Encryption p);

void deshifr_Galimov(string& sh_text,Encryption p);