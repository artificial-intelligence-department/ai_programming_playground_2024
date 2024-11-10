#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int* a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int left_pos = 0;
    int right_pos = n - 1;

    while (true) {
    
        if (left_pos == right_pos) {
            cout << left_pos + 1 << " " << right_pos + 1 << endl;
            cout << "Collision" << endl;
            return 0;
        }

        if (left_pos + 1 == right_pos) {
            cout << left_pos + 1 << " " << right_pos + 1 << endl;
            cout << "Stopped" << endl;
            return 0;
        }

        if (left_pos > right_pos) {
            cout << left_pos + 1 << " " << right_pos + 1 << endl;
            cout << "Miss" << endl;
            return 0;
        }

        left_pos += a[left_pos];    
        right_pos -= a[right_pos];   
    }
    delete[] a;
    return 0;
}
