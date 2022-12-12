#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <chrono>
#include "Header.h"
#include "Affin_rec.h"
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
void run(string text, T func_name, Encryption p)
{
	auto start = steady_clock::now();
	func_name(text, p);
	auto end = steady_clock::now();
	auto elapsed_ms = duration_cast<microseconds>(end - start);
	cout << elapsed_ms.count() << " microsec" << endl;
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
	p = setKeys(1, 2, 3, 4, "keyword");
	run(text, Affin_rec_Galimov, p);
	run(text, Encryption_pleifer, p);
	run(text, Affin_method, p);
	run(text, Encryption_vigenere, p);
	p = setKeys(0, 0, 0, 0, "lovestrin");
	run(text, Hill_encryption, p);

}
