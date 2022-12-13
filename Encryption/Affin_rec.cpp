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

    if (p.a % 2 == 0 || p.b % 2 == 0)
    {
        cout << "The alpha values must be coprime with the size of the alphabet" << endl;
        return;
    }
    else
    {
        alpha[0] = p.a % alphavit.size();
        alpha[1] = p.b % alphavit.size();
        beta[0] = p.c % alphavit.size();
        beta[1] = p.d % alphavit.size();
    }
}

void Affin_rec_Galimov(string text,Encryption p)  //���� �������
{
    int kolvo = 0, poz = 0, sh_poz = 0;
    vector <char> alphavit(256);
    vector <long> alpha, beta;
    char el;
    zapoln_alphavit(alphavit);//������� ��������
    zapoln_keys(p, alpha, beta, alphavit);//����� ���������� �� ���������

    if (alpha[0] ==0&& alpha[1] ==0&& beta[0] ==0&& beta[1] == 0)
    {
        
    }
    else
    {
        kolvo = text.length();//������ ���������� ���� � �����
        for (int i = 0; i < kolvo; i++)//�� ������ ����� ���
        {
            el = text[i];//���� ������ �����
            vector<char>::iterator it = find(alphavit.begin(), alphavit.end(), el); //������ ��� ����� � �������� � ���� ��������
            if (it == alphavit.end())//�������� �� ���������� �����
            {
                //cout << "Element " << el << " not found" << endl;//�� �� ������� ������� ��
            }
            else //� ���� �������
            {
                poz = distance(alphavit.begin(), it) % alphavit.size();   //https://www.techiedelight.com/ru/find-index-element-vector-cpp/ ������ ������� � ��������
                if (i == 0 || i == 1) //������ ��� ���� ���� �� �����
                {
                    sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size(); //������� ������������� �����
                    cout << alphavit[sh_poz];//������ ������������� �����          
                }
                else //��� ����� ������ �������� ����� ���� ��������� �� �������
                {
                    alpha.push_back((alpha[i - 2] * alpha[i - 1]) % alphavit.size()); //������ ����� �����
                    beta.push_back((beta[i - 2] + beta[i - 1]) % alphavit.size());  //������ ����� �����
                    sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size();
                    cout << alphavit[sh_poz]; //������ ������������� �����               
                }
            }
        }
    }
}






void deshifr_Galimov(Encryption p)
{
    int kolvo = 0, poz = 0, sh_poz = 0;
    vector <char> alphavit(256);
    vector <long> alpha, beta;
    string shslovo;
    char el;
    cout << endl;
    getline(cin >> ws, shslovo);
    zapoln_alphavit(alphavit);//������� ��������
    zapoln_keys(p, alpha, beta, alphavit);//����� ���������� �� ���������
    kolvo = shslovo.length();//������ ���������� ���� � �����
    for (int i = 0; i < kolvo; i++)//�� ������ ����� ���
    {
        el = shslovo[i];//���� ������ �����
        vector<char>::iterator it = find(alphavit.begin(), alphavit.end(), el); //������ ��� ����� � �������� � ���� ��������
        if (it == alphavit.end())//�������� �� ���������� �����
        {
            //cout << "Element " << el << " not found" << endl;//�� �� ������� ������� ��
        }
        else //� ���� �������
        {
            sh_poz = distance(alphavit.begin(), it) % alphavit.size();   //https://www.techiedelight.com/ru/find-index-element-vector-cpp/ ������ ������� � ��������
            if (i == 0 || i == 1) //������ ��� ���� ���� �� �����
            {
                while (((sh_poz - beta[i]) % alpha[i]) != 0 && sh_poz!=beta[i])
                {
                    int j = 1;
                    sh_poz = sh_poz + alphavit.size() * j;
                }

                poz = ((sh_poz -beta[i])/alpha[i]) % alphavit.size(); //������� ������������� �����
                cout << alphavit[poz];//������ �������������� �����          
            }
            else //��� ����� ������ �������� ����� ���� ��������� �� �������
            {
                alpha.push_back((alpha[i - 2] * alpha[i - 1]) % alphavit.size()); //������ ����� �����
                beta.push_back((beta[i - 2] + beta[i - 1]) % alphavit.size());  //������ ����� �����
                if (sh_poz - beta[i] == 0 && alpha[i] == 0)
                {
                    //���� �� ����
                }
                else
                {      
                    while (((sh_poz - beta[i]) % alpha[i])!=0 && sh_poz != beta[i])
                    {
                        int j = 1;
                        sh_poz = sh_poz + alphavit.size() * j;
                    }
                    poz = ((sh_poz - beta[i]) / alpha[i]);//����� �������� �� 0/0   
                    cout << alphavit[poz]; //������ �������������� �����
                
                }              
            }
        }
    }
}