#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    map<string, int> wordCount;
    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
        for (size_t j = 0; j < words[i].size(); ++j) {
            words[i][j] = tolower(words[i][j]);
        }
        wordCount[words[i]]++;
    }

    set<char> uniqueLetters;
    for (map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it) {
        if (it->second >= K) {
            for (size_t j = 0; j < it->first.size(); ++j) {
                uniqueLetters.insert(it->first[j]);
            }
        }
    }
    if (uniqueLetters.empty()) {
        cout << "Empty!" << endl;
    } else {
        cout << uniqueLetters.size() << endl;
        vector<char> result(uniqueLetters.begin(), uniqueLetters.end());
        sort(result.rbegin(), result.rend());
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
