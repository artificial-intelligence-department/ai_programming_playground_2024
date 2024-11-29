#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void printResult(const vector<int>& res) {
    cout << res.size() << endl;
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl << endl;
}

void vidn(vector<int>& mas1, vector<int>& mas2) {
    vector<int> res;
    sort(mas1.begin(), mas1.end());
    sort(mas2.begin(), mas2.end());

    set_difference(mas1.begin(), mas1.end(), mas2.begin(), mas2.end(), back_inserter(res));
    printResult(res);
}

void per(vector<int>& mas1, vector<int>& mas2) {
    vector<int> res;
    sort(mas1.begin(), mas1.end());
    sort(mas2.begin(), mas2.end());

    set_intersection(mas1.begin(), mas1.end(), mas2.begin(), mas2.end(), back_inserter(res));
    printResult(res);
}

void obj(vector<int>& mas1, vector<int>& mas2) {
    vector<int> res;
    sort(mas1.begin(), mas1.end());
    sort(mas2.begin(), mas2.end());

    set_union(mas1.begin(), mas1.end(), mas2.begin(), mas2.end(), back_inserter(res));
    printResult(res);
}

void sym(vector<int>& mas1, vector<int>& mas2) {
    vector<int> res;
    sort(mas1.begin(), mas1.end());
    sort(mas2.begin(), mas2.end());

    set_symmetric_difference(mas1.begin(), mas1.end(), mas2.begin(), mas2.end(), back_inserter(res));
    printResult(res);
}

int main() {
    int N, M;

    cin >> N;
    if (N < 1 || N > 100) {
        return 1;
    }

    vector<int> mas1(N);
    for (int i = 0; i < N; i++) {
        cin >> mas1[i];
        if (mas1[i] < 1 || mas1[i] > 100) {
            return 1;
        }
    }

    cin >> M;
    if (M < 1 || M > 100) {
        return 1;
    }

    vector<int> mas2(M);
    for (int i = 0; i < M; i++) {
        cin >> mas2[i];
        if (mas2[i] < 1 || mas2[i] > 100) {
            return 1;
        }
    }

    vidn(mas1, mas2);
    vidn(mas2, mas1);
    per(mas1, mas2);
    obj(mas1, mas2);
    sym(mas1, mas2);

    return 0;
}
