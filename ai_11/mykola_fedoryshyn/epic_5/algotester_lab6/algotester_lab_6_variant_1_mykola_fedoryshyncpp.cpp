#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cin.ignore();

    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        getline(cin, words[i]);
        transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
    }
    unordered_map<string, int> freq_map;
    for (const auto& word : words) { /*створюємо map де кожному слові буде відповідати 1*/
        ++freq_map[word];
    }

    vector<int> char_freq(26, 0);
    for (const auto& pair : freq_map) {
        if (pair.second >= k) {
            for (char c : pair.first) {
                char_freq[c - 'a'] = 1;
            }
        }
    }
    vector<char> result;

    for (int i = 25; i >= 0; --i) {
        if (char_freq[i]) {
            result.push_back(i + 'a');
        }
    }

    if (result.empty()) {
        cout << "Empty!";
    } else {
        cout << result.size() << endl;
        for (char c : result) {
            cout << c << " ";
        }
    }

    return 0;
}

/*
5 2
stugna
neptune
grim
oplot
Grim
*/
    
