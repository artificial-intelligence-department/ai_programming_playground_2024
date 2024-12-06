#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <cctype>

using namespace std;

int countVowels(const string& word) {
    int count = 0;
    string vowels = "aeiouAEIOU";
    for (int i = 0; i < word.length(); ++i) {
        char c = word[i];
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }
    return count;
}

int main() {
    ofstream fileF1("F1.txt");
    fileF1 << "This is a sample line." << endl;
    fileF1 << "Hello world!" << endl;
    fileF1 << "C++ programming is fun." << endl;
    fileF1 << "Short sentence." << endl;
    fileF1 << "Another example of text." << endl;
    fileF1 << "How are you today?" << endl;
    fileF1 << "A simple test case." << endl;
    fileF1 << "One more line to go." << endl;
    fileF1 << "We need more lines." << endl;
    fileF1 << "Finally, the last line." << endl;
    fileF1.close();

    ifstream fileIn("F1.txt");
    ofstream fileF2("F2.txt");

    string line;
    int globalMaxVowelCount = 0;
    string wordWithMostVowels;

    while (getline(fileIn, line)) {
        istringstream iss(line);
        vector<string> words((istream_iterator<string>(iss)), istream_iterator<string>());

        if (words.size() > 2) {
            fileF2 << line << endl;
        }

        for (size_t i = 0; i < words.size(); ++i) {
            int vowelCount = countVowels(words[i]);
            if (vowelCount > globalMaxVowelCount) {
                globalMaxVowelCount = vowelCount;
                wordWithMostVowels = words[i];
            }
        }
    }

    fileIn.close();
    fileF2.close();

    cout << "Word with the most vowels: " << wordWithMostVowels 
         << " (vowels: " << globalMaxVowelCount << ")" << endl;

    return 0;
}
