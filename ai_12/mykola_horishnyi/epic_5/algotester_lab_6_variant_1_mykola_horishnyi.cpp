#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void lowerCase(string& str) {
    int len = str.size();
    for (int letter = 0; letter < len; letter++) {
        if (str[letter] >= 65 && str[letter] <= 90)
            str[letter] += 32;
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    cin.ignore(32000, '\n');
    vector <string> str(N);
    for (int i = 0; i < N; i++) {
        getline(cin, str[i]);
        lowerCase(str[i]);
    }

    map<string, int> words;
    for (const string& s : str) {
        words[s]++;
    }

    vector<bool> isPresent(26, false);
    for (const auto& pair : words) {
        if (pair.second >= K) {
            for (char ch : pair.first) {
                isPresent[ch - 'a'] = true;
            }
        }
    }

    vector<char> let;
    for (int i = 25; i >= 0; i--) {
        if (isPresent[i]) {
            let.push_back('a' + i);
        }
    }

    if (let.size() == 0)
        cout << "Empty!";
    else {
        cout << let.size() << "\n";
        for (char el : let)
            cout << el << " ";
    }
    return 0;
}
