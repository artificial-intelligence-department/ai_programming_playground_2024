#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    cin.ignore();

    unordered_map<string, int> wordCount;
    set<char> resultSet;

    for (int i = 0; i < N; ++i) {
        string word;
        getline(cin, word);
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        wordCount[word]++;
    }

    for (const auto &entry : wordCount) {
        if (entry.second >= K) {
            for (char c : entry.first) {
                resultSet.insert(c);
            }
        }
    }

    if (resultSet.empty()) {
        cout << "Empty!" << endl;
    } else {
        cout << resultSet.size() << endl;
        for (auto it = resultSet.rbegin(); it != resultSet.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
