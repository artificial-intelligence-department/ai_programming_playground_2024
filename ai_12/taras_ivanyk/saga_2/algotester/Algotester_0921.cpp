// ALgotester 0921
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int min_val = min(a, b);
    int max_val = max(a, b);

    if (max_val - min_val > 1) {
        cout << min_val + 1;  
    } else {
        cout << -1;  
    }

    return 0;
}
