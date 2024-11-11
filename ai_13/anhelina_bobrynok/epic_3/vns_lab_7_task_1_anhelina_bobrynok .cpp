#include <iostream>
#include <vector>

using namespace std;

int sum(const vector<int>& numbers) {
    int result = 0;
    
    if (numbers.size() < 2) {
        return 0;
    }

    for (size_t i = 0; i < numbers.size() - 1; ++i) {
        result += numbers[i] * numbers[i + 1];
    }
    return result;
}

int main() {
    cout << "Sum for 5 parameters: " << sum({1, 2, 3, 4, 5}) << endl;
    cout << "Sum for 10 parameters: " << sum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << endl;
    cout << "Sum for 12 parameters: " << sum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}) << endl;

    return 0;
}


