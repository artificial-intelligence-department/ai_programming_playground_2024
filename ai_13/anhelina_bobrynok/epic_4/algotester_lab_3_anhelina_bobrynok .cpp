#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cin >> M;

    vector<int> b(M);
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }

    int same = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i] == b[j]) {
                same++;
                break;
            }
        }
    }

    vector<int> unique;
    for (int i = 0; i < N; i++) {
        bool isUnique = true;
        for (int j = 0; j < unique.size(); j++) {
            if (a[i] == unique[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            unique.push_back(a[i]);
        }
    }

    for (int i = 0; i < M; i++) {
        bool isUnique = true;
        for (int j = 0; j < unique.size(); j++) {
            if (b[i] == unique[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            unique.push_back(b[i]);
        }
    }

    cout << same << endl;
    cout << unique.size() << endl;

    return 0;
}




