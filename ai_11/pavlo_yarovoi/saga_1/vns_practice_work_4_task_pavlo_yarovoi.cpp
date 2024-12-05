#include <iostream>
#include <limits>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "The number of elements must be positive." << endl;
        return 1;
    }

    double sum = 0;
    double min_num = numeric_limits<double>::max();
    double max_num = numeric_limits<double>::min();

    for (int i = 0; i < n; i++) {
        double num;
        cin >> num;
        
        sum += num;

        if (num < min_num) {
            min_num = num;
        }

        if (num > max_num) {
            max_num = num;
        }
    }

    double average = sum / n;

    cout << "Arithmetic average mean: " << average << endl;
    cout << "Minimum number: " << min_num << endl;
    cout << "Maximum number: " << max_num << endl;

    return 0;
}
