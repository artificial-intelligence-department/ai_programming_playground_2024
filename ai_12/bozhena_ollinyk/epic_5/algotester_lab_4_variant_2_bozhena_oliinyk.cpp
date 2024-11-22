#include <iostream>
#include <algorithm>
using namespace std;

void printResult(const int *result, int size) {
    cout << size << endl;
    for (int i = 0; i < size; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

void differenceN_M(const int *n, int N, const int *m, int M) {
    int result[1000], resultSize = 0;

    int i = 0, j = 0;
    while (i < N && j < M) {
        if (n[i] < m[j]) {
            result[resultSize++] = n[i++];
        } else if (n[i] > m[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    while (i < N) {
        result[resultSize++] = n[i++];
    }

    printResult(result, resultSize);
}

void intersection(const int *n, int N, const int *m, int M) {
    int result[1000], resultSize = 0;

    int i = 0, j = 0;
    while (i < N && j < M) {
        if (n[i] < m[j]) {
            i++;
        } else if (n[i] > m[j]) {
            j++;
        } else {
            result[resultSize++] = n[i];
            i++;
            j++;
        }
    }

    printResult(result, resultSize);
}

void unionN_M(const int *n, int N, const int *m, int M) {
    int result[2000], resultSize = 0;

    int i = 0, j = 0;
    while (i < N && j < M) {
        if (n[i] < m[j]) {
            result[resultSize++] = n[i++];
        } else if (n[i] > m[j]) {
            result[resultSize++] = m[j++];
        } else {
            result[resultSize++] = n[i];
            i++;
            j++;
        }
    }

    while (i < N) {
        result[resultSize++] = n[i++];
    }

    while (j < M) {
        result[resultSize++] = m[j++];
    }

    printResult(result, resultSize);
}

void symmetricDifference(const int *n, int N, const int *m, int M) {
    int result[2000], resultSize = 0;

    int i = 0, j = 0;
    while (i < N && j < M) {
        if (n[i] < m[j]) {
            result[resultSize++] = n[i++];
        } else if (n[i] > m[j]) {
            result[resultSize++] = m[j++];
        } else {
            i++;
            j++;
        }
    }

    while (i < N) {
        result[resultSize++] = n[i++];
    }

    while (j < M) {
        result[resultSize++] = m[j++];
    }

    printResult(result, resultSize);
}

int main() {
    int N, M;

    cin >> N;
    int n[1000];
    for (int i = 0; i < N; ++i) {
        cin >> n[i];
    }

    cin >> M;
    int m[1000];
    for (int i = 0; i < M; ++i) {
        cin >> m[i];
    }

    sort(n, n + N);
    sort(m, m + M);

    differenceN_M(n, N, m, M);
    cout << endl;

    differenceN_M(m, M, n, N);
    cout << endl;

    intersection(n, N, m, M);
    cout << endl;

    unionN_M(n, N, m, M);
    cout << endl;

    symmetricDifference(n, N, m, M);
    cout << endl;

    return 0;
}
