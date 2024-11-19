#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    if (N < 0 || N > 100) return 0;
    vector<int> firstArr;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a < 0 || a > 100) return 0;
        firstArr.push_back(a);
    }
    cin >> M;
    if (M < 0 || M > 100) return 0;
    vector<int> secondArr;
    for (int i = 0; i < M; ++i) {
        int b;
        cin >> b;
        if (b < 0 || b > 100) return 0;
        secondArr.push_back(b);
    }
    int eqvivalEl;
    for (int elF : firstArr) {
        for (int elS : secondArr) {
            if (elF == elS) {
                eqvivalEl++;
                break;
            }
        }
    }
    int uniqEl = (M + N) - eqvivalEl;
    cout << eqvivalEl << endl << uniqEl;
    return 0;
}