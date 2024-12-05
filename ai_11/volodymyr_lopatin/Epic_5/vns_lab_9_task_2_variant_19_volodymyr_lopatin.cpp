#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int countConsonants(const string& line) {
    int consonants = 0;
    for (char ch : line) {
        if (isalpha(ch)) {
            char lower = tolower(ch);
            if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
                consonants++;
            }
        }
    }
    return consonants;
}

int main() {
    ofstream fileF1("F1.txt");
    if (fileF1.is_open()) {
        fileF1 << "apple banana cherry\n";
        fileF1 << "orange apple grape\n";
        fileF1 << "pear plum apple\n";
        fileF1 << "banana orange pear\n";
        fileF1 << "mango kiwi peach\n";
        fileF1 << "lemon lime orange\n";
        fileF1 << "grape banana kiwi\n";
        fileF1 << "strawberry orange lemon\n";
        fileF1 << "blueberry peach mango\n";
        fileF1 << "pineapple cherry grape\n";
        fileF1.close();
    }

    ifstream fileF1Read("F1.txt");
    ofstream fileF2("F2.txt");
    vector<string> filteredLines;
    if (fileF1Read.is_open() && fileF2.is_open()) {
        string line;
        while (getline(fileF1Read, line)) {
            istringstream iss(line);
            string firstWord;
            iss >> firstWord;

            string word;
            bool hasDuplicate = false;
            while (iss >> word) {
                if (word == firstWord) {
                    hasDuplicate = true;
                    break;
                }
            }
            if (!hasDuplicate) {
                filteredLines.push_back(line);
                fileF2 << line << "\n";
            }
        }
        fileF1Read.close();
        fileF2.close();
    }

    if (!filteredLines.empty()) {
        int consonantsCount = countConsonants(filteredLines[0]);
        cout << consonantsCount << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}
