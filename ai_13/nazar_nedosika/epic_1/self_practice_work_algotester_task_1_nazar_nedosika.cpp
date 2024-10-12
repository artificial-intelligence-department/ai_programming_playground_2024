#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> order_of_elements(n);
    for (int i = 0; i < n; ++i) {
        cin >> order_of_elements[i];
    }

    vector<int> lengths(n, 1);
    
    int maxLength = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (order_of_elements[i] > order_of_elements[j]) {
                lengths[i] = max(lengths[i], lengths[j] + 1);
            }
        }
        maxLength = max(maxLength, lengths[i]);
    }

    cout << maxLength << endl;

    return 0;
}
