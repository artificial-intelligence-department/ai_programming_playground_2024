#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <map>

using namespace std;

// Files: 
// input.txt
// output.txt
// capitalized_words.txt

int main() {
    string input, output, capitalized_words;

    cout << "Enter name of input file: ";
    getline(cin, input);
    cout << "Enter name of output file: ";
    getline(cin, output);
    cout << "Enter name of capitalized words file: ";
    getline(cin, capitalized_words);

    ifstream inputFile(input);
    ofstream outputFile(output);
    ofstream capitalizedWordsFile(capitalized_words);

    if (!inputFile.is_open() || !outputFile.is_open() || !capitalizedWordsFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }
    
    string line;
    int lineCount = 0, wordCount = 0, charCount = 0;
    vector<string> capitalizedWords; 

    while (getline(inputFile, line)) {
        lineCount++; 
        charCount += line.size() + 1; 
        string word = "";  

        for (char ch : line) {
            if (isalnum(ch)) {
                word += ch;
            } else {
                if (!word.empty()) {
                    wordCount++;  

                    if (isupper(word[0])) {
                        capitalizedWords.push_back(word); 
                    }
                    word = "";  
                }
            }
        }

        if (!word.empty()) {
            wordCount++;
            if (isupper(word[0])) {
                capitalizedWords.push_back(word);
            }
        }
    }

    outputFile << "Lines: " << lineCount << endl;
    outputFile << "Words: " << wordCount << endl;
    outputFile << "Chars: " << charCount << endl;

    for (const string &word : capitalizedWords) {
        capitalizedWordsFile << word << endl;
    }

    inputFile.close();
    outputFile.close();
    capitalizedWordsFile.close();

    cout << "Everything is written." << endl;
    return 0;
}
