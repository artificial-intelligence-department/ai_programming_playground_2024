#include <iostream>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    int worker = (n - 1) / k + 1;
    int glove_number = (n - 1) % k + 1;

    cout << worker << " " << glove_number << endl;

    return 0;
}
