#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int wow_count = 1;
    int current_min = numbers[0];

    for (int i = 1; i < n; i++) {
        if (numbers[i] <= current_min) {
            wow_count++;
            current_min = numbers[i];
        }
    }

    cout << wow_count << endl;

    return 0;
}
