#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Функція для створення файлу F1 з інформацією
void createFileF1(const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Помилка при відкритті файлу для запису!" << endl;
        return;
    }
    outFile << "Best\n";
    outFile << "Cities\n";
    outFile << "In\n";
    outFile << "Ukraine\n";
    outFile << "Are without a doubt:\n";
    outFile << "Ternopil\n";
    outFile << "Kyiv\n";
    outFile << "Odesa\n";
    outFile << "And\n";
    outFile << "Mykachevo\n";
    outFile.close();
}

// Функція для копіювання рядків з одним словом з F1 у F2
void copySingleWordLines(const string& fileF1, const string& fileF2) {
    ifstream inFile(fileF1);
    ofstream outFile(fileF2);
    if (!inFile || !outFile) {
        cerr << "Помилка при відкритті файлів!" << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string word;
        int wordCount = 0;
        while (ss >> word) {
            ++wordCount;
        }
        if (wordCount == 1) {
            outFile << line << "\n";
        }
    }
    inFile.close();
    outFile.close();
}

// Функція для знаходження найдовшого слова у файлі F2
string findLongestWordInFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Помилка при відкритті файлу для читання!" << endl;
        return "";
    }
    string longestWord;
    string line;
    while (inFile >> line) {
        if (line.length() > longestWord.length()) {
            longestWord = line;
        }
    }
    inFile.close();
    return longestWord;
}

int main() {
    const string fileF1 = "F1.txt";
    const string fileF2 = "F2.txt";

    // Створюємо файл F1
    createFileF1(fileF1);

    // Копіюємо рядки з одним словом з файлу F1 у файл F2
    copySingleWordLines(fileF1, fileF2);

    // Знаходимо найдовше слово у файлі F2
    string longestWord = findLongestWordInFile(fileF2);
    cout << "Найдовше слово у файлі F2: " << longestWord << endl;

    return 0;
}
