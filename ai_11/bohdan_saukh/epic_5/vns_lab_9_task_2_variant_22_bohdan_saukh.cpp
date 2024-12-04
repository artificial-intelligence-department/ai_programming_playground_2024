#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

bool is_single_word(const string& line) {
    stringstream ss(line);
    string word;
    int count = 0;
    while (ss >> word) {
        count++;
    }
    return count == 1;
}

int count_consonants(const string& word) {
    string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    int count = 0;
    for (char ch : word) {
        if (consonants.find(ch) != string::npos) {
            count++;
        }
    }
    return count;
}

int main() {
    const char* file1 = "F1.txt";
    const char* file2 = "F2.txt";

    ofstream outFile(file1);
    outFile << "Apple\n"
            << "Orange banana pear\n"
            << "my headphones\n"
            << "Car\n"
            << "Computer mouse\n"
            << "Keyboard\n"
            << "laptop\n"
            << "Coffe\n"
            << "Cup\n"
            << "Cup of coffe\n";
    outFile.close();

    ifstream inFile(file1);
    ofstream outFile2(file2);

    string line;
    while (getline(inFile, line)) {
        if (is_single_word(line)) {
            outFile2 << line << endl;
        }
    }
    inFile.close();
    outFile2.close();

    cout << "Рядки з одним словом скопійовано у файл F2." << endl;

    ifstream inFileForConsonants(file1);
    string best_word;
    int max_consonants = 0;

    while (getline(inFileForConsonants, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            int consonant_count = count_consonants(word);
            if (consonant_count > max_consonants) {
                max_consonants = consonant_count;
                best_word = word;
            }
        }
    }

    inFileForConsonants.close();

    cout << "Слово з найбільшою кількістю приголосних: " << best_word << endl;

    return 0;
}
