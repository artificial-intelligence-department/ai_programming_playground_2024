#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool is_single_word(const string& line) {
    istringstream stream(line);
    string word;
    int count = 0;
    
    while (stream >> word) {
        count++;
    }
    return count == 1;
}

string find_longest(const string& line) {
    istringstream stream(line);
    string word, longest;
    while (stream >> word) {
        if (word.length() > longest.length()) {
            longest = word;
        }
    }
    return longest;
}

int main() {
    ofstream f1("F1.txt");

    if (!f1) {
        cerr << "Помилка при відкритті файлу F1.\n";
        return 1;
    }

    cout << "Введіть 10 рядків для запису в файл F1:\n";
    for (int i = 0; i < 10; ++i) {
        string line;
        getline(cin, line);
        f1 << line << "\n";
    }
    f1.close();

    ifstream f1_read("F1.txt");
    ofstream f2("F2.txt");

    if (!f1_read || !f2) {
        cerr << "Помилка при відкритті файлів F1 або F2.\n";
        return 1;
    }

    string line;
    while (getline(f1_read, line)) {
        if (is_single_word(line)) {
            f2 << line << "\n";
        }
    }
    f1_read.close();
    f2.close();

    ifstream f2_read("F2.txt");

    if (!f2_read) {
        cerr << "Помилка при відкритті файлу F2.\n";
        return 1;
    }

    string longest_word;
    while (getline(f2_read, line)) {
        string longest_in_line = find_longest(line);
        if (longest_in_line.length() > longest_word.length()) {
            longest_word = longest_in_line;
        }
    }
    cout << "Найдовше слово у файлі F2: " << longest_word << "\n";

    f2_read.close();
    return 0;
}
