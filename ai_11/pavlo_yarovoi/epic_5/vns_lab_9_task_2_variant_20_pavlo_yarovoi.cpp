#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <cctype>
using namespace std;

bool hasDuplicateWords(const string& line) {
    istringstream stream(line);
    string word;
    set<string> words;
    while (stream >> word) {
        if (words.count(word)) {
            return true;
        }
        words.insert(word);
    }
    return false;
}

int countVowels(const string& line) {
    const string vowels = "AEIOUYaeiouy"; 
    int count = 0;
    for (char c : line) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }
    return count;
}

int main() {
    const char* file1 = "F1.txt";
    const char* file2 = "F2.txt";

    ofstream f1(file1);
    if (!f1) {
        cerr << "Error: Cannot create F1." << endl;
        return 1;
    }

    cout << "Enter at least 10 lines for F1. Type 'END' to finish:" << endl;
    vector<string> lines;
    string inputLine;
    while (getline(cin, inputLine)) {
        if (inputLine == "END") break;
        lines.push_back(inputLine);
    }

    if (lines.size() < 10) {
        cerr << "Error: At least 10 lines are required." << endl;
        return 1;
    }

    for (const auto& line : lines) {
        f1 << line << endl;
    }
    f1.close();

    ifstream f1Input(file1);
    ofstream f2(file2);
    if (!f1Input || !f2) {
        cerr << "Error: Cannot open files." << endl;
        return 1;
    }

    string line;
    vector<string> f2Lines;
    while (getline(f1Input, line)) {
        if (hasDuplicateWords(line)) {
            f2 << line << endl;
            f2Lines.push_back(line);
        }
    }

    f1Input.close();
    f2.close();

    if (f2Lines.empty()) {
        cout << "F2 is empty, no duplicate words found." << endl;
    } else {
        string lastLine = f2Lines.back();
        int vowelCount = countVowels(lastLine);
        cout << "Number of vowels in the last line of F2: " << vowelCount << endl;
    }

    return 0;
}
