#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    short int N;
    cin >> N;
    cin.ignore();

    vector<string> w(N);
    int M = 0;

    for (int i = 0; i < N; i++) {
        getline(cin, w[i]);
        bool suborder = false;

        for (char c : w[i]) {
            if (c == '#') {
                if (!suborder) {
                    M++;
                    suborder = true;
                }
            } else {
                suborder = false;
            }
        }
    }

    cout << M << endl;
    return 0;
}
