#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int x, y;
    cin >> x >> y;
    if (x < 1 || y < 1 || x > N || y > M) return 0;
    
    vector<vector<int>> array(N, vector<int>(M, -1));

    --x, --y;
    array[x][y] = 0;

    for (int i = 0; i <= N + M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (array[j][k] == i) {
                    //Check if the coordinate we want to change exists
                    if (j - 1 >= 0 && array[j - 1][k] == -1) {
                        array[j - 1][k] = i + 1;
                    }
                    if (k - 1 >= 0 && array[j][k - 1] == -1) {
                        array[j][k - 1] = i + 1;
                    }
                    if (j + 1 < N && array[j + 1][k] == -1) {
                        array[j + 1][k] = i + 1;
                    }
                    if (k + 1 < M && array[j][k + 1] == -1) {
                        array[j][k + 1] = i + 1;
                    }
                }
            }
        }
    }

    int max_height = array[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            max_height = max(max_height, array[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            array[i][j] = max_height - array[i][j];
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}