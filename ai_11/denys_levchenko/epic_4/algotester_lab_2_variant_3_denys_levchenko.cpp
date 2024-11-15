#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int left = 0;
    int right = N - 1;

    while (true) {
        if (left == right) {
            cout << left + 1 << " " << right + 1 << endl;
            cout << "Collision" << endl;
            break;
        } 
        else if (left + 1 == right) {
            cout << left + 1 << " " << right + 1 << endl;
            cout << "Stopped" << endl;
            break;
        } 
        else if (left > right) {
            cout << left + 1 << " " << right + 1 << endl;
            cout << "Miss" << endl;
            break;
        }

        left += a[left];
        right -= a[right];
    }

    return 0;
}
