#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    cin.ignore(); // Ignore the newline after reading integers

    vector<string> words(N);
    vector<int> wordCount(N, 0);
    vector<char> resultSet;

    // Read words and count their occurrences
    for (int i = 0; i < N; ++i) {
        getline(cin, words[i]);
        
        // Convert to lowercase
        for (char &c : words[i]) {
            c = tolower(c);
        }
    }

    // Count the occurrences of each word
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (words[i] == words[j]) {
                wordCount[i]++;
            }
        }
    }

    // Check which words meet the threshold K
    for (int i = 0; i < N; ++i) {
        if (wordCount[i] >= K) {
            // Add letters of the word to the result set
            for (char c : words[i]) {
                if (find(resultSet.begin(), resultSet.end(), c) == resultSet.end()) {
                    resultSet.push_back(c);
                }
            }
        }
    }

    // Sort the result in reverse order
    sort(resultSet.rbegin(), resultSet.rend());

    // Output results
    if (resultSet.empty()) {
        cout << "Empty!" << endl;
    } else {
        cout << resultSet.size() << endl;
        for (char c : resultSet) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}