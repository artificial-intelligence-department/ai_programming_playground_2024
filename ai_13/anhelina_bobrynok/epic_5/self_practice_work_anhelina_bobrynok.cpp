#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

map<char, int> countLetters(const string& s) {
    map<char, int> freq;
    for (char c : s) {
        ++freq[c];
    }
    return freq;
}

int main() {
    string targetWord;
    cin >> targetWord;

    int n;
    cin >> n;

    map<char, int> totalLetters;

    for (int i = 0; i < n; ++i) {
        string sign;
        cin >> sign;
        for (char c : sign) {
            ++totalLetters[c];
        }
    }

    map<char, int> targetFreq = countLetters(targetWord);

    int minCount = INT_MAX;
    for (auto& [letter, count] : targetFreq) {
        if (totalLetters[letter] == 0) {
            minCount = 0; 
            break;
        }
        minCount = min(minCount, totalLetters[letter] / count);
    }

    cout << minCount << endl;
    return 0;
}












