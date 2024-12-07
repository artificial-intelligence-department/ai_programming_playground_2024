#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<string> words(N);
    map<string, int> wordCount;

    for (int i = 0; i < N; ++i) {
        cin >> words[i];
        transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
        wordCount[words[i]]++;
    }

    set<char, greater<char>> result;

    for (const auto& pair : wordCount) {
        if (pair.second >= K) {
            for (char ch : pair.first) {
                result.insert(ch);
            }
        }
    }

    if (result.empty()) {
        cout << "Empty!" << endl;
    } else {
        cout << result.size() << endl;
        for (char ch : result) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}
