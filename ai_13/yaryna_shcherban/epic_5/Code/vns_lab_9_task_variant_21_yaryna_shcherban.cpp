#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int countVowels(const string& word) {
    int count = 0;
    for (char c : word) {
        c = tolower(c); 
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            count++;
        }
    }
    return count;
}


void processFiles(const string& inputFile) {
    ifstream inFile(inputFile);

    if (!inFile) {
        cerr << "Error: Unable to open input file." << endl;
        return;
    }

    string line;
    string maxVowelWord;
    int maxVowelCount = 0;
    int lineNumber = 0;
    int currentLineNumber = 0;

    while (getline(inFile, line)) {
        currentLineNumber++;
        istringstream iss(line);
        string word;

        while (iss >> word) {
            int vowelCount = countVowels(word); 
            if (vowelCount > maxVowelCount) {
                maxVowelCount = vowelCount;
                maxVowelWord = word;
                lineNumber = currentLineNumber; 
            }
        }
    }

    inFile.close();

    if (maxVowelCount > 0) {
        cout << "The word with the most vowels: '" << maxVowelWord 
             << "' (number of vowels: " << maxVowelCount 
             << ") in line number " << lineNumber << "." << endl;
    } else {
        cout << "No words with vowels found. " << endl;
    }
}

int main() {

    ofstream f1("F1.txt");
    if (!f1) {
        cerr << "Error: Unable to create file F1." << endl;
        return 1;
    } 
    string line;
    cout << "Enter lines to write to file (type 'exit' to finish):" << endl;

    while (true) {
        getline(cin, line); 
        if (line == "exit") { 
            break;
        }
        f1 << line << endl; 
    }
    f1.close(); 

    cout << "The lines have been successfully written to the F1.txt file." << endl;
    processFiles("F1.txt");

    return 0;
}