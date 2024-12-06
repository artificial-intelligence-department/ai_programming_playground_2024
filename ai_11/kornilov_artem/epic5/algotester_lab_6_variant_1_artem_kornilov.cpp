#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void toLower(string& str) {
    for (char& c : str) {
        c = tolower(c);
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    unordered_map<string, int> freq;
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
        toLower(words[i]);
        freq[words[i]]++;
    }

    set<char> letters;
    for (const auto& [word, count] : freq) {
        if (count >= K) {
            for (char c : word) {
                letters.insert(c);
            }
        }
    }

    if (letters.empty()) {
        cout << "Empty!" << endl;
        return 0;
    }

    vector<char> sortedLetters(letters.begin(), letters.end());
    sort(sortedLetters.rbegin(), sortedLetters.rend());

    cout << sortedLetters.size() << endl;
    for (size_t i = 0; i < sortedLetters.size(); i++) {
        cout << sortedLetters[i];
        if (i != sortedLetters.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}