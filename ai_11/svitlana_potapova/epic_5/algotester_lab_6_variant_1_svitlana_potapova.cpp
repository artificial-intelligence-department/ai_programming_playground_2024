#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cin.ignore();

    vector<string> w(n);

    for (int i = 0; i < n; i++) {
        getline(cin, w[i]);
        for (char &c : w[i]) {
            c = tolower(c);
        }
    }

    unordered_map<string, int> word_count;

    for (const string& word : w) {
        word_count[word]++;
    }

    set<char> result_set;

    for (const auto& entry : word_count) {
        if (entry.second >= k) {
            for (char c : entry.first) {
                result_set.insert(c); 
            }
        }
    }

    if (result_set.empty()) {
        cout << "Empty!";
        return 0;
    }

    vector<char> result(result_set.begin(), result_set.end());

    sort(result.rbegin(), result.rend());

    cout << result.size() << endl;

    for (const char &c : result) {
        cout << c << " ";
    }

    return 0;
}

