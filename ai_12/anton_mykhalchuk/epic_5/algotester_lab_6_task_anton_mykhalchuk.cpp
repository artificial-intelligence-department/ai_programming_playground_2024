#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    map<string, int> wordCount;
    vector<string> words(n);
    string word;


    for (int i = 0; i < n; i++) {
        cin >> words[i];
        transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
        wordCount[words[i]]++;
    }

    set<char> uniqueLetters;


    for (const auto& entry : wordCount) {
        if (entry.second >= k) {
            for (char c : entry.first) {
                uniqueLetters.insert(c);
            }
        }
    }


    if (uniqueLetters.empty()) {
        cout << "Empty!" << endl;
    } else {
        cout << uniqueLetters.size() << endl;
        

        vector<char> sortedLetters(uniqueLetters.rbegin(), uniqueLetters.rend());
        for (char c : sortedLetters) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}