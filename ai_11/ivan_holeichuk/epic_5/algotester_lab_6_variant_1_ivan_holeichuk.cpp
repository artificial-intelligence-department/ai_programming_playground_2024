#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cin.ignore();

    vector<int> letter_count(26, 0);

    for (int i = 0; i < n; ++i) {
        string word;
        getline(cin, word);
        unordered_set<char> unique_letters;

        for (char c : word) {
            if (isalpha(c)) {
                unique_letters.insert(tolower(c));
            }
        }

        for (char letter : unique_letters) {
            letter_count[letter - 'a']++;
        }
    }

    vector<char> result;
    for (int i = 0; i < 26; ++i) {
        if (letter_count[i] >= k) {
            result.push_back('a' + i);
        }
    }

    if (result.empty()) {
        cout << "Empty!" << endl;
    }
    else {
        cout << result.size() << endl;
        for (int i = result.size() - 1; i >= 0; --i) {
            cout << result[i] << (i == 0 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}

