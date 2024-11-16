#include <iostream>
using namespace std;
int main() {
    int n;
    int m = 0;
    int numbers[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    cin >> n;
    for (int i : numbers) {
        m += n/i;
        n -= (n/i)*i;
    }
    cout << m;
    return 0;
}