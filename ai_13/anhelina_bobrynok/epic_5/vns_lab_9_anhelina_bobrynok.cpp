#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Функція для перевірки, чи рядок починається і закінчується на одну й ту саму букву
bool startsAndEndsWithSameLetter(const string& line) {
    if (line.empty()) return false;
    char firstChar = line[0];
    char lastChar = line[line.size() - 1];
    return (tolower(firstChar) == tolower(lastChar)); 
}

int main() {
    const char* inputFilename = "F1.txt";
    const char* outputFilename = "F2.txt";

    // Відкриваємо файл F1 для читання
    ifstream inputFile(inputFilename);
    if (!inputFile) {
        cerr << "Помилка при відкритті файлу " << inputFilename << endl;
        return 1;
    }

    // Відкриваємо файл F2 для запису
    ofstream outputFile(outputFilename);
    if (!outputFile) {
        cerr << "Помилка при відкритті файлу " << outputFilename << endl;
        return 1;
    }

    string line;
    int totalChars = 0; // Лічильник символів у F2

    // Читання кожного рядка з файлу F1
    while (getline(inputFile, line)) {
        if (startsAndEndsWithSameLetter(line)) {
            outputFile << line << endl; 
            totalChars += line.size(); 
        }
    }

    inputFile.close();
    outputFile.close();

    // Виведення кількості символів у F2
    cout << "Кількість символів у файлі F2: " << totalChars << endl;

    return 0;
}
