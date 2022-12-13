#include "Affin_rec.h"
#include <locale>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>


//при расшифровке проблема в алфавите, что есть схожие элементы, котоыре он видит как одинаковые и как следствие неверно распознаЄт

void input_check_keys(Encryption& p, vector <long>& alpha, vector <long>& beta, string alphabet)  //переприсваивание нужных мне ключей из структуры
{
    alpha.resize(2);
    beta.resize(2);

    if (p.a % 2 == 0 || p.b % 2 == 0)
    {
        cout << "The alpha values must be coprime with the size of the alphabet" << endl;
        return;
    }
    else
    {
        alpha[0] = p.a % alphabet.size();
        alpha[1] = p.b % alphabet.size();
        beta[0] = p.c % alphabet.size();
        beta[1] = p.d % alphabet.size();
    }
}

void input_alphabet(string& alphabet) //заполнение алфавита всей кодировкой ACII
{
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!є;%:?*()_+-=@#$^&<>{}[]'/|.`~, ";
}

void Affin_rec_Galimov(string text, Encryption p)  //сама функци€
{
    int kolvo = 0, poz = 0, sh_poz = 0;
    string alphabet;
    vector <long> alpha, beta;
    char el;
    input_alphabet(alphabet);//алфавит заполн€ю
    input_check_keys(p, alpha, beta, alphabet);//ключи забираютс€ из структуры

    if (alpha[0] == 0 && alpha[1] == 0 && beta[0] == 0 && beta[1] == 0)
    {

    }
    else
    {
        kolvo = text.length();//смотрю количество букв в слове
        for (int i = 0; i < kolvo; i++)//на каждую букву шаг
        {
            el = text[i];//беру нужную букву
            string::iterator it = find(alphabet.begin(), alphabet.end(), el); //нахожу эту букву в алфавите и беру итератор
            if (it == alphabet.end())//проверка на нахождение буквы
            {
                //cout << "Element " << el << " not found" << endl;//ну не найдено пон€тно же
            }
            else //а если найдена
            {
                poz = distance(alphabet.begin(), it) % alphabet.size();   //https://www.techiedelight.com/ru/find-index-element-vector-cpp/ нахожу позицию в алфавите
                if (i == 0 || i == 1) //первые два раза коэф по вводу
                {
                    sh_poz = (poz * alpha[i] + beta[i]) % alphabet.size(); //позици€ зашифрованной буквы
                    cout << alphabet[sh_poz];//вывожу зашифрованную букву          
                }
                else //тут после второй итерации ключи сами создаютс€ по формуле
                {
                    alpha.push_back((alpha[i - 2] * alpha[i - 1]) % alphabet.size()); //считаю новую альфу
                    beta.push_back((beta[i - 2] + beta[i - 1]) % alphabet.size());  //считаю новую бетту
                    sh_poz = (poz * alpha[i] + beta[i]) % alphabet.size();
                    cout << alphabet[sh_poz]; //вывожу зашифрованную букву               
                }
            }
        }
    }
}

void deshifr_Galimov(Encryption p)
{
    int kolvo = 0, poz = 0, sh_poz = 0;
    string alphabet;
    vector <long> alpha, beta;
    string shslovo;
    char el;
    cout << endl;
    getline(cin >> ws, shslovo);
    input_alphabet(alphabet);//алфавит заполн€ю
    input_check_keys(p, alpha, beta, alphabet);//ключи забираютс€ из структуры
    kolvo = shslovo.length();//смотрю количество букв в слове
    for (int i = 0; i < kolvo; i++)//на каждую букву шаг
    {
        el = shslovo[i];//беру нужную букву
        string::iterator it = find(alphabet.begin(), alphabet.end(), el); //нахожу эту букву в алфавите и беру итератор
        if (it == alphabet.end())//проверка на нахождение буквы
        {
            //cout << "Element " << el << " not found" << endl;//ну не найдено пон€тно же
            alpha.push_back(alpha[i - 1]*alpha[i-2]);
            beta.push_back(beta[i - 1]+beta[i-2]); //костыль из-за которого поломаетс€ вс€ расшифровка, но не выскочит ошибка
        }
        else //а если найдена
        {
            sh_poz = distance(alphabet.begin(), it) % alphabet.size();   //https://www.techiedelight.com/ru/find-index-element-vector-cpp/ нахожу позицию в алфавите
            if (i == 0 || i == 1) //первые два раза коэф по вводу
            {
                while (((sh_poz - beta[i]) % alpha[i]) != 0 && sh_poz != beta[i])
                {
                    int j = 1;
                    sh_poz = sh_poz + alphabet.size() * j;
                }

                poz = ((sh_poz - beta[i]) / alpha[i]) % alphabet.size(); //позици€ зашифрованной буквы
                cout << alphabet[poz];//вывожу расшифрованную букву          
            }
            else //тут после второй итерации ключи сами создаютс€ по формуле
            {
                alpha.push_back((alpha[i - 2] * alpha[i - 1]) % alphabet.size()); //считаю новую альфу
                beta.push_back((beta[i - 2] + beta[i - 1]) % alphabet.size());  //считаю новую бетту        

                while (((sh_poz - beta[i]) % alpha[i]) != 0 && sh_poz != beta[i] || sh_poz < beta[i])
                {
                    int j = 1;
                    sh_poz = sh_poz + alphabet.size() * j;
                }
                poz = ((sh_poz - beta[i]) / alpha[i]);
                cout << alphabet[poz]; //вывожу расшифрованную букву          
            }
        }
    }
}