#include <iostream>
#include <vector>
using namespace std;

// Швидке сортування (QuickSort)
void quickSort(vector<int>& arr, int left, int right, auto comparator) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (comparator(arr[i], pivot)) ++i;
        while (comparator(pivot, arr[j])) --j;

        if (i <= j) {
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }

    if (left < j) quickSort(arr, left, j, comparator);
    if (i < right) quickSort(arr, i, right, comparator);
}

// Видалення дублікатів (власна реалізація)
vector<int> removeDuplicates(vector<int>& arr) {
    vector<int> unique;
    for (int i = 0; i < arr.size(); ++i) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            unique.push_back(arr[i]);
        }
    }
    return unique;
}

// Основна функція
int main() {
    int N;
    cin >> N;

    vector<int> array(N);
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    // Власний компаратор
    auto modComparator = [](int a, int b) {
        if (a % 3 != b % 3) {
            return a % 3 < b % 3; // Спочатку за остачею
        }
        if (a % 3 == 1) {
            return a > b; // Остача 1 — за спаданням
        }
        return a < b; // Інші (остача 0 або 2) — за зростанням
    };

    // Сортування з використанням власного QuickSort
    quickSort(array, 0, array.size() - 1, modComparator);

    // Видалення дублікатів
    vector<int> result = removeDuplicates(array);

    // Вивід результату
    cout << result.size() << "\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
