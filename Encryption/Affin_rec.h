#pragma once
#include <locale>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include "Header.h"

using namespace std;

void zapoln_alphabet(vector <char>& alphabet);

void zapoln_keys(Encryption& p, vector <int>& alpha, vector <int>& beta, vector <char> alphabet);

void Affin_rec_Galimov(string text,Encryption p);

void deshifr_Galimov(Encryption p);



void zapoln_keys2(Encryption& p, vector <long>& alpha, vector <long>& beta, string alphabet2);

void zapoln_alphabet2(string& alphabet2);

void Affin_rec_Galimov2(string text, Encryption p);

void deshifr_Galimov2(Encryption p);