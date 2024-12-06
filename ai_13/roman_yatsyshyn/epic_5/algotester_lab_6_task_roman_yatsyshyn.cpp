#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int N = 0;
    cin >> N;    

    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    int Q;
    cin >> Q;

    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        --queries[i].first;
        --queries[i].second;
    }

    for (const auto& [x, y] : queries) {
        // cout << grid[x][y] << endl;
        if (grid[x][y] != '0') {
            cout << '1' << endl << grid[x][y] << endl;
            continue;
        }

        set<char> used_numbers;
        for (int i = 0; i < N; ++i) {
            if (grid[x][i] != '0') {
                used_numbers.insert(grid[x][i]);
            }
            if (grid[i][y] != '0') {
                used_numbers.insert(grid[i][y]);
            }
        }

        vector<int> possible_numbers;
        
        string str = to_string(N);
        char n = str[0];
        for (char c = '1'; c <= n; ++c) {
            if (!used_numbers.count(c)) {
                possible_numbers.push_back(c - '0');
            }
        }

        cout << possible_numbers.size() << endl;
        for (int num : possible_numbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}