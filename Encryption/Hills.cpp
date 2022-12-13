#include <iostream>
#include <math.h>
#include "Hill.h"
#include <string>
#include <vector>
#include "Header.h"

using namespace std;

//Ключ матрица, заданная изначально

string symbols;

vector<int> KEY(string keyword)
{
	vector<int> key;
	double e = sqrt(keyword.length());
	if (keyword == "")
	{
		cout << " Error, enter a keyword" << endl;
		
	}
	else if (e != (trunc(e)))
	{
		cout << " Error, enter a word whose number of characters is an integer when using the root ";
		
	}
	else {
		for ( auto&  f : keyword)
		{

			key.push_back(int(f));
		}
	}
	return key;
}


string Hill_encryption(string word, Encryption p)
{
	vector<int> key;
	 key = KEY(p.keyword);
	 if (key.size() == 0)
		 return p.keyword;
	 else {
		 int divider = sqrt(key.size());

		 if ((word.length() != 0) and (word.length() % divider != 0))
		 {
			 int amount = divider - word.length() % divider;
			 for (int i(0); i < amount; ++i)
				 word += '#';
		 }

		 //cout << word << endl;


		 int i(0);
		 string outputword = "";
		 while (i < word.length() - 1) {
			 for (int j(0); j < divider; ++j)
			 {
				 int column = 0;
				 for (int m(0); m < divider-1; ++m)
				 {
					 column += word[i + m] * key[j * divider + m];
				 }
				 //при шифровании по Хиллу мы используем mod256 для замены символов
				 int letter = column % 256;
				 outputword += (char)letter;
			 }
			 i += divider;
		 }

		 //cout << outputword << endl;
		 return outputword;
	 }
}


