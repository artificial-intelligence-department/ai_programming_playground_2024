#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

/*
1) Скопіювати з файлу F1 у файл F2 рядки, починаючи з N до K.
2) Підрахувати кількість приголосних букв у файлі F2.
*/

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

string getRandomLine() {
    string line = "         ";
    for(int i = 0; i < 10; i++) {
        line[i] = getRandomNumber(97, 122);
    }
    return line;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    fstream file("F1", ios::out | ios::trunc);
    if(file.is_open()) {
        for(int i = 0; i < 10; i++) {
            string line = getRandomLine();
            file << line << "\n";
        }
    } else {
        cout << "Error: file F1 is not opened;";
        exit(1);
    }
    file.close();

    file.open("F1", ios::in);
    if(!file.is_open()) {
        cout << "Error: file F2 is not opened for reading;";
        exit(1);
    }
    file.seekg(0, ios::beg);
    int n = getRandomNumber(2, 4), k = getRandomNumber(5, 9);
    cout << "We will copy lines from " << n << " to " << k;

    fstream file2("F2", ios::out | ios::trunc);
    if(file2.is_open()) {
        for(int i = 1; i <= k; i++) {
            string copy;
            getline(file, copy);
            if(i >= n) 
                file2 << copy << "\n";
        }
    } else {
        cout << "Error: file F2 is not opened;";
        exit(1);
    }
    file.close();
    file2.close();

    file2.open("F2", ios::in);
    if(!file2.is_open()) {
        cout << "Error: file F2 is not opened for reading;";
        exit(1);
    }

    char c;
    int num = 0;
    while(file2.get(c)) {
        switch(c) {
            case 'a':
            case 'o':
            case 'i':
            case 'u':
            case 'e': 
            case '\n': break;
            default: num++; break;
        }
    }

    cout << "\nWe have " << num << " consonant letters in F2";

    file2.close();
    return 0;
}