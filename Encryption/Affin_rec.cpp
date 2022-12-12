#include "Affin_rec.h"
#include <locale>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>

void zapoln_alphavit(vector <char>& alphavit) //заполнение алфавита всей кодировкой ACII
{
    iota(alphavit.begin(), alphavit.end(), 'A'); //https://web-answers.ru/c/inicializacija-vektora-anglijskim-alfavitom.html
}

void zapoln_keys(Encryption& p, vector <long>& alpha, vector <long>& beta, vector <char> alphavit)  //переприсваивание нужных мне ключей из структуры
{
    alpha.resize(2);
    beta.resize(2);

  /*  p.a = 1;
    p.b = 1;
    p.c = 1;
    p.d = 1;*/

    alpha[0] = p.a % alphavit.size();
    alpha[1] = p.b % alphavit.size();
    beta[0] = p.c % alphavit.size();
    beta[1] = p.d % alphavit.size();
}

void Affin_rec_Galimov(string text,Encryption p)  //сама функци€
{
    int kolvo = 0, poz = 0, sh_poz = 0;
    vector <char> alphavit(256);
    vector <long> alpha, beta;
    //string slovo = "ABCD";
    char el;
    zapoln_alphavit(alphavit);//алфавит заполн€ю
    zapoln_keys(p, alpha, beta, alphavit);//ключи забираютс€ из структуры
    kolvo = text.length();//смотрю количество букв в слове
    for (int i = 0; i < kolvo; i++)//на каждую букву шаг
    {
        el = text[i];//беру нужную букву
        vector<char>::iterator it = find(alphavit.begin(), alphavit.end(), el); //нахожу эту букву в алфавите и беру итератор
        if (it == alphavit.end())//проверка на нахождение буквы
        {
            //cout << "Element " << el << " not found" << endl;//ну не найдено пон€тно же
        }
        else //а если найдена
        {
            poz = distance(alphavit.begin(), it) % alphavit.size();   //https://www.techiedelight.com/ru/find-index-element-vector-cpp/ нахожу позицию в алфавите
            if (i == 0 || i == 1) //первые два раза коэф по вводу
            {
                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size(); //позици€ зашифрованной буквы
                //cout << alphavit[sh_poz];//вывожу зашифрованную букву          
            }
            else //тут после второй итерации ключи сами создаютс€ по формуле
            {
                alpha.push_back((alpha[i - 2] * alpha[i - 1]) % alphavit.size()); //считаю новую альфу
                beta.push_back((beta[i - 2] + beta[i - 1]) % alphavit.size());  //считаю новую бетту
                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size();             
                //cout << alphavit[sh_poz]; //вывожу зашифрованную букву               
            }
        }
    }
    //cout << endl;
}