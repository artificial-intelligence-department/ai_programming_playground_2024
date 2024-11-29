#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Функція для перевірки наявності однакових слів у рядку
bool containsDuplicateWords(const string& line) {
    vector<string> words;
    stringstream ss(line);
    string word;
    
    while (ss >> word) {
        for (const auto& w : words) {
            if (w == word) {
                return true;
            }
        }
        words.push_back(word);
    }
    return false;
}

// Функція для пошуку індексу слова з найбільшою кількістю цифр
int findWordWithMostDigits(const string& line) {
    stringstream ss(line);
    string word;
    int maxDigits = 0;
    int wordIndex = -1;
    int currentIndex = 0;
    
    while (ss >> word) {
        int digitCount = 0;
        for (char c : word) {
            if (isdigit(c)) {
                digitCount++;
            }
        }
        if (digitCount > maxDigits) {
            maxDigits = digitCount;
            wordIndex = currentIndex;
        }
        ++currentIndex;
    }
    return wordIndex;
}

int main() {
    ifstream input("F1.txt");
    ofstream output("F2.txt");

    if (!input) {
        cerr << "Не вдалося відкрити вхідний файл." << endl;
        return 1;
    }

    if (!output) {
        cerr << "Не вдалося відкрити вихідний файл." << endl;
        return 1;
    }

    string line;
    while (getline(input, line)) {
        // Копіюємо рядки з дублікатами слів
        if (containsDuplicateWords(line)) {
            output << line << endl;
        }
    }

    input.clear(); // Очистити флаг помилки після завершення роботи з файлом
    input.seekg(0, ios::beg); // Повернутися на початок файлу для наступного проходу

    cout << "Номер слова з найбільшою кількістю цифр у кожному рядку:" << endl;
    while (getline(input, line)) {
        int index = findWordWithMostDigits(line);
        if (index == -1) {
            cout << "У рядку немає слів з цифрами" << endl;
        } else {
            cout << "Номер слова: " << index << endl;
        }
    }

    return 0;
}
