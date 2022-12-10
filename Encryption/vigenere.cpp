#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include "Header.h"
#include "vigenere.h"


using namespace std;
//string D;

//struct Encryption
//{
//    string text = "pipec";
//    string keyword = "aklmn";
//};
/*void ops(string text, string keyword) //растягиваем ключ, если его длина меньше длины слова.
{
    if (text.length() >= keyword.length())
    {
        for (int i = 0; i < (text.length() / keyword.length()); i++)
        {
            D = D + keyword;
        }
    }
    else {
        for (int j = 0; j < (text.length() % keyword.length()); j++)
        {
            D = D + keyword[j];
        }
    }

}

void Encode(vector <char> alphabet, string text, string keyword)
{
    string code;
    int poz = 0;//индекс буквы
    char el;
    int sh_key, sh_poz;
    char sh_el;
    for (size_t i = 0; i < text.length(); i++)
    {
        if (text.length() >= keyword.length())
        {
            for (int i = 0; i < (text.length() / keyword.length()); i++)
            {
                D = D + keyword;
            }
            for (int j = 0; j < (text.length() % p.keyword.length()); j++)
            {
                D = D + p.keyword[j];
            }
        }
        else {
            for (int j = 0; j < (text.length() % p.keyword.length()); j++)
            {
                D = D + p.keyword[j];
            }
        }

        //keyword = keyword + keyword + keyword;
        el = text[i];
        vector<char>::iterator it = find(alphabet.begin(), alphabet.end(), el);
        poz = distance(alphabet.begin(), it); //номер буквы в алфавите из слова

        sh_el = D[i];//считываю по буквам пароль
        vector<char>::iterator it2 = find(alphabet.begin(), alphabet.end(), sh_el);//нахожу итератор его позиции в алфавите
        sh_key = distance(alphabet.begin(), it2); //нахожу его позицию в алфавите(пароля)
        //sh_key2 = sh_key

        sh_poz = (poz + sh_key) % alphabet.size(); //складываем номер буквы из слова на номер буквы из пароля

        cout << alphabet[sh_poz];
        //cout << "\n" << sh_key << endl;
        //cout << "\n" << keyword.length() << endl;
        //cout << "\n" << D << endl;
    }
}*/
void Encryption_vigenere(string& text, Encryption& p)
{
    vector <char> alphabet(256);
    iota(alphabet.begin(), alphabet.end(), 'A');
    string code;
    int poz = 0;//индекс буквы
    char el;
    int sh_key, sh_poz;
    char sh_el;
    string D;
    p.keyword = "cat";
    for (size_t i = 0; i < text.length(); i++)
    {
        if (text.length() >= p.keyword.length())//
        {
            for (int i = 0; i < (text.length() / p.keyword.length()); i++)
            {
                D = D + p.keyword;
            }
            for (int j = 0; j < (text.length() % p.keyword.length()); j++)
            {
                D = D + p.keyword[j];
            }
        }
        //else {
            //for (int j = 0; j < (text.length() % p.keyword.length()); j++)
            //{
              //  D = D + p.keyword[j];
           // }
       // }

        //keyword = keyword + keyword + keyword;
        el = text[i];
        vector<char>::iterator it = find(alphabet.begin(), alphabet.end(), el);
        poz = distance(alphabet.begin(), it); //номер буквы в алфавите из слова

        sh_el = D[i];//считываю по буквам пароль
        vector<char>::iterator it2 = find(alphabet.begin(), alphabet.end(), sh_el);//нахожу итератор его позиции в алфавите
        sh_key = distance(alphabet.begin(), it2); //нахожу его позицию в алфавите(пароля)
        //sh_key2 = sh_key

        sh_poz = (poz + sh_key) % alphabet.size(); //складываем номер буквы из слова на номер буквы из пароля

        //cout << alphabet[sh_poz]; //19 символов по итогу
        //cout << "\n" << sh_key << endl;
        //cout << "\n" << keyword.length() << endl;
        //cout << "\n" << D << endl;
    }
    //setlocale(LC_ALL, "Russian");

    //vector <char> alphabet(256);
    //iota(alphabet.begin(), alphabet.end(), 'A');
    //string keyword = p.keyword;
    //string text = p.text;
    //Encode(alphabet, text, keyword);
}