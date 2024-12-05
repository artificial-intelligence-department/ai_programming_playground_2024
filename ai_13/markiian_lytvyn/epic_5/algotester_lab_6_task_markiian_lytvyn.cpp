#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    cin.ignore(); 
    unordered_map<string, int> Count;
    unordered_set<char> res_set;

    for (int i = 0; i < N; ++i) {
        string words;
        getline(cin, words);

        transform(words.begin(), words.end(), words.begin(), ::tolower);
        Count[words]++;
    }
    for (const auto &entry : Count) {
        if (entry.second >= K) {
           
            for (char c : entry.first) {
                res_set.insert(c);
            }
        }
    }
    vector<char> res(res_set.begin(), res_set.end());
    sort(res.rbegin(), res.rend()); 
    int M = res.size();
    if (res.empty()) {
        cout << "Empty!" << endl;
    } else {
        cout << M << endl;
        for (char c : res) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
