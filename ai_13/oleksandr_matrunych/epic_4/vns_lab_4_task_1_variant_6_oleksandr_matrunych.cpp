#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
    srand(time(0)); 
    int n, index;

    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; 
    }

    cout << "Initial array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Enter the index of the element to delete (0 - " << n - 1 << "): ";
    cin >> index;

    int valueBeforeDelete = 0; 
    if (index > 0 && index < arr.size()) {
        valueBeforeDelete = arr[index - 1]; 
        arr.erase(arr.begin() + index);    
    } else if (index == 0 && !arr.empty()) {
        arr.erase(arr.begin()); 
    } else {
        cout << "Invalid element index." << endl;
    }

    int valueToAdd = valueBeforeDelete + 2; 
    bool foundEven = false;

    for (auto it = arr.begin(); it != arr.end(); ++it) {
        if (*it % 2 == 0) { 
            arr.insert(it + 1, valueToAdd); 
            foundEven = true;
            break;
        }
    }

    if (!foundEven) {
        cout << "No even element found. Element not added." << endl;
    }

    cout << "Resulting array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
