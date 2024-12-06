#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

void readField(vector<vector<int>>& field, int N) {
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            field[i][j] = row[j] - '0';
        }
    }
}

void processQueries(const vector<vector<int>>& field, int N, int Q) {
    vector<string> results;
    for (int t = 0; t < Q; t++) {
        int x, y;
        cin >> x >> y;
        x = x - 1; 
        y = y - 1;

        set<int> cantused;
        for (int i = 0; i < N; i++) {
            if (field[x][i] != 0) {
                cantused.insert(field[x][i]);
            }
        }

        for (int i = 0; i < N; i++) {
            if (field[i][y] != 0) {
                cantused.insert(field[i][y]);
            }
        }

        if (field[x][y] != 0) {
            string result = "1 " + to_string(field[x][y]);
            results.push_back(result);
        } else {
            vector<int> possible;
            for (int num = 1; num <= N; num++) {
                if (cantused.find(num) == cantused.end()) {
                    possible.push_back(num);
                }
            }

            string result = to_string(possible.size());
            for (int num : possible) {
                result += " " + to_string(num);
            }
            results.push_back(result);
        }
    }

    for (const string& res : results) {
        cout << res << "\n";
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> field(N, vector<int>(N));
    readField(field, N);

    int Q;
    cin >> Q;

    processQueries(field, N, Q);

    return 0;
}

