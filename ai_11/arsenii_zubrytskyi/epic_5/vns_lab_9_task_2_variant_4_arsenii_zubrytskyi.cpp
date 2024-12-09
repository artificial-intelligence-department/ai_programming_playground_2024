#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Функція для копіювання рядків з F1 у F2, починаючи з 4-го
void copyLinesFromFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Помилка відкриття файлу " << inputFile << endl;
        return;
    }

    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Помилка відкриття файлу " << outputFile << endl;
        return;
    }

    string line;
    int lineCount = 0;

    // Читаємо рядки з файлу і записуємо в F2, починаючи з 4-го
    while (getline(inFile, line)) {
        lineCount++;
        if (lineCount >= 4) {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();
}

// Функція для підрахунку кількості символів в останньому слові файлу
int countLastWordLength(const string& fileName) {
    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Помилка відкриття файлу " << fileName << endl;
        return 0;
    }

    string line;
    string lastWord;
    while (getline(inFile, line)) {
        // Розбиваємо рядок на слова
        stringstream ss(line);
        string word;
        while (ss >> word) {
            lastWord = word;  // Оновлюємо останнє слово
        }
    }

    inFile.close();

    // Повертаємо довжину останнього слова
    return lastWord.length();
}

int main() {
    const string inputFile = "F1.txt";
    const string outputFile = "F2.txt";

    // Створюємо файл F1 і записуємо в нього інформацію
    ofstream outFile(inputFile);
    if (!outFile) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        return 1;
    }

    // Записуємо 10 рядків у файл F1
    outFile << "Перше слово" << endl;
    outFile << "Друге слово" << endl;
    outFile << "Третє слово" << endl;
    outFile << "Четверте слово" << endl;
    outFile << "П'яте слово" << endl;
    outFile << "Шосте слово" << endl;
    outFile << "Сьоме слово" << endl;
    outFile << "Восьме слово" << endl;
    outFile << "Дев'яте слово" << endl;
    outFile << "Десяте слово" << endl;

    outFile.close();

    // Копіюємо рядки з F1 у F2, починаючи з 4-го
    copyLinesFromFile(inputFile, outputFile);
    cout << "Рядки скопійовано з F1 в F2, починаючи з 4-го." << endl;

    // Підраховуємо кількість символів в останньому слові файлу F2
    int lastWordLength = countLastWordLength(outputFile);
    cout << "Кількість символів в останньому слові файлу F2: " << lastWordLength << endl;

    return 0;
}
