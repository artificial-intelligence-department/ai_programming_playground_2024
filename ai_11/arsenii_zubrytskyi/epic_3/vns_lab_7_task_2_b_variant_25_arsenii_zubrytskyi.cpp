#include <iostream>
#include <vector>

using namespace std;

void removeElementsBetweenZeros(vector<int>& arr) {
    int firstZero = -1; // Індекс першого нуля
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) {
            if (firstZero == -1) {
                firstZero = i;  // Зберігаємо індекс першого нуля
            } else {
                // Видаляємо елементи між першим і другим нулем
                arr.erase(arr.begin() + firstZero + 1, arr.begin() + i);
                break;  // Перериваємо після видалення
            }
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 5, 0, 6, 7};

    cout << "Before removing elements between zeros:" << endl;
    printArray(arr);

    removeElementsBetweenZeros(arr);

    cout << "After removing elements between zeros:" << endl;
    printArray(arr);

    return 0;
}
