#include <iostream>
#include <vector>
using namespace std;

int main() {
    int quantity;

    cout << "Enter quantity of marks: ";
    cin >> quantity;

    if (quantity <= 0) {
        cout << "Invalid quantity of marks. Exiting program." << endl;
        return 1;
    }

    vector<int> a(quantity);
    int sum = 0;
    int maxMark = INT_MIN; 
    int minMark = INT_MAX; 

    cout << "Enter the marks (1-12):" << endl;
    for (int i = 0; i < quantity; i++) {
        cin >> a[i];
        while (a[i] < 1 || a[i] > 12) {
            cout << "Wrong value of mark, please enter (1-12): ";
            cin >> a[i];
        }
        sum += a[i];
        if (a[i] > maxMark) {
            maxMark = a[i];
        }
        if (a[i] < minMark) {
            minMark = a[i];
        }
    }
    double average = static_cast<double>(sum) / quantity;
    cout << "\nAverage mark: " << average << endl;
    cout << "Max mark: " << maxMark << endl;
    cout << "Min mark: " << minMark << endl;

    return 0;
}
