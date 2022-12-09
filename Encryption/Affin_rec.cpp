#include "Affin_rec.h"
#include <locale>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>

void zapoln_alphavit(vector <char>& alphavit) //���������� �������� ���� ���������� ACII
{
    iota(alphavit.begin(), alphavit.end(), 'A'); //https://web-answers.ru/c/inicializacija-vektora-anglijskim-alfavitom.html
}

void zapoln_keys(Encryption& p, vector <long>& alpha, vector <long>& beta, vector <char> alphavit)  //���������������� ������ ��� ������ �� ���������
{
    alpha.resize(2);
    beta.resize(2);
    alpha[0] = p.a % alphavit.size();
    alpha[1] = p.b % alphavit.size();
    beta[0] = p.c % alphavit.size();
    beta[1] = p.d % alphavit.size();
}

void Galimov(Encryption& p)  //���� �������
{
    int kolvo = 0, poz = 0, sh_poz = 0;
    vector <char> alphavit(256);
    vector <int> shifr;
    vector <long> alpha, beta;
    string alphavit2;
    string slovo = "abcd";
    char el;
    zapoln_alphavit(alphavit);//������� ��������
    zapoln_keys(p, alpha, beta, alphavit);//����� ���������� �� ���������
    kolvo = slovo.length();//������ ���������� ���� � �����
    for (int i = 0; i < kolvo; i++)//�� ������ ����� ���
    {
        el = slovo[i];//���� ������ �����
        vector<char>::iterator it = find(alphavit.begin(), alphavit.end(), el); //������ ��� ����� � �������� � ���� ��������
        if (it == alphavit.end())//�������� �� ���������� �����
        {
            cout << "Element " << el << " not found" << endl;//�� �� ������� ������� ��
        }
        else //� ���� �������
        {
            poz = distance(alphavit.begin(), it) % alphavit.size();   //https://www.techiedelight.com/ru/find-index-element-vector-cpp/ ������ ������� � ��������
            if (i == 0 || i == 1) //������ ��� ���� ���� �� �����
            {
                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size(); //������� ������������� �����
                //shifr.push_back(alphavit[sh_poz]); //������ � ������ ������������� �����
                cout << alphavit[sh_poz];//������ ������������� �����          
            }
            else //��� ����� ������ �������� ����� ���� ��������� �� �������
            {
                alpha.push_back((alpha[i - 2] * alpha[i - 1]) % alphavit.size()); //������ ����� �����
                beta.push_back((beta[i - 2] + beta[i - 1]) % alphavit.size());  //������ ����� �����
                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size();
                //shifr.push_back(alphavit[sh_poz]);  //������ � ������ ������������� �����               
                cout << alphavit[sh_poz]; //������ ������������� �����               
            }
        }
    }
    cout << endl;
}