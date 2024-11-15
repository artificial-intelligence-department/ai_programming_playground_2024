#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(0));

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101;
    }

    cout << "Initial array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.erase(remove(arr.begin(), arr.end(), 0), arr.end());

    cout << "Array after removal: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) { 
            int newValue = (i > 0 ? arr[i - 1] : 0) + 2;
            arr.insert(arr.begin() + i + 1, newValue);
            break;
        }
    }

    cout << "Array after insertion: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
