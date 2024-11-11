#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, a, b, c;
    cin >> N;

    vector<int> r(N);

    for (int i = 0; i < N; ++i) {
        cin >> r[i];
    }
    cin >> a >> b >> c;

    r.erase(remove(r.begin(), r.end(), a), r.end());
    r.erase(remove(r.begin(), r.end(), b), r.end()); //Видаляє з вектора a,b,c
    r.erase(remove(r.begin(), r.end(), c), r.end());

    if (r.size() < 2) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> sumArray;
    for (int i = 0; i < r.size() - 1; ++i) {
        sumArray.push_back(r[i] + r[i + 1]);
    }
    cout << sumArray.size() << endl;
    for (int num : sumArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
