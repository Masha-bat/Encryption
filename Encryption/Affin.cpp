#include "Affin.h"



template <typename temp> temp GetCorrectNumber(temp min, temp max) {
    temp x{};
    while ((std::cin >> x).fail() || x < min || x > max) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Enter a valid number!" << std::endl;
    }
    return x;
}

int search1(char a, const std::string& alphabet) {
    int j = 0;
    while (alphabet.at(j) != a) {
        if (j + 1 < (alphabet.size()))
            j++;
        else
            return -1;
    }
    return j;
}

int NOD(int a, int b) {
    int result;
    for (int i = a; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            result = i;
            break;
        }
    }
    return result;
}



int Evklid(int a, int b, int c) {
    int otvet[4];
    int bb = b, x_2 = 1, x_1 = 0, y_2 = 0, y_1 = 1, x = 0, y = 0, q = 0, r = 0;
    while (b > 0) {
        q = a / b;
        r = a % b;
        x = x_2 - q * x_1;
        y = y_2 - q * y_1;

        a = b;
        b = r;
        x_2 = x_1;
        x_1 = x;
        y_2 = y_1;
        y_1 = y;
    }

    otvet[0] = (x % bb); //остаток от деления
    otvet[1] = x_2;
    otvet[2] = y_2;
    otvet[3] = b;
    if (c == 0) return otvet[0];
    else {
        if (c == 1) return otvet[1];
        else {
            if (c == 2) return otvet[2];
            else return otvet[3];
        }
    }
}

std::string Zashifr(const std::string& alphabet, const std::string& word_to_shifr, const int& alfa, const int& beta) {
    //std::cout << "Input random number (<Alphabet size):" << std::endl;
    //int beta = GetCorrectNumber(0, (int)alphabet.size() - 1);
    int j;
    std::string shifr_result;
    //std::cout << "Enter word to shifr:" << std::endl;
    //std::cin >> word_to_shifr;
    //auto start_1 = std::chrono::system_clock::now();
    for (int i = 0; i < word_to_shifr.size(); i++) {
        j = search1(word_to_shifr.at(i), alphabet);                                        //ищем положение i-го символа в нашем алфавите
        if (j == -1)
            shifr_result += word_to_shifr.at(i);
        else {
            shifr_result += alphabet.at(((alfa * j) + beta) % (alphabet.size()));  //дописываем в переменную out символ с расчитанным положением в алфавите
        }
    }
    //auto finish_1 = std::chrono::system_clock::now();
    //auto duration_1 = std::chrono::duration_cast<std::chrono::microseconds>(finish_1 - start_1).count();
    //std::cout << "Time shifr(mcrs): " << duration_1 << std::endl;;
    return shifr_result;
}

std::string Rashif(const std::string& shifr, const std::string& alphabet) {
    std::cout << "Input key(two values)" << std::endl;
    int alfa_1 = Evklid(GetCorrectNumber(1, (int)alphabet.size() - 1), (int)alphabet.size(), 1);
    int beta = GetCorrectNumber(0, (int)alphabet.size() - 1);
    int j;
    std::string word_result;
    auto start_1 = std::chrono::system_clock::now();
    for (int i = 0; i < shifr.size(); i++) {
        j = search1(shifr.at(i), alphabet);        //ищем положение i-го символа в нашем алфавите
        if (j == -1)
            word_result += shifr.at(i);
        else {
            int p = (alfa_1 * (j - beta)) % (alphabet.size());
            if ((alfa_1 * (j - beta)) < 0) {
                p = (abs((alfa_1 * (j - beta))) % ((int)alphabet.size())) * -1 + (int)alphabet.size();
            }
            word_result += alphabet.at(p);       //  дописываем в переменную out символ с расчитанным положением в алфавите
        }
    }
    auto finish_1 = std::chrono::system_clock::now();
    auto duration_1 = std::chrono::duration_cast<std::chrono::microseconds>(finish_1 - start_1).count();
    std::cout << "Time rashifr(mcrs): " << duration_1 << std::endl;
    return word_result;
}

void Affin_method(const std::string& word_to_shifr, Encryption p)
{
    int alfa = p.a;
    int beta = p.b;
    std::string alphabet = "\n !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    std::cout << "Alphabet size: " << alphabet.size() << std::endl;
    //std::cout << "Input simple number of alphabet size:" << std::endl;
    //int alfa = GetCorrectNumber(1, (int)alphabet.size() - 1);
    while (NOD(alfa, (int)alphabet.size()) != 1) {
        std::cout << "Input correct number key!" << std::endl;
        alfa = GetCorrectNumber(1, (int)alphabet.size() - 1);
    }
    //std::cout << "Input random number (<Alphabet size):" << std::endl;
    //int beta = GetCorrectNumber(0, (int)alphabet.size() - 1);
    std::string shifr = Zashifr(alphabet, word_to_shifr, alfa, beta);
    std::cout << "Output shifr: " << shifr << std::endl;
    std::cout << "Try to rashifr our shifr:" << std::endl;
    std::string word_after_rashifr = Rashif(shifr, alphabet);
    while (word_after_rashifr != word_to_shifr) {
        std::cout << "Rashifr word: " << word_after_rashifr << std::endl;
        std::cout << "Rashifr is not equal word to shifr, new try:" << std::endl;
        word_after_rashifr = Rashif(shifr, alphabet);
    }
    std::cout << "Rashifr correct word: " << word_after_rashifr << std::endl;
}