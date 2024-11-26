#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    cin.ignore(); 
    
    vector<string> words(N);
    vector<int> wordCount(N, 0);
    vector<char> resultSet;

    for (int i = 0; i < N; ++i) {
        getline(cin, words[i]);
        
        for (char &c : words[i]) {
            c = tolower(c);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (words[i] == words[j]) {
                wordCount[i]++;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (wordCount[i] >= K) {
            for (char c : words[i]) {
                if (find(resultSet.begin(), resultSet.end(), c) == resultSet.end()) {
                    resultSet.push_back(c);
                }
            }
        }
    }

    sort(resultSet.rbegin(), resultSet.rend());

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