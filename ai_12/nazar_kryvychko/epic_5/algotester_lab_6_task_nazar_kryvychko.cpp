#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    cin.ignore(); // Ignore the newline after reading integers

    unordered_map<string, int> wordCount;
    unordered_set<char> resultSet;

    // Read words and count their occurrences
    for (int i = 0; i < N; ++i) {
        string word;
        getline(cin, word);
        
        // Convert to lowercase
        for (char &c : word) {
            c = tolower(c);
        }
        
        // Increment the count for the word
        wordCount[word]++;
    }

    // Check which words meet the threshold K
    for (const auto &pair : wordCount) {
        if (pair.second >= K) {
            // Add letters of the word to the result set
            for (char c : pair.first) {
                resultSet.insert(c);
            }
        }
    }

    // Prepare the result
    vector<char> result(resultSet.begin(), resultSet.end());
    sort(result.rbegin(), result.rend()); // Sort in reverse order

    // Output results
    if (result.empty()) {
        cout << "Empty!" << endl;
    } else {
        cout << result.size() << endl;
        for (char c : result) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}