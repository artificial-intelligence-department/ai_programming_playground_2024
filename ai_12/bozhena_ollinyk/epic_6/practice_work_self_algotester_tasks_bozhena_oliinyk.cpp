#include <iostream>
#include <climits>
using namespace std;

// Прямокутна ковзанка №1835

const int MAX_N = 1500;

int n, m, k;
int d[MAX_N][MAX_N];
int maxInRow[MAX_N][MAX_N];

void rowMax() {
    for (int i = 0; i < n; ++i) {
        int queue[MAX_N], head = 0, tail = 0;
        for (int j = 0; j < m; ++j) {
            if (head < tail && queue[head] <= j - k) {
                ++head;
            }

            while (head < tail && d[i][queue[tail - 1]] <= d[i][j]) {
                --tail;
            }

            queue[tail++] = j;

            if (j >= k - 1) {
                maxInRow[i][j - k + 1] = d[i][queue[head]];
            }
        }
    }
}

int minMax() {
    int result = INT_MAX;

    for (int j = 0; j <= m - k; ++j) {
        int queue[MAX_N], head = 0, tail = 0;

        for (int i = 0; i < n; ++i) {
            if (head < tail && queue[head] <= i - k) {
                ++head;
            }

            while (head < tail && maxInRow[queue[tail - 1]][j] <= maxInRow[i][j]) {
                --tail;
            }

            queue[tail++] = i;

            if (i >= k - 1) {
                result = min(result, maxInRow[queue[head]][j]);
            }
        }
    }

    return result;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> d[i][j];
        }
    }

    rowMax();

    int result = minMax();

    cout << result << endl;

    return 0;
}
