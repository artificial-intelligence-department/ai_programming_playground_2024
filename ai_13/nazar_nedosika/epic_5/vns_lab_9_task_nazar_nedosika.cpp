#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void createFileF1(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Не вдалося створити файл F1!\n";
        return;
    }
    cout << "Введіть рівно 10 рядків тексту:\n";

    string line;
    int count = 0;

    while (count < 10 && getline(cin, line)) {
        file << line << endl;
        count++;
    }

    file.close();
    cout << "Файл F1 успішно створено!\n";
}

void copyLines(const string& fileF1, const string& fileF2, int N1, int N2) {
    ifstream file1(fileF1);
    ofstream file2(fileF2);

    if (!file1 || !file2) {
        cout << "Не вдалося відкрити файли!\n";
        return;
    }

    string line;
    int lineNumber = 0;
    vector<string> copiedLines;

    while (getline(file1, line)) {
        lineNumber++;

        if (lineNumber >= N1 && lineNumber <= N2 && line.find('A') == string::npos && line.find('a') == string::npos) {
            file2 << line << endl;
            copiedLines.push_back(line);
        }
    }

    file1.close();
    file2.close();

    cout << "\nСкопійовані рядки:\n";
    for (const string& copiedLine : copiedLines) {
        cout << copiedLine << endl;
    }
}

int findLineWithMostVowels(const string& fileF2) {
    ifstream file(fileF2);
    if (!file) {
        cout << "Не вдалося відкрити файл F2!\n";
        return -1;
    }

    string line;
    int maxVowels = 0;
    int maxVowelLine = 0;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;
        int vowelCount = 0;

        for (char c : line) {
            if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' ||
                tolower(c) == 'o' || tolower(c) == 'u' || tolower(c) == 'y') {
                vowelCount++;
            }
        }

        if (vowelCount > maxVowels) {
            maxVowels = vowelCount;
            maxVowelLine = lineNumber;
        }
    }

    file.close();
    return maxVowelLine;
}

int main() {
    string fileF1 = "F1.txt";
    string fileF2 = "F2.txt";

    cout << "Створимо файл F1:\n";
    createFileF1(fileF1);

    int N1, N2;
    cout << "Введіть номер початкового рядка (N1): ";
    cin >> N1;
    cout << "Введіть номер кінцевого рядка (N2): ";
    cin >> N2;

    copyLines(fileF1, fileF2, N1, N2);

    int lineWithMostVowels = findLineWithMostVowels(fileF2);
    if (lineWithMostVowels != -1) {
        cout << "Номер рядка з найбільшою кількістю голосних у F2: " << lineWithMostVowels << endl;
    } else {
        cout << "Файл F2 порожній або не існує.\n";
    }

    return 0;
}
