#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <chrono>
#include "Header.h"
#include "Affin_rec.h"
#include "sykin.h"
#include "Pleifer.h"
#include "Affin.h"
#include "vigenere.h"
#include "Hill.h"


using namespace std;
using namespace chrono;

Encryption setKeys(int a = 0, int b = 0, int c = 0, int d = 0, string keyword="")
{
	Encryption pack;
	pack.a = a;
	pack.b = b;
	pack.c = c;
	pack.d = d;
	pack.keyword = keyword;
	return pack;
}


template <typename T>
string run(const string text, T func_name, Encryption p)
{
	auto start = steady_clock::now();
	string shifr = func_name(text, p);
	auto end = steady_clock::now();
	auto elapsed_ms = duration_cast<microseconds>(end - start);
	cout << elapsed_ms.count() << " microsec" << endl;
	//cout << __func__ << endl;
	return shifr;
}


int main()
{
	string text;
	ifstream file;
	file.open("txt.txt");
	if (file.is_open())
	{
		getline(file >> ws, text);
	}
	file.close();
	//string text = "krasava, ruki v ushi and <>pognal,./";
	Encryption p;
	cout << "Affine recurrent method: ";
	p = setKeys(1, 3, 4, 5, "keyword");
	run(text, Affin_rec_Galimov, p);
	cout << "Pleifer method: ";
	p = setKeys(0, 0, 0, 0, "cat");
	run(text, Encryption_pleifer, p);
	cout << "Affine method: ";
	p = setKeys(13, 3, 0, 0, "keyword");
	run(text, Affin_method, p);
	cout << "Vigenere method: ";
	p = setKeys(0, 0, 0, 0, "keyword");
	run(text, Encryption_vigenere, p);
	cout << "Hill method: ";
	p = setKeys(0, 0, 0, 0, "lovestrin");
	run(text, Hill_encryption, p);
}
