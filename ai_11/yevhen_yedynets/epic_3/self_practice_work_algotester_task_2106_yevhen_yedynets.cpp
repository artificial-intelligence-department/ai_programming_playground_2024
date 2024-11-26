#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string upper, lower;
    cin >> upper >> lower;

    for (int i = 0; i < n; ++i) {
        if (upper[i] == '1' && lower[i] == '1') {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No";
    return 0;
}
