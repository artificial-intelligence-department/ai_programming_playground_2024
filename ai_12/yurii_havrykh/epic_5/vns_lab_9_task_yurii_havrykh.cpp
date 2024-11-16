#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void createFileF1(const string &filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Помилка відкриття файлу F1 для запису." << endl;
        return;
    }

    vector<string> lines = {
            "Акація цвіте",
            "Вітер з моря",
            "Дерева у тіні",
            "Аромат весни",
            "Квітка розквітлA",
            "Сонце гріє землю",
            "Зелена трAвA",
            "Хвилі на морі",
            "Пісок гарячий",
            "Магнолія розквітлA"
    };

    for (auto line : lines) {
        file << line << endl;
    }

    file.close();
    cout << "Файл F1 створено." << endl;
}

void copyLinesToF2(const string &fileF1, const string &fileF2, int N1, int N2) {
    ifstream file1(fileF1);
    ofstream file2(fileF2);

    if (!file1) {
        cerr << "Помилка відкриття файлу F1 для читання." << endl;
        return;
    }
    if (!file2) {
        cerr << "Помилка відкриття файлу F2 для запису." << endl;
        return;
    }

    string line;
    int lineNumber = 0;

    while (getline(file1, line)) {
        lineNumber++;
        if (lineNumber >= N1 && lineNumber <= N2 && line.back() == 'A') {
            file2 << line << endl;
        }
    }

    file1.close();
    file2.close();
    cout << "Рядки скопійовано у файл F2." << endl;
}

int findLineWithMaxA(const string &fileF2) {
    ifstream file(fileF2);

    if (!file) {
        cerr << "Помилка відкриття файлу F2 для читання." << endl;
        return -1;
    }

    string line;
    int lineNumber = 0, maxLineNumber = -1, maxACount = 0;

    while (getline(file, line)) {
        lineNumber++;
        int aCount = 0;
        for (char ch : line) {
            if (ch == 'A'){
                aCount++;
            }
        }
        if (aCount > maxACount) {
            maxACount = aCount;
            maxLineNumber = lineNumber;
        }
    }

    file.close();
    return maxLineNumber;
}

int main() {
    const string fileF1 = "F1.txt";
    const string fileF2 = "F2.txt";

    createFileF1(fileF1);

    int N1, N2;
    cout << "Введіть номер рядка N1, N2: ";
    cin >> N1>>N2;

    copyLinesToF2(fileF1, fileF2, N1, N2);


    int maxLine = findLineWithMaxA(fileF2);
    if (maxLine != -1) {
        cout << "Номер рядка з найбільшою кількістю 'А' у файлі F2: " << maxLine << endl;
    } else {
        cout << "Файл F2 порожній або не знайдено рядків." << endl;
    }

    return 0;
}
