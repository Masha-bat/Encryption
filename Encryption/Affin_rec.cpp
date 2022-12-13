#include "Affin_rec.h"
#include <locale>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>


//��� ����������� �������� � ��������, ��� ���� ������ ��������, ������� �� ����� ��� ���������� � ��� ��������� ������� ���������

void input_check_keys(Encryption& p, vector <long>& alpha, vector <long>& beta, string alphabet)  //���������������� ������ ��� ������ �� ���������
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

void input_alphabet(string& alphabet) //���������� �������� ���� ���������� ACII
{
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!�;%:?*()_+-=@#$^&<>{}[]'/|.`~, �����Ũ����������������������������������������������������������";
}

void Affin_rec_Galimov(const string& text, Encryption p)  //���� �������
{
    int kolvo = 0, poz = 0, sh_poz = 0;
    string alphabet,sh_text;
    vector <long> alpha, beta;
    char sh_el;
    char el;
    input_alphabet(alphabet);//������� ��������
    input_check_keys(p, alpha, beta, alphabet);//����� ���������� �� ���������

    if (alpha[0] == 0 && alpha[1] == 0 && beta[0] == 0 && beta[1] == 0) //���� ����� �� ��������
    {

    }
    else
    {
        kolvo = text.length();//������ ���������� ���� � �����
        for (int i = 0; i < kolvo; i++)//�� ������ ����� ���
        {
            el = text[i];//���� ������ �����
            string::iterator it = find(alphabet.begin(), alphabet.end(), el); //������ ��� ����� � �������� � ���� ��������
            if (it == alphabet.end())//�������� �� ���������� �����
            {
                //cout << "Element " << el << " not found" << endl;//�� �� ������� ������� ��
            }
            else //� ���� �������
            {
                poz = distance(alphabet.begin(), it) % alphabet.size();   //https://www.techiedelight.com/ru/find-index-element-vector-cpp/ ������ ������� � ��������
                if (i == 0 || i == 1) //������ ��� ���� ���� �� �����
                {
                    sh_poz = (poz * alpha[i] + beta[i]) % alphabet.size(); //������� ������������� �����
                    cout << alphabet[sh_poz];//������ ������������� �����    
                    sh_el = alphabet[sh_poz];
                    sh_text.push_back(sh_el);
                }
                else //��� ����� ������ �������� ����� ���� ��������� �� �������
                {
                    alpha.push_back((alpha[i - 2] * alpha[i - 1]) % alphabet.size()); //������ ����� �����
                    beta.push_back((beta[i - 2] + beta[i - 1]) % alphabet.size());  //������ ����� �����
                    sh_poz = (poz * alpha[i] + beta[i]) % alphabet.size();
                    cout << alphabet[sh_poz]; //������ ������������� �����      
                    sh_el = alphabet[sh_poz];
                    sh_text.push_back(sh_el);
                }
            }
        }
    }
    cout << endl;
}

void deshifr_Galimov(string& sh_text,Encryption p)
{
    int kolvo = 0, poz = 0, sh_poz = 0;
    string alphabet;
    vector <long> alpha, beta;
    //string shslovo;
    char el;
    //cout << endl;
   // getline(cin >> ws, shslovo);
    input_alphabet(alphabet);//������� ��������
    input_check_keys(p, alpha, beta, alphabet);//����� ���������� �� ���������
    kolvo = sh_text.length();//������ ���������� ���� � �����
    for (int i = 0; i < kolvo; i++)//�� ������ ����� ���
    {
        el = sh_text[i];//���� ������ �����
        string::iterator it = find(alphabet.begin(), alphabet.end(), el); //������ ��� ����� � �������� � ���� ��������
        if (it == alphabet.end())//�������� �� ���������� �����
        {
            //cout << "Element " << el << " not found" << endl;//�� �� ������� ������� ��
            alpha.push_back(alpha[i - 1]*alpha[i-2]);
            beta.push_back(beta[i - 1]+beta[i-2]); //������� ��-�� �������� ���������� ��� �����������, �� �� �������� ������
        }
        else //� ���� �������
        {
            sh_poz = distance(alphabet.begin(), it) % alphabet.size();   //https://www.techiedelight.com/ru/find-index-element-vector-cpp/ ������ ������� � ��������
            if (i == 0 || i == 1) //������ ��� ���� ���� �� �����
            {
                while (((sh_poz - beta[i]) % alpha[i]) != 0 && sh_poz != beta[i]) //��� �������� ������ ������������� ������ �������� ����� %, �� ��� ����� ������� �� ����� ������� ����������, ��� � ��� � �������������
                {
                    int j = 1;
                    sh_poz = sh_poz + alphabet.size() * j;
                }

                poz = ((sh_poz - beta[i]) / alpha[i]) % alphabet.size(); //������� ������������� �����
                cout << alphabet[poz];//������ �������������� �����          
            }
            else //��� ����� ������ �������� ����� ���� ��������� �� �������
            {
                alpha.push_back((alpha[i - 2] * alpha[i - 1]) % alphabet.size()); //������ ����� �����
                beta.push_back((beta[i - 2] + beta[i - 1]) % alphabet.size());  //������ ����� �����        

                while (((sh_poz - beta[i]) % alpha[i]) != 0 && sh_poz != beta[i] || sh_poz < beta[i])
                {
                    int j = 1;
                    sh_poz = sh_poz + alphabet.size() * j;
                }
                poz = ((sh_poz - beta[i]) / alpha[i]);
                cout << alphabet[poz]; //������ �������������� �����          
            }
        }
    }
}