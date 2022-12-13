#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include "Header.h"
#include "vigenere.h"


using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ#$%&'()*+,-./0123456789:;<=>?@ ";

// ������� ��������� ���� �������
//���� ������ � �������� � ��������� ��� �����.
int keycode(char s) {
    for (int i = 0; i < alphabet.length(); i++) {
        if (s == alphabet[i]) return i;
    }
    return 0;
}

string Encode(string text, string key) {
    string code;//keycode(text[i]) ����� ������ ����� ������
    //keycode(key[i]) ����� ������ ����� �����
    //keycode(key[i % key.length()]) ����� �� ������ ����� �����, ����� ���� ���������� �� ��������� ������
    for (int i = 0; i < text.length(); i++) {
        code += alphabet[(keycode(text[i]) + keycode(key[i % key.length()])) % alphabet.length()];
    }
    return code;
}

string Decode(string text, string key) {
    string code;
    for (int i = 0; i < text.length(); i++) {
        code += alphabet[(keycode(text[i]) - keycode(key[i % key.length()]) + alphabet.length()) % alphabet.length()];//���������� ����� ��������, ����� �������� ������������� �����
    }
    return code;
}

void Encryption_vigenere(string& text, Encryption& p) {
    string txt, key;
    txt = text;
    //p.keyword = "cat";
    key = p.keyword;
    char x;

    //���� ����� ��� ���� � ������ ���������, ��� ����� �������� � �������� ��������(��������� �����):
    for (auto& c : txt) c = toupper(c);
    for (auto& c : key) c = toupper(c);
    string q = Encode(txt, key);
    //cout << "Encode: " << q << endl;
    //cout << "Decode: " << Decode(q, key) << endl;
 
}