#include <iostream>
#include <string>
//#include <vector>
//#include <numeric>
//#include <algorithm>
#include "Header.h"
#include "vigenere.h"


using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ#$%&'()*+,-./0123456789:;<=>?@ ";

// функция получения кода символа
//ищем сивмол в алфавите и возращаем его номер.
int keycode(char s) {
    for (int i = 0; i < alphabet.length(); i++) {
        if (s == alphabet[i]) return i;
    }
    return 0;
}

string Encode(string text, string key) {
    string code;//keycode(text[i]) число каждой буквы текста
    //keycode(key[i]) число каждой буквы ключа
    //keycode(key[i % key.length()]) делим по модулю длины ключа, чтобы ключ растянулся по вводимому тексту
    for (int i = 0; i < text.length(); i++) {
        code += alphabet[(keycode(text[i]) + keycode(key[i % key.length()])) % alphabet.length()];
    }
    return code;
}

string Decode(string text, string key) {
    string code;
    for (int i = 0; i < text.length(); i++) {
        code += alphabet[(keycode(text[i]) - keycode(key[i % key.length()]) + alphabet.length()) % alphabet.length()];//прибалвяем длину алфавита, чтобы избежать отрицательные числа
    }
    return code;
}

string Encryption_vigenere(const string& text, Encryption& p) {
    string txt, key;
    txt = text;
    //p.keyword = "cat";
    key = p.keyword;
    char x;

    //если текст или ключ в разных регистрах, нам нужно привести с верхнему регистру(ЗАГЛАВНЫЕ БУКВЫ):
    for (auto& c : txt) c = toupper(c);
    for (auto& c : key) c = toupper(c);
    string q = Encode(txt, key);
    cout << "Encode: " << q << endl;
    cout << "Decode: " << Decode(q, key) << endl;
 
    return q;
}