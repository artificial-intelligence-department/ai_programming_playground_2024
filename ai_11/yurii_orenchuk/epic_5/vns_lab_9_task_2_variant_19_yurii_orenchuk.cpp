#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

bool consonant_check(char c) {
    return isalpha(c) && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    cout << "Enter the contents for source.txt (type 'END' to finish):\n";
    ofstream sourceFile("source.txt");
    if (!sourceFile.is_open()) {
        cout << "Failed to create/open source.txt file\n";
        return 1;
    }

    string userInput;
    while (getline(cin, userInput)) {
        if (userInput == "END") break;
        sourceFile << userInput << endl;
    }
    sourceFile.close();

    ifstream readFile("source.txt");
    if (!readFile.is_open()) {
        cout << "Failed to open source.txt file\n";
        return 1;
    }

    ofstream writeFile("final.txt");
    if (!writeFile.is_open()) {
        cout << "Failed to open final.txt file\n";
        return 1;
    }

    string line;
    string firstWord;
    int consonantCount = 0;

    if (getline(readFile, line)) {
        istringstream iss(line);
        if (iss >> firstWord) {
            for (char c : line) {
                if (consonant_check(c)) {
                    consonantCount++;
                }
            }
        }
        writeFile << line << endl;
    }

    while (getline(readFile, line)) {
        if (line.empty()) continue;

        if (line.find(firstWord) != string::npos) {
            continue;
        }

        writeFile << line << endl;
    }

    writeFile << "Amount of consonants in 1st line: " << consonantCount << endl;

    readFile.close();
    writeFile.close();

    return 0;
}