#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <map>

void code(std::string word);
void decode(std::string word);
std::string vigenereCode(std::string word, std::string keyword);
std::string vigenereDecode(std::string word, std::string keyword);
bool alphabetOnly = true;

//using namespace std::chrono;

void code(std::string Encryption p) {
    unsigned int choice = 0;    

    std::string keyword;

    //std::cout << "Choose a keyword > ";
    std::string keyword = p.word;

    if(keyword.size() == 0)     { std::cout << "keyword's length is 0, quitting"; return; }
    //auto start_1 = system_clock::now();
    
    std::string result = vigenereCode(p.word, keyword);

    //std::cout << "Result : " << result;
    //auto finish_1 = system_clock::now();
    //auto duration_1 = duration_cast<microseconds>(finish_1-start_1).count();
    //std::cout << "\nEncrypt time: "<< duration_1 << " microseconds"<< std::endl;
}

void decode(std::string Encryption p) {
    
    std::string keyword;

    //std::cout << "Your keyword > ";
    std::string keyword = p.keyword;

    if(keyword.size() == 0)     { std::cout << "keyword's length is 0, quitting"; return; }

    //auto start_2 = system_clock::now();
    std::string result = vigenereDecode(p.word, keyword);

    //std::cout << "Result : " << result;
    //auto finish_2 = system_clock::now();
    //auto duration_2 = duration_cast<microseconds>(finish_2-start_2).count();
    //std::cout << "\nDecrypt time: "<< duration_2 << " microseconds"<< std::endl;
}

std::string vigenereCode(std::string p.word, std::string p.keyword) {
    unsigned int counterkeyword = 0, sizeOfkeyword = p.keyword.size();
    char codedChar;
    std::string codedString;
    unsigned int placeOfChar;
    if(alphabetOnly) {
        std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,-/!?<>{}[]^*+=#%";
        for(unsigned int i = 0; i < p.word.size(); i++) {                         //.,-/!?<>{}[]^*+=#%
            if((placeOfChar = alphabet.find(p.word[i])) == std::string::npos)  { return "Error, characters are not part of the following string : " + alphabet; }
            codedChar = (placeOfChar + p.keyword[counterkeyword]%53)%53;
            //std::cout << codedChar << std::endl;
            codedString += alphabet[codedChar];
            ++counterkeyword%=sizeOfkeyword;
        }
    } else {
        for(unsigned int i = 0; i < p.word.size(); i++) {
            codedChar = (p.word[i] + p.keyword[counterkeyword])%256;
            
            codedString += codedChar;
            ++counterkeyword%=sizeOfkeyword;
        }
    }
    return codedString;
}

std::string vigenereDecode(std::string p.word, std::string p.keyword) {
    unsigned int counterkeyword = 0, sizeOfkeyword = p.keyword.size();
    char decodedChar;
    std::string decodedString;
    unsigned int placeOfChar;
    if(alphabetOnly) {
        std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,-/!?’»<>{}[]^*+=#%’";
        for(unsigned int i = 0; i < p.word.size(); i++) {
            if((placeOfChar = alphabet.find(p.word[i])) == std::string::npos)  { return "Error, characters are not part of the following string : " + alphabet; }
            decodedChar = (placeOfChar - (p.keyword[counterkeyword]%53));
           // std::cout<< "1: " << (int)decodedChar << std::endl;
            if(decodedChar < 0)   { decodedChar+=53; }
            //std::cout<< "2: " << (int)decodedChar << std::endl;
            decodedString += alphabet[decodedChar];
            ++counterkeyword%=sizeOfkeyword;
        }
    } else {
        for(unsigned int i = 0; i < p.word.size(); i++) {
            decodedChar = (p.word[i] - p.keyword[counterkeyword]);
            if(decodedChar < 0)   { decodedChar+=256; }
            decodedString += decodedChar;
            ++counterkeyword%=sizeOfkeyword;
        }
    }
    return decodedString;
}
