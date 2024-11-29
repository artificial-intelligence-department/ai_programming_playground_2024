#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Функція для підрахунку кількості приголосних у рядку
int countConsonants(const string& line) {
    int count = 0;
    for (char c : line) {
        char lower = tolower(c);
        if (isalpha(lower) && !(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u' || lower == 'y')) {
            count++;
        }
    }
    return count;
}

int main() {
    
    ofstream fileF1("F1.txt");
    if (!fileF1.is_open()) {
        cerr << "Помилка при створенні файлу F1.txt" << endl;
        return 1;
    }

    
    fileF1 << "This is the first line.\n";
    fileF1 << "The second line.\n";
    fileF1 << "The third line.\n";
    fileF1 << "The fourth line.\n";
    fileF1 << "This is the fifth line.\n";
    fileF1 << "The sixth line.\n";
    fileF1 << "The seventh line.\n";
    fileF1 << "The eighth line.\n";
    fileF1 << "The ninth line.\n";
    fileF1 << "Tenth line.\n";
    fileF1.close();

    
    ifstream fileF1Read("F1.txt");
    ofstream fileF2("F2.txt");
    if (!fileF1Read.is_open() || !fileF2.is_open()) {
        cerr << "Помилка при відкритті файлів." << endl;
        return 1;
    }

    int N = 3, K = 6;
    string line;
    int lineNumber = 0;

    while (getline(fileF1Read, line)) {
        lineNumber++;
        if (lineNumber >= N && lineNumber <= K) {
            fileF2 << line << '\n';
        }
    }

    fileF1Read.close();
    fileF2.close();

    ifstream fileF2Read("F2.txt");
    if (!fileF2Read.is_open()) {
        cerr << "Помилка при відкритті файлу F2.txt" << endl;
        return 1;
    }

    int consonantCount = 0;
    while (getline(fileF2Read, line)) {
        consonantCount += countConsonants(line);
    }
    fileF2Read.close();

    cout << "Кількість приголосних у файлі F2: " << consonantCount << endl;

    return 0;
}
