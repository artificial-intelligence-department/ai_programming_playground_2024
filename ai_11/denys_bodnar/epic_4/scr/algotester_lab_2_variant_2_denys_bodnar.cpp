#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> r(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }
    
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> Nnew;
    for (int i = 0; i < N; i++) {
        if (r[i] != a && r[i] != b && r[i] != c) {
            Nnew.push_back(r[i]);
        }
    }

    vector<int> suma;
    for (int i = 1; i < Nnew.size(); i++) {
        suma.push_back(Nnew[i - 1] + Nnew[i]);
    }

    cout << suma.size() << endl;
    for (int sum : suma) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
