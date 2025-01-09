#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the amount of numbers: ";
    cin >> n;

    double* numbers = new double[n];

    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Number " << (i + 1) << ": ";
        cin >> numbers[i];
    }


    double maxValue = 0;
    double minValue = 1e6;
    for (int i = 0; i < n; i++) {
        if (numbers[i] > maxValue) {
            maxValue = numbers[i];
        }

        if (numbers[i] < minValue) {
            minValue = numbers[i];
        }
    }

    cout << "The maximum value:" << maxValue << endl;
    cout << "The minimum value:" << minValue << endl;

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += numbers[i];
    }
    double average = sum / n;

    cout << "Avarage value: " << average << endl;

    delete[] numbers;

    numbers = nullptr;

    return 0;
}