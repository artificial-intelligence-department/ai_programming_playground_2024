#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
using namespace std;

// Функція для створення текстового файлу F1 з 10 рядками
void createFileF1(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        return;
    }

    file << "Рядок 1: Це перший рядок.\n";
    file << "Рядок 2: У цьому рядку є кілька слів.\n";
    file << "Рядок 3: Програма на мові С++.\n";
    file << "Рядок 4: Це четвертий рядок файлу.\n";
    file << "Рядок 5: Голосні букви у реченні.\n";
    file << "Рядок 6: Приклад тексту для обробки.\n";
    file << "Рядок 7: Робота з файлами в C++.\n";
    file << "Рядок 8: Копіювання та підрахунок символів.\n";
    file << "Рядок 9: Завершення роботи програми.\n";
    file << "Рядок 10: Останній рядок у файлі.\n";

    file.close();
    cout << "Файл F1 створено.\n";
}

// Функція для копіювання рядків з K по K+5 з файлу F1 у файл F2
void copyLines(const string& fileF1, const string& fileF2, int K) {
    ifstream input(fileF1);
    ofstream output(fileF2);

    if (!input) {
        cerr << "Помилка відкриття файлу F1 для читання!" << endl;
        return;
    }
    if (!output) {
        cerr << "Помилка відкриття файлу F2 для запису!" << endl;
        return;
    }

    string line;
    int lineNumber = 0;

    while (getline(input, line)) {
        ++lineNumber;
        if (lineNumber >= K && lineNumber <= K + 5) {
            output << line << "\n";
        }
    }

    input.close();
    output.close();
    cout << "Рядки з файлу F1 успішно скопійовані до файлу F2.\n";
}

// Функція для підрахунку кількості голосних букв у файлі F2
int countVowels(const string& fileF2) {
    ifstream input(fileF2);
    if (!input) {
        cerr << "Помилка відкриття файлу F2 для читання!" << endl;
        return 0;
    }

    string vowels = "аеєиіїоуюяАЕЄИІЇОУЮЯaeiouAEIOU";
    string line;
    int vowelCount = 0;

    while (getline(input, line)) {
        for (char c : line) {
            if (vowels.find(c) != string::npos) {
                ++vowelCount;
            }
        }
    }

    input.close();
    return vowelCount;
}

// Головна функція для виконання програми
int main() {
    string fileF1 = "F1.txt";
    string fileF2 = "F2.txt";
    int K = 3; // Номер рядка, з якого починаємо копіювання

    // Створення файлу F1
    createFileF1(fileF1);

    // Копіювання рядків з K по K+5 у файл F2
    copyLines(fileF1, fileF2, K);

    // Підрахунок кількості голосних у файлі F2
    int vowelsCount = countVowels(fileF2);
    cout << "Кількість голосних букв у файлі F2: " << vowelsCount << endl;

    return 0;
}
