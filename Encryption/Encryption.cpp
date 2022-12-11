#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <chrono>
#include "Header.h"
#include "Affin_rec.h"
#include "Pleifer.h"
#include "Affin.h"
#include "vigenere.h"

using namespace std;
using namespace chrono;

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
	string text = "krasava, ruki v ushi and <>pognal,./";
	Encryption p;
	run(text, Galimov, p);
	run(text, Encryption_pleifer, p);
	run(text, Affin_method, p);
	run(text, Encryption_vigenere, p);
	//run(text, Hill, p);

}
