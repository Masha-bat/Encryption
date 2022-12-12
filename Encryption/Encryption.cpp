#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <chrono>
#include "Header.h"
#include "Affin_rec.h"
#include "sykin.h"

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
	string text = "ddbufhsvdfhvvbdgvhf";
	Encryption p;

	run(text, Galimov, p);
	//run(text, Hill, p);

}
