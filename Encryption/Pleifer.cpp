
#include "Pleifer.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <chrono>
#include "Header.h"


using namespace std;

//void PrintMatrix(char(&matrix)[5][5]) {
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++) {
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//}

void Encryption_pleifer(string& text, Encryption& p)
{
    vector<int> index;
    string alphabet = "abcdefghijklmnoprstuvwxyz";
    char matrix[5][5];
    p.keyword = "cat";

    // delete double
    for (int i = 1; i < p.keyword.length(); i++) {
        if (p.keyword[i - 1] == p.keyword[i]) {
            p.keyword.erase(i, 1);
            i--;
        }
    };
    //delete key letters
    for (int i = 0; i < p.keyword.length(); i++) {
        for (int j = 0; j < alphabet.length(); j++) {
            if (p.keyword[i] == alphabet[j]) alphabet.erase(j, 1);
        }
    };
    //word check
    int l = 0;
    while (l == 0) {
        text.erase(remove_if(text.begin(), text.end(), isspace), text.end());
        text.erase(remove_if(text.begin(), text.end(), ispunct), text.end());
        text.erase(remove_if(text.begin(), text.end(), isdigit), text.end());
        for (int i = 0; i < text.length(); i++) {
            if (isupper(text[i])) text[i] = tolower(text[i]);
        }
        for (int i = 0; i < text.length(); i++) {
            if (isalpha(text[i]))  l = 1;
        }
    };
    //cout << "PR2";
    //double message check
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == text[i + 1]) text.insert(i + 1, 1, 'x');
        //cout << "PR5";
    };

    //add symbol
    if (text.length() % 2 != 0) text.push_back('x');
    //cout << "PR3";
    //bygrams formation
    for (int i = 0; i < text.length(); i += 2) {
        text[i] << text[i + 1];
    };
    //matrix creation
    int k = 0, m = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (k < p.keyword.length()) {
                matrix[i][j] = p.keyword[k];
            }
            if (k >= p.keyword.length()) {
                matrix[i][j] = alphabet[m];
                m++;
            }
            k++;
        }
        //cout << "PR4";
    };


    //find id
    for (int i = 0; i < text.length(); i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (text[i] == matrix[j][k]) {
                    index.push_back(j);
                    index.push_back(k);
                }
            }
        }
    }
    //enmessage
    int a = 0, b = 0;
    for (int i = 0; i <= index.size() - 3; i += 4) {
        a = index[i + 3] + 1;
        // one line
        if (index[i] == index[i + 2] && a < 5) {
             matrix[index[i]][index[i + 1] + 1] << matrix[index[i + 2]][a];
        }
        // one line border
        if (index[i] == index[i + 2] && a >= 5) {
            a = 0;
             matrix[index[i]][index[i + 1] + 1] << matrix[index[i + 2]][a];
        }
        b = index[i + 2] + 1;
        // one column
        if (index[i + 1] == index[i + 3] && b < 5) {
              matrix[index[i] + 1][index[i + 1]] << matrix[b][index[i + 3]];
        }
        // one column border
        if (index[i + 1] == index[i + 3] && b >= 5) {
            b = 0;
             matrix[index[i] + 1][index[i + 1]] << matrix[b][index[i + 3]];
        }

        if (index[i] != index[i + 2] && index[i + 1] != index[i + 3]) {
             matrix[index[i + 2]][index[i + 1]] << matrix[index[i]][index[i + 3]];
        }
    }
}
    