#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    const int MAX_LENGTH = 256;
    char input[MAX_LENGTH];

    cout << "Enter the sentence (with a period) : ";
    gets(input);

    if (input[strlen(input) - 1] != '.')
    {
        cout << "You need to enter sentence with a period. " << endl;
        return 1;
    }

    stringstream ss(input);
    string word;
    vector<string> words;

    while (ss >> word) {
        if (word.back() == '.') {
            word.pop_back();
        }
        words.push_back(word);
    }

    cout << "Result : ";
    for (size_t i = 0; i < words.size(); ++i) {
        if (i % 2 == 0) {
            cout << words[i] << " ";
        }
    }
    cout << endl;
    return 0;
}