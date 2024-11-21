#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void print(vector<short>& arr) {
    for (short num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void shiftRight(vector<short>& arr, int K) {
    int n = arr.size();
    K = K % n; // Запобігання зайвим зсувам
    if (K == 0) return;

    vector<short> temp(arr.end() - K, arr.end());
    for (int i = n - 1; i >= K; --i) {
        arr[i] = arr[i - K];
    }
    for (int i = 0; i < K; ++i) {
        arr[i] = temp[i];
    }
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    vector<short> arr(size);
    cout << "Generated array: ";
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Генеруємо числа від 0 до 99
        cout << arr[i] << " ";
    }
    cout << endl;

    short del;
    cout << "Enter the value you want to delete: ";
    cin >> del;

    vector<short> index(0);
    for (short i = 0; i < arr.size(); i++) {
        if (arr[i] == del) {
            index.push_back(i);
            break; // Видаляємо тільки перше входження
        }
    }

    for (short idx : index) {
        arr.erase(arr.begin() + idx);
    }

    cout << "Array after deletion: ";
    print(arr);

    short K;
    cout << "How many elements shall the array be shifted to the right: ";
    cin >> K;

    shiftRight(arr, K);

    cout << "Array after shifting: ";
    print(arr);

    return 0;
}
