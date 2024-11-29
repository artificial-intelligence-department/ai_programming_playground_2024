#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

bool hasDuplicateWords(const string& line) {
    unordered_set<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);          
        if (!words.insert(word).second) {
            return true;
        }
    }
    return false;
}

int countVowels(const string& line) {
    const string vowels = "aeiouAEIOU";
    return count_if(line.begin(), line.end(), [&vowels](char ch) { return vowels.find(ch) != string::npos; });
}

void createAndWriteToFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == nullptr) {
        cerr << "Не вдалося відкрити файл для запису." << endl;
        exit(1);
    }

    const char* lines[] = {
        "This is a test line.\n",
        "This line contains duplicate duplicate words.\n",
        "Unique line is here.\n",
        "Another line line with duplicates.\n",
        "Programming is fun and rewarding.\n",
        "Learn to code and build something fun 'yep'.\n",
        "Building projects is fun fun fun.\n",
        "You must broaden your mindset in order to become powerful\n",
        "Growth is lifelong lifelong journey.\n",
        "Easter egg:(=+=PRESS F TO PAY RESPECT=+=).\n"
    };

    for (const char* line : lines) {
        fputs(line, file);
    }

    cout << "Дані успішно записані у файл " << filename << endl;
    fclose(file);
}

void printFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        cerr << "Не вдалося відкрити файл для читання." << endl;
        exit(2);
    }

    char line[256];
    cout << "Вміст файлу " << filename << ":\n";
    cout << "---------------------------------\n";
    while (fgets(line, sizeof(line), file)) {
        cout << line;
    }
    fclose(file);
}

void createNewFileWithNoDuplicates(const char* fromFileName, const char* toFileName) {
    ifstream from(fromFileName);
    ofstream to(toFileName);

    if (!from || !to) {
        cerr << "Не вдалося відкрити файл для читання або запису." << endl;
        exit(3);
    }

    string line;
    while (getline(from, line)) {
        if (!hasDuplicateWords(line)) {
            to << line << endl;
        }
    }

    cout << "Рядки без повторюваних слів успішно скопійовані у файл " << toFileName << endl;
}

int countVowelsInFirstLine(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Не вдалося відкрити файл для читання." << endl;
        exit(4);
    }

    string line;
    if (getline(file, line)) {
        return countVowels(line);
    }
    return 0;
}

int main() {
    const char* filename1 = "F1.txt";
    const char* filename2 = "F2.txt";

    createAndWriteToFile(filename1);

    printFile(filename1);

    createNewFileWithNoDuplicates(filename1, filename2);

    printFile(filename2);

    cout << endl
         << "Кількість голосних у першому рядку файлу F2: " << countVowelsInFirstLine(filename2) << endl;

    return 0;
}
