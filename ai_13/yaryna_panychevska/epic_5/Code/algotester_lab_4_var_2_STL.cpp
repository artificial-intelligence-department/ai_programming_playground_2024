#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Реалізація через STL
int main() {
    int n, k;
    cin >> n >> k;
    vector <int> elements(n);

    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    sort(elements.begin(), elements.end());
    elements.erase(unique(begin(elements), end(elements)), end(elements));
    int new_size = elements.size();

    if (new_size > 0) {
        k %= new_size;
        rotate(elements.begin(), elements.begin() + k, elements.end());
    }

    cout << new_size << endl;
    for (int i = 0; i < new_size; i++) {
        cout << elements[i] << " ";
    }
    return 0;
}