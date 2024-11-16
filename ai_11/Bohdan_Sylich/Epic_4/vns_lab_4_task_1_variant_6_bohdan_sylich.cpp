#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int n, indexToDelete;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }


    cout << "Початковий масив: ";
    printArray(arr);

    cout << "Введіть індекс елемента для видалення (від 0 до " << n - 1 << "): ";
    cin >> indexToDelete;

    if (indexToDelete >= 0 && indexToDelete < arr.size()) {
        arr.erase(arr.begin() + indexToDelete);
    } else {
        cout << "Неправильний індекс!" << endl;
    }

    cout << "Масив після видалення елемента: ";
    printArray(arr);

    bool added = false;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] % 2 == 0) { 
            int newElement = arr[i - 1] + 2;
            arr.insert(arr.begin() + i, newElement);
            added = true;
            break;
        }
    }

    if (!added) {
        cout << "Парного елемента не знайдено, додавання не виконане." << endl;
    }

    cout << "Масив після додавання елемента: ";
    printArray(arr);

    return 0;
}