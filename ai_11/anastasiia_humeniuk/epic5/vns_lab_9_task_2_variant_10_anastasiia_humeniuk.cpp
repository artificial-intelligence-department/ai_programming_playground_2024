#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <climits>

using namespace std;

#define MAX_WORDS 50
#define MAX_LINE_LENGTH 256

bool has_same_starting_letter(char line[]) {
    char* words[MAX_WORDS];
    int word_count = 0;

    char* token = strtok(line, " \n");
    while (token != NULL && word_count < MAX_WORDS) {
        words[word_count++] = token;
        token = strtok(NULL, " \n");
    }

    for (int i = 0; i < word_count - 1; ++i) {
        for (int j = i + 1; j < word_count; ++j) {
            if (tolower(words[i][0]) == tolower(words[j][0])) {
                return true; // Якщо слова мають однакову першу букву
            }
        }
    }
    return false; // Якщо всі перші букви різні
}

void print_shortest_word_in_file(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Не вдалося відкрити файл " << filename << ".\n";
        return;
    }

    string shortest_word;
    string word;
    size_t min_length = INT_MAX;

    while (file >> word) {
        if (word.length() < min_length) {
            min_length = word.length();
            shortest_word = word;
        }
    }

    file.close();

    if (!shortest_word.empty()) {
        cout << "Найкоротше слово в файлі " << filename << ": " << shortest_word << endl;
    } else {
        cout << "Файл " << filename << " порожній або не містить слів.\n";
    }
}

int main() {
    ifstream inputFile("F1.txt");
    if (!inputFile) {
        cerr << "Не вдалося відкрити файл F1.txt.\n";
        return 1;
    }

    ofstream outputFile("F2.txt");
    if (!outputFile) {
        cerr << "Не вдалося створити файл F2.txt.\n";
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    while (inputFile.getline(line, MAX_LINE_LENGTH)) {
        char line_copy[MAX_LINE_LENGTH];
        strcpy(line_copy, line);

        if (!has_same_starting_letter(line_copy)) {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    print_shortest_word_in_file("F2.txt");

    return 0;
}
