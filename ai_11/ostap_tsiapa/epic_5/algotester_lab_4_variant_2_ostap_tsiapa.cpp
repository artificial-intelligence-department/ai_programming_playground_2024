#include <iostream>
#include <vector>
using namespace std;

// Функція для сортування масиву за допомогою алгоритму Quick Sort
void quickSort(vector<int>& arr, int left, int right, bool ascending = true) {
    int i = left, j = right;
    int element = arr[(left + right) / 2];
    while (i <= j) {
        if (ascending) {
            while (arr[i] < element) ++i;
            while (arr[j] > element) --j;
        } else {
            while (arr[i] > element) ++i;
            while (arr[j] < element) --j;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    if (left < j) quickSort(arr, left, j, ascending);
    if (i < right) quickSort(arr, i, right, ascending);
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Розділяємо масив на три частини
    vector<int> mod0, mod1, mod2;
    for (int num : arr) {
        if (num % 3 == 0) mod0.push_back(num);
        else if (num % 3 == 1) mod1.push_back(num);
        else mod2.push_back(num);
    }

    // Сортуємо кожну частину відповідно до умов
    if (!mod0.empty()) quickSort(mod0, 0, mod0.size() - 1);
    if (!mod1.empty()) quickSort(mod1, 0, mod1.size() - 1, false);
    if (!mod2.empty()) quickSort(mod2, 0, mod2.size() - 1);

    // Об'єднуємо всі частини разом в правильному порядку
    vector<int> result;
    result.insert(result.end(), mod0.begin(), mod0.end());
    result.insert(result.end(), mod1.begin(), mod1.end());
    result.insert(result.end(), mod2.begin(), mod2.end());
    
    // Видаляємо дублікати
    vector<int> uniqueResult;
    for (int num : result) {
        if (uniqueResult.empty() || uniqueResult.back() != num) {
            uniqueResult.push_back(num);
        }
    }

    // Виводимо результуючий масив
    cout << uniqueResult.size() << endl;
    for (int num : uniqueResult) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
