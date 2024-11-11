#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

void create_file_F1(const std::string &filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cout << "Error: Cannot open file " << filename << " for writing.\n";
        return;
    }
    // Записуємо 10 прикладних рядків у файл
    file << "The quick brown fox jumps over the lazy dog.\n";
    file << "Hello world program example.\n";
    file << "Data science and machine learning.\n";
    file << "Lorem ipsum hello.\n";
    file << "Machine learning and data analysis.\n";
    file << "Example of the unique words.\n";
    file << "Programming in C++ and Python.\n";
    file << "Find the shortest word in the text.\n";
    file << "File handling in C++ is straightforward.\n";
    file << "This is a simple example text.\n";
    file.close();
}

bool has_words_starting_with_same_letter(const std::string &line) {
    std::istringstream stream(line);
    std::set<char> first_letters;
    std::string word;
    while (stream >> word) {
        char first_letter = tolower(word[0]);
        if (first_letters.count(first_letter)) {
            return true; // Знайшли дублюючі початкові букви
        }
        first_letters.insert(first_letter);
    }
    return false;
}

void copy_to_F2(const std::string &F1, const std::string &F2) {
    std::ifstream file1(F1);
    std::ofstream file2(F2);

    if (!file1 || !file2) {
        std::cout << "Error: Cannot open files for copying.\n";
        return;
    }

    std::string line;
    while (std::getline(file1, line)) {
        if (!has_words_starting_with_same_letter(line)) {
            file2 << line << "\n";
        }
    }

    file1.close();
    file2.close();
}

std::string find_shortest_word(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error: Cannot open file " << filename << " for reading.\n";
        return "";
    }

    std::string shortest_word;
    int min_length = INT_MAX;
    std::string word;

    while (file >> word) {
        if (word.length() < min_length) {
            min_length = word.length();
            shortest_word = word;
        }
    }

    file.close();
    return shortest_word;
}

int main() {
    std::string F1 = "F1.txt";
    std::string F2 = "F2.txt";

    create_file_F1(F1);
    std::cout << "File F1 created and filled with data.\n";

    copy_to_F2(F1, F2);
    std::cout << "Lines copied from F1 to F2 based on the condition.\n";

    std::string shortest_word = find_shortest_word(F2);
    if (!shortest_word.empty()) {
        std::cout << "The shortest word in F2 is: " << shortest_word << "\n";
    } else {
        std::cout << "No words found in file F2.\n";
    }

    return 0;
}
