#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n < k || n > 3 * k) {
        cout << "Impossible" << endl;
        return 0;
    }

    vector<int> teams(k, 1);
    n -= k; 

    for (int i = 0; i < k && n > 0; ++i) {
        int add_students = min(n, 2); 
        teams[i] += add_students;
        n -= add_students;
    }

    for (int i = 0; i < k; ++i) {
        cout << teams[i] << " ";
    }
    cout << endl;

    return 0;
}
