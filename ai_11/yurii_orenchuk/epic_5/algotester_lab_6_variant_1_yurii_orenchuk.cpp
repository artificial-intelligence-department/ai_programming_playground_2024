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

    unordered_map<string, int> amount;
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
        toLower(words[i]);
        amount[words[i]]++;
    }

    set<char> letters;
    for (const auto [word, count] : amount) {
        if (count >= K) {
            for (char c : word) {
                letters.insert(c);
            }
        }
    }

    if (letters.empty()) {
        cout << "Empty!";
        return 0;
    }

    vector<char> sorted(letters.begin(), letters.end());
    sort(sorted.rbegin(), sorted.rend());

    cout << sorted.size() << endl;
    for (size_t i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << " ";
    }
    cout << endl;

    return 0;
}