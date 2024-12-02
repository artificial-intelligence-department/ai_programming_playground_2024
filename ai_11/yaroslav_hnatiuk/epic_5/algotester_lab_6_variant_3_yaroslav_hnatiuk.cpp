#include <iostream>
#include <vector>
using namespace std;

vector<int> possibleNumbers(vector<vector<int>>& matrix, int x, int y, int N);

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = row[j] - '0';
        }
    }

    int Q;
    cin >> Q;

    vector<pair<int, int>> coord(Q);
    for (int i = 0; i < Q; i++) {
        cin >> coord[i].first >> coord[i].second;
        --coord[i].first; 
        --coord[i].second;
    }

    for (int i = 0; i < Q; i++) {
        vector<int> possible = possibleNumbers(matrix, coord[i].first, coord[i].second, N);
        if (!possible.empty()) {
            cout << possible.size() << endl;
            for (int num : possible) {
                cout << num << " ";
            } 
        } else {
            cout << 0;
        }
        cout << endl << endl;   
    }

    return 0;
}

vector<int> possibleNumbers(vector<vector<int>>& matrix, int x, int y, int N) {
    if (matrix[x][y] != 0) {
        return {matrix[x][y]};
    }

    vector<int> possible(N);
    for (int i = 0; i < N; ++i) {
        possible[i] = i + 1;
    }

    for (int i = 0; i < N; ++i) {
        if (matrix[x][i] != 0) {
            for (int j = 0; j < possible.size(); j++) {
                if (matrix[x][i] == possible[j]) possible.erase(possible.begin()  + j);
            }
        }

        if (matrix[i][y] != 0) {
            for (int j = 0; j < possible.size(); j++) {
                if (matrix[i][y] == possible[j]) possible.erase(possible.begin()  + j);
            }
        }
    }

    return vector<int>(possible.begin(), possible.end());
}

