#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    vector<long long int> temp_numbers = numbers;

    long long int gcd = temp_numbers[0];

    for (int i = 1; i < n; ++i) {
        while (temp_numbers[i] != 0) {
            long long int temp = temp_numbers[i];
            temp_numbers[i] = gcd % temp_numbers[i];
            gcd = temp;
        }
    }

    long long int sum = 0;

    for (int j = 0; j < n; j++)
    {
        sum += (numbers[j] / gcd);
    }
    cout << sum << endl;

    return 0;
}

