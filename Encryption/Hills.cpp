#include <iostream>
#include <math.h>
#include "Hill.h"
#include <string>
#include <vector>
#include "Header.h"

using namespace std;

//Ключ матрица, заданная изначально

string symbols;
vector<int> key = {};

vector<int> KEY(string keyword)
{	
	if (keyword == "")
		cout << "Error, enter a keyword" << endl;
	else {
		for (char c : keyword)
		{

			key.push_back(int(c));
		}
	}
	return key;
}

void output(int n) {

	cout << n << endl;
}

string Hill_encryption(string word, Encryption p)
{
	p.keyword = "alpinizmm";
	key = KEY(p.keyword);


	if ((word.length() != 0) and (word.length() % 3 != 0))
	{
		int amount = 3 - word.length() % 3;
		for (int i(0); i < amount; ++i)
			word += '#';
	}

	//cout << word << endl;


	int i(0);
	string outputword = "";
	while (i < word.length() - 1) {
		for (int j(0); j < 3; ++j) {
			//при шифровании по Хиллу мы используем mod256 для замены символов
			int letter = (word[i] * key[j * 3 + 0] + word[i + 1] * key[j * 3 + 1] + word[i + 2] * key[j * 3 + 2]) % 256;
			outputword += (char)letter;
		}
		i += 3;
	}

	//cout << outputword << endl;
	return outputword;
}
