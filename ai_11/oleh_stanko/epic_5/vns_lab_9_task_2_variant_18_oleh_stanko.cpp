#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool has_duplicate_words(const string& line) {
    istringstream iss(line);
    unordered_set<string> word_set;
    string word;

    while (iss >> word) {
        if (word_set.find(word) != word_set.end()) {
            return true; 
        }
        word_set.insert(word);
    }
    return false; 
}

void copy_unique_lines(const char* file_from, const char* file_to) {
    ifstream inFile(file_from);
    if (!inFile.is_open()) {
        cerr << "Error opening source file for reading!\n";
        return;
    }

    ofstream outFile(file_to);
    if (!outFile.is_open()) {
        cerr << "Error opening destination file for writing!\n";
        return;
    }

    string line;
    while (getline(inFile, line)) {
        if (!has_duplicate_words(line)) {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();
}

int count_vowels(const string& line) {
    int count = 0;
    for (char c : line) {
        c = tolower(c); 
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            count++;
        }
    }
    return count;
}

void add_some_lines(const char* file1) {
    ofstream outFile(file1, ios::app);
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing!\n";
        return;
    }

    string line;
    int n;
    cout << "Enter the number of lines you want to add: ";
    cin >> n;
    cin.ignore(); 
    cout << "Enter the lines you want to add:\n";
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        outFile << line << endl;
    }
    outFile.close();
}

void process_file(const char* file1, const char* file2) {
    add_some_lines(file1);
    copy_unique_lines(file1, file2);

    cout << "Content of " << file2 << ":\n";
    ifstream debugFile(file2);
    string debugLine;
    while (getline(debugFile, debugLine)) {
        cout << debugLine << endl;
    }
    debugFile.close();

    ifstream inFile(file2);
    if (!inFile.is_open()) {
        cerr << "Error opening destination file for reading!\n";
        return;
    }

    string line;
    int lineNumber = 1; 
    while (getline(inFile, line)) {
        int vowel_count = count_vowels(line);
        cout << "Number of vowels in line " << lineNumber << " of " << file2 << ": " << vowel_count << endl;
        lineNumber++;
    }

    inFile.close();
}

int main() {
    const char* file1 = "F1.txt";
    const char* file2 = "F2.txt";

    process_file(file1, file2);

    return 0;
}
