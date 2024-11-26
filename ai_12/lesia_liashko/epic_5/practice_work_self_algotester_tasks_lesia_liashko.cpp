#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createInputFile(const string& inputFile) {
    ofstream inFile(inputFile);

    if (!inFile) {
        cout << "Не вдалося створити вхідний файл!" << endl;
        return;
    }

    inFile << "# Це коментар" << endl;
    inFile << "Це перший рядок" << endl;
    inFile << "Другий рядок" << endl;
    inFile << endl;
    inFile << "# Ще один коментар" << endl;
    inFile << "Третій рядок" << endl;
    inFile << "Четвертий рядок" << endl;

    inFile.close();
}

void processFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile) {
        cout << "Не вдалося відкрити вхідний файл: " << inputFile << endl;
        return;
    }

    if (!outFile) {
        cout << "Не вдалося створити вихідний файл: " << outputFile << endl;
        return;
    }

    string line;
    int removedLines = 0;
    int totalLines = 0;

    while (getline(inFile, line)) {
        totalLines++;
        if (line.empty() || line[0] == '#') {
            removedLines++;
            continue;
        }
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    cout << "Загальна кількість рядків: " << totalLines << endl;
    cout << "Кількість видалених рядків: " << removedLines << endl;

    cout << "\nТекст у файлі " << outputFile << ":\n";
    ifstream resultFile(outputFile);
    while (getline(resultFile, line)) {
        cout << line << endl;
    }
    resultFile.close();
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    cout << "Створюємо вхідний файл " << inputFile << "...\n";
    createInputFile(inputFile);

    processFile(inputFile, outputFile);

    return 0;
}
